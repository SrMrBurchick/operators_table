#ifndef __OPERATOR_HPP__
#define __OPERATOR_HPP__

#include <QString>

class Operator {
    public:
        Operator(QString nmc, QString mcc, QString name);
        Operator(const Operator&) = default;
        ~Operator() = default;

        bool operator == (const Operator& dest);

        QString getMCC() const { return m_mcc; }
        QString getMNC() const { return m_mnc; }
        QString getName() const { return m_name; }
        QString getImgPath() const { return m_imgPath; }

    private:
        QString m_mcc;
        QString m_mnc;
        QString m_name;
        QString m_imgPath;
};

#endif /* __OPERATOR_HPP__ */
