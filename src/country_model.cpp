#include <QQmlEngine>

#include "../inc/country_model.hpp"

CountryModel::CountryModel() {
    updateData();
}

QVariant CountryModel::data(const QModelIndex &index, int role) const {
    if (true != index.isValid() || index.row() > rowCount(index)) {
        return {};
    }

    const Country& country{m_countries.at(index.row())};

    switch (role) {
    case eCountryRole::eNameRole:
        return QVariant::fromValue(country.getName());
    case eCountryRole::eImgRole:
        return QVariant::fromValue(country.getImgPath());
    default:
        return true;
    }

    return {};
}

QHash<int, QByteArray> CountryModel::roleNames() const {
    QHash<int, QByteArray> roleNames;

    roleNames[eCountryRole::eNameRole] = "name";
    roleNames[eCountryRole::eImgRole] = "img";

    return roleNames;
}

int CountryModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);

    return static_cast<int>(m_countries.size());
}

eErrors_t CountryModel::registerModel(const std::string& modelName) {
    qmlRegisterType<CountryModel>(modelName.c_str(), 1, 0, "CountryModel");

    return eSucces;
}

bool CountryModel::updateData() {
    bool result = false;
    std::vector<Country> countryList;

    std::tie(result, countryList) = m_reader.requestCountries();

    if (true == result) {
        m_countries.swap(countryList);
        emit dataChanged(createIndex(0,0), createIndex(m_countries.size(), 0));
    }

    return result;
}

