#include "../include/CurrencyAPI.h"
#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <cstdlib>

using json = nlohmann::json;

size_t CurrencyAPI::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
    size_t newLength = size * nmemb;
    try {
        // Appends incoming data chunks to the buffer string
        s->append((char*)contents, newLength);
    } catch (std::bad_alloc& e) {
        // Prevent buffer overflow/memory exhaustion
        return 0;
    }
    return newLength;
}

void CurrencyAPI::updateCache(ExchangeCache& cache) {
    const char* apiKeyEnv = std::getenv("EXCHANGE_RATE_KEY");
    if (!apiKeyEnv) {
        std::cerr << "\n[!] Error: EXCHANGE_RATE_KEY not set in .env file.\n";
        return;
    }

    std::string apiKey(apiKeyEnv);
    CURL* curl = curl_easy_init();
    std::string readBuffer;

    if(curl) {
        // Requesting specific symbols to optimize payload size
        std::string url = "https://api.exchangerate.host/live?access_key=" + apiKey + "&symbols=BRL,EUR";
        
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); // Standard for local environments without CA bundles

        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if(res == CURLE_OK) {
            try {
                auto data = json::parse(readBuffer);
                
                // Validate API success state before accessing quotes object
                if (data.contains("success") && data["success"] == true) {
                    if(data.contains("quotes")) {
                        cache.brl = data["quotes"]["USDBRL"].get<double>();
                        cache.eur = data["quotes"]["USDEUR"].get<double>();
                        cache.loaded = true;
                        std::cout << "[+] Exchange rates updated successfully.\n";
                    }
                } else {
                    std::cerr << "[!] API Error: " << data["error"]["info"] << "\n";
                }
            } catch (...) {
                std::cerr << "[!] JSON Error: Could not parse exchange data.\n";
            }
        } else {
            std::cerr << "[!] Network Error: " << curl_easy_strerror(res) << "\n";
        }
    }
}