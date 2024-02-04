//#include <QtTest/QtTest>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <Server.h>
#include <iostream>
#include <memory>
#include "doctest.h"

TEST_CASE("Server can be constructed") {
    INFO("Server can be constructed");
    char ** args = new char*;
    args[0] = "1";
    QExpress::Server server(1,args);
    QExpress::Request req;
    QExpress::Response res;
    server.get("/", [](QExpress::Request& req, QExpress::Response& res) {
        
    });
}

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
