#ifndef QEXPRESS_REQUESTIMPL_H_
#define QEXPRESS_REQUESTIMPL_H_


#include "../Globals.h"
#include "QHttp.h"
#include "../Request.h"


namespace QExpress
{
    using RequestParser = QHttp::RequestParser;
    
    struct Request::RequestImpl {
        RequestParser _parser;
        Server& _app;
        Response& _res;
        Route& _route;
        
        RequestImpl(Server& app, Response& res, Route& route);
        ~RequestImpl();

        Buffer protocol() const;
        Buffer version() const;
        const Buffer& method() const;
        const Buffer hostname() const;
        const Buffer host() const;
        const std::vector<Buffer> subdomains() const;
        Buffer ip() const;
        Buffer uri() const;
        const Buffer& get(Buffer&) const;
        BufferMap params() const;
        Buffer originalURL() const;
        Buffer baseURL() const;
        Buffer path() const;
        BufferMap body() const;
        BufferMap cookies() const;
        BufferMap signedCookies() const;
        Buffer contentType() const;
    };

    Request::RequestImpl::RequestImpl(Server& app, Response& res, Route& route)
        : _app(app), _res(res), _route(route)
    {
        
    }
    
    Request::RequestImpl::~RequestImpl()
    {
        
    }
    
    Buffer Request::RequestImpl::protocol() const
    {
        return "http";
    }
    
    Buffer Request::RequestImpl::version() const
    {
        return "HTTP/1.1";
    }
    
    const Buffer& Request::RequestImpl::method() const
    {
        return _parser.method();
    }
    
    const Buffer Request::RequestImpl::hostname() const
    {
        return Buffer();
    }
    
    const Buffer Request::RequestImpl::host() const
    {
        return Buffer();
    }
    
    const std::vector<Buffer> Request::RequestImpl::subdomains() const
    {
        return std::vector<Buffer>();
    }
    
    Buffer Request::RequestImpl::ip() const
    {
        return Buffer();
    }
    
    Buffer Request::RequestImpl::uri() const
    {
        return Buffer();
    }
    
    const Buffer& Request::RequestImpl::get(Buffer& name) const
    {
        return _parser.headers()[name];
    }
    
    BufferMap Request::RequestImpl::params() const
    {
        return BufferMap();
    }
    
    Buffer Request::RequestImpl::originalURL() const
    {
        return Buffer();
    }
    
    Buffer Request::RequestImpl::baseURL() const
    {
        return Buffer();
    }
    
    Buffer Request::RequestImpl::path() const
    {
        return Buffer();
    }
    
    BufferMap Request::RequestImpl::body() const
    {
        return BufferMap();
    }
    
    BufferMap Request::RequestImpl::cookies() const
    {
        return BufferMap();
    }
    
    BufferMap Request::RequestImpl::signedCookies() const
    {
        return BufferMap();
    }
    
    Buffer Request::RequestImpl::contentType() const
    {
        return Buffer();
    }
    
    
    
} // namespace QExpress

#endif // QEXPRESS_REQUESTIMPL_H_