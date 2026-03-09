#include <stdio.h>

// função que recebe uma matriz 2x3
// m representa o endereço da primeira linha da matriz
void imprimirMatriz(int m[2][3]) {

    int *p;

    // p aponta para o primeiro elemento da matriz
    p = &m[0][0];

    printf("Elementos da matriz:\n");

    // loop para percorrer linhas
    for (int i = 0; i < 2; i++) {

        // loop para percorrer colunas
        for (int j = 0; j < 3; j++) {

            // cálculo da posição no vetor linear da memória
            // posição = (linha * numero_de_colunas) + coluna
            printf("%d ", *(p + (i * 3 + j)));

        }

        printf("\n");
    }
}

int main() {

    int matriz[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // passando a matriz para a função
    imprimirMatriz(matriz);

    return 0;
}