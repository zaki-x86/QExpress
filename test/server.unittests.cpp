//#include <QtTest/QtTest>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <Server.h>
#include <iostream>
#include <memory>
#include "doctest.h"

TEST_SUITE_BEGIN("Server tests" 
                    * doctest::description("Basic server unit tests"));

TEST_CASE("QExpress::Server::CTOR") {
    char ** args = new char*;
    args[0] = "1";
    QExpress::Server server(1,args);
    server.get("/", [](QExpress::Request& req, QExpress::Response& res) {
        
    });
} // QExpress::Server::CTOR

TEST_CASE("QExpress::Server::COPY") {} // QExpress::Server::COPY

TEST_CASE("QExpress::Server::MOVE") {} // QExpress::Server::MOVE

TEST_CASE("QExpress::Server::DTOR") {
    /**
     * @brief Constructs the server within a scope
     * checks if all server resources are destroyed properly after going out-of-scope
     */
    
} // QExpress::Server::DTOR

TEST_CASE("QExpress:Server::listen") {
    SUBCASE("Server can be started on specific port") {}

    SUBCASE("Server can be started with a callback function") {}

    SUBCASE("Server can be started with on a specified host address") {}

} // QExpress:Server::listen

TEST_CASE("QExpress:Server::createRouter") {

} // QExpress:Server::createRouter

TEST_CASE("QExpress:Server::router") {
    
} // QExpress:Server::router

TEST_CASE("QExpress:Server::use"){
    SUBCASE("Mounting functions without path"){
        SUBCASE("Server can mount a middleware function") {}

        SUBCASE("Server can mount a comma separated list of middleware functions") {}

        SUBCASE("Server can mount an initalizer list of middleware functions") {}

    } // Mounting functions without path
    
    SUBCASE("Mounting functions to specified path") {
        SUBCASE("Server can mount a middleware function to specific path") {}

        SUBCASE("Server can mount a comma separated list of middleware functions to specific path") {}

        SUBCASE("Server can mount an initalizer list of middleware functions to specific path") {}
    } // Mounting functions to specified path

    SUBCASE("Mounting routers without path"){
        SUBCASE("Server can mount a middleware router object") {}

        SUBCASE("Server can mount a comma separated list of middleware routers") {}

        SUBCASE("Server can mount an initalizer list of middleware router objects") {}
    } // Mounting routers without path

    SUBCASE("Mounting routers to specified path"){
        SUBCASE("Server can mount a middleware router object to specific path") {}

        SUBCASE("Server can mount a comma separated list of middleware routers to specific path") {}

        SUBCASE("Server can mount an initalizer list of middleware router objects to specific path") {}
    } // Mounting routers to specified path

    SUBCASE("Mounting server subapps without path") {
        SUBCASE("Server can mount a server subapp") {}

        SUBCASE("Server can mount a comma separated list of server subapps") {}

        SUBCASE("Server can mount an initalizer list of server subapps") {}
    } // Mounting server subapps without path

    SUBCASE("Mounting server subapps to specified path") {
        SUBCASE("Server can mount a server subapp to specified path") {}

        SUBCASE("Server can mount a comma separated list of server subapps to specified path") {}

        SUBCASE("Server can mount an initalizer list of server subapps to specified path") {}
    } // Mounting server subapps to specified path

} // QExpress:Server::use


TEST_CASE("QExpress:Server::METHOD"){
    SUBCASE("Server can register a GET method") {}

    SUBCASE("Server can register a POST method") {}

    SUBCASE("Server can register a PUT method") {}

    SUBCASE("Server can register a DELETE method") {}

    SUBCASE("Server can register a ALL method") {}

    SUBCASE("Server can register serveral functions to the specified method-path") {}

    SUBCASE("Server can mount router(s) to the specified method-path") {}
} // QExpress:Server::METHOD

TEST_SUITE_END();

// class TestServer: public QObject
// {
// Q_OBJECT
// public:
//     TestServer() = default;
//     ~TestServer() = default;

    
// private slots:
//     void server_constructed_successfully();
//     void server_starts_on_specific_port();
//     void server_invokes_callback_func_upon_starting();
//     void server_can_create_new_router_object();
//     void server_can_return_router_object();
//     void server_can_register_get_method();
//     void server_can_register_post_method();
//     void server_can_register_put_method();
//     void server_can_register_delete_method();
//     void server_can_mount_middleware_to_specific_path();
//     void server_can_mount_application_level_middleware();
// private:
//     //QExpress::Server m_Server;
// };

// void TestServer::server_constructed_successfully() {

// }

// void TestServer::server_starts_on_specific_port(){

// }

// void TestServer::server_invokes_callback_func_upon_starting(){

// }

// void TestServer::server_can_create_new_router_object(){

// }

// void TestServer::server_can_register_get_method(){

// }

// void TestServer::server_can_register_post_method(){

// }

// void TestServer::server_can_register_put_method(){

// }

// void TestServer::server_can_register_delete_method(){

// }

// void TestServer::server_can_mount_middleware_to_specific_path(){

// }

// void TestServer::server_can_mount_application_level_middleware(){

// }

// void TestServer::server_can_return_router_object(){

// }



// QTEST_MAIN(TestServer)
// #include "tests.moc"
