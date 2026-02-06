#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "../include/ExchangeCache.h"
#include "../include/CurrencyAPI.h"
#include "../include/InputHandler.h"
#include "../include/EnvLoader.h"

int main() {
    EnvLoader::load();
    int option = -1;
    double usdValue = 0.0;
    ExchangeCache cache;

    InputHandler::usdInput(usdValue);
    CurrencyAPI::updateCache(cache);

    std::cout << std::fixed << std::setprecision(2);

    do {
        std::cout << "\n----------------------------------------\n";
        std::cout << "CURRENCY CONVERTER (v2.0)| Base: $" << usdValue << "\n";
        std::cout << "1 - Euro (EUR) [" << (cache.eur > 0 ? std::to_string(cache.eur) : "N/A") << "]\n";
        std::cout << "2 - Real (BRL) [" << (cache.brl > 0 ? std::to_string(cache.brl) : "N/A") << "]\n";
        std::cout << "3 - Change USD\n";
        std::cout << "4 - Refresh Rates\n";
        std::cout << "0 - Exit\n";
        std::cout << "Option: ";

        if (!(std::cin >> option)) {
            InputHandler::clearBuffer();
            option = -1;
            continue;
        }

        switch (option) {
            case 1: 
                if(cache.loaded) 
                std::cout << "Value in USD: " << usdValue << " converted to EUR...\n";
                std::cout << "Total: " << usdValue * cache.eur << " EUR\n"; 
                break;
            case 2: 
                if(cache.loaded) 
                std::cout << "Value in USD: " << usdValue << " converted to BRL...\n";
                std::cout << "Total: " << usdValue * cache.brl << " BRL\n"; 
                break;
            case 3: 
                InputHandler::usdInput(usdValue); 
                break;
            case 4: 
                CurrencyAPI::updateCache(cache); 
                break;
        }
    } while (option != 0);

    return 0;
}