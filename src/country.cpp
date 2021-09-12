#include "../inc/country.hpp"
#include "../inc/common.hpp"

Country::Country(QString mcc, QString code, QString name)
    : m_code{code}, m_name{name} {
    m_imgPath = getCountryCodeImgPath(m_code);
    m_mcc = mcc.toInt();
}

Country::~Country() {
    /* TODO: Implement */
}

bool Country::operator == (const Country &country) {
    return m_code == country.m_code;
}
