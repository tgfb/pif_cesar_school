#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;
};

int main() {
    struct Pessoa *p;

    // Alocação dinâmica
    p = (struct Pessoa*) malloc(sizeof(struct Pessoa));
    if (p == NULL) {
        printf("Erro de alocação!\n");
        return 1;
    }

    // Preenchendo dados
    printf("Digite o nome: ");
    scanf("%s", p->nome);
    printf("Digite a idade: ");
    scanf("%d", &p->idade);

    // Imprimindo dados
    printf("\nNome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);

    free(p);
    return 0;
}