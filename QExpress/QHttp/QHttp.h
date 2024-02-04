#ifndef QHTTP_H_
#define QHTTP_H_

#include <QByteArray>
#include <QDebug>
#include <QMap>
#include <QMultiMap>

#include <type_traits>

extern "C" {
    #include "llhttp.h"
}

namespace QHttp
{   
    using Buffer = QByteArray;
    
    template <typename T>
    struct http_message_has_method {
        template <typename U>
        static auto test(U* p) -> decltype(std::declval<U>().method, std::true_type());

        template <typename U>
        static auto test(...) -> std::false_type;

        static constexpr bool value = decltype(test<T>(nullptr))::value;
    };

    template <typename T>
    struct http_message_has_status {
        template <typename U>
        static auto test(U* p) -> decltype(std::declval<U>().status, std::true_type());

        template <typename U>
        static auto test(...) -> std::false_type;

        static constexpr bool value = decltype(test<T>(nullptr))::value;
    };

    struct HttpMessage {
        Buffer version;
        Buffer url;
        QMap<Buffer,Buffer> headers;
        Buffer body;
    };

    struct RequestMessage : public HttpMessage {
        Buffer method;
    };

    struct ResponseMessage : public HttpMessage {
        int statusCode;
        Buffer status;
    };

    
    template<typename Message>
    class Parser
    {
    public:
        Parser() {
            llhttp_init(&m_Parser, HTTP_BOTH, &Parser<Message>::m_Settings);
            m_Parser.data = this;
        }
        
        Parser(const Parser&) = delete;
        Parser& operator=(const Parser&) = delete;
        Parser(Parser&&) = delete;
        Parser& operator=(Parser&&) = delete;

        bool execute(Buffer data, int len) {
            enum llhttp_errno err = llhttp_execute(&m_Parser, data.constData(), data.length());

            if (err != HPE_OK) {
                fprintf(stderr, "Parse error: %s %s\n", llhttp_errno_name(err), m_Parser.reason);
                return false;
            }
            return true;
        }

        template <typename U = Message>
        std::enable_if_t<http_message_has_method<U>::value, const Buffer&> method() const {
            return m_Message.method;
        }

        template <typename U = Message>
        std::enable_if_t<http_message_has_status<U>::value, const Buffer&> statusDesc() const {
            return m_Message.status;
        }

        template <typename U = Message>
        std::enable_if_t<http_message_has_status<U>::value, const int&> statusCode() const {
            return m_Message.statusCode;
        }

        const Buffer& url() const {
            return m_Message.url;
        }

        const Buffer& version() const {
            return m_Message.version;
        }

        const Buffer& body() const{
            return m_Message.body;
        }

        const QMap<Buffer, Buffer>& headers() const {
            return m_Message.headers;
        }

        const llhttp_t& parser() const {
            return m_Parser;
        }

    public:
        int on_message_begin(llhttp_t* parser)
        {
            qDebug("parse start\n");
            return 0;
        }

        int on_message_complete(llhttp_t* parser) {
            _get_method_name_from_parser();
            _get_response_status_from_parser();
            //printf("Message completed!\n");
            return 0;
        }

        // // Only used when parser is initialized as HTTP_REQUEST
        int on_method(llhttp_t* parser, const char* at, size_t length)
        {
            if constexpr(std::is_same_v<Message, RequestMessage>){
                m_Message.method = Buffer(at, length);
                //printf("on_method: %s\n", m_Message.method.constData());
                return 0;
            }
            return 0;
        }

        // Only used when parser is initialized as HTTP_RESPONSE
        int on_status(llhttp_t* parser, const char* at, size_t length)
        {
            if constexpr(std::is_same_v<Message, ResponseMessage>){
                m_Message.status = Buffer(at, length);
                //printf("on_status: %s\n", m_Message.status.constData());
                return 0;
            }

            return 0;            
        }

        int on_url(llhttp_t* parser, const char* at, size_t length)
        {
            m_Message.url = Buffer(at, length);
            //printf("on_url: %s\n", m_Message.url.constData());
            return 0;
        }

        int on_version(llhttp_t* parser, const char* at, size_t length)
        {
            m_Message.version = Buffer(at, length);
            //printf("on_version: %s\n", m_Message.version.constData());
            return 0;
        }

