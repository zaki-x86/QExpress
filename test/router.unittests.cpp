#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Router.h"
#include "Request.h"
#include "Response.h"

TEST_SUITE_BEGIN("Router"
                        * doctest::description("Basic Router unit tests"));

TEST_CASE("QExpress:Router::CTOR"){
    using namespace QExpress;
    Router router;
    Router* routerPtr = &router;
    CHECK(routerPtr != nullptr);

    std::shared_ptr<Router> routerPtr2 = std::make_shared<Router>();
    CHECK(routerPtr2 != nullptr);
} // QExpress::Router::CTOR

TEST_CASE("QExpress:Router::COPY"){} // QExpress::Router::COPY

TEST_CASE("QExpress:Router::MOVE"){} // QExpress::Router::MOVE

TEST_CASE("QExpress:Router::DTOR"){} // QExpress::Router::DTOR

TEST_CASE("QExpress:Router::route"){} // QExpress::Router::route

TEST_CASE("QExpress:Router::param"){} // QExpress::Router::param

TEST_CASE("QExpress:Router::use"){} // QExpress::Router::use

TEST_CASE("QExpress:Router::METHOD"){} // QExpress::Router::METHOD

TEST_SUITE_END();