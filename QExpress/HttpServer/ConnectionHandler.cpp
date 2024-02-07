#include "ConnectionHandler.h"
#include "private/ConnectionHandlerImpl.h"

namespace QExpress
{
    ConnectionHandler::ConnectionHandler(Next handle, QObject *parent)
    {
    }
    
    ConnectionHandler::~ConnectionHandler()
    {
    }

    void ConnectionHandler::handleConnection(const qintptr socketDescriptor)
    {

    }

    void ConnectionHandler::onReadyRead()
    {

    }

    void ConnectionHandler::onReadyWrite(Buffer data)
    {

    }

    void ConnectionHandler::onThreadDone()
    {

    }

    void ConnectionHandler::onReadtimerTimeout()
    {

    }

    void ConnectionHandler::onSocketDisconnect()
    {

    }
    
} // namespace QExpress
