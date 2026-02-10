#include <stdio.h>

int main() {
    // Declaração das variáveis do tipo double
    double raio, area;
    double pi = 3.14159;

    // Leitura do valor do raio
    scanf("%lf", &raio);

    // Cálculo da área da circunferência
    // area = pi * raio ao quadrado
    area = pi * raio * raio;

    // Impressão do resultado com 4 casas decimais
    printf("A=%.4lf\n", area);

    return 0;
}
