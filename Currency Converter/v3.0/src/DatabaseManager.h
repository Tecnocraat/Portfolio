#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <pqxx/pqxx>
#include <string>
#include <vector>
#include <QTableWidget>
#include "ExchangeCache.h"

class DatabaseManager {
public:
    static bool saveConversion(std::string base, std::string target, double amount, double rate, double result);
    static void fillHistoryTable(QTableWidget* table);
};

#endif
