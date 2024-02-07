#ifndef QEXPRESS_ROUTERIMPL_H_
#define QEXPRESS_ROUTERIMPL_H_

#include <vector>

#include "../Router.h"
#include "../MiddlewareLayer.h"

namespace QExpress
{
    struct Router::RouterImpl{
        RouterImpl() = default;
        ~RouterImpl() = default;
        
        std::vector<MiddlewareLayer> layers;
    };
    
} // namespace QExpress


#endif // QEXPRESS_ROUTERIMPL_H_