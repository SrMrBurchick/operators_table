#include <QDebug>

#include "system.hpp"
#include "common.hpp"
#include "country_reader.hpp"

bool System::isFileExist(QString path) {
    return isImgExist(path);
}

QString System::getOperatorImg(QString mcc, QString mnc) {
    return getOperatorImgPath(mcc, mnc);
}

QString System::getCountryImg(QString mcc) {
    QString code = CountryReader::getCountryCode(mcc);
    qDebug() << code;
    return getCountryCodeImgPath(code);
}
