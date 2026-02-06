#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <limits>
#include <iostream>

class InputHandler {
public:
    /**
     * Prompts the user for a USD amount and validates the input.
     * Ensures the value is numeric and non-negative.
     * @param usdValue Reference to the double variable where the input will be stored.
     */
    static void usdInput(double& usdValue);

    static void clearBuffer(); // Clears the std::cin error flags and flushes the input buffer.
};

#endif