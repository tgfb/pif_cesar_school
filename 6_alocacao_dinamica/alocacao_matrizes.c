#include <stdio.h>
#include <stdlib.h>

int main() {
    int linhas = 3;
    int colunas = 4;
    int **matriz; // Um ponteiro que aponta para outros ponteiros

    printf("--- Alocando a Matriz Dinâmica ---\n\n");

    // Passo 1: Alocar o array principal (o array de ponteiros para as linhas)
    // sizeof(int*) porque este array vai guardar endereços de memória, não números.
    // IMPORTANTE: Esse passo nao aloca as linhas da matriz, aloca um array de ponteiros
    // para as linhas.
    matriz = (int**) malloc(linhas * sizeof(int*));
    
    if (matriz == NULL) {
        printf("Erro ao alocar o array de ponteiros.\n");
        return 1;
    }

    // Passo 2: Alocar cada linha (os arrays de inteiros reais)
    for (int i = 0; i < linhas; i++) {
        // Para cada ponteiro do array principal, alocamos espaço para 'colunas' inteiros
        // IMPORTANTE: Esse passo nao aloca uma coluna da matriz, aloca cada linha
        // que tem como tamanho a quantidade de colunas da matriz.
        matriz[i] = (int*) malloc(colunas * sizeof(int));
        
        if (matriz[i] == NULL) {
            printf("Erro ao alocar a linha %d.\n", i);
            return 1;
        }
    }

    // --- ANALISANDO A TOPOLOGIA DA MEMÓRIA ---
    printf("1. Onde está a variável 'matriz'?\n");
    printf("   Endereço de &matriz: %p\n", (void*)&matriz);
    printf("   Para onde ela aponta (o array de %d ponteiros): %p\n\n", linhas, (void*)matriz);

    printf("2. Endereços das Linhas e seus Elementos:\n");
    for (int i = 0; i < linhas; i++) {
        // &matriz[i] é ONDE o ponteiro está guardado
        // matriz[i] é PARA ONDE o ponteiro aponta (o início dos dados da linha)
        printf("\n=> LINHA %d (Ponteiro guardado em %p):\n", i, (void*)&matriz[i]);
        printf("   A linha %d começa no endereço: %p\n", i, (void*)matriz[i]);
        
        // Imprimindo o endereço de cada elemento (coluna) dentro da linha
        for (int j = 0; j < colunas; j++) {
            // Os elementos de uma MESMA linha são vizinhos na memória (contíguos)
            // A diferença de endereço entre eles será de exatamente 4 bytes (tamanho de um int)
            printf("      Elemento [%d][%d] -> Endereço: %p\n", i, j, (void*)&matriz[i][j]);
        }
    }

    // Passo 3: Liberação da Memória (A Ordem Importa!)
    // Você DEVE liberar de dentro para fora. Se liberar 'matriz' primeiro, 
    // você perde os endereços das linhas e causa um memory leak colossal.
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]); // Libera cada array de inteiros (as linhas)
    }
    free(matriz); // Por fim, libera o array de ponteiros
    matriz = NULL;

    printf("\n\nMemória da matriz liberada com sucesso.\n");

    return 0;
}