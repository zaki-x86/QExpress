#include "Route.h"
#include "private/RouteImpl.h"
namespace QExpress
{
    Route::Route()
        : Impl(new RouteImpl())
    {
        
    }
    
    Route::~Route()
    {
        
    }
    
    void Route::dispatch(Request& req, Response& res, Next next)
    {
        
    }
}