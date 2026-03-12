#include <stdio.h>

/*
FUNÇÃO 1
A matriz é recebida normalmente: int m[2][3]

Dentro da função criamos um ponteiro para int.
Esse ponteiro aponta para o primeiro elemento da matriz (m[0][0]).

A partir disso tratamos a matriz como um vetor linear de inteiros.
Por isso precisamos calcular manualmente a posição:
indice = linha * numero_de_colunas + coluna
*/
void imprimirMatriz1(int m[2][3]) {

    int *p = &m[0][0]; // ponteiro para o primeiro elemento da matriz

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {

            // acesso usando aritmética de ponteiros
            printf("%d ", *(p + (i * 3 + j)));

        }
        printf("\n");
    }
}


/*
FUNÇÃO 2
Aqui usamos um ponteiro diferente:

int (*p)[3]

Isso significa:
p é um ponteiro para um vetor de 3 inteiros
(ou seja, para uma linha da matriz).

Agora o compilador já sabe que cada linha tem 3 elementos,
então podemos acessar normalmente usando p[i][j].
*/
void imprimirMatriz2(int m[2][3]) {

    int (*p)[3] = m; // p aponta para a primeira linha da matriz

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {

            // acesso direto como se fosse matriz
            printf("%d ", p[i][j]);

        }
        printf("\n");
    }
}


/*
FUNÇÃO 3
Aqui a própria função já recebe um ponteiro para linha da matriz.

Parâmetro:
int (*p)[3]

Isso significa que quem chama a função deve passar uma matriz
que tenha 3 colunas.

Como o ponteiro já está no formato correto,
podemos acessar diretamente p[i][j].
*/
void imprimirMatriz3(int (*p)[3]) {

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {

            printf("%d ", p[i][j]);

        }
        printf("\n");
    }
}


int main() {

    // declaração da matriz 2x3
    int matriz[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    printf("Forma 1 (ponteiro para int):\n");
    imprimirMatriz1(matriz);

    printf("\nForma 2 (ponteiro para linha da matriz):\n");
    imprimirMatriz2(matriz);

    printf("\nForma 3 (ponteiro para linha recebido na funcao):\n");
    imprimirMatriz3(matriz);

    return 0;
}
