#ifndef QEXPRESS_MIDDLEWARE_INTERFACE_H_
#define QEXPRESS_MIDDLEWARE_INTERFACE_H_

#include "Globals.h"
#include <type_traits>

namespace QExpress
{
    class MiddlewareInterface
    {
    protected:
        virtual void handle_req(Request&, Response&, Next next = nullptr) = 0;
        virtual void handle_err(std::exception_ptr, Request&, Response&, Next = nullptr) = 0;

        template<typename Callable>
        HandlerCallback make_req_handler(Callable mw);

        template<>
        HandlerCallback make_req_handler<MiddlewareInterface*>(MiddlewareInterface* mw);

        template<typename Callable>
        ErrorHandlerCallback make_err_handler(Callable callable);

        template<>
        ErrorHandlerCallback make_err_handler<MiddlewareInterface*>(MiddlewareInterface* mw);
    
    private:
        friend class ConnectionHandler;
    };

    template<typename Callable>
    HandlerCallback MiddlewareInterface::make_req_handler(Callable mw) {
        if constexpr (std::is_invocable_v<Callable, Request&, Response&>) {
            return [mw](Request& req, Response& res, Next) -> void {
                mw(req, res);
            };
        } else if constexpr (std::is_invocable_v<Callable, Request&, Response&, Next>) {
            return mw;
        } 
        
        return nullptr;
    }

    template<>
    HandlerCallback MiddlewareInterface::make_req_handler<MiddlewareInterface*>(MiddlewareInterface* mw) {
        return [mw](Request& req, Response& res, Next next) -> void {
            mw->handle_req(req, res, next);
        };
    }

    template<typename Callable>
    ErrorHandlerCallback MiddlewareInterface::make_err_handler(Callable mw) {
        if constexpr (std::is_invocable_v<Callable, std::exception_ptr, Request&, Response&>) {
            return [mw](std::exception_ptr e, Request& req, Response& res, Next next) -> void {
                mw(e, req, res);
            };
        } else if constexpr (std::is_invocable_v<Callable, std::exception_ptr, Request&, Response&, Next>) {
            return mw;
        } 
        
        return nullptr;
    }

    template<>
    ErrorHandlerCallback MiddlewareInterface::make_err_handler<MiddlewareInterface*>(MiddlewareInterface* mw) {
        return [mw](std::exception_ptr e, Request& req, Response& res, Next next) -> void {
            mw->handle_err(e, req, res, next);
        };
    }
    
    
} // namespace QExpress



#endif // QEXPRESS_MIDDLEWARE_INTERFACE_H_