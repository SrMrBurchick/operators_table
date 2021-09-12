#ifndef __COUTNRY_HPP__
#define __COUTNRY_HPP__

#include <map>
#include <memory>

#include <QString>

#include "operator.hpp"
#include "errors.hpp"

class Country{
    public:
        Country(QString mcc, const QString code, QString name);
        Country(const Country&) = default;
        virtual ~Country();

        bool operator == (const Country &country);

        QString getName() const { return m_name; }
        int getMcc() const { return m_mcc; }
        QString getImgPath() const { return m_imgPath; }

    private:
        int m_mcc;
        QString m_code;
        QString m_name;
        QString m_imgPath;
        std::map<int, std::shared_ptr<Operator>> m_operators;
};

#endif /* __COUTNRY_HPP__ */
