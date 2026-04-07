#include <stdio.h>
#include <string.h>

// Definindo o enum
typedef enum EstadoCivil {
    SOLTEIRO,
    CASADO,
    DIVORCIADO
} EstadoCivil;

// Definindo a struct
struct Pessoa {
    char nome[50];
    int idade;
    EstadoCivil estado;
};

char* estadoParaTexto(EstadoCivil estado) {
    switch(estado) {
        case SOLTEIRO: return "Solteiro";
        case CASADO: return "Casado";
        case DIVORCIADO: return "Divorciado";
        default: return "Desconhecido";
    }
}

int main() {
    struct Pessoa p1;

    // Atribuindo valores
    strcpy(p1.nome, "João");
    p1.idade = 30;
    p1.estado = CASADO;

    // Exibindo
    printf("Nome: %s\n", p1.nome);
    printf("Idade: %d\n", p1.idade);
    printf("Estado civil (numero): %d\n", p1.estado);
    printf("Estado civil: %s\n", estadoParaTexto(p1.estado));

    return 0;
}