#include <iostream>  // Inclui a biblioteca para entrada e saída de dados (cin, cout)
#include <string>    // Inclui a biblioteca para manipulação de strings
#include <iomanip>   // Inclui a biblioteca para controle de formatação de saída
#include <cstdlib>   // Inclui a biblioteca para funções como system("pause")

using namespace std;  // Permite o uso direto de objetos da biblioteca padrão, como cout e cin

int main() {
    // Declaração das variáveis
    string moeda;     // Variável para armazenar a moeda desejada (dolar ou euro)
    double reais;     // Variável para armazenar o valor em reais a ser convertido
    double dolar, euro;  // Variáveis para armazenar as taxas de conversão

	// Atribuindo valores às moedas
    dolar = 5.5;  // 1 dólar = 5.5 reais (taxa fictícia para exemplo)
    euro = 6.0;   // 1 euro = 6.0 reais (taxa fictícia para exemplo)

    // Solicita ao usuário que insira um valor em reais
    cout << "Digite um valor em reais: \n";
    cin >> reais;  // Lê o valor digitado pelo usuário e armazena na variável 'reais'

    // Pergunta ao usuário qual moeda ele gostaria de converter
    cout << "Gostaria de converter para dolar ou euro?";
    cin >> moeda;  // Lê a escolha do usuário (dolar ou euro) e armazena na variável 'moeda'

    // Configura a saída para exibir 2 casas decimais após o ponto
    cout << fixed << setprecision(2);

    // Condicional para verificar qual moeda foi escolhida e realizar a conversão
    if (moeda == "dolar" || moeda == "Dolar") {  // Verifica se a escolha do usuário é dolar (considerando maiúsculas ou minúsculas)
        // Exibe o valor convertido para dólares
        cout << "O valor em dolar e US$" << reais / dolar;
    } else if (moeda == "euro" || moeda == "Euro") {  // Verifica se a escolha do usuário é euro (considerando maiúsculas ou minúsculas)
        // Exibe o valor convertido para euros
        cout << "O valor em euro e EUR" << reais / euro;
    } else {
        // Caso o usuário digite uma moeda não reconhecida
        cout << "Erro! Moeda não reconhecida. Por favor, insira uma moeda valida (dolar ou euro)" << endl;
    }

    // Pausa a execução do programa antes de fechá-lo (usado no Windows)
    system("pause");

    // Retorna 0, indicando que o programa terminou com sucesso
    return 0;
}
