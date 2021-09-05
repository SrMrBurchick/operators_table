#include "../inc/country_model.hpp"

eErrors_t CountryModel::addNewCountry(Country &country) {
    /* TODO: Implement */

    return eSucces;
}

eErrors_t CountryModel::addNewCountry(int mcc, const std::string &code, const std::string &name) {
    /* TODO: Implement */

    return eSucces;
}

QVariant CountryModel::data(const QModelIndex &index, int role) const {
    /* TODO: Implement */

    return {};
}

QHash<int, QByteArray> CountryModel::roleNames() const {
    /* TODO: Implement */

    return {};
}

int CountryModel::rowCount(const QModelIndex &parent) const {
    /* TODO: Implement */

    return 0;
}

