#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "mat.h"
#include "linearfilter.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    qmlRegisterType<Mat>("OpenCV", 1, 0, "Mat");
    qmlRegisterType<LinearFilter>("OpenCV", 1, 0, "LinearFilter");
    engine.load(url);

    return app.exec();
}
