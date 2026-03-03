#include <stdio.h>

// Enunciado:
// Crie uma função que recebe uma matriz de inteiros de 3 linhas e 5 colunas 
// e verifica, para cada linha, se existe pelo menos um par de elementos consecutivos iguais. 
// A função deve preencher um vetor de resultados com 1 se a linha possuir tais elementos 
// consecutivos iguais ou 0 caso contrário. Por fim, exiba o vetor resultado.

void verificarBlocos(int matriz[3][5], int linhas, int colunas, int resultado[]) {
    // Percorre cada linha da matriz
    for (int i = 0; i < linhas; i++) {
        resultado[i] = 0;  // Inicializa o vetor resultado na posição i com 0
                           // assumindo que não há elementos consecutivos iguais

        // Percorre cada coluna da linha, exceto a última
        for (int j = 0; j < colunas-1; j++) {
            // Verifica se o elemento atual é igual ao próximo na mesma linha
            if(matriz[i][j] == matriz[i][j+1]){
                resultado[i] = 1;  // Marca 1 se encontrar elementos consecutivos iguais
                break;             // Para de verificar a linha, já encontrou um par
            }
        }
    }

    // Exibe o vetor resultado na tela
    printf("Vetor resultado:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", resultado[i]); // Imprime cada elemento do vetor resultado
    }
    printf("\n"); // Quebra de linha no final da impressão
}

int main() {
    // Declara e inicializa uma matriz de 3 linhas e 5 colunas
    int matriz[3][5] = { 
        {1, 1, 2, 3, 4}, // Linha 0 tem elementos consecutivos iguais (1,1)
        {5, 6, 7, 8, 9}, // Linha 1 não tem elementos consecutivos iguais
        {2, 2, 2, 3, 3}  // Linha 2 tem elementos consecutivos iguais (2,2 e 3,3)
    };

    int resultado[3]; // Vetor que armazenará o resultado de cada linha

    // Chama a função para verificar a matriz e preencher o vetor resultado
    verificarBlocos(matriz, 3, 5, resultado);

    return 0; // Finaliza o programa
}