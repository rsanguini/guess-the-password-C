# 🎮 Jogo da Adivinhação de Senha em C

![Linguagem C](https://img.shields.io/badge/Linguagem-C-blue.svg)
![Ambiente](https://img.shields.io/badge/Ambiente-VSCode-lightgrey.svg)
![Licença](https://img.shields.io/badge/Licen%C3%A7a-MIT-green.svg)

Uma aplicação interativa via linha de comando desenvolvida em linguagem C onde o usuário tem o desafio de adivinhar uma senha secreta numérica de 4 dígitos em até 10 tentativas, contando com um sistema progressivo de dicas.

---

## 📌 Sumário
- [Maneira que foi Pensado](#-maneira-que-foi-pensado)
- [Arquitetura do Projeto](#-arquitetura-do-projeto)
- [Ferramentas e Tecnologias](#-ferramentas-e-tecnologias)
- [Como Funciona Cada Parte](#-como-funciona-cada-parte)
- [Destaque de Estruturas de Código](#-destaque-de-estruturas-de-c%C3%B3digo)
- [Como Rodar o Projeto](#-como-rodar-o-projeto)
- [Licença](#-licen%C3%A7a)
- [Apoie o Projeto](#-apoie-o-projeto)
- [Autor](#-autor)

---

## 🧠 Maneira que foi Pensado

O projeto foi idealizado como um exercício prático de lógica de programação em **C**, focando nos seguintes objetivos:
1. **Interatividade:** Proporcionar uma experiência fluida para o usuário com limpezas de tela e validações amigáveis.
2. **Decomposição Matemática:** Manipular números inteiros usando matemática básica (módulo `%` e divisão `/`) em vez de strings para extrair cada dígito individualmente.
3. **Mecânica de Dicas Progressivas:** À medida que o jogador consome tentativas sem acertar, o jogo fornece pistas dinâmicas para ajudá-lo na resolução.

---

## 🏗 Arquitetura do Projeto

A estrutura de execução do projeto segue o fluxo simples de um jogo de console interativo:

```text
[Início] ➔ [Sorteio da Senha (1000-9999)] ➔ [Menu Inicial]
                                                │
                                    ┌───────────┴───────────┐
                                    ▼                       ▼
                              (1) Jogar               (2) Sair ➔ [Fim]
                                    │
                                    ▼
                         ┌─► [Entrada do Usuário]
                         │          │
                         │          ▼
                         │   [Validação de Entrada]
                         │          │
                         │          ▼
                         │   [Verificação dos Dígitos]
                         │          │
                         │          ▼
                         │   [Apresentação de Dicas] (Tentativas 5-9)
                         │          │
                         └──────────┴── Tentativas < 10 && Acertos < 4
                                    │
                                    ▼
                         [Resultado: Vitória ou Derrota]
                                    │
                                    ▼
                         [Deseja jogar novamente?]

```

## 🛠 Ferramentas e Tecnologias
- **Linguagem:** C
- **Compilador Recomendado:** GCC / MinGW
- **Bibliotecas Padrão Utilizadas:**
  - `<stdio.h>`: Manipulação de entrada e saída (`printf`, `scanf`).
  - `<stdlib.h>`: Funções do sistema (`system("cls")`, `exit`) e geração de números aleatórios (`rand`, `srand`).
  - `<time.h>`: Semente de aleatoriedade baseada no tempo do sistema (`time(NULL)`).
  - `<locale.h>`: Suporte para caracteres em português (`setlocale`).

---

## 🔍 Como Funciona Cada Parte
1. **Geração do Número Secreto:** O programa gera um número entre 1000 e 9999 usando a função `rand()`. Os 4 dígitos da senha são separados usando operações de divisão e resto da divisão.
2. **Menu de Boas-Vindas:** Explica as regras do jogo e permite que o jogador escolha iniciar ou encerrar a aplicação.
3. **Loop Principal de Tentativas:** Permite até 10 palpites do usuário. Em cada tentativa:
   - Valida se a entrada é um número de 4 dígitos.
   - Compara cada dígito digitado com o dígito correspondente da senha secreta.
   - Fixa os dígitos já acertados nas tentativas anteriores para orientar o jogador.
4. **Sistema de Dicas Progressivas:**
   - **Tentativa 5:** Dica de par/ímpar sobre um dos dígitos pendentes.
   - **Tentativa 6:** Soma total dos 4 dígitos.
   - **Tentativa 7:** O maior dígito presente na senha.
   - **Tentativa 8:** Análise de dígitos pendentes (maior/igual ou menor que 5).
   - **Tentativa 9:** Informa se existem dígitos repetidos na senha.
5. **Encerramento e Reinício:** Exibe mensagem de vitória ou derrota e pergunta se o usuário deseja reiniciar a partida sem fechar o programa.

---

## 💻 Destaque de Estruturas de Código

### Decomposição de Dígitos por Módulo e Divisão
Para quebrar um número de 4 dígitos em partes sem usar strings, utilizamos aritmética inteira:
```c
n4 = n % 10;        // Pega o último dígito
n3 = (n / 10) % 10;  // Pega o terceiro dígito
n2 = (n / 100) % 10; // Pega o segundo dígito
n1 = (n / 1000) % 10;// Pega o primeiro dígito
