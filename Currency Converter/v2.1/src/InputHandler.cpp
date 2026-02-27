#include "../include/InputHandler.h"
#include <iomanip>

/**
 * Clears the input buffer to recover from invalid entries
 * and prevents infinite loops during input validation.
 */
void InputHandler::clearBuffer() {
    std::cin.clear();
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
}

/**
 * Handles USD amount input with validation.
 * Ensures the value is a valid number and non-negative.
 */
void InputHandler::usdInput(double& usdValue) {
    std::cout << "Enter an amount in US Dollar (USD): ";
    while (!(std::cin >> usdValue) || usdValue < 0) {
        std::cout << "Invalid. Please enter a positive number: ";
        clearBuffer();
    }
}