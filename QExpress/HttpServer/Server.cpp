#include "Server.h"
#include "private/ServerImpl.h"


namespace QExpress
{
    Server::Server(int argc, char **argv)
        : QCoreApplication(argc, argv) {

    }

    Server::~Server() {
        
    }

    void Server::newConnection(qintptr socketDescriptor) {

    }

    void Server::handle(Request& request, Response& response, Next done) {

    }
    
    void Server::incomingConnection(qintptr socketDescriptor)
    {
        
    }
    
    void Server::listen(uint16_t port, QHostAddress host, std::function<void()> callback)
    {
    }
    
    void Server::listen(uint16_t port, QHostAddress host)
    {
        
    }
    
    void Server::listen(uint16_t port, std::function<void()> callback)
    {
        
    }
    
    Router* Server::createRouter()
    {
        return nullptr;   
    }
    
    Router* Server::router()
    {
        return nullptr;
    }

    template<typename F>
    void Server::use(F callback){

    }
    
    template<typename F>
    void Server::use(std::initializer_list<F> callbacks){

    }
    
    template<typename F, typename... Fs>
    void Server::use(F callback, Fs... callbacks){

    }
    
    template<typename F>
    void Server::use(const Buffer& path, F callback){

    }
    
    template<typename F>
    void Server::use(const Buffer& path, std::initializer_list<F> callbacks){

    }
    
    template<typename F, typename ...Fs>
    void Server::use(const Buffer& path, F callback, Fs... callbacks){

    }
    

} // namespace QExpress
