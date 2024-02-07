#ifndef QEXPRESS_RESPONSEIMPL_H_
#define QEXPRESS_RESPONSEIMPL_H_

#include "../Globals.h"
#include "../Response.h"
#include "../Cookie.h"

namespace QExpress
{
    struct Response::ResponseImpl {
        ResponseImpl(Server& app, Request& req);
        ~ResponseImpl();

        Server& _app;
        Request& _req;
        Cookie _cookie;
        int _status;
        BufferMap _headers;
        Buffer _body;

        bool headersSent();
        void locals(const BufferMap&);
        void locals(const BufferMap&&);
        void append(Buffer name, Buffer value);

        void send(Buffer&);
    };

    Response::ResponseImpl::ResponseImpl(Server& app, Request& req)
        : _app(app), _req(req), _status(404), _headers(), _body()
    {
        
    }
    
    Response::ResponseImpl::~ResponseImpl()
    {
        
    }
    
    bool Response::ResponseImpl::headersSent()
    {
        return false;
    }
    
    void Response::ResponseImpl::locals(const BufferMap&)
    {
        
    }
    
    void Response::ResponseImpl::locals(const BufferMap&&)
    {
        
    }
    
    void Response::ResponseImpl::append(Buffer name, Buffer value)
    {
        
    }
    
    void Response::ResponseImpl::send(Buffer&)
    {
        
    }
    
    
    
} // namespace QExpress

#endif // QEXPRESS_RESPONSEIMPL_H_