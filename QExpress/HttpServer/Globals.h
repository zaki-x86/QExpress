#ifndef QEXPRESS_GLOBALS_H_
#define QEXPRESS_GLOBALS_H_

#include <functional>
#include <QObject>
#include <QMap>
#include <QByteArray>

namespace QExpress {
    class Request;
    class Response;
    class Router;
    class Server;
    class ConnectionHandler;
    class Cookie;
    class Session;
    class Route;

    using Next = std::function<void(std::exception_ptr)>;
    using HandlerCallback = std::function<void(Request&, Response&, Next)>;
    using ErrorHandlerCallback = std::function<void(std::exception_ptr, Request&, Response&, Next)>;

    using Buffer = QByteArray;
    using BufferMap = QMap<Buffer, Buffer>;

    enum class HTTP_METHOD : uint8_t {
        GET, POST, PUT, DEL, HEAD, OPTIONS, PATCH, TRACE, CONNECT, ALL
    };
    
}

#endif // !QEXPRESS_GLOBALS_H_