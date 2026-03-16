#include <stdio.h>
#include <string.h> // Essencial para strlen e strcpy

int main() {
    // 1. Declaração e Inicialização
    // O C adiciona o '\0' (nulo) automaticamente ao final de aspas duplas
    char origem[] = "C e Incrivel"; 
    
    // 2. Capacidade vs. Conteúdo
    // Reservamos 50 espaços, mas só usaremos alguns
    char destino[50]; 
    
    // 3. Medindo a String (strlen)
    // strlen conta os caracteres ATÉ o '\0', sem incluir o nulo.
    int tamanho = strlen(origem);
    
    printf("String original: %s\n", origem);
    printf("Quantidade de caracteres (strlen): %d\n", tamanho);
    printf("Espaco total no array (sizeof): %zu bytes\n", sizeof(origem));

    // 4. Copiando Strings (strcpy)
    // Nunca faça 'destino = origem'! Em C, usamos strcpy(destino, fonte)
    strcpy(destino, origem);
    printf("Copia realizada no destino: %s\n", destino);

    // 5. O poder do caractere nulo '\0'
    // Se inserirmos um nulo no meio, as funções de C acham que a string acabou ali
    destino[1] = '\0'; 
    printf("Destino apos alterar o indice [1] para '\\0': %s\n", destino);

    return 0;
}