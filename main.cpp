#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtWebView>
#include <QtCore>
#include "utils.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QtWebView::initialize();

    QQmlApplicationEngine engine;

    QString  tmpath = loadWebDir();
    // if wanted, set the QML webview URL
    engine.rootContext()->setContextProperty( "baseUrl", tmpath + "/index.html"  );

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
