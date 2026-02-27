#include "../include/DatabaseManager.h"
#include <iostream>
#include <cstdlib>

bool DatabaseManager::saveConversion(std::string base, std::string target, double amount, double rate, double result) {
    try {
        // Connection string sourced via environment variables for security
        std::string connStr = "host=localhost port=5432 dbname=currency_converter user=postgres password=" + std::string(std::getenv("DB_PASS"));
        pqxx::connection C(connStr);
        
        if (C.is_open()) {
            pqxx::work T(C); // Initialize transactional worker
            
            // Use T.quote() to sanitize string inputs against SQL Injection
            std::string sql = "INSERT INTO conversion_history (base_currency, target_currency, input_amount, exchange_rate, converted_amount, created_at) "
                              "VALUES (" + 
                              T.quote(base) + ", " + 
                              T.quote(target) + ", " + 
                              std::to_string(amount) + ", " + 
                              std::to_string(rate) + ", " + 
                              std::to_string(result) + ", NOW());";
            
            T.exec(sql);
            T.commit(); // Ensure atomicity of the operation
            std::cout << "[DB] Detailed record saved to PostgreSQL.\n";
            return true;
        }
    } catch (const std::exception &e) {
        std::cerr << "[DB Error] " << e.what() << std::endl;
    }
    return false;
}