#include "private/ResponseImpl.h"

namespace QExpress
{
    Response::Response(Server& app, Request& req)
        : Impl(new ResponseImpl(app, req))
    {
        
    }

    Response::~Response()
    {
        
    }
    
    Server& Response::app()
    {
        return Impl->_app;
    }
    
    Request& Response::request()
    {
        return Impl->_req;
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
        return Impl->_cookie;
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