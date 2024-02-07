#ifndef QEXPRESS_CONNECTION_HANDLER_H_
#define QEXPRESS_CONNECTION_HANDLER_H_

#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include <QTimer>

#include "Globals.h"
#include "Router.h"

namespace QExpress
{
    class ConnectionHandler : public QObject
    {
        Q_OBJECT
        Q_DISABLE_COPY(ConnectionHandler)
    public:
        ConnectionHandler(Next handle, QObject* parent = nullptr);
        ~ConnectionHandler();

        const QTcpSocket &socket() const;
        const QThread &thread() const;
        const QTimer &readTimer() const;

    public slots:
        void handleConnection(const qintptr socketDescriptor);
    
    private slots:
        void onReadyRead();
        void onReadyWrite(Buffer data);
        void onThreadDone();
        void onReadtimerTimeout();
        void onSocketDisconnect();

    private:
        struct ConnectionHandlerImpl;
        ConnectionHandlerImpl *m_Impl;
    };

    
} // namespace QExpress


#endif // !QEXPRESS_CONNECTION_HANDLER_H_
