#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

void exibirPessoa(Pessoa *p) {
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
}

int main() {
    Pessoa pessoa1;

    strcpy(pessoa1.nome, "Ana");
    pessoa1.idade = 25;

    Pessoa *ptr = &pessoa1;

    exibirPessoa(ptr);

    return 0;
}