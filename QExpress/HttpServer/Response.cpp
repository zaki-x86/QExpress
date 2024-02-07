#include "private/ResponseImpl.h"

namespace QExpress
{
    Response::Response(Server& app, Request& req)
        : impl(new ResponseImpl(app, req))
    {
        
    }

    Response::~Response()
    {
        
    }
    
    Server& Response::app()
    {
        return impl->_app;
    }
    
    Request& Response::request()
    {
        return impl->_req;
    }
    
    bool Response::headersSent()
    {
        return false;
    }
    
    void Response::locals(const BufferMap&)
    {
        
    }
    
    void Response::locals(const BufferMap&&)
    {
        
    }
    
    void Response::append(Buffer name, Buffer value)
    {
        
    }
    
    Cookie& Response::cookie()
    {
        return impl->_cookie;
    }
    
    void Response::send(Buffer&)
    {
        
    }
    
    Response& Response::sendStatus(int)
    {
        return *this;
    }
    
    void Response::setStatus(int)
    {
        
    }
    
    void Response::set(BufferMap& headers)
    {
        
    }
}