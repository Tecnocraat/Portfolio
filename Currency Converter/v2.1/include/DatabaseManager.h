#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <pqxx/pqxx>
#include <string>
#include "ExchangeCache.h"

/**
 * @brief Handles all persistent storage operations for currency transactions.
 * Uses PostgreSQL as the main relational data store.
 */
class DatabaseManager {
public:
    /**
     * @brief Persists a conversion record into the database history.
     * @return true if the transaction was successful, false otherwise.
     */
    static bool saveConversion(std::string base, std::string target, double amount, double rate, double result);
};

#endif