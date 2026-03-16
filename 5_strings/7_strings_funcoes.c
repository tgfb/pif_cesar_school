#include <stdio.h>
#include <string.h>
#include <ctype.h> // Para toupper()

// Protótipo da função
// Recebe um ponteiro para char (string) e retorna o mesmo ponteiro
char* formatar_nome(char nome[]) {
    // 1. Transformar tudo em MAIÚSCULO
    for (int i = 0; nome[i] != '\0'; i++) {
        nome[i] = toupper(nome[i]);
    }

    // Retornamos o endereço inicial da string formatada
    return nome;
}

// Função que conta vogais (Passagem apenas para leitura)
int contar_vogais(const char *str) {
    int contador = 0;
    char c;

    for (int i = 0; str[i] != '\0'; i++) {
        c = tolower(str[i]); // Trabalha com minúscula para facilitar
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
    }
    return contador;
}

int main() {
    char usuario[50];

    printf("Digite seu nome completo: ");
    fgets(usuario, sizeof(usuario), stdin);
    usuario[strcspn(usuario, "\n")] = '\0'; // Limpeza do \n

    // Chamada da função que retorna um int
    int vogais = contar_vogais(usuario);

    // Chamada da função que retorna uma string (char*)
    // Note que a função altera a variável 'usuario' original (passagem por referência)
    char *nome_maiusculo = formatar_nome(usuario);

    printf("\n--- RESULTADO DO PROCESSAMENTO ---\n");
    printf("Nome Formatado: %s\n", nome_maiusculo);
    printf("Total de Vogais: %d\n", vogais);
    printf("Confirmacao da variavel original: %s\n", usuario);

    return 0;
}