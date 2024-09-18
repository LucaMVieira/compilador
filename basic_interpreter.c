#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_VAR_COUNT 100

// Estrutura para armazenar variáveis
typedef struct {
    char name[20];
    int value;
} Variable;

Variable variables[MAX_VAR_COUNT];
int var_count = 0;

// Função para procurar ou criar uma variável
int* get_variable(char *name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return &variables[i].value;
        }
    }
    // Criar nova variável
    if (var_count < MAX_VAR_COUNT) {
        strcpy(variables[var_count].name, name);
        variables[var_count].value = 0;
        var_count++;
        return &variables[var_count - 1].value;
    }
    return NULL; // Erro: muitas variáveis
}

// Função para obter o valor de uma variável ou número
int get_value(char *token) {
    int value;

    // Se for um número, converte e retorna
    if (sscanf(token, "%d", &value) == 1) {
        return value;
    }

    // Caso contrário, tenta pegar o valor da variável
    int *var_ptr = get_variable(token);
    if (var_ptr) {
        return *var_ptr;
    }

    printf("Erro: Variável '%s' não encontrada\n", token);
    return 0;  // Retorna 0 se a variável não for encontrada (pode ser tratado de outra forma)
}

// Função para interpretar uma linha do código BASIC
void interpret_line(char *line) {
    char command[MAX_LINE_LENGTH];
    sscanf(line, "%s", command);
    int value1;  // Declaração de value1 no escopo correto

    // Comando PRINT
    if (strcmp(command, "PRINT") == 0) {
        char var[20];
        sscanf(line + 6, "%s", var);
        int *value = get_variable(var);
        if (value) {
            printf("%d\n", *value);
        } else {
            printf("Erro: Variável não encontrada\n");
        }
    }
    // Atribuição de variável com operação (ex: A = 5 + B)
    else if (strchr(line, '=') != NULL) {
        char var[20], token1[20], token2[20];
        char op;

        // Verifica se é uma operação com variáveis ou números
        if (sscanf(line, "%s = %s %c %s", var, token1, &op, token2) == 4) {
            int *var_ptr = get_variable(var);
            int value1 = get_value(token1);
            int value2 = get_value(token2);

            if (var_ptr) {
                switch (op) {
                    case '+':
                        *var_ptr = value1 + value2;
                        break;
                    case '-':
                        *var_ptr = value1 - value2;
                        break;
                    default:
                        printf("Erro: Operador desconhecido\n");
                        break;
                }
            } else {
                printf("Erro: Não foi possível criar variável\n");
            }
        }
        // Atribuição simples (ex: A = 5)
        else if (sscanf(line, "%s = %d", var, &value1) == 2) {
            int *var_ptr = get_variable(var);
            if (var_ptr) {
                *var_ptr = value1;
            } else {
                printf("Erro: Não foi possível criar variável\n");
            }
        } else {
            printf("Erro: Sintaxe de atribuição incorreta\n");
        }
    } else {
        printf("Erro: Comando desconhecido\n");
    }
}

// Função principal para ler o arquivo e interpretar linha por linha
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <arquivo_basic>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Erro: Não foi possível abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // Debug: exibir linha lida
        printf("Linha lida: %s", line);

        interpret_line(line);
    }

    fclose(file);
    return 0;
}
