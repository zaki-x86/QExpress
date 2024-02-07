#include "private/RequestImpl.h"

namespace QExpress
{
    Request::Request(Server& app, Response& res, Route& route)
        : impl(new RequestImpl(app, res, route))
    {
        
    }
    
    Request::~Request() {}

    Server &Request::app() const
    {
        return impl->_app;
    }
    
    Buffer Request::originalURL() const
    {
        return impl->originalURL();
    }
    
    Buffer Request::baseURL() const
    {
        return impl->baseURL();
    }
    
    Buffer Request::path() const
    {
        return impl->path();
    }
    
    BufferMap Request::body() const
    {
        return impl->body();
    }
    
    BufferMap Request::cookies() const
    {
        return impl->cookies();
    }
    
    Buffer Request::host() const
    {
        return impl->host();
    }
    
    Buffer Request::hostname() const
    {
        return impl->hostname();
    }
    
    BufferMap Request::params() const
    {
        return impl->params();
    }
    
    Buffer Request::ip() const
    {
        return impl->ip();
    }
    
    Buffer Request::method() const
    {
        return impl->method();
    }
    
    Buffer Request::protocol() const
    {
        return impl->protocol();
    }
    
    Route& Request::route() const
    {
        return impl->_route;
    }
    
    bool Request::secure() const
    {
        return impl->protocol() == "https";
    }
    
    BufferMap Request::signedCookies() const
    {
        return impl->signedCookies();
    }
    
    std::vector<Buffer> Request::subdomains() const
    {
        return impl->subdomains();
    }
    
    Buffer Request::get(Buffer& name)
    {
        return impl->get(name);
    }
}