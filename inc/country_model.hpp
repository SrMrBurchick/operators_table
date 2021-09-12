#ifndef __COUNTRY_MODEL_HPP__
#define __COUNTRY_MODEL_HPP__

#include <QAbstractListModel>
#include <vector>

#include "country.hpp"
#include "country_reader.hpp"

enum eCountryRole{
    eCountryNameRole = Qt::UserRole + 1,
    eCountryImgRole,
    eCountryMccRole,
};

class CountryModel : public QAbstractListModel {
    Q_OBJECT

    public:
        CountryModel();
        virtual ~CountryModel() = default;

        virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        virtual QHash<int, QByteArray> roleNames() const override;
        virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;

        static eErrors_t registerModel(const std::string& modelName);

    private:
        bool updateData();

        CountryReader m_reader;
        std::vector<Country> m_countries;
};

#endif /* __COUNTRY_MODEL_HPP__ */
