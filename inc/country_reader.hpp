#ifndef __COUNTRY_READER_HPP__
#define __COUNTRY_READER_HPP__

#include <vector>
#include <utility>

#include "country.hpp"

class CountryReader {
    public:
        std::pair<bool, std::vector<Country>> requestCountries();
};

#endif /* __COUNTRY_READER_HPP__ */