        int on_header_field(llhttp_t* parser, const char* at, size_t length)
        {
            m_CurrentHeader = Buffer(at, length);
            //printf("header field: %s\n", m_CurrentHeader.constData());
            return 0;
        }

        int on_header_value(llhttp_t* parser, const char* at, size_t length)
        {
            Buffer header_value = Buffer(at, length);
            // TODO: why request.headers[currentHeader] = header_value; doesn't work?
            m_Message.headers.insert(m_CurrentHeader, header_value);
            //printf("head value: %s\n", header_value.constData());
            return 0;
        }

        int on_headers_complete(llhttp_t* parser)
        {
            //printf("on_headers_complete, major: %d, major: %d, keep-alive: %d, upgrade: %d\n", parser->http_major, parser->http_minor, llhttp_should_keep_alive(parser), parser->upgrade);
            return 0;
        }

        int on_body(llhttp_t* parser, const char* at, size_t length)
        {
            m_Message.body = Buffer(at, length);
            //printf("on_body: %s\n", m_Message.body.constData());
            return 0;
        }

    private:
        void _get_method_name_from_parser(){
            if constexpr(std::is_same_v<Message, RequestMessage>){
                auto methodEnum = llhttp_get_method(&m_Parser);
                const char* methodName = llhttp_method_name(static_cast<llhttp_method_t>(methodEnum));
                m_Message.method = Buffer(methodName, strlen(methodName));
            } else
            {
                return;
            }
            
        }

        void _get_response_status_from_parser(){
            if constexpr(std::is_same_v<Message, ResponseMessage>){
                int statusCode = llhttp_get_status_code(&m_Parser);
                m_Message.statusCode = statusCode;
                const char* statusName = llhttp_status_name(static_cast<llhttp_status_t>(statusCode));
                m_Message.status = Buffer(statusName, strlen(statusName));
            } else {
                return ;
            }
        }

    private:
        Message m_Message;
        llhttp_t m_Parser;
        static llhttp_settings_t m_Settings;
        Buffer m_CurrentHeader;
    };

    // have to initialize settings with these functions in the same order:
    // struct llhttp_settings_s {
    // llhttp_cb      on_message_begin;
    // llhttp_data_cb on_url;
    // llhttp_data_cb on_status;
    // llhttp_data_cb on_method;
    // llhttp_data_cb on_version;
    // llhttp_data_cb on_header_field;
    // llhttp_data_cb on_header_value;
    // llhttp_data_cb      on_chunk_extension_name;
    // llhttp_data_cb      on_chunk_extension_value;
    // llhttp_cb      on_headers_complete;
    // llhttp_data_cb on_body;
    // llhttp_cb      on_message_complete;
    // };
    
    template<typename Message>
    llhttp_settings_t Parser<Message>::m_Settings = {
        // on_message_begin,
        [](llhttp_t * parser) {
            return ((Parser *)parser->data)->on_message_begin(parser);
        },
        // on_url,
        [](llhttp_t * parser, const char * data, size_t len) {
            return ((Parser *)parser->data)->on_url(parser, data, len);
        },
        // on_status,
        0,
        // on_method,
        0,
        // on_version,
        [](llhttp_t * parser, const char * data, size_t len) {
            return ((Parser *)parser->data)->on_version(parser, data, len);
        },
        // on_header_field,
        [](llhttp_t * parser, const char * data, size_t len) {
            return ((Parser *)parser->data)->on_header_field(parser, data, len);
        },
        // on_header_value,
        [](llhttp_t * parser, const char * data, size_t len) {
            return ((Parser *)parser->data)->on_header_value(parser, data, len);
        },
        // on_chunk_extension_name,
        0,
        // on_chunk_extension_value,
        0,
        // on_headers_complete,
        [](llhttp_t * parser) {
            return ((Parser *)parser->data)->on_headers_complete(parser);
        },
        // on_body,
        [](llhttp_t * parser, const char * data, size_t len) {
            return ((Parser *)parser->data)->on_body(parser, data, len);
        },
        // on_message_complete,
        [](llhttp_t * parser) {
            return ((Parser *)parser->data)->on_message_complete(parser);
        }
    };
    
} // namespace QHttp

namespace QHttp
{
    using RequestParser = Parser<RequestMessage>;
    using ResponseParser = Parser<ResponseMessage>;
}


#endif // !QHTTP_H_