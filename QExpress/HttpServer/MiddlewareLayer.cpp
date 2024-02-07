#include "MiddlewareLayer.h"

namespace QExpress
{
    MiddlewareLayer::MiddlewareLayer()
    {
        
    }
    
    void MiddlewareLayer::handle_req(Request&, Response&, Next) 
    {
        
    }
    
    void MiddlewareLayer::handle_err(std::exception_ptr, Request&, Response&, Next)
    {
        
    }
}