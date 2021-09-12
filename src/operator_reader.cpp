#include <algorithm>
#include <QDebug>
#include <cstring>

#include "../inc/operator_reader.hpp"
#include "../inc/database.hpp"

#define SELECT_FROM_OPERATORS_P1 "SELECT * FROM operators WHERE mcc = "
#define SELECT_FROM_OPERATORS_P2 " ORDER BY name ASC;"

std::pair<bool, std::vector<Operator>> OperatorReader::requestOperators(QString mcc) {
    QJsonArray responce = {};
    QString request = SELECT_FROM_OPERATORS_P1;
    auto db = Database::getDatabase();
    eErrors_t result = eSucces;
    std::vector<Operator> data;

    request.append(mcc);
    request.append(SELECT_FROM_OPERATORS_P2);

    qDebug() << request;

    std::tie(result, responce) = db->sendRequest(request.toStdString().c_str());

    if (eSucces != result) {
        return std::make_pair(false, data);
    }

    for (const auto& item : responce) {
        QJsonObject obj = item.toObject();
        Operator oper(obj["mcc"].toString(),
                      obj["mnc"].toString(),
                      obj["name"].toString());

        qDebug() << obj;

        if(data.end() != std::find(data.begin(), data.end(), oper)) {
            continue;
        }

        data.push_back(oper);
    }

    return std::make_pair(true, data);
}
