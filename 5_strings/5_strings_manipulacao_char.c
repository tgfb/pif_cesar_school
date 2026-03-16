#include <stdio.h>

int main() {
    char frase[] = "C-Prog 2026!";
    printf("Original: %s\n\n", frase);

    printf("Analise caractere por caractere:\n");
    for (int i = 0; frase[i] != '\0'; i++) {
        char c = frase[i];

        // 1. Transformar Minúsculas em Maiúsculas
        // Na ASCII: 'a' e 97, 'A' e 65. A diferenca e sempre 32.
        if (c >= 'a' && c <= 'z') {
            frase[i] = c - 32; 
        }

        // 2. Identificar tipos de caracteres usando intervalos ASCII
        printf("'%c' (ASCII %3d) -> ", c, c);
        
        if (c >= '0' && c <= '9') {
            printf("Digito Numerico\n");
        } else if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
            printf("Letra do Alfabeto\n");
        } else {
            printf("Simbolo ou Especial\n");
        }
    }

    printf("\nResultado Final: %s\n", frase);

    // 3. Exemplo de "Criptografia" simples (Cifra de Cesar +1)
    char segredo[] = "IBM"; // 'I'+1 = 'J', 'B'+1 = 'C', 'M'+1 = 'N' -> HAL invertido? Nao, JCN.
    for(int i = 0; segredo[i] != '\0'; i++) {
        segredo[i] = segredo[i] + 1;
    }
    printf("Segredo (+1 ASCII): %s\n", segredo);

    return 0;
}