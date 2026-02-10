#include <stdio.h>

/*
Enunciado:
Leia um valor N, que será o tamanho de um vetor X[N].
Em seguida, leia cada valor do vetor.
O programa deve encontrar o menor valor do vetor e sua posição,
e mostrar essas informações.

Entrada:
- Primeira linha: inteiro N (1 < N < 1000)
- Segunda linha: N valores inteiros separados por espaço

Saída:
- Primeira linha: "Menor valor: " seguido do menor valor
- Segunda linha: "Posicao: " seguido da posição do menor valor
O vetor inicia na posição zero.
*/

int main() {
    int N;
    scanf("%d", &N);  // Leitura do tamanho do vetor

    int X[N];          // Declaração do vetor
    int i;

    // Leitura dos elementos do vetor
    for (i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }

    // Inicializa menor valor e posição
    int menor = X[0];
    int posicao = 0;

    // Procura o menor valor e sua posição
    for (i = 1; i < N; i++) {
        if (X[i] < menor) {
            menor = X[i];
            posicao = i;
        }
    }

    // Impressão do resultado
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    return 0;
}
