# 🎮 Jogo da Adivinhação de Senha em C

![Linguagem C](https://img.shields.io/badge/Linguagem-C-blue.svg)
![Ambiente](https://img.shields.io/badge/Ambiente-VS%20Code-lightgrey.svg)
![Compilador](https://img.shields.io/badge/Compilador-GCC%2FMinGW-orange.svg)
![Licença](https://img.shields.io/badge/Licença-MIT-green.svg)

Um jogo interativo desenvolvido em **linguagem C**, executado diretamente no terminal, no qual o jogador precisa descobrir uma senha numérica secreta de quatro dígitos em até 10 tentativas.

O projeto conta com um sistema de dicas progressivas, identificação dos dígitos descobertos e possibilidade de iniciar novas partidas sem precisar executar o programa novamente.

Mais do que um jogo, este projeto é um exercício prático de lógica de programação, manipulação de números inteiros, estruturas condicionais, laços de repetição e geração de números pseudoaleatórios.

---

## 📌 Sumário

- [Sobre o Projeto](#-sobre-o-projeto)
- [Objetivos e Conceitos Aplicados](#-objetivos-e-conceitos-aplicados)
- [Regras do Jogo](#-regras-do-jogo)
- [Sistema de Dicas](#-sistema-de-dicas)
- [Arquitetura e Fluxo de Execução](#-arquitetura-e-fluxo-de-execução)
- [Estrutura do Projeto](#-estrutura-do-projeto)
- [Tecnologias e Bibliotecas](#-tecnologias-e-bibliotecas)
- [Principais Estruturas de Código](#-principais-estruturas-de-código)
- [Como Executar o Projeto](#-como-executar-o-projeto)
- [Possíveis Melhorias](#-possíveis-melhorias)
- [Licença](#-licença)
- [Autor](#-autor)

---

## 🎯 Sobre o Projeto

O Jogo da Adivinhação de Senha foi desenvolvido com o objetivo de praticar os fundamentos da programação utilizando a linguagem C.

Ao iniciar uma partida, o programa gera um número pseudoaleatório entre `1000` e `9999`. O jogador deve descobrir esse número por meio de palpites, recebendo informações sobre os dígitos corretos e dicas adicionais conforme avança nas tentativas.

O jogo também permite visualizar os dígitos já descobertos, mantendo essas posições fixas na apresentação da senha e facilitando a resolução do desafio.

### Principais funcionalidades

- Geração pseudoaleatória de uma senha numérica de quatro dígitos.
- Limite de 10 tentativas por partida.
- Validação básica dos palpites informados.
- Identificação dos dígitos corretos em suas respectivas posições.
- Exibição progressiva dos dígitos descobertos.
- Sistema de cinco dicas liberadas ao longo da partida.
- Mensagens de vitória e derrota.
- Opção de jogar novamente sem reiniciar o executável.
- Interface textual interativa com limpeza de tela.

---

## 🧠 Objetivos e Conceitos Aplicados

O desenvolvimento do projeto permite aplicar conceitos fundamentais da linguagem C em uma situação prática.

| Conceito | Aplicação no projeto |
|---|---|
| Variáveis e tipos de dados | Armazenamento da senha, dos palpites e das tentativas. |
| Entrada e saída | Interação com o jogador por meio de `scanf()` e `printf()`. |
| Estruturas condicionais | Verificação de acertos, validações e decisões do jogo. |
| Laços de repetição | Controle das tentativas e reinício das partidas. |
| Operadores aritméticos | Extração dos dígitos por divisão inteira e módulo. |
| Números pseudoaleatórios | Geração da senha com `rand()`. |
| Funções de biblioteca | Manipulação de tempo, entrada e saída e recursos do sistema. |
| Controle de fluxo | Utilização de `break` e `exit()`. |

### Principais objetivos de aprendizagem

1. **Desenvolver raciocínio lógico:** estruturar as regras do jogo em etapas bem definidas.
2. **Manipular números inteiros:** extrair e comparar dígitos sem depender de strings.
3. **Trabalhar com repetição:** controlar o limite de tentativas e permitir novas partidas.
4. **Aplicar condições:** identificar acertos e decidir quais informações apresentar.
5. **Criar uma experiência interativa:** organizar mensagens, menus e dicas no terminal.

---

## 🎮 Regras do Jogo

O funcionamento é simples: descubra a senha antes de esgotar suas tentativas.

1. O programa gera uma senha secreta entre `1000` e `9999`.
2. O jogador escolhe iniciar uma partida pelo menu.
3. Em cada rodada, informa um palpite de quatro dígitos.
4. O programa compara cada posição do palpite com a senha secreta.
5. Os dígitos acertados em suas respectivas posições são revelados e permanecem visíveis.
6. A partir da quinta tentativa, novas dicas são disponibilizadas.
7. O jogador vence quando todas as quatro posições são descobertas.
8. Caso não consiga descobrir a senha dentro do limite de tentativas, o jogo apresenta o número correto.
9. Ao final, é possível iniciar outra partida ou encerrar a execução.

**Importante:** não basta encontrar os mesmos dígitos em posições diferentes. Para que uma posição seja considerada correta, o dígito precisa corresponder exatamente à posição da senha secreta.

---

## 💡 Sistema de Dicas

O jogo utiliza um sistema progressivo de dicas para auxiliar o jogador sem revelar a senha diretamente.

| Tentativa | Dica | Descrição |
|---|---|---|
| 5ª | Par ou ímpar | Informa se um dos primeiros dígitos ainda não descobertos é par ou ímpar. |
| 6ª | Soma dos dígitos | Revela a soma dos quatro dígitos da senha. |
| 7ª | Maior dígito | Informa o maior dígito presente na senha. |
| 8ª | Comparação com 5 | Informa se cada dígito ainda não descoberto é menor que 5 ou maior ou igual a 5. |
| 9ª | Dígitos repetidos | Indica se a senha possui dígitos repetidos. |

As dicas são apresentadas conforme o número da tentativa, incentivando o jogador a combinar as informações obtidas com os acertos anteriores.

**Observação técnica:** na quinta tentativa, a dica de paridade considera o primeiro dígito ainda não descoberto. Na oitava tentativa, a comparação com 5 é aplicada individualmente às posições que continuam desconhecidas.

---

## 🏗 Arquitetura e Fluxo de Execução

O programa é organizado em uma sequência de etapas que controlam o início, a execução e o encerramento das partidas.

```text
                    ┌──────────────────────┐
                    │   Início do programa │
                    └──────────┬───────────┘
                               │
                               ▼
                    ┌──────────────────────┐
                    │ Geração da senha     │
                    │ secreta (1000–9999)  │
                    └──────────┬───────────┘
                               │
                               ▼
                    ┌──────────────────────┐
                    │     Menu inicial     │
                    └──────────┬───────────┘
                               │
                     ┌─────────┴─────────┐
                     ▼                   ▼
              ┌────────────┐      ┌────────────┐
              │  Jogar     │      │   Sair     │
              └─────┬──────┘      └────────────┘
                    │
                    ▼
          ┌──────────────────────┐
          │ Receber um palpite   │
          └──────────┬───────────┘
                     │
                     ▼
          ┌──────────────────────┐
          │ Validar a entrada    │
          └──────────┬───────────┘
                     │
                     ▼
          ┌──────────────────────┐
          │ Comparar os dígitos  │
          └──────────┬───────────┘
                     │
                     ▼
          ┌──────────────────────┐
          │ Revelar os acertos   │
          │ e apresentar dicas   │
          └──────────┬───────────┘
                     │
                     ▼
          ┌──────────────────────┐
          │ Vitória ou limite de │
          │ tentativas atingido  │
          └──────────┬───────────┘
                     │
                     ▼
          ┌──────────────────────┐
          │ Jogar novamente?     │
          └──────────┬───────────┘
                     │
                ┌────┴────┐
                ▼         ▼
             Nova       Encerrar
             partida    programa
```

O fluxo utiliza estruturas de repetição aninhadas para controlar o menu inicial, as tentativas de cada partida e a possibilidade de jogar novamente.

---

## 📂 Estrutura do Projeto

A estrutura básica do repositório pode ser organizada da seguinte maneira:

```text
jogo-adivinhacao-senha/
├── main.c
├── README.md
└── LICENSE
```

| Arquivo | Descrição |
|---|---|
| `main.c` | Contém a implementação da lógica do jogo. |
| `README.md` | Documentação do projeto, regras e instruções de execução. |
| `LICENSE` | Define os termos de utilização e distribuição do código, caso a licença MIT seja incluída. |

Os nomes são sugestões de organização. Ajuste-os caso os arquivos do seu repositório tenham nomes diferentes.

---

## 🛠 Tecnologias e Bibliotecas

### Linguagem

- **C:** utilizada para implementar toda a lógica do jogo.

### Ferramentas recomendadas

- **Visual Studio Code:** editor de código-fonte.
- **GCC / MinGW-w64:** compilador para programas em C no Windows.
- **Terminal do Windows ou PowerShell:** ambiente para compilação e execução.

### Bibliotecas utilizadas

| Biblioteca | Finalidade |
|---|---|
| `stdio.h` | Entrada e saída de dados, incluindo `printf()` e `scanf()`. |
| `stdlib.h` | Geração pseudoaleatória com `rand()`, encerramento com `exit()` e recursos auxiliares. |
| `time.h` | Obtenção do horário do sistema para inicializar o gerador pseudoaleatório. |
| `locale.h` | Configuração regional por meio de `setlocale()`. |
| `conio.h` | Disponibiliza `getch()`, utilizado para aguardar uma tecla. |

**Nota:** o código apresentado utiliza `getch()` e comandos específicos do Windows, como `system("cls")`. Por isso, a implementação atual não é diretamente portátil para todos os sistemas operacionais.

---

## 💻 Principais Estruturas de Código

### 1. Geração da senha secreta

A senha é gerada por meio da função `rand()`, que produz números pseudoaleatórios.

```c
srand(time(NULL));

int n = (rand() % 9000) + 1000;
```

A expressão `rand() % 9000` produz um valor entre `0` e `8999`. Ao adicionar `1000`, o resultado fica entre `1000` e `9999`.

A função `srand(time(NULL))` inicializa o gerador utilizando o horário atual como semente.

> A geração com `rand()` é adequada para um exercício didático, mas não deve ser utilizada para gerar senhas criptograficamente seguras.

### 2. Decomposição dos dígitos

O programa utiliza operações matemáticas para separar os quatro dígitos da senha.

```c
n4 = n % 10;
n3 = (n / 10) % 10;
n2 = (n / 100) % 10;
n1 = (n / 1000) % 10;
```

Considere, por exemplo, o número `5832`:

| Variável | Operação | Resultado |
|---|---|---:|
| `n1` | `(5832 / 1000) % 10` | 5 |
| `n2` | `(5832 / 100) % 10` | 8 |
| `n3` | `(5832 / 10) % 10` | 3 |
| `n4` | `5832 % 10` | 2 |

Essa abordagem permite acessar individualmente cada posição utilizando apenas operações com números inteiros.

### 3. Validação do palpite

O programa verifica se a entrada pode ser interpretada como um número inteiro e se está dentro do intervalo permitido.

```c
if (scanf("%d", &x) != 1) {
    printf("Número inválido.\n");
} else if (x < 1000 || x > 9999) {
    printf("Número inválido.\n");
}
```

A primeira condição verifica se a leitura foi bem-sucedida. A segunda verifica se o valor está entre `1000` e `9999`.

Essa validação é básica: uma versão futura pode utilizar leitura por linha e conversão controlada para tratar entradas não numéricas e outros casos de forma mais robusta.

### 4. Comparação dos dígitos

Cada posição do palpite é comparada com a posição correspondente da senha secreta.

```c
x1 = (x / 1000) % 10;
x2 = (x / 100) % 10;
x3 = (x / 10) % 10;
x4 = x % 10;
```

Depois da separação, o programa verifica os acertos individualmente. Quando um dígito é descoberto, sua posição passa a ser exibida nas tentativas seguintes.

### 5. Controle dos dígitos descobertos

As variáveis `fix1`, `fix2`, `fix3` e `fix4` são inicializadas com `-1`.

```c
int fix1 = -1;
int fix2 = -1;
int fix3 = -1;
int fix4 = -1;
```

O valor `-1` representa uma posição ainda não descoberta. Quando o jogador acerta uma posição, a variável correspondente passa a armazenar o dígito correto.

Essa técnica permite distinguir posições descobertas de posições pendentes.

### 6. Estruturas de repetição

O projeto utiliza laços `do-while`, `for` e `while` para controlar as diferentes etapas.

- `do-while`: mantém o menu ativo até que uma opção válida de início seja selecionada e permite repetir partidas.
- `for`: controla o limite de 10 tentativas.
- `while`: mantém a solicitação de entrada até que o palpite passe pelas verificações implementadas.

A combinação dessas estruturas organiza o fluxo do jogo sem exigir funções recursivas.

---

## 🚀 Como Executar o Projeto

### Pré-requisitos

Antes de executar o projeto, verifique se você possui:

- Windows 10 ou Windows 11.
- Visual Studio Code instalado.
- GCC/MinGW-w64 configurado no PATH do sistema.
- Arquivo-fonte do projeto em C.

### 1. Clonar o repositório

No terminal, execute:

```bash
git clone URL_DO_SEU_REPOSITORIO
```

Entre na pasta criada:

```bash
cd NOME_DO_REPOSITORIO
```

Substitua `URL_DO_SEU_REPOSITORIO` e `NOME_DO_REPOSITORIO` pelos dados reais do seu repositório.

### 2. Abrir no Visual Studio Code

Se o comando `code` estiver disponível, execute:

```bash
code .
```

Abra o arquivo principal do projeto, por exemplo, `main.c`.

### 3. Compilar o programa

No terminal integrado do VS Code, execute:

```bash
gcc main.c -o jogo.exe
```

Se o arquivo-fonte tiver outro nome, substitua `main.c` pelo nome correto.

### 4. Executar o jogo

Após uma compilação bem-sucedida, execute:

```powershell
.\jogo.exe
```

O menu inicial será apresentado no terminal.

### Solução de problemas

**Erro: `gcc não é reconhecido`**

O GCC pode não estar instalado ou o diretório `bin` do MinGW-w64 pode não estar configurado na variável de ambiente `PATH`.

Verifique a instalação com:

```bash
gcc --version
```

**Erro relacionado a `getch()`**

O código precisa da declaração de `getch()`, normalmente fornecida por `conio.h` nos ambientes compatíveis. Confirme se a biblioteca está disponível no compilador utilizado.

**O comando `cls` não funciona**

A implementação utiliza `system("cls")`, que depende do ambiente Windows. Em outros sistemas, será necessário adaptar a limpeza de tela.

**Caracteres acentuados aparecem incorretamente**

Verifique a codificação do arquivo-fonte, preferencialmente UTF-8, e a configuração de codificação do terminal. A chamada `setlocale(LC_ALL, "portuguese")` também depende das configurações regionais disponíveis no sistema.

---

## 🔧 Possíveis Melhorias

O projeto pode evoluir com algumas melhorias técnicas e funcionais:

- [ ] Separar a lógica do jogo em funções para melhorar a organização.
- [ ] Tornar a leitura de entradas mais robusta.
- [ ] Corrigir e centralizar o controle de vitória e derrota.
- [ ] Remover a exibição da senha secreta durante as tentativas.
- [ ] Inicializar o gerador pseudoaleatório uma única vez no início do programa.
- [ ] Melhorar a portabilidade para Linux e macOS.
- [ ] Adicionar níveis de dificuldade com diferentes limites de tentativas.
- [ ] Implementar um sistema de pontuação baseado no número de tentativas.
- [ ] Criar um histórico das partidas.
- [ ] Adicionar testes para validar as regras e o comportamento do jogo.

Essas melhorias podem tornar o programa mais robusto, modular e fácil de manter.

---

## 📄 Licença

Este projeto pode ser distribuído sob a licença MIT.

A licença permite utilizar, modificar e redistribuir o código, inclusive em projetos comerciais, desde que os avisos de direitos autorais e a licença sejam preservados.

Para que essa indicação seja válida no repositório, inclua um arquivo `LICENSE` contendo o texto oficial da licença MIT e as informações corretas do titular dos direitos autorais.

---

## 👤 Author

**Rafael Sanguini Colagrossi** — Software Engineering Student

Desenvolvido como projeto prático de estudo da linguagem C, com foco em lógica de programação, manipulação de números inteiros e construção de aplicações interativas em terminal.

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=flat-square&logo=linkedin&logoColor=white)](https://linkedin.com/in/rafaelsanguini)
[![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat-square&logo=github&logoColor=white)](https://github.com/rsanguini)
[![Portfolio](https://img.shields.io/badge/Portfolio-000000?style=flat-square&logo=vercel&logoColor=white)](https://rafaelsanguini.vercel.app)
[![Email](https://img.shields.io/badge/Email-D14836?style=flat-square&logo=gmail&logoColor=white)](mailto:rafaelcolagrossi@gmail.com)

---

⭐ Se este projeto foi útil para seus estudos, considere deixar uma estrela no repositório - Significa muito!

**Obrigado por conferir o projeto!**
