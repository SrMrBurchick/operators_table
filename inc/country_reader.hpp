#ifndef __COUNTRY_READER_HPP__
#define __COUNTRY_READER_HPP__

#include <vector>
#include <utility>
#include <QString>

#include "country.hpp"

class CountryReader {
    public:
        std::pair<bool, std::vector<Country>> requestCountries();
        static QString getCountryCode(QString mcc);
};

#endif /* __COUNTRY_READER_HPP__ */
