#include <stdio.h>
#include <stdlib.h>

// ==========================================
// FUNÇÕES QUE RECEBEM A MATRIZ DINÂMICA
// ==========================================

// Função para preencher a matriz com valores
// Recebe o ponteiro duplo (int **), a quantidade de linhas e colunas
void preencher_matriz(int **matriz, int linhas, int colunas) {
    printf("Preenchendo a matriz...\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            // Preenchemos com uma lógica simples (ex: soma dos índices)
            matriz[i][j] = (i + 1) * 10 + (j + 1); 
        }
    }
}

// Função para imprimir a matriz na tela de forma formatada
void imprimir_matriz(int **matriz, int linhas, int colunas) {
    printf("\nConteúdo da Matriz (%d x %d):\n", linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            // O %4d garante que cada número ocupe 4 espaços, alinhando as colunas
            printf("%4d ", matriz[i][j]); 
        }
        printf("\n"); // Pula de linha ao terminar as colunas
    }
    printf("\n");
}


// ==========================================
// PROGRAMA PRINCIPAL
// ==========================================
int main() {
    int linhas = 3;
    int colunas = 5;
    
    // Declaramos nosso ponteiro duplo
    int **minha_matriz; 

    // 1. Alocação (usando o método padrão de array de ponteiros)
    minha_matriz = (int**) malloc(linhas * sizeof(int*));
    if (minha_matriz == NULL) return 1;

    for (int i = 0; i < linhas; i++) {
        minha_matriz[i] = (int*) malloc(colunas * sizeof(int));
        if (minha_matriz[i] == NULL) return 1;
    }

    // 2. Chamando as funções
    // Basta passar o nome da variável 'minha_matriz', que já é um 'int **'
    preencher_matriz(minha_matriz, linhas, colunas);
    
    imprimir_matriz(minha_matriz, linhas, colunas);

    // 3. Liberação da memória
    for (int i = 0; i < linhas; i++) {
        free(minha_matriz[i]);
    }
    free(minha_matriz);
    minha_matriz = NULL;

    printf("Memória liberada e programa encerrado com sucesso.\n");

    return 0;
}