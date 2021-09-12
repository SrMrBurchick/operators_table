
#include <cstring>

#include "../inc/common.hpp"

#define COUNTRY_PATH_FMT "qrc:qml/img/countries/"
#define OPERATOR_PATH_FMT "qrc:qml/img/operators/"

QString getCountryCodeImgPath(QString code) {
    QString path = COUNTRY_PATH_FMT;

    path.append(code);
    path.append(".png");

    return path;
}

QString getOperatorImgPath(QString mcc, QString mnc) {
    QString path = OPERATOR_PATH_FMT;

    path.append(mcc);
    path.append("_");
    path.append(mnc);
    path.append(".png");

    return path;
}
