#include <cstring>

#include "../inc/common.hpp"

#define COUNTRY_PATH_FMT "qml/img/countries/%s.png"

std::string& getCountryCodeImgPath(const std::string &code) {
    char *buff = NULL;
    std::string path;
    int len;

    len = sprintf(NULL, COUNTRY_PATH_FMT, code.c_str());

    buff = new char(len + 1);

    sprintf(buff, COUNTRY_PATH_FMT, code.c_str());

    path = buff;

    delete buff;

    return path;
}
