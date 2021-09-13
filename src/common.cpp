#include <QFile>
#include <cstring>

#include "../inc/common.hpp"

#define QRC_PATH "qrc:"
#define COUNTRY_PATH_FMT "qml/img/countries/"
#define OPERATOR_PATH_FMT "qml/img/operators/"
#define UKNOWN_IMG "qrc:qml/img/system/uknown.png"

QString getCountryCodeImgPath(QString code) {
    QString path = COUNTRY_PATH_FMT;

    path.append(code);
    path.append(".png");

    if (!isImgExist(QString(QT_STRINGIFY(PROJECT_PATH)) + "/" + path)) {
        return UKNOWN_IMG;
    }

    return QRC_PATH + path;
}

QString getOperatorImgPath(QString mcc, QString mnc) {
    QString path = OPERATOR_PATH_FMT;

    path.append(mcc);
    path.append("_");
    path.append(mnc);
    path.append(".png");

    if (!isImgExist(QString(QT_STRINGIFY(PROJECT_PATH)) + "/" + path)) {
        return UKNOWN_IMG;
    }

    return QRC_PATH + path;
}

bool isImgExist(QString path) {
    return QFile::exists(path);
}
