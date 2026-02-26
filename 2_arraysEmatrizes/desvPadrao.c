// Faça um programa que calcule o desvio padrão de um vetor v
// contendo n = 10 numeros, onde m e a media do vetor.

// Desvio padrão é igual à raiz quadrada
// da soma dos quadrados de cada valor menos
// a média da população, dividida pelo número total de valores.
// ou veja a formula que está neste repositorio (desvPadrao.png)

#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    int n = 10;
    double v[n];
    double media, soma = 0.0, somatorio = 0.0;

    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &v[i]);
    }

    for (int i = 0; i < n; i++)
    {
        soma += v[i];
    }
    media = soma/n;
    
    for (int i = 0; i < n; i++)
    {
        somatorio += pow(v[i]-media, 2);
    }

    double desv = sqrt( (1.0/(n-1)) * somatorio);
    
    printf("%.4lf", desv);

    return 0;
}
