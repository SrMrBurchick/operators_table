#include <iostream>

#include "database.hpp"

Database *Database::db_instance = nullptr;

static int callback(void *json_array, int argc, char **argv, char **azColName) {
   int i;
   QJsonObject item;
   QJsonArray *array = nullptr;

   if (nullptr == json_array) {
       std::cerr << "Invalid params: json_array = " << json_array << std::endl;

       return SQLITE_FAIL;
   }

   for(i = 0; i<argc; i++) {
      item[azColName[i]] = argv[i] ? argv[i] : "NULL";
   }

   array = static_cast<QJsonArray *>(json_array);

   array->append(item);

   return 0;
}

Database::Database(const std::string &name) {
    db_name = name;
}

Database::~Database() {
    sqlite3_close(db_sqlite);
}

Database *Database::createDatabase(const std::string &name) {
    int rc = SQLITE_OK;

    if (nullptr != db_instance) {
        return db_instance;
    }

    db_instance = new Database(name);

    rc = sqlite3_open(db_instance->db_name.c_str(), &db_instance->db_sqlite);
    if (SQLITE_OK != rc) {
        std::cerr << "Failed to open db:" << name << std::endl;

        delete db_instance;
        db_instance = nullptr;
    }

    return  db_instance;
}

Database *Database::getDatabase() {
    return  Database::db_instance;
}

eErrors_t Database::sendRequest(const std::string &request) {
    int rc = SQLITE_OK;
    char *errMsg = nullptr;

    while (true != responce.isEmpty()) {
        responce.removeLast();
    }

    rc = sqlite3_exec(db_sqlite, request.c_str(), callback, nullptr, &errMsg);
    if (SQLITE_OK != rc) {
        std::cerr << "SQLITE Error: " << errMsg << std::endl;
        sqlite3_free(errMsg);

        return eError;
    } else {
        std::cout << "Operation completed succesfully" << std::endl;
        emit responceRecived(responce);
    }

    return  eSucces;
}
