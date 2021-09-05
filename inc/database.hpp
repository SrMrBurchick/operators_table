#ifndef __DATABASE_HPP__
#define __DATABASE_HPP__

#include <sqlite3.h>
#include <string>
#include <utility>

#include <QObject>
#include <QJsonArray>
#include <QJsonObject>

#include "errors.hpp"

class Database : public QObject {
    Q_OBJECT

    public:
        ~Database();

        std::pair<eErrors_t, QJsonArray> sendRequest(const std::string &request);
        static Database *createDatabase(const std::string &name);
        static Database *getDatabase();

    private:
        Database(const std::string &name);

        sqlite3 *db_sqlite;
        std::string db_name;

        static Database *db_instance;

    signals:
        void responceRecived(const QJsonArray &responce);
};

#endif /* __DATABASE_HPP__ */
