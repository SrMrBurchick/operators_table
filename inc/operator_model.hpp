#ifndef __OPERATOR_MODEL_HPP__
#define __OPERATOR_MODEL_HPP__

#include <QAbstractListModel>
#include <QString>
#include <vector>

#include "operator.hpp"
#include "errors.hpp"
#include "operator_reader.hpp"

enum eOperatorRole{
    eOperatorNameRole = Qt::UserRole + 1,
    eOperatorImgRole,
    eOperatorMccRole,
    eOperatorMncRole,
};

class OperatorModel : public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY(QString countryMCC MEMBER m_mcc READ getMcc WRITE setMcc)

    public:
        OperatorModel();
        virtual ~OperatorModel() = default;

        virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        virtual QHash<int, QByteArray> roleNames() const override;
        virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;

        static eErrors_t registerModel(const std::string& modelName);

        void setMcc(const QString& mcc);
        QString getMcc() {return m_mcc;};

    public slots:
        void initModel(int mcc);

    private:
        QString m_mcc;
        OperatorReader m_reader;
        bool updateData();
        std::vector<Operator> m_operators;
};

#endif /* __OPERATOR_MODEL_HPP__ */
