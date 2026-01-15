# Conversor de Moedas — v1.0 (Console)

Versão inicial do projeto **Conversor de Moedas**, desenvolvida em C++ para execução em console.

Esta versão tem como objetivo validar a lógica básica de conversão e a interação com o usuário, servindo como base para versões mais avançadas do projeto.

## Funcionalidades
- Conversão de valores em reais para:
  - Dólar
  - Euro
- Taxas de câmbio fixas (valores fictícios)
- Entrada de dados via terminal

## Tecnologias utilizadas
- C++
- Biblioteca padrão da linguagem

## Observações técnicas
- As taxas são definidas diretamente no código.
- A entrada da moeda segue o padrão ISO 4217 (ex.: BRL, USD, EUR), reduzindo ambiguidades na entrada do usuário.
- O foco desta versão é simplicidade e clareza.
- Não há persistência de dados nem integração com APIs externas.

## Evolução planejada
- v2.0: Conversão com taxas atualizadas em tempo real via API
- v2.1: Persistência das conversões em banco de dados PostgreSQL
- v3.0: Interface gráfica utilizando Qt

> Esta versão representa o ponto de partida do projeto.