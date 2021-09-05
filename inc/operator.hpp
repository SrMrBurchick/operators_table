#ifndef __OPERATOR_HPP__
#define __OPERATOR_HPP__

#include <string>

class Operator {
    public:
        Operator(int nmc, int mcc, const std::string & name);
        ~Operator();

        bool operator == (const Operator& dest);

        int getMCC() const { return m_mcc; }
        int getMNC() const { return m_mnc; }
        const std::string& getName() const { return m_name; }
        const std::string& getImgPath() const { return m_imgPath; }

    private:
        int m_mcc;
        int m_mnc;
        std::string m_name;
        std::string m_imgPath;
};

#endif /* __OPERATOR_HPP__ */
