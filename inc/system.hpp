#ifndef __SYSTEM_HPP__
#define __SYSTEM_HPP__

#include <QObject>
#include <QString>

class System : public QObject {
    Q_OBJECT

    public :
        explicit System(QObject *parent = nullptr) : QObject(parent) {}
        virtual ~System() = default;

        Q_INVOKABLE bool isFileExist(QString path);
        Q_INVOKABLE QString getOperatorImg(QString mcc, QString mnc);
        Q_INVOKABLE QString getCountryImg(QString mcc);
};

#endif /* __SYSTEM_HPP__ */
