#include "../include/CurrencyAPI.h"
#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <cstdlib>

using json = nlohmann::json;

// Callback function to handle incoming data stream from libcurl
size_t CurrencyAPI::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
    size_t newLength = size * nmemb;
    try {
        s->append((char*)contents, newLength);
    } catch (std::bad_alloc& e) {
        return 0;
    }
    return newLength;
}

void CurrencyAPI::updateCache(ExchangeCache& cache) {
    const char* apiKeyEnv = std::getenv("EXCHANGE_RATE_KEY");
    if (!apiKeyEnv) {
        std::cerr << "\n[!] Error: EXCHANGE_RATE_KEY not set.\n";
        return;
    }

    std::string apiKey(apiKeyEnv);
    CURL* curl = curl_easy_init();
    std::string readBuffer;

    if(curl) {
        std::string url = "https://api.exchangerate.host/live?access_key=" + apiKey + "&symbols=BRL,EUR";
        
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        
        std::cout << "\n[Connecting to API...]\n";
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if(res == CURLE_OK) {
            try {
                auto data = json::parse(readBuffer);
                if (data["success"] == true) {
                    cache.brl = data["quotes"]["USDBRL"];
                    cache.eur = data["quotes"]["USDEUR"];
                    cache.loaded = true;
                    std::cout << "[Success: Cache updated!]\n";
                }
            } catch (...) {
                std::cerr << "[JSON Error: Parse failed]\n";
            }
        }
    }
}