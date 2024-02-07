#ifndef QEXPRESS_RESPONSE_H_
#define QEXPRESS_RESPONSE_H_


#include <memory>

#include "Globals.h"

namespace QExpress
{
    class Response {
    public:
        Response(Server& app, Request& req);
        ~Response();

        Server& app();
        Request& request();
        bool headersSent();
        void locals(const BufferMap&);
        void locals(const BufferMap&&);
        void append(Buffer name, Buffer value);
        Cookie& cookie();

        void send(Buffer&);
        Response& sendStatus(int);
        void setStatus(int);
        void set(BufferMap& headers);

    private:
        struct ResponseImpl;
        std::unique_ptr<ResponseImpl> Impl;
    }; 
} // namespace QExpress


#endif // !QEXPRESS_RESPONSE_H_