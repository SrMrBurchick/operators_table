#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <iostream>

#include "../inc/country_model.hpp"
#include "../inc/database.hpp"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImportPath(":/qml");

    std::cout << QT_STRINGIFY(PROJECT_PATH) << std::endl;

    Database::createDatabase(QT_STRINGIFY(PROJECT_PATH) "/system.db");

    CountryModel::registerModel("Countries");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
