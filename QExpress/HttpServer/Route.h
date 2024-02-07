#ifndef QEXPRESS_ROUTE_H_
#define QEXPRESS_ROUTE_H_

#include <memory>

#include "Globals.h"
#include "MiddlewareLayer.h"

namespace QExpress
{
    class Route
    {
    public:
        Route();
        ~Route();

        void dispatch(Request&, Response&, Next);
    
    private:
        struct RouteImpl;
        std::unique_ptr<RouteImpl> Impl;
    };
    
} // namespace QExpress



#endif // QEXPRESS_ROUTE_H_