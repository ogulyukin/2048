#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "viewchanger.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    KeyboardFilter* filter = new KeyboardFilter();
    app.installEventFilter(filter);
    ViewChanger vchanger(filter);
    QQmlApplicationEngine engine;
    int count = 0;
    for(auto it = vchanger.rectangles.begin(); it != vchanger.rectangles.end(); it++){
        engine.rootContext()->setContextProperty("grect" + QString::number(count), *it);
        count++;
    }
    count = 0;
    for (auto it = vchanger.rectDim.begin(); it != vchanger.rectDim.end(); it++)
    {
        engine.rootContext()->setContextProperty("dimension" + QString::number(count), *it);
        count++;
    }
    engine.rootContext()->setContextProperty("vchanger", &vchanger);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
