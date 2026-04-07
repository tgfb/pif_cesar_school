#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;
};

// Função que retorna endereço de struct
struct Pessoa* cria_pessoa(char *nome, int idade) {
    struct Pessoa *p = (struct Pessoa*) malloc(sizeof(struct Pessoa));
    if (p != NULL) {
        strcpy(p->nome, nome);
        p->idade = idade;
    }
    return p;
}

int main() {
    struct Pessoa *p1 = cria_pessoa("Carlos", 30);

    if (p1 != NULL) {
        printf("Nome: %s\n", p1->nome);
        printf("Idade: %d\n", p1->idade);
        free(p1);
    }

    return 0;
}