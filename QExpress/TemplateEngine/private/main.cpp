#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qInfo() << "QExpress template!";
    
    return app.exec();
}
