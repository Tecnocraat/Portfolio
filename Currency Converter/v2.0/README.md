# Currency Converter — v2.0 (C++)
A professional-grade currency converter developed in C++, focusing on modular architecture, secure credential management, and REST API integration. This project has evolved from a basic script to a robust system following industry-standard design patterns.

## Features
- **Real-time exchange rates**: Integration with external API for up-to-date currency conversion (BRL, EUR, USD).
- **Intelligent Caching**: Local data structure to minimize API calls and improve performance.
- **Secure Credential Handling**: Support for .env files and environment variables to protect API keys.
- **Robust Input Handling**: Validation system for numeric inputs and menu navigation.
- **Modular Architecture**: Professional folder structure (`src/` and `include/`) for better maintainability.

## Used Technologies
- **C++17**: Core language using modern standards.
- **libcurl**: High-performance library for HTTP/REST requests.
- **nlohmann/json**: Modern JSON parsing for C++.

## Technical Observations
- **Single Responsibility Principle (SRP)**: The architecture follows industry standards by decoupling concerns into specialized modules: 
    - `CurrencyAPI` (networking)
    - `InputHandler` (user validation)
    - `EnvLoader` (infrastructure/config)
    - `ExchangeCache` (data state)
- **Security-First Approach**: Environment variable management using a custom-built `.env` parser to isolate sensitive API credentials from the source code.
- **Resilient Data Streaming**: Implemented a dedicated `WriteCallback` to handle HTTP data chunks dynamically, preventing memory spikes during API responses.
- **Cache Strategy**: The application fetches rates once per session to reduce latency, optimize API quotas, and provide a seamless user experience without redundant network overhead.

## Build and setup
1. **API Key**: Rename `.env.example` to `.env` and add your `EXCHANGE_RATE_KEY`.
2. **Compilation**:
   * **Windows**: Open `run_windows.bat`, ensure the `vcvars64.bat` and `vcpkg` paths match your local installation, and run it. The script automatically initializes the MSVC environment and compiles the project.
   * **Manual/Other**: Ensure `libcurl` and `nlohmann_json` are linked and compile all files in the `src/` directory.

## Planned Evolution
- **v2.1**: Persistence of conversion history and configuration using **PostgreSQL**
- **v3.0**: Graphical user interface implemented with **Qt**
- **v4.0**: Evolution into a high-performance **HTTP Server** and **RESTful API** using **CrowCpp**, enabling remote clients to access conversion data and history via standardized endpoints.