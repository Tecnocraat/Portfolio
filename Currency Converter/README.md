# 💱 Currency Converter — Evolutionary C++ Project

Welcome to the **Currency Converter** portfolio ecosystem. This project was built in evolutionary versions to demonstrate different architectural layers, ranging from basic console robust logic to a modern desktop GUI and infrastructure persistence.

---

## 🗺️ Project Roadmap & Evolution

Here is the breakdown of how the application evolved. Click on each version to explore its dedicated documentation and source code:

### [📁 Version 1.0 — Static Logic & Console](v1.0/)
- **Core Focus:** C++ fundamentals, clean code, input validation, and control flow robustness.
- **Key Feature:** Interactive console menu with fixed exchange rates to establish the core domain.

### [📁 Version 2.0 — Real-Time API Integration](v2.0/)
- **Core Focus:** External integration and networking.
- **Key Feature:** Implementation of `libcurl` and `nlohmann-json` to fetch real-time exchange rates from a live financial API.

### [📁 Version 2.1 — Database Persistence](v2.1/)
- **Core Focus:** Storage layer and data infrastructure.
- **Key Feature:** Integration of a **PostgreSQL** database via `libpqxx` to persist conversion logs, historical data, and client session configurations.

### [📁 Version 3.0 — Qt Graphical User Interface](v3.0/) *(Latest Release)*
- **Core Focus:** Desktop User Experience (UX/UI) and asynchronous events.
- **Key Feature:** Full graphical interface implemented with the **Qt 6 Framework**, supporting High-DPI scaling, interactive tabs, and visual history logs.

---

## Tech Stack Summary
Across all versions, the ecosystem utilizes:
- **Language:** C++ (Modern standards)
- **GUI Framework:** Qt 6
- **Database:** PostgreSQL
- **Libraries:** libcurl, nlohmann-json
- **Build System & Package Manager:** CMake & vcpkg

---

## How to Explore
1. If you want to review the foundational logic, check the [v1.0 README](v1.0/README.md).
2. To see how external services and databases were structured, go to [v2.0](v2.0/README.md) or [v2.1](v2.1/README.md).
3. To run or inspect the complete, modern desktop application, jump directly to the [v3.0 directory](v3.0/).