#include <stdio.h>
#include <stdlib.h>

// Definimos uma enumeração para criar constantes nomeadas para os tipos.
// Isso torna o código mais legível do que usar números mágicos (0, 1, 2).
typedef enum {
    TIPO_INT,
    TIPO_FLOAT,
    TIPO_CHAR
} TipoDado;

// Função Genérica de Impressão
// Recebe: o ponteiro void, a quantidade de elementos e o tipo que está lá dentro.
void imprimir_array_generico(void *array, int quantidade, TipoDado tipo) {
    printf("[ ");

    for (int i = 0; i < quantidade; i++) {
        // Precisamos usar um switch para decidir como interpretar a memória.
        switch (tipo) {
            case TIPO_INT:
                // 1. Convertemos void* para int* : (int*)array
                // 2. Acessamos o índice [i]
                printf("%d", ((int*)array)[i]);
                break;
            
            case TIPO_FLOAT:
                // 1. Convertemos void* para float* : (float*)array
                // 2. Acessamos o índice [i]
                printf("%.2f", ((float*)array)[i]);
                break;

            case TIPO_CHAR:
                // 1. Convertemos void* para char* : (char*)array
                // 2. Acessamos o índice [i]
                printf("'%c'", ((char*)array)[i]);
                break;
        }

        // Apenas para formatar a vírgula entre os elementos
        if (i < quantidade - 1) {
            printf(", ");
        }
    }

    printf(" ]\n");
}

int main() {
    int qtd = 4;

    // ---------------------------------------------------------
    // Cenário 1: Array Dinâmico de Inteiros
    // ---------------------------------------------------------
    int *dados_int = (int*) malloc(qtd * sizeof(int));
    if (dados_int == NULL) return 1; // Verificação simples de segurança

    for (int i = 0; i < qtd; i++) {
        dados_int[i] = i * 10;
    }

    printf("Imprimindo array de inteiros:\n");
    // Chamamos a função passando o ponteiro de int e a flag TIPO_INT
    imprimir_array_generico(dados_int, qtd, TIPO_INT);
    printf("\n");


    // ---------------------------------------------------------
    // Cenário 2: Array Dinâmico de Floats
    // ---------------------------------------------------------
    float *dados_float = (float*) malloc(qtd * sizeof(float));
    if (dados_float == NULL) return 1;

    dados_float[0] = 1.5f;
    dados_float[1] = 2.75f;
    dados_float[2] = 3.1415f;
    dados_float[3] = 10.0f;

    printf("Imprimindo array de floats:\n");
    // Chamamos a MESMA função, mas agora passando o ponteiro de float e TIPO_FLOAT
    imprimir_array_generico(dados_float, qtd, TIPO_FLOAT);
    printf("\n");


    // ---------------------------------------------------------
    // Cenário 3: Array Dinâmico de Chars (String manual)
    // ---------------------------------------------------------
    char *dados_char = (char*) malloc(qtd * sizeof(char));
    if (dados_char == NULL) return 1;

    dados_char[0] = 'C';
    dados_char[1] = 'o';
    dados_char[2] = 'd';
    dados_char[3] = 'e';

    printf("Imprimindo array de chars:\n");
    imprimir_array_generico(dados_char, qtd, TIPO_CHAR);


    // Liberação de memória
    free(dados_int);
    free(dados_float);
    free(dados_char);

    return 0;
}