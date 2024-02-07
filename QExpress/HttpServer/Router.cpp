#include "Router.h"
#include "private/RouterImpl.h"

namespace QExpress
{
    Router::Router() noexcept
    {

    }

    Router::~Router()
    {
    }

    void Router::handle(Request& req, Response& res, Next next){
        
    }

    template<typename F>
    void Router::use(F callback){

    }
    
    template<typename F>
    void Router::use(std::initializer_list<F> callbacks){

    }
    
    template<typename F, typename... Fs>
    void Router::use(F callback, Fs... callbacks){

    }
    
    template<typename F>
    void Router::use(const Buffer& path, F callback){

    }
    
    template<typename F>
    void Router::use(const Buffer& path, std::initializer_list<F> callbacks){

    }
    
    template<typename F, typename ...Fs>
    void Router::use(const Buffer& path, F callback, Fs... callbacks){

    }

} // namespace QExpress
