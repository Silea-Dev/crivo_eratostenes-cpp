
# Crivo de Eratóstenes com C++ e `std::vector`

Uma implementação de alta performance do clássico algoritmo Crivo de Eratóstenes em C++, focada em velocidade nativa e gerenciamento explícito de memória para encontrar números primos até um limite especificado.

## Contexto do Projeto

Este projeto, originalmente um exercício prático unindo **Matemática** e  **Análise e Desenvolvimento de Sistemas (TADS)** , foi refeito e aprimorado agora sob a nova ótica da  **Engenharia de Software** .

O objetivo foi revisitar a tradução de uma implementação de Python/NumPy para C++ puro. O foco mudou de apenas "fazer funcionar" para aplicar **princípios de engenharia** de forma explícita:

* **Performance Nativa:** Entender por que o C++ compilado é ordens de magnitude mais rápido que o Python/NumPy para esta tarefa.
* **Gerenciamento de Tipos e Memória:** Lidar diretamente com os limites dos tipos de dados (usando `unsigned long long int` para evitar  *overflow* ) e entender o custo-benefício da especialização `std::vector<bool>` (8x mais eficiente em memória).
* **Recriação da "Mecânica":** Traduzir os "atalhos" de alto nível do NumPy (`slicing`, `np.ones`, `np.where`) para suas contrapartes mecânicas em C++ (laços `for` manuais, listas de inicialização de construtor e iteração explícita).

## Tecnologias e Conceitos Aplicados

* **C++ (Padrão C++17)**
* **Programação Orientada a Objetos (POO):** `class`, Construtor (`: lista_de_inicializacao`), Destrutor e Métodos.
* **Biblioteca Padrão C++ (STL):**
  * `std::vector<bool>`: Uso da especialização de template para "empacotar" booleanos e economizar memória.
  * `<cmath>`: Uso de `std::sqrt` para otimização de laço.
  * `<iostream>`: Para entrada e saída do terminal.
* **Gerenciamento de Tipos:** Uso de `unsigned long long int` para lidar com números de 64 bits e evitar  *integer overflow* .
* **Análise de Algoritmos:** Implementação otimizada do Crivo de Eratóstenes (início em `p*p` e limite na `raiz_i`).
* **Compilação e Linkagem:** Uso de `g++` com a flag `-lm` para linkar bibliotecas externas.

## Como Compilar e Executar

O programa requer um compilador C++ (como g++ ou Clang) e precisa ser linkado com a biblioteca de matemática (`-lm`) devido ao uso de `std.sqrt`.

```
# 1. Compilar o programa
# (Use -std=c++17 ou mais recente)
g++ seu_arquivo.cpp -o crivo -std=c++17 -lm

# 2. Executar o programa
./crivo
```

## Referências

* O Crivo de Eratóstenes (Números Primos), disponível em `https://matematicando.net.br/o-crivo-de-eratostenes-numeros-primos/`, acessado em 17 de outubro de 2025.
