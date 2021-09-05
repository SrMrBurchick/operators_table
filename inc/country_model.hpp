#ifndef __COUNTRY_MODEL_HPP__
#define __COUNTRY_MODEL_HPP__

#include <QAbstractListModel>
#include <list>

#include "country.hpp"

typedef enum {
    eNameRole = Qt::UserRole,
    eImgRole,
} eCountryRole_t;

class CountryModel : public QAbstractListModel {
    Q_OBJECT

    public:
        CountryModel() = default;
        virtual ~CountryModel() = default;

        eErrors_t addNewCountry(Country &country);
        eErrors_t addNewCountry(int mcc, const std::string &code, const std::string &name);

        virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        virtual QHash<int, QByteArray> roleNames() const override;
        virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    private:
        std::list<std::shared_ptr<Country>> m_countries;
};

#endif /* __COUNTRY_MODEL_HPP__ */
