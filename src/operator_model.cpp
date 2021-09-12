#include <QQmlEngine>
#include <QDebug>

#include "operator_model.hpp"

OperatorModel::OperatorModel() {
}

QVariant OperatorModel::data(const QModelIndex &index, int role) const {
    if (true != index.isValid() || index.row() > rowCount(index)) {
        return {};
    }

    const Operator& oper{m_operators.at(index.row())};

    switch (role) {
    case eOperatorRole::eOperatorNameRole:
        return QVariant::fromValue(oper.getName());
    case eOperatorRole::eOperatorImgRole:
        return QVariant::fromValue(oper.getImgPath());
    case eOperatorRole::eOperatorMccRole:
        return QVariant::fromValue(oper.getMCC());
    case eOperatorRole::eOperatorMncRole:
        return QVariant::fromValue(oper.getMNC());
    default:
        return true;
    }

    return {};
}

QHash<int, QByteArray> OperatorModel::roleNames() const {
    QHash<int, QByteArray> roleNames;

    roleNames[eOperatorRole::eOperatorNameRole] = "name";
    roleNames[eOperatorRole::eOperatorMccRole] = "mcc";
    roleNames[eOperatorRole::eOperatorMncRole] = "mnc";
    roleNames[eOperatorRole::eOperatorImgRole] = "img";

    return roleNames;
}

int OperatorModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);

    return static_cast<int>(m_operators.size());
}

eErrors_t OperatorModel::registerModel(const std::string& modelName) {
    qmlRegisterType<OperatorModel>(modelName.c_str(), 1, 0, "OperatorModel");

    return eSucces;
}

bool OperatorModel::updateData() {
    bool result = false;
    std::vector<Operator> operatorList;

    std::tie(result, operatorList) = m_reader.requestOperators(m_mcc);

    if (true == result) {
        m_operators.swap(operatorList);
        emit dataChanged(createIndex(0,0), createIndex(m_operators.size(), 0));
    }

    return result;
}

void OperatorModel::initModel(int mcc) {
    qDebug() << "Model mcc:" << mcc;
}

void OperatorModel::setMcc(const QString &mcc) {
    m_mcc = mcc;
    qDebug() << "mcc:" << mcc;
    updateData();
}
