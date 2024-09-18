# Interpretador BASIC em C

Este é um interpretador simples para a linguagem BASIC, implementado em C. Ele pode interpretar comandos de atribuição e realizar operações básicas como soma e subtração, além de exibir variáveis com o comando `PRINT`.

## Funcionalidades

- Atribuição de valores a variáveis (ex: `A = 10`)
- Operações aritméticas de soma e subtração entre variáveis (ex: `C = A + B`)
- Exibição de valores com o comando `PRINT` (ex: `PRINT C`)

## Como usar

### 1. Compilar o programa

Para compilar o interpretador, execute o seguinte comando no terminal:

```bash
gcc -o basic_interpreter basic_interpreter.c
```

Isso irá gerar um executável chamado `basic_interpreter`.

### 2. Executar o programa

Para executar o interpretador, forneça um arquivo de texto contendo código BASIC como argumento. Por exemplo:

```bash
./basic_interpreter programa.bas
```

O arquivo `programa.bas` deve conter as instruções BASIC que você deseja interpretar.

### 3. Exemplo de arquivo BASIC

Aqui está um exemplo de código BASIC que você pode colocar no arquivo `programa.bas`:

```
A = 10
B = 5
C = A + B
D = A - B
PRINT C
PRINT D
```

A saída desse programa será:

```
15
5
```

### 4. Erros Comuns

- **Erro: Variável não encontrada**: Certifique-se de que todas as variáveis utilizadas nas operações foram declaradas e atribuídas previamente.
- **Erro: Sintaxe de atribuição incorreta**: Verifique a sintaxe da linha. O interpretador espera atribuições simples como `A = 5` ou operações como `A = B + C`.

## Requisitos

- Um compilador C, como `gcc`, instalado na máquina.

## Contato

- Teams Luca Marques E, Vieira 20211003300398