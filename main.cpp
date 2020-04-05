#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "mat.h"
#include "blur.h"
#include "guassianblur.h"
#include "sobel.h"
#include "convert.h"
#include "canny.h"
#include "matchtemplate.h"
#include "region.h"

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
    qmlRegisterType<GuassianBlur>("OpenCV", 1, 0, "GuassianBlur");
    qmlRegisterType<Sobel>("OpenCV", 1, 0, "Sobel");
    qmlRegisterType<Convert>("OpenCV", 1, 0, "Convert");
    qmlRegisterType<Canny>("OpenCV", 1, 0, "Canny");
    qmlRegisterType<Region>("OpenCV", 1, 0, "Region");
    engine.load(url);

    return app.exec();
}
