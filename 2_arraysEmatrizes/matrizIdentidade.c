#include <stdio.h>

int main() {
    int identidade[3][3];

    // Criando matriz identidade
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                identidade[i][j] = 1; // diagonal principal = 1
            } else {
                identidade[i][j] = 0; // resto = 0
            }
            printf("%d ", identidade[i][j]);
        }
        printf("\n");
    }

    return 0;
}
