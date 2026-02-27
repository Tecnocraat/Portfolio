#include "../include/EnvLoader.h"
#include <fstream>
#include <string>
#include <cstdlib>

/**
 * Loads environment variables from a local .env file.
 * Injects keys into the process environment for secure access.
 */
void EnvLoader::load(const char* filepath) {
    std::ifstream envFile(filepath);
    
    if (envFile.is_open()) {
        std::string line;
        while (std::getline(envFile, line)) {
            size_t delimiterPos = line.find('=');
            if (delimiterPos != std::string::npos) {
                std::string key = line.substr(0, delimiterPos);
                std::string value = line.substr(delimiterPos + 1);
                
                // OS-specific environment injection
                #ifdef _WIN32
                    _putenv_s(key.c_str(), value.c_str());
                #else
                    setenv(key.c_str(), value.c_str(), 1);
                #endif
            }
        }
        envFile.close();
    }
}