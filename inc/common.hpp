#ifndef __COMMON_HPP__
#define __COMMON_HPP__

#include <QString>

typedef enum{
    eCountry = 0,
    eOperators
} eTableType_t;

QString getCountryCodeImgPath(QString code);
QString getOperatorImgPath(QString mcc, QString mnc);

#endif /* __COMMON_HPP__ */
