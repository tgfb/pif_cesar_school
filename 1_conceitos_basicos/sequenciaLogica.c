#include <stdio.h>

/*
Enunciado:
O programa deve ler dois números inteiros X e Y.
Em seguida, deve imprimir uma sequência de números de 1 até Y,
mostrando X números por linha, separados por espaço.

Para isso, deve-se utilizar um laço de repetição (for) que vai de 1 até Y.
A cada múltiplo de X, uma quebra de linha deve ser feita.

Restrições:
1 < X < 20
X < Y < 100000

A saída deve terminar exatamente no número Y.
*/

int main() {
    // Declaração das variáveis
    int X, Y;
    int i;

    // Leitura dos valores X e Y
    scanf("%d %d", &X, &Y);

    // Laço de repetição de 1 até Y
    for (i = 1; i <= Y; i++) {
        // Imprime o número atual
        printf("%d", i);

        // Se i for múltiplo de X, quebra a linha
        if (i % X == 0) {
            printf("\n");
        } else {
            // Caso contrário, imprime espaço
            printf(" ");
        }
    }

    return 0;
}
