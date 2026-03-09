#include <stdio.h>

// função que troca valores entre duas variáveis
void trocar(int *a, int *b) {

    int temp;

    temp = *a;   // guarda valor apontado por a
    *a = *b;     // valor de b vai para a
    *b = temp;   // valor antigo de a vai para b

}

int main() {

    int x = 10;
    int y = 20;

    printf("Antes da troca:\n");
    printf("x = %d, y = %d\n", x, y);

    // passamos os endereços das variáveis
    trocar(&x, &y);

    printf("Depois da troca:\n");
    printf("x = %d, y = %d\n", x, y);

    return 0;
}