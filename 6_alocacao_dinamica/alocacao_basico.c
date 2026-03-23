#include <stdio.h>
#include <stdlib.h>

int main() {
    int quantidade_elementos;  // inteiro para guardar a quantidade de elementos a ser alocada
    int *meu_array;            // ponteiro para o array de inteiros

    // Pede ao usuário para digitar o tamanho desejado
    printf("Digite a quantidade de elementos que deseja alocar: ");
    scanf("%d", &quantidade_elementos);

    // Validação de segurança: evita tentar alocar tamanho 0 ou negativo
    if (quantidade_elementos <= 0) {
        printf("Erro: A quantidade de elementos deve ser maior que zero.\n");
        return 1; // Encerra o programa com erro
    }

    printf("\nTentando alocar memória para %d inteiros...\n", quantidade_elementos);

    // Passo 1: Alocação Dinâmica com o tamanho escolhido pelo usuário
    meu_array = (int*) malloc(quantidade_elementos * sizeof(int));

    // Passo 2: Verificação se a memória foi realmente alocada
    if (meu_array == NULL) {
        printf("Erro crítico: Memória insuficiente!\n");
        return 1; 
    }

    printf("Memória alocada com sucesso!\n\n");

    // Passo 3: Utilização da Memória
    // O loop agora vai até a quantidade definida pelo usuário
    // preenchendo o array
    for (int i = 0; i < quantidade_elementos; i++) {
        meu_array[i] = (i + 1) * 10; 
    }
    // Imprimindo os valores do array (poderia estar dentro do loop anterior também).
    for (int i = 0; i < quantidade_elementos; i++) {
        printf("Posição %d: Valor %d\n", i, meu_array[i]);
    }

    // Passo 4: Liberação da Memória 
    free(meu_array);
    meu_array = NULL; 

    printf("\nMemória liberada corretamente. Fim do programa.\n");

    return 0;
}