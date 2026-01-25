#include <iostream>
#include <iomanip>
#include <limits>

/*
 * Handles USD input and guarantees a valid numeric value.
 * This logic is centralized to allow reuse and future extensions.
 */
void usdInput(double& usdValue) {
        std::cout << "Enter an amount in US Dollar (USD): ";

        while (!(std::cin >> usdValue))
        {
            std::cout << "Invalid input. Please enter a numeric value (e.g., 100.50): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

int main()
{
    int option = -1;

    // Base value used for all conversions
    double usdValue;

    // Fixed exchange rates (v1.0 scope)
    double brlRate = 5.50;
    double eurRate = 0.92;

    // Initial USD value is required before entering the menu
    usdInput(usdValue);

    std::cout << std::fixed << std::setprecision(2);

    /*
     * Main interaction loop.
     * Allow multiple conversions using the same base value
     * until the user explicitly exits.
     */
    do {
        std::cout << "\n--------------------------------------\n";
        std::cout << "CURRENCY CONVERTER (v1.0)\n";
        std::cout << "1 - Convert to Euro (EUR)\n";
        std::cout << "2 - Convert to Brazilian real (BRL)\n";
        std::cout << "3 - Redefine the US Dollar (USD) value\n";
        std::cout << "0 - Exit\n";
        std::cout << "Choose your option:\n";

        // Protects the control flow against non-numeric input
        if (!(std::cin >> option)) {
            std::cout << "\n[!] Error: Please enter a number (1, 2, 3 or 0).\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            option = -1;
            continue;
        }

        switch (option) {
            case 1:
                std::cout << "US Dollar (USD) value: " << usdValue << "\n";
                std::cout << "Converted to Euro (EUR): " << usdValue * eurRate << "\n";
                break;
            case 2:
                std::cout << "US Dollar (USD) value: " << usdValue << "\n";
                std::cout << "Converted to Brazilian real (BRL): " << usdValue * brlRate << "\n";
                break;
            case 3:
                usdInput(usdValue); // Allows redefining the base value without restarting the program
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid option. Try again.\n"; // Numeric input outside the allowed domain
                break;
        }

    } while (option != 0);
    return 0;
}