#include <stdio.h>    // Biblioteca padrão de entrada e saída
#include <string.h>   // Biblioteca necessária para usar a função strcpy

// Definição de um novo tipo chamado Livro a partir de uma struct
// Essa struct representa um livro com título, autor, gênero e identificador
typedef struct Livro {
    char titulo[50];   // Vetor de caracteres para armazenar o título do livro
    char autor[50];    // Vetor de caracteres para armazenar o nome do autor
    char genero[25];   // Vetor de caracteres para armazenar o gênero do livro
    int livro_id;      // Campo inteiro para armazenar o identificador do livro
} Livro;               // "Livro" passa a ser um apelido para "struct Livro"

int main(int argc, char const *argv[])
{
    // Declaração de duas variáveis do tipo Livro
    // Cada uma representa um livro diferente
    Livro livro1;
    Livro livro2;

    // Copia a string "O Senhor dos Aneis" para o campo titulo de livro1
    // strcpy é usada para copiar strings para vetores de char
    strcpy(livro1.titulo, "O Senhor dos Aneis");

    // Copia o nome do autor para o campo autor de livro1
    strcpy(livro1.autor, "Tolkien");

    // Copia o gênero do livro para o campo genero de livro1
    strcpy(livro1.genero, "Fantasia");

    // Atribui o identificador numérico ao livro1
    livro1.livro_id = 100;

    // Copia o título do segundo livro para o campo titulo de livro2
    strcpy(livro2.titulo, "Guia do mochileiro das galaxias");

    // Copia o nome do autor para o campo autor de livro2
    strcpy(livro2.autor, "Douglas Adams");

    // Copia o gênero do segundo livro para o campo genero de livro2
    strcpy(livro2.genero, "Ficção cientifica");

    // Atribui o identificador numérico ao livro2
    livro2.livro_id = 101;

    // Neste ponto, os dois livros já estão preenchidos com dados
    // O programa, porém, não exibe nenhuma informação na tela

    // Retorna 0 para indicar que o programa foi finalizado com sucesso
    return 0;
}