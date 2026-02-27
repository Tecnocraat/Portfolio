#ifndef ENV_LOADER_H
#define ENV_LOADER_H

/**
 * Utility class to manage environment variables and .env files.
 */
class EnvLoader {
public:
    /**
     * Reads a .env file and injects its variables into the process environment.
     * @param filepath Path to the .env file (default is ".env").
     */
    static void load(const char* filepath = ".env");
};

#endif