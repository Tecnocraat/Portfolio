#include <iostream>  // Inclui a biblioteca para entrada e sa�da de dados (cin, cout)
#include <string>    // Inclui a biblioteca para manipula��o de strings
#include <iomanip>   // Inclui a biblioteca para controle de formata��o de sa�da
#include <cstdlib>   // Inclui a biblioteca para fun��es como system("pause")

using namespace std;  // Permite o uso direto de objetos da biblioteca padr�o, como cout e cin

int main() {
    // Declara��o das vari�veis
    string moeda;     // Vari�vel para armazenar a moeda desejada (dolar ou euro)
    double reais;     // Vari�vel para armazenar o valor em reais a ser convertido
    double dolar, euro;  // Vari�veis para armazenar as taxas de convers�o

	// Atribuindo valores �s moedas
    dolar = 5.5;  // 1 d�lar = 5.5 reais (taxa fict�cia para exemplo)
    euro = 6.0;   // 1 euro = 6.0 reais (taxa fict�cia para exemplo)

    // Solicita ao usu�rio que insira um valor em reais
    cout << "Digite um valor em reais: \n";
    cin >> reais;  // L� o valor digitado pelo usu�rio e armazena na vari�vel 'reais'

    // Pergunta ao usu�rio qual moeda ele gostaria de converter
    cout << "Gostaria de converter para dolar ou euro?";
    cin >> moeda;  // L� a escolha do usu�rio (dolar ou euro) e armazena na vari�vel 'moeda'

    // Configura a sa�da para exibir 2 casas decimais ap�s o ponto
    cout << fixed << setprecision(2);

    // Condicional para verificar qual moeda foi escolhida e realizar a convers�o
    if (moeda == "dolar" || moeda == "Dolar") {  // Verifica se a escolha do usu�rio � dolar (considerando mai�sculas ou min�sculas)
        // Exibe o valor convertido para d�lares
        cout << "O valor em dolar e US$" << reais / dolar;
    } else if (moeda == "euro" || moeda == "Euro") {  // Verifica se a escolha do usu�rio � euro (considerando mai�sculas ou min�sculas)
        // Exibe o valor convertido para euros
        cout << "O valor em euro e EUR" << reais / euro;
    } else {
        // Caso o usu�rio digite uma moeda n�o reconhecida
        cout << "Erro! Moeda n�o reconhecida. Por favor, insira uma moeda valida (dolar ou euro)" << endl;
    }

    // Pausa a execu��o do programa antes de fech�-lo (usado no Windows)
    system("pause");

    // Retorna 0, indicando que o programa terminou com sucesso
    return 0;
}
