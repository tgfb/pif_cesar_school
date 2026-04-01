#include <stdio.h>    // Biblioteca para entrada e saída, como printf
#include <string.h>   // Biblioteca necessária para usar a função strcpy

// Define uma struct para representar um aluno
typedef struct {
    char nome[50];   // Vetor de caracteres para armazenar o nome do aluno
    int idade;       // Campo para armazenar a idade do aluno
    float nota;      // Campo para armazenar a nota do aluno
} Aluno;

int main() {
    // Declara um vetor de 3 posições, em que cada posição armazena uma struct Aluno
    Aluno turma[3];

    // Preenche os dados do primeiro aluno
    strcpy(turma[0].nome, "Ana");
    turma[0].idade = 20;
    turma[0].nota = 8.5;

    // Preenche os dados do segundo aluno
    strcpy(turma[1].nome, "Bruno");
    turma[1].idade = 22;
    turma[1].nota = 7.8;

    // Preenche os dados do terceiro aluno
    strcpy(turma[2].nome, "Carla");
    turma[2].idade = 19;
    turma[2].nota = 9.2;

    // Percorre o vetor de structs usando um laço for
    // A variável i representa o índice de cada aluno no vetor
    for (int i = 0; i < 3; i++) {
        // Exibe o número do aluno atual
        printf("Aluno %d\n", i + 1);

        // Exibe o nome do aluno armazenado na posição i do vetor
        printf("Nome: %s\n", turma[i].nome);

        // Exibe a idade do aluno armazenado na posição i do vetor
        printf("Idade: %d\n", turma[i].idade);

        // Exibe a nota do aluno armazenado na posição i do vetor
        printf("Nota: %.1f\n\n", turma[i].nota);
    }

    // Retorna 0 para indicar que o programa terminou corretamente
    return 0;
}