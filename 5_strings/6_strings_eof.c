#include <stdio.h>

int main() {
    int c; // IMPORTANTE: Usamos int, nao char, para comportar o valor de EOF (-1)

    printf("Digite um texto livre. Para encerrar o fluxo (EOF):\n");
    printf("- No Windows: Pressione Ctrl + Z e depois Enter\n");
    printf("- No Linux/Mac: Pressione Ctrl + D\n\n");

    // O loop continua ate que o sinal de fim de arquivo seja detectado
    while ((c = getchar()) != EOF) {
        // Exemplo: so imprime se nao for espaco
        if (c != ' ') {
            putchar(c);
        }
    }

    printf("\n\nFluxo encerrado. O programa detectou o sinal EOF.\n");

    return 0;
}