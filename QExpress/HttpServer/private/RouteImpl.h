#ifndef QEXPRESS_ROUTEIMPL_H_
#define QEXPRESS_ROUTEIMPL_H_

#include <vector>

#include "../Globals.h"
#include "../Route.h"
#include "../MiddlewareLayer.h"

namespace QExpress
{
    struct Route::RouteImpl{
        RouteImpl() = default;
        ~RouteImpl() = default;

        struct RouteLayer;
        std::vector<RouteLayer*> stack;
        std::vector<HTTP_METHOD> methods;
    };

    struct Route::RouteImpl::RouteLayer {
        RouteLayer() = default;
        ~RouteLayer() = default;

        Buffer path;
        HTTP_METHOD method;
        MiddlewareLayer* middleware;
    };
    
    
} // namespace QExpress

#endif // QEXPRESS_ROUTEIMPL_H_