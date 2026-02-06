#ifndef CURRENCY_API_H
#define CURRENCY_API_H

#include <string>
#include "ExchangeCache.h"

class CurrencyAPI {
public:
    /**
     * Fetches real-time exchange rates and updates the cache structure.
     * @param cache Reference to the ExchangeCache to be updated.
     */
    static void updateCache(ExchangeCache& cache);

private:
    /**
     * Internal callback function required by libcurl to process the HTTP response.
     * Handles the data stream and appends it to a string buffer.
     */
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s);
};

#endif