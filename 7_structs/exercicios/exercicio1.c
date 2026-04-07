#include <stdio.h>
#include <stdlib.h>

struct Vetor {
    int *valores;
    int tamanho;
};

int main() {
    struct Vetor v;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &v.tamanho);

    // Alocação dinâmica
    v.valores = (int*) malloc(v.tamanho * sizeof(int));
    if (v.valores == NULL) {
        printf("Erro de alocação!\n");
        return 1;
    }

    // Preenchendo valores
    for(int i = 0; i < v.tamanho; i++) {
        printf("Digite o valor %d: ", i);
        scanf("%d", &v.valores[i]);
    }

    // Imprimindo valores
    printf("Valores do vetor: ");
    for(int i = 0; i < v.tamanho; i++) {
        printf("%d ", v.valores[i]);
    }
    printf("\n");

    // Liberando memória
    free(v.valores);

    return 0;
}