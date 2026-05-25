#include "DatabaseManager.h"
#include <iostream>
#include <cstdlib>
#include <QDebug>

// Prevents crashes by safely providing a fallback value if an environment variable is missing
std::string getEnvSafe(const char* key, const std::string& defaultValue) {
    const char* val = std::getenv(key);
    return val ? std::string(val) : defaultValue;
}

bool DatabaseManager::saveConversion(std::string base, std::string target, double amount, double rate, double result) {
    qDebug() << "Starting saveConversion (Stable Version)...";

    std::string host = getEnvSafe("DB_HOST", "localhost");
    std::string port = getEnvSafe("DB_PORT", "5432");
    std::string dbname = getEnvSafe("DB_NAME", "currency_converter");
    std::string user = getEnvSafe("DB_USER", "postgres");
    std::string pass = getEnvSafe("DB_PASS", "");

    std::string connStr = "host=" + host + " port=" + port + " dbname=" + dbname + " user=" + user + " password=" + pass;

    try {
        // 'new' is used intentionally to bypass automatic object destruction
        // at the end of the block, preventing lifecyle crashes with libpqxx.
        pqxx::connection* C = new pqxx::connection(connStr);

        if (C->is_open()) {
            pqxx::work T(*C);

            std::string sql = "INSERT INTO conversion_history (base_currency, target_currency, exchange_rate, input_amount, converted_amount, created_at) VALUES (" +
                              T.quote(base) + ", " +
                              T.quote(target) + ", " +
                              std::to_string(rate) + ", " +
                              std::to_string(amount) + ", " +
                              std::to_string(result) + ", NOW());";

            T.exec(sql);
            T.commit();
            qDebug() << "[DB] Data sent and committed successfully!";
        }

        return true;

    } catch (const std::exception &e) {
        qDebug() << "DATABASE ERROR:" << e.what();
        return false;
    }
}

void DatabaseManager::fillHistoryTable(QTableWidget* table) {
    std::string host = getEnvSafe("DB_HOST", "localhost");
    std::string port = getEnvSafe("DB_PORT", "5432");
    std::string dbname = getEnvSafe("DB_NAME", "currency_converter");
    std::string user = getEnvSafe("DB_USER", "postgres");
    std::string pass = getEnvSafe("DB_PASS", "");

    std::string connStr = "host=" + host + " port=" + port + " dbname=" + dbname + " user=" + user + " password=" + pass;

    try {
        pqxx::connection* C = new pqxx::connection(connStr);

        if (C->is_open()) {
            pqxx::nontransaction N(*C);
            pqxx::result R = N.exec("SELECT base_currency, target_currency, input_amount, exchange_rate, converted_amount FROM conversion_history ORDER BY created_at DESC LIMIT 50;");

            table->setRowCount(0);
            table->setColumnCount(4);

            int rowIndex = 0;
            for (auto const &row : R) {
                table->insertRow(rowIndex);

                // UI data formatting (combining base and target into a single column)
                std::string conv = row[0].c_str() + std::string(" -> ") + row[1].c_str();
                table->setItem(rowIndex, 0, new QTableWidgetItem(QString::fromStdString(conv)));
                table->setItem(rowIndex, 1, new QTableWidgetItem(QString::fromStdString(row[2].c_str())));
                table->setItem(rowIndex, 2, new QTableWidgetItem(QString::fromStdString(row[3].c_str())));
                table->setItem(rowIndex, 3, new QTableWidgetItem(QString::fromStdString(row[4].c_str())));

                rowIndex++;
            }
            qDebug() << "Table filled with" << rowIndex << "rows.";
        }
    } catch (const std::exception &e) {
        qDebug() << "Error filling history table:" << e.what();
    }
}
