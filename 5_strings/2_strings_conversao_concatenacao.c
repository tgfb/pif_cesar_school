#include <stdio.h>
#include <stdlib.h> // Para atoi, atof, atol
#include <string.h> // Para strncat, strlen

int main() {
    // --- PARTE 1: CONVERSÕES (String para Número) ---
    char str_int[] = "42";
    char str_float[] = "3.1415";
    char str_long[] = "2147483647";

    int v_int = atoi(str_int);       // String para Integer
    double v_float = atof(str_float); // String para Float/Double
    long v_long = atol(str_long);    // String para Long

    printf("Inteiro: %d | Double: %.4f | Long: %ld\n", v_int, v_float, v_long);

    // --- PARTE 2: CONVERSÃO (Número para String) ---
    // Em C moderno, usamos sprintf para "imprimir" um número dentro de um array de char
    char str_resultado[100];
    float nota = 9.5;
    sprintf(str_resultado, "A nota final e: %.1f", nota);
    printf("Resultado do sprintf: %s\n", str_resultado);

    // --- PARTE 3: CONCATENAÇÃO SEGURA (strncat) ---
    char saudacao[30] = "Ola, ";
    char nome[] = "Professor Aluno de Programacao C";

    /* strncat(destino, origem, n)
       'n' deve ser o espaço restante no destino para não invadir memória alheia.
       Calculamos: Tamanho Total (30) - O que já tem lá (strlen) - 1 (para o \0)
    */
    int espaco_livre = sizeof(saudacao) - strlen(saudacao) - 1;

    strncat(saudacao, nome, espaco_livre);

    printf("Saudacao (truncada se necessario): %s\n", saudacao);

    return 0;
}