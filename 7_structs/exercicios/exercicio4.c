#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
    char nome[50];
    int idade;
}Pessoa;

Pessoa* cria_pessoa(char* nome, int idade, Pessoa* p){
    p->idade = idade;
    strcpy(p->nome, nome);
    return p;
}

int main(){
    Pessoa p1;
    Pessoa *p = cria_pessoa("fulano", 20, &p1);
    printf("%p\n", p);
    printf("%p", &p1);
}