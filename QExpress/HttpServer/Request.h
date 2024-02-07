#ifndef QEXPRESS_REQUEST_H_
#define QEXPRESS_REQUEST_H_

#include <QHostAddress>
#include <QTcpSocket>
#include <QMap>
#include <QMultiMap>
#include <QSettings>
#include <QTemporaryFile>
#include <QUuid>

#include <memory>

#include <QHttp.h>
#include "Globals.h"

namespace QExpress
{
    class Request
    {
    public:
        Request(Server& app, Response& res, Route& route);
        ~Request();

        Server& app() const;
        Response& res() const;
        Route& route() const;

        /**
         * Note
         * originalUrl = baseUrl + path
         * Example:
         * GET 'http://www.example.com/admin/new?sort=desc'
         * app.use('/admin', handler);
         * originalUrl: '/admin/new?sort=desc'
         * baseUrl: '/admin'
         * path: '/new'
         */
        Buffer originalURL() const;
        Buffer baseURL() const;
        Buffer path() const;

        BufferMap body() const;
        BufferMap cookies() const;
        Buffer host() const;
        Buffer hostname() const;
        BufferMap params() const;
        Buffer ip() const;
        Buffer method() const;
        Buffer protocol() const;
        bool secure() const;
        BufferMap signedCookies() const;
        std::vector<Buffer> subdomains() const;
        bool accepts(Buffer& content_type);
        Buffer get(Buffer& name);
        bool is(Buffer& type);

    private:
        friend class Server;
        struct RequestImpl;
        std::unique_ptr<RequestImpl> impl;
    };
} // namespace QExpress


#endif // !QEXPRESS_REQUEST_H_