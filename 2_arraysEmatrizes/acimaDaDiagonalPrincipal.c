#include <stdio.h>

/*
Enunciado:
Leia um caractere maiúsculo O ('S' ou 'M') indicando a operação
(Soma ou Média), e uma matriz M[12][12] de valores de ponto flutuante.
Calcule a soma ou a média dos elementos que estão acima da diagonal principal
(ou seja, elementos onde a coluna é maior que a linha: j > i).
Imprima o resultado com 1 casa decimal.
*/

int main() {
    char operacao;
    double M[12][12];
    int i, j;
    double soma = 0.0;
    int count = 0;

    // Leitura da operação
    scanf(" %c", &operacao);

    // Leitura da matriz 12x12
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }

    // Somar os elementos acima da diagonal principal
    for (i = 0; i < 12; i++) {
        for (j = i + 1; j < 12; j++) {  // j > i garante que é acima da diagonal
            soma += M[i][j];
            count++;
        }
    }

    // Verifica se deve calcular média
    if (operacao == 'M') {
        soma = soma / count;
    }

    // Impressão do resultado com 1 casa decimal
    printf("%.1lf\n", soma);

    return 0;
}
