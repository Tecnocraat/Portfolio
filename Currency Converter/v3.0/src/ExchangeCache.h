#ifndef EXCHANGE_CACHE_H
#define EXCHANGE_CACHE_H

/**
 * Structure to store exchange rates and synchronization status.
 * Separated into a dedicated header to follow the Single Responsibility Principle.
 */
struct ExchangeCache {
    double brl = 0.0;
    double eur = 0.0;
    double gbp = 0.0;
    double btc = 0.0;
    bool loaded = false;
};

#endif
