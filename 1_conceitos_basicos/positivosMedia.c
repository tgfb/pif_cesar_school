#include <stdio.h>

/*
Enunciado:
Leia 6 valores numéricos (inteiros ou de ponto flutuante).
Em seguida, mostre quantos destes valores digitados são positivos.
Na próxima linha, mostre a média de todos os valores positivos digitados,
com um dígito após o ponto decimal.

Observação:
Pelo menos um dos valores informados será positivo.
*/

int main() {
    // Declaração das variáveis
    double valor, soma = 0.0;
    int positivos = 0;
    int i;

    // Leitura dos 6 valores
    for (i = 0; i < 6; i++) {
        scanf("%lf", &valor);

        // Verifica se o valor é positivo
        if (valor > 0) {
            soma = soma + valor;
            positivos++;
        }
    }

    // Impressão da quantidade de valores positivos
    printf("%d valores positivos\n", positivos);

    // Impressão da média dos valores positivos
    printf("%.1lf\n", soma / positivos);

    return 0;
}
