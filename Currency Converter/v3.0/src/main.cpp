#include "mainwindow.h"
#include "EnvLoader.h"
#include <QApplication>
#include <QDebug>
#include <cstdlib>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    EnvLoader::load(".env");

    // Diagnostic check for initial environment setup
    const char* apiKey = std::getenv("EXCHANGE_RATE_KEY");
    if (apiKey) {
        qDebug() << "SUCCESS: API Key found ->" << apiKey;
    } else {
        qDebug() << "ERROR: .env not loaded or EXCHANGE_RATE_KEY is missing!";
    }

    MainWindow w;
    w.show();

    return a.exec();
}
