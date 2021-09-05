#include "../inc/country.hpp"
#include "../inc/common.hpp"

Country::Country(int mcc, QString code, QString name)
    : m_mcc{mcc}, m_code{code}, m_name{name} {
    m_imgPath = getCountryCodeImgPath(m_code);
}

Country::~Country() {
    /* TODO: Implement */
}

bool Country::operator == (const Country &country) {
    return m_mcc == country.m_mcc && m_code == country.m_code;
}
