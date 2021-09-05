#include "../inc/country_reader.hpp"

static const std::vector<Country> st_country = {
    {289, "GE-AB", "Abkhazia"},
    {505, "AU", "Australia"},
    {232, "AT", "Austria"},
    {400, "AZ", "Azerbaijan"},
    {276, "AL", "Albania"},
    {603, "DZ", "Algeria"},
    {332, "VI", "United States Virgin Islands"},
    {544, "AS", "American Samoa"},
    {631, "AO", "Angolia"},
    {213, "AD", "Andorra"},
    {365, "AI", "Anguilla"},
    {344, "AG", "Antigua and Barbuda"},
    {722, "AR", "Argentina"},
    {283, "AM", "Armenia"},
    {363, "AW", "Aruba"},
    {412, "AF", "Afghanistan"},
    {364, "BS", "Bahamas"},
    {470, "BD", "Bangladesh"},
};


std::pair<bool, std::vector<Country>> CountryReader::requestCountries() {
    return std::make_pair(true, st_country);
}
