# Currency Converter — v1.0 (C++)

Initial version of the **Currency Converter** project, developed in **C++** for console execution.

Version 1.0 focuses on input validation, control flow robustness, and clean
code organization.

## Features
- Conversion from US Dollar (USD) to:
    - Euro (EUR)
    - Brazilian Real (BRL)
- Robust handling of invalid user input
- Interactive menu allowing multiple conversions per execution
- Ability to redefine the base USD value without restarting the program

## Used Technologies
- C++
- The C++ Standard library

## Technical Observations
- Exchange rates are intentionally fixed in v1.0 to keep the focus on
application flow and input validation.
- Input handling logic is centralized in a dedicated function to ensure
consistency and facilitate future extensions.
- The program separates concerns between:
    - User input validation
    - Menu control flow
    - Conversion logic
- The current structure is designed to scale without major refactoring.


## Planned Evolution
- **v2.0**: Conversion using real-time exchange rates via external API
- **v2.1**: Persistence of conversion history and configuration using PostgreSQL
- **v3.0**: Graphical user interface implemented with Qt