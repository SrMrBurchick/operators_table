#include "db_component.hpp"
#include "database.hpp"

void DBComponent::updateOperator(QString name, QString mcc, QString mnc) {
    Database *db = Database::getDatabase();
    QString request;

    request.append("UPDATE operators SET name = \"");
    request.append(name);
    request.append("\" WHERE mcc = " + mcc + " AND mnc = " + mnc + ";");

    db->sendRequest(request.toStdString().c_str());
}

void DBComponent::addOperator(QString name, QString mcc, QString mnc) {
    Database *db = Database::getDatabase();
    QString request;

    request.append("INSERT INTO operators (mcc, mnc, name) ");
    request.append("VALUES(" + mcc + ", " + mnc + ", \"" + name + "\");");

    db->sendRequest(request.toStdString().c_str());
}