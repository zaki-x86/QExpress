#ifndef QEXPRESS_ROUTER_H_
#define QEXPRESS_ROUTER_H_

#include <initializer_list>
#include <memory>

#include "Globals.h"
#include "RouteHandlerMacro.h"
#include "Route.h"

namespace QExpress
{
    class Router : public QObject
    {        
    public:
        Router() noexcept;
        
        ~Router();

        Route route(Buffer& path);

        template<typename F>
        void param(Buffer path, F callback);

        template<typename F>
        void use(F callback);
        template<typename F>
        void use(std::initializer_list<F> callbacks);
        template<typename F, typename... Fs>
        void use(F callback, Fs... callbacks);
        template<typename F>
        void use(const Buffer& path, F callback);
        template<typename F>
        void use(const Buffer& path, std::initializer_list<F> callbacks);
        template<typename F, typename ...Fs>
        void use(const Buffer& path, F callback, Fs... callbacks);

        ROUTE_HANDLERS({
            //implement here
        })

    private:
        void handle(Request& req, Response& res, Next next);

    private:
        struct RouterImpl;
        std::unique_ptr<RouterImpl> Impl;
    };

} // namespace QExpress


#endif // !QEXPRESS_ROUTER_H_
