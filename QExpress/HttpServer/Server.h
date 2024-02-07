#ifndef QEXPRESS_SERVER_H_
#define QEXPRESS_SERVER_H_

#include <QCoreApplication>
#include <QtNetwork/QTcpServer>

#include <functional>
#include <memory>

#include "Globals.h"
#include "RouteHandlerMacro.h"
#include "Request.h"
#include "Response.h"

namespace QExpress
{
    class Server : public QCoreApplication {
        Q_OBJECT
        Q_DISABLE_COPY(Server)
        
    public:
        Server(int argc, char** argv);
        ~Server();

        void listen(uint16_t port, QHostAddress host = QHostAddress::Any, std::function<void()> callback = 0);
        void listen(uint16_t port, QHostAddress host);
        void listen(uint16_t port, std::function<void()> callback);


        static Router* createRouter();

        /**
         * Defines a template engine to handle files with specific extensions
         * The engine callback should take a filename as first argument, and options map as 2nd argument.
         * the options map stores key-value pairs of options that are passed to the template engine. 
         */
        template<typename F>
        void engine(const Buffer& ext, F engine);

        /**
         * Returns router object
         */
        Router* router();

        /**
         * Mount middlewares
         * 
         * `use(MiddlewareCallback callback)` does application-level mounting, such that it intercepts
         * all incoming requests to the server.
         * `use(QString& path, MiddlewareCallback callback)` does path-level mounting, 
         * such that it intercepts requests to the specified path (regardless of http method).
         */
        template<typename F>
        void use(F callback);
        template<typename F>
        void use(std::initializer_list<F> callbacks);
        template<typename F, typename... Fs>
        void use(F callback, Fs... callbacks);
        template<typename F>
        void use(const Buffer& path, F callback);
        template<typename F>
        void use(const Buffer& path, std::initializer_list<F> callbacks);
        template<typename F, typename ...Fs>
        void use(const Buffer& path, F callback, Fs... callbacks);

        ROUTE_HANDLERS({
            // implementation here
        })
    
    protected:
        void incomingConnection(qintptr socketDescriptor);

    private:
        void newConnection(qintptr socketDescriptor);
        void handle(Request& request, Response& response, Next done);
    
    private:
        struct ServerImpl;
        std::unique_ptr<ServerImpl> Impl;
    };
    
    
} // namespace QExpress


#endif // !QEXPRESS_SERVER_H_
