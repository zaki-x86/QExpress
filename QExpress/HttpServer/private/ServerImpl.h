#ifndef QEXPRESS_SERVERIMPL_H_
#define QEXPRESS_SERVERIMPL_H_

#include <QCoreApplication>
#include <QTcpServer>

#include "../Server.h"
#include "../Router.h"

namespace QExpress
{
    struct Server::ServerImpl
    {
        ServerImpl(int argc, char** argv, QObject *parent);
        ~ServerImpl();

    private:
        QObject *_parent;
        QCoreApplication _app;
        QTcpServer _server;
        Router* _router;        
    };
    
    Server::ServerImpl::ServerImpl(int argc, char** argv, QObject *parent)
        : _parent(parent) , _app(argc, argv), _server(parent), _router(new Router())
    {
        
    }
    
    Server::ServerImpl::~ServerImpl()
    {
        
    }
    
    
    
} // namespace QExpress


#endif // QEXPRESS_SERVERIMPL_H_