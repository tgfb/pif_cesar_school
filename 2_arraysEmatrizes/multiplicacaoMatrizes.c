#include <stdio.h>

/*
Enunciado:
Leia duas matrizes 2x2 de inteiros e calcule a matriz resultante da multiplicação.
*/

int main() {
    int A[2][2], B[2][2], C[2][2];
    int i, j, k;

    // Leitura da matriz A
    for (i = 0; i < 2; i++) {          // Percorre as linhas da matriz A
        for (j = 0; j < 2; j++) {      // Percorre as colunas da matriz A
            scanf("%d", &A[i][j]);
        }
    }

    // Leitura da matriz B
    for (i = 0; i < 2; i++) {          // Percorre as linhas da matriz B
        for (j = 0; j < 2; j++) {      // Percorre as colunas da matriz B
            scanf("%d", &B[i][j]);
        }
    }

    // Inicialização da matriz C com zero
    for (i = 0; i < 2; i++) {          // Percorre as linhas da matriz C
        for (j = 0; j < 2; j++) {      // Percorre as colunas da matriz C
            C[i][j] = 0;               // Inicializa cada elemento como 0
        }
    }

    // Multiplicação das matrizes A e B
    for (i = 0; i < 2; i++) {          // Percorre as linhas da matriz C (resultado)
        for (j = 0; j < 2; j++) {      // Percorre as colunas da matriz C
            for (k = 0; k < 2; k++) {  // Realiza a soma dos produtos para C[i][j]
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Impressão da matriz resultante
    for (i = 0; i < 2; i++) {          // Percorre as linhas da matriz C
        for (j = 0; j < 2; j++) {      // Percorre as colunas da matriz C
            printf("%d ", C[i][j]);    // Imprime cada elemento
        }
        printf("\n");                   // Quebra de linha ao final de cada linha
    }

    return 0;
}
