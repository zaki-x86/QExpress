#include "private/RequestImpl.h"

namespace QExpress
{
    Request::Request(Server& app, Response& res, Route& route)
        : Impl(new RequestImpl(app, res, route))
    {
        
    }
    
    Request::~Request() {}

    Server &Request::app() const
    {
        return Impl->_app;
    }
    
    Buffer Request::originalURL() const
    {
        return Impl->originalURL();
    }
    
    Buffer Request::baseURL() const
    {
        return Impl->baseURL();
    }
    
    Buffer Request::path() const
    {
        return Impl->path();
    }
    
    BufferMap Request::body() const
    {
        return Impl->body();
    }
    
    BufferMap Request::cookies() const
    {
        return Impl->cookies();
    }
    
    Buffer Request::host() const
    {
        return Impl->host();
    }
    
    Buffer Request::hostname() const
    {
        return Impl->hostname();
    }
    
    BufferMap Request::params() const
    {
        return Impl->params();
    }
    
    Buffer Request::ip() const
    {
        return Impl->ip();
    }
    
    Buffer Request::method() const
    {
        return Impl->method();
    }
    
    Buffer Request::protocol() const
    {
        return Impl->protocol();
    }
    
    Route& Request::route() const
    {
        return Impl->_route;
    }
    
    bool Request::secure() const
    {
        return Impl->protocol() == "https";
    }
    
    BufferMap Request::signedCookies() const
    {
        return Impl->signedCookies();
    }
    
    std::vector<Buffer> Request::subdomains() const
    {
        return Impl->subdomains();
    }
    
    Buffer Request::get(Buffer& name)
    {
        return Impl->get(name);
    }
}