#ifndef QEXPRESS_MIDDLEWARELAYER_H_
#define QEXPRESS_MIDDLEWARELAYER_H_

#include "Globals.h"
#include "MiddlewareInterface.h"

namespace QExpress
{
    class MiddlewareLayer : public MiddlewareInterface{
    public:
        MiddlewareLayer();

        void handle_req(Request&, Response&, Next) override;
        void handle_err(std::exception_ptr, Request&, Response&, Next) override;
    
    private:
        Buffer m_Path;
    };

    
        
} // namespace QExpress


#endif // QEXPRESS_MIDDLEWARELAYER_H_