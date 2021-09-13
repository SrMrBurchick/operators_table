#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <iostream>

#include "../inc/country_model.hpp"
#include "../inc/operator_model.hpp"
#include "../inc/database.hpp"
#include "db_component.hpp"
#include "system.hpp"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QScopedPointer<DBComponent> db_component(new DBComponent);
    QScopedPointer<System> system_component(new System);

    QQmlApplicationEngine engine;
    engine.addImportPath(":/qml");

    std::cout << QT_STRINGIFY(PROJECT_PATH) << std::endl;

    Database::createDatabase(QT_STRINGIFY(PROJECT_PATH) "/system.db");

    CountryModel::registerModel("Countries");
    OperatorModel::registerModel("Operators");

    qmlRegisterSingletonInstance("DBComponent", 1, 0, "Database", db_component.get());
    qmlRegisterSingletonInstance("SystemComponent", 1, 0, "System", system_component.get());

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
