#ifndef QEXPRESS_CONNECTIONHANDLERIMP_H_
#define QEXPRESS_CONNECTIONHANDLERIMP_H_


#include <QThread>
#include <QTimer>

#include "../Globals.h"
#include "../ConnectionHandler.h"

namespace QExpress
{
    struct ConnectionHandler::ConnectionHandlerImpl {
        ConnectionHandlerImpl() = default;
        ~ConnectionHandlerImpl() = default;

    private:
        QThread thread;
        QTimer timer;
    };
    
} // namespace QExpress

#endif // QEXPRESS_CONNECTIONHANDLERIMP_H_