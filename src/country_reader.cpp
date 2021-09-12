#include <algorithm>
#include <QString>

#include "../inc/country_reader.hpp"
#include "../inc/database.hpp"

#define SELECT_FROM_COUNTRIES "SELECT * from countries ORDER BY name ASC;"

std::pair<bool, std::vector<Country>> CountryReader::requestCountries() {
    QJsonArray responce = {};
    auto db = Database::getDatabase();
    eErrors_t result = eSucces;
    std::vector<Country> data;

    std::tie(result, responce) = db->sendRequest(SELECT_FROM_COUNTRIES);

    if (eSucces != result) {
        return std::make_pair(false, data);
    }

    for (const auto& item : responce) {
        QJsonObject obj = item.toObject();
        Country country(obj["mcc"].toString(),
                        obj["code"].toString(),
                        obj["name"].toString());

        if(data.end() != std::find(data.begin(), data.end(), country)) {
            continue;
        }

        data.push_back(country);
    }

    return std::make_pair(true, data);
}
