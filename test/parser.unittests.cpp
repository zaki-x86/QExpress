//#include <QtTest/QtTest>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <QHttp.h>
#include <iostream>
#include <memory>
#include "doctest.h"

TEST_CASE("Praser can be constructed in different ways") {
    QHttp::RequestParser req_parser;
    QHttp::ResponseParser res_parser;
    std::unique_ptr<QHttp::RequestParser> req_ptr(new QHttp::RequestParser());
    std::unique_ptr<QHttp::ResponseParser> res_ptr(new QHttp::ResponseParser());
    CHECK(req_ptr != nullptr);
    CHECK(res_ptr != nullptr);
    QHttp::RequestParser* req_ptr2 = new QHttp::RequestParser();
    QHttp::ResponseParser* res_ptr2 = new QHttp::ResponseParser();
    CHECK(req_ptr2 != nullptr);
    CHECK(res_ptr2 != nullptr);
    delete req_ptr2;
    delete res_ptr2;
}