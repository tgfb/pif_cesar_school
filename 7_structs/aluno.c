#include <stdio.h>

typedef struct Endereco
{
    char rua[50];
    int numero;
}Endereco;

typedef struct aluno
{
    char nome[50];
    int idade;
    Endereco end;
}Aluno;

int main(){
    Aluno vetor[2];
    for (int i = 0; i < 2; i++)
    {
        printf("Digite o nome do aluno \n");
        scanf("%s", vetor[i].nome);
        printf("Digite a idade do aluno \n");
        scanf("%d", &vetor[i].idade);
        printf("Digite o endereco do aluno \n");
        scanf("%s", vetor[i].end.rua);
        printf("Digite o numero do endereco do aluno \n");
        scanf("%d", &vetor[i].end.numero);
    }
    for (int i = 0; i < 2; i++)
    {
        printf("\nAluno %d:\n", i);
        printf("%s ", vetor[i].nome);
        printf("\n%d ", vetor[i].idade);
        printf("\n%s ,", vetor[i].end.rua);
        printf("%d", vetor[i].end.numero);
    }
    
}