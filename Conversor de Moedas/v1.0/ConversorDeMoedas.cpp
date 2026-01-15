#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>

int main() {
    std::string moeda;
    double reais;
    double dolar = 5.5; // Taxa fictícia
    double euro  = 6.0; // Taxa fictícia

    std::cout << "Digite um valor em BRL:\n";
    std::cin >> reais;

    std::cout << "Gostaria de converter para USD ou EUR? ";
    std::cin >> moeda;

    for (char& c : moeda) { // Normaliza a entrada para letras maiúsculas
        c = std::toupper(c);
    }

    std::cout << std::fixed << std::setprecision(2); // Exibe valores com 2 casas decimais

    if (moeda == "USD") {
        std::cout << "O valor em dolar e US$" << reais / dolar << "\n";
    } else if (moeda == "EUR") {
        std::cout << "O valor em euro e EUR" << reais / euro << "\n";
    } else {
        std::cout << "Erro! Moeda nao reconhecida.\n";
    }

    system("pause"); // Apenas para Windows
    return 0;
}