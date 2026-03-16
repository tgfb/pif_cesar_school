#include <stdio.h>
#include <string.h>

int main() {
    char senha_mestra[] = "C_e_Vida_2026";
    char senha_usuario[20];
    int autenticado = 0; // Variável de controle (0 = falso, 1 = verdadeiro)

    printf("--- SISTEMA DE ACESSO RESTRITO ---\n");

    // O loop continuará enquanto 'autenticado' for igual a 0
    while (!autenticado) {
        printf("\nDigite sua senha: ");

        // 1. Leitura segura
        if (fgets(senha_usuario, sizeof(senha_usuario), stdin)) {
            
            // 2. Remoção do '\n' (caractere de nova linha do Enter)
            senha_usuario[strcspn(senha_usuario, "\n")] = '\0';

            // 3. Comparação: strcmp retorna 0 se forem IGUAIS
            if (strcmp(senha_usuario, senha_mestra) == 0) {
                printf("[SUCESSO] Senha correta! Acessando o sistema...\n");
                autenticado = 1; // Altera a variável para sair do loop
            } else {
                printf("[ERRO] Senha incorreta. Tente novamente.\n");
                
                // Dica: se o usuário digitou algo muito longo, o buffer do teclado
                // pode ter sobras. Uma forma simples de limpar o buffer 'stdin':
                // while(getchar() != '\n'); // Opcional para robustez extrema
            }
        }
    }

    printf("\nBem-vindo, Professor! O programa continuara daqui...\n");

    return 0;
}