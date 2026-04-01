#include <stdio.h>    // Biblioteca para entrada e saída, como printf
#include <string.h>   // Biblioteca necessária para usar funções de string, como strcpy
#include <stdlib.h>   // Biblioteca necessária para usar malloc e free

// Define uma struct chamada Pessoa
// Essa struct possui:
// - um ponteiro para char chamado nome
// - um inteiro chamado idade
typedef struct {
    char* nome;   // Ponteiro para char, usado para armazenar uma string dinamicamente
    int idade;    // Idade da pessoa
} Pessoa;

// Função que recebe um ponteiro para struct Pessoa
// e exibe os dados armazenados nela
void exibirPessoa(Pessoa *p) {
    // Acessa os campos da struct usando ->
    // porque p é um ponteiro para struct
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
}

int main() {
    // Declara uma variável do tipo Pessoa
    Pessoa pessoa1;

    // Aloca dinamicamente memória para armazenar até 50 caracteres
    // sizeof(char) vale 1, mas foi mantido para deixar explícito
    pessoa1.nome = (char*)malloc(50 * sizeof(char));

    // Verifica se a alocação falhou
    // Se malloc falhar, ele retorna NULL
    if (pessoa1.nome == NULL) {
        return 1;
    }

    // ERRADO neste caso:
    // pessoa1.nome = "Ana Silva";
    //
    // Explicação:
    // a linha acima faria o ponteiro pessoa1.nome deixar de apontar
    // para a memória que foi alocada com malloc e passar a apontar
    // para a string literal "Ana Silva".
    //
    // Com isso:
    // 1) a memória alocada com malloc seria perdida (vazamento de memória)
    // 2) o espaço reservado dinamicamente deixaria de ser usado
    //
    // Como já foi feita uma alocação dinâmica, o correto é COPIAR
    // o conteúdo da string para dentro da memória alocada.

    // Copia a string "Ana Silva" para a região de memória apontada por pessoa1.nome
    // Agora a string fica armazenada dentro do bloco alocado com malloc
    strcpy(pessoa1.nome, "Ana Silva");

    // Atribui um valor ao campo idade da struct
    pessoa1.idade = 25;

    // Cria um ponteiro para struct Pessoa
    // ptr guarda o endereço de pessoa1
    Pessoa *ptr = &pessoa1;

    // Chama a função passando o ponteiro para a struct
    exibirPessoa(ptr);

    // Libera a memória alocada dinamicamente para o campo nome
    // Sempre que malloc for usado, o ideal é usar free ao final
    free(pessoa1.nome);

    // Retorna 0 indicando que o programa terminou corretamente
    return 0;
}