#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "mat.h"
#include "blur.h"

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

    qmlRegisterType<LinearFilter>();
    qmlRegisterType<Mat>("OpenCV", 1, 0, "Mat");
    qmlRegisterType<Blur>("OpenCV", 1, 0, "Blur");
    engine.load(url);

    return app.exec();
}
