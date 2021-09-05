#ifndef __COMMON_HPP__
#define __COMMON_HPP__

#include <string>

typedef enum{
    eCountry = 0,
    eOperators
} eTableType_t;

std::string& getCountryCodeImgPath(const std::string& code);

#endif /* __COMMON_HPP__ */
