
#include <cstring>

#include "../inc/common.hpp"

#define COUNTRY_PATH_FMT "qrc:qml/img/countries/"

QString getCountryCodeImgPath(QString code) {
    QString path = COUNTRY_PATH_FMT;

    path.append(code);
    path.append(".png");

    return path;
}
