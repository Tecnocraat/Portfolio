# Currency Converter — PostgreSQL Database Integration (v2.1)
A professional-grade currency converter developed in C++, now featuring persistent storage. This version marks the transition from a volatile session-based tool to a robust system capable of logging and auditing conversion history through **PostgreSQL** interaction.

## Features
- **Persistent History**: Full integration with PostgreSQL to store conversion logs (base currency, target currency, rates and timestamps).
- **Real-time exchange rates**: Integration with external API for up-to-date currency conversion (USD, EUR, BRL).
- **Intelligent Caching**: Local data structure to minimize API calls and improve performance.
- **Secure Credential Handling**: Support for `.env` files to protect both API keys and database credentials.

## Used Technologies
- **C++20**: Core language utilizing modern standards.
- **PostgreSQL**: Relational database for persistent data storage.
- **libpqxx**: Official C++ client for PostgreSQL.
- **libcurl**: High-performance library for HTTP/REST requests.
- **nlohmann/json**: Modern JSON parsing for C++.
- **vcpkg**: Microsoft's C++ library manager for dependency control.

## Technical Observations
- **Data Persistence Layer**: Implementation of the `DatabaseManager` module, responsible for the lifecycle of the SQL connection and secure data insertion using transaction-safe operations.
- **Relational Schema**: A dedicated database schema designed for financial traceability, capturing:
    - Imput amounts and converted results.
    - Exact exchange rates at the time of transaction.
    - Automated timestamps for auditing purposes.
- **Modern Compiler Integration**: Updated build a pipeline to use **MSVC 2022/2026** with `/std:c++20`, resolving modern STL compatibility requirements (e.g, <span>).

## Build and Setup
1. **Database Setup**: Create a PostgreSQL database named `currency_converter` and run the provided SQL script to initialize the `conversion-history` table.
2. **API & DB Keys**: Update your `.env` file with your `EXCHANGE_RATE_KEY` and your database credentials (`DB_PASS`, etc.)
3. **Compilation**:
    - **Windows**: Run `run_windows.bat`. This script now includes paths for `vcpkg` and links `pqxx.lib` and `libpq.lib`, and other essential Windows networking libraries (`ws2_32.lib`, `crypt32.lib`).
    - **Dependency Check**: Ensure `vcpkg` has installed `curl`, `nlohmann-json`, and `libpqxx`.

## Planned Evolution
- **v3.0**: Graphical user interface implemented with **Qt Framework**
- **v4.0**: Evolution into a high-performance **HTTP Server** and **RESTful API** using **CrowCpp**, enabling remote clients to access conversion data and history via standardized endpoints.