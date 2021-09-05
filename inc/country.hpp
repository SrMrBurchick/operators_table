#ifndef __COUTNRY_HPP__
#define __COUTNRY_HPP__

#include <map>
#include <memory>
#include <string>

#include <QObject>

#include "operator.hpp"
#include "errors.hpp"

class Country : public QObject {
    Q_OBJECT

    public:
        Country(int mcc, const std::string &code, const std::string &name);
        virtual ~Country();

        bool operator == (const Country &country);

        const std::string& getName() const { return m_name; }
        const std::string& getImgPath() const { return m_imgPath; }

    private:
        int m_mcc;
        std::string m_code;
        std::string m_name;
        std::string m_imgPath;
        std::map<int, std::shared_ptr<Operator>> m_operators;
};

#endif /* __COUTNRY_HPP__ */
