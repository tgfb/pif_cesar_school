#include <stdio.h>

void modificar(char *s) {
    s[0] = 'T'; // O erro acontece aqui!
}

int main() {
    // FORMA 1: Array (Segura para modificação)
    // O C copia "C-Prog" para dentro do espaço reservado na pilha (stack)
    char como_array[] = "C-Prog";
    
    // FORMA 2: Ponteiro para Literal (PERIGOSA)
    // O ponteiro 'como_ponteiro' aponta direto para a memória do executável
    // onde as constantes de texto ficam guardadas (área somente leitura)
    char *como_ponteiro = "C-Prog";

    printf("Tentando modificar o array...\n");
    modificar(como_array); // Funciona perfeitamente
    printf("Sucesso: %s\n", como_array);

    printf("\nTentando modificar o ponteiro literal...\n");
    printf("(O programa vai travar agora!)\n");
    
    // Descomente a linha abaixo para demonstrar o erro:
    // modificar(como_ponteiro); 

    return 0;
}