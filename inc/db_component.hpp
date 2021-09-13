#ifndef __DB_COMPONENT_HPP__
#define __DB_COMPONENT_HPP__

#include <QObject>
#include <QString>

class DBComponent : public QObject {
    Q_OBJECT

    public :
        explicit DBComponent(QObject *parent = nullptr) : QObject(parent) {}
        virtual ~DBComponent() = default;

        Q_INVOKABLE void updateOperator(QString name, QString mcc, QString mnc);
        Q_INVOKABLE void addOperator(QString name, QString mcc, QString mnc);
};

#endif /* __DB_COMPONENT_HPP__ */
