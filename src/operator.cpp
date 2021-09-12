#include "../inc/operator.hpp"
#include "../inc/common.hpp"

Operator::Operator(QString mcc, QString mnc, QString name)
    : m_mcc{mcc}, m_mnc{mnc}, m_name{name} {

    m_imgPath = getOperatorImgPath(mcc, mnc);
}

bool Operator::operator == (const Operator &dest) {
    return m_mcc == dest.m_mcc && m_mnc == dest.m_mnc;
}
