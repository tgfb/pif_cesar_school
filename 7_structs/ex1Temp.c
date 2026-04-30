#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
    char nome[50];
    int idade;
}Pessoa;

Pessoa* cria_pessoa(char* nome, int idade, Pessoa *p){
    p->idade = idade;
    strcpy(p->nome, nome);
    return p;
}

int main(){
    Pessoa p;
    Pessoa *pt = cria_pessoa("Fulano", 20, &p);
    printf("%p\n%p", &p, pt);
}