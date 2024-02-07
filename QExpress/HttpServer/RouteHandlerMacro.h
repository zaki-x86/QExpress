#ifndef QEXPRESS_ROUTEHANDLERMACRO_H_
#define QEXPRESS_ROUTEHANDLERMACRO_H_

#include "Globals.h"


#define ROUTE_HANDLERS(code)          \
        template<typename F>        \
        void get(const Buffer& path, F callback){        \
                    \
        }        \
        \
        template<typename F>        \
        void get(const Buffer& path, std::initializer_list<F> callbacks){        \
        \
        }        \
        \
        template<typename F, typename ...Fs>        \
        void get(const Buffer& path, F callback, Fs... callbacks){        \
        \
        }        \
        \
        template<typename F>        \
        void post(const Buffer& path, F callback){        \
        \
        }        \
        \
        template<typename F>        \
        void post(const Buffer& path, std::initializer_list<F> callbacks){        \
        \
        }        \
                \
        template<typename F, typename ...Fs>        \
        void post(const Buffer& path, F callback, Fs... callbacks){        \
        \
        }        \
        \
        template<typename F>        \
        void put(const Buffer& path, F callback){        \
        \
        }        \
        \
        template<typename F>        \
        void put(const Buffer& path, std::initializer_list<F> callbacks){        \
        \
        }        \
        \
        template<typename F, typename ...Fs>        \
        void put(const Buffer& path, F callback, Fs... callbacks){        \
        \
        }        \
        \
        \
        template<typename F>        \
        void del(const Buffer& path, F callback){        \
        \
        }        \
        \
        template<typename F>        \
        void del(const Buffer& path, std::initializer_list<F> callbacks){        \
        \
        }        \
        \
        template<typename F, typename ...Fs>        \
        void del(const Buffer& path, F callback, Fs... callbacks){        \
        \
        }        \
        \
        \
        template<typename F>        \
        void all(const Buffer& path, F callback){        \
        \
        }        \
        \
        template<typename F>        \
        void all(const Buffer& path, std::initializer_list<F> callbacks){        \
        \
        }        \
        \
        template<typename F, typename ...Fs>        \
        void all(const Buffer& path, F callback, Fs... callbacks){        \
        \
        }  


#endif // QEXPRESS_ROUTEHANDLERMACRO_H_