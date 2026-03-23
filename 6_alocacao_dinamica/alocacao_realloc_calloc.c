#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho_inicial = 3;
    int novo_tamanho;
    int *meu_array;
    int *ponteiro_temporario;

    // Passo 1: Alocação inicial com calloc
    printf("Alocando inicialmente espaço para %d inteiros...\n", tamanho_inicial);
    
    // =========================================================================
    // DIFERENÇAS ENTRE MALLOC E CALLOC:
    // 1. Sintaxe: O malloc recebe apenas o tamanho total em bytes (ex: 3 * sizeof(int)). 
    //    O calloc recebe dois parâmetros: a quantidade de elementos e o tamanho de cada um.
    // 2. Inicialização (A mais importante!): O malloc apenas reserva a memória, deixando
    //    "lixo" (valores aleatórios antigos) lá dentro. O calloc percorre toda a
    //    memória alocada e "zera" tudo (preenche com zeros).
    // =========================================================================
    meu_array = (int*) calloc(tamanho_inicial, sizeof(int));

    if (meu_array == NULL) {
        printf("Erro na alocação inicial!\n");
        return 1;
    }

    // Comprovando o benefício do calloc: os valores já vêm zerados!
    printf("\nValores no array logo após o calloc (note que não há lixo de memória):\n");
    for (int i = 0; i < tamanho_inicial; i++) {
        printf("Posição %d: Valor %d\n", i, meu_array[i]);
    }

    // Preenchendo os dados para podermos testar o realloc
    printf("\nSubstituindo os zeros por valores...\n");
    for (int i = 0; i < tamanho_inicial; i++) {
        meu_array[i] = (i + 1) * 10;
        printf("Posição %d: Novo valor %d\n", i, meu_array[i]);
    }

    // Passo 2: Definindo o novo tamanho
    printf("\nO array está cheio! Digite o novo tamanho total desejado (maior que %d): ", tamanho_inicial);
    scanf("%d", &novo_tamanho);

    if (novo_tamanho <= tamanho_inicial) {
        printf("O novo tamanho deve ser maior que o inicial para este exemplo.\n");
        free(meu_array); 
        return 1;
    }

    // Passo 3: O uso do realloc (O realloc NÃO zera a nova memória, ele age como o malloc)
    printf("\nRedimensionando o array para %d inteiros...\n", novo_tamanho);
    ponteiro_temporario = (int*) realloc(meu_array, novo_tamanho * sizeof(int));

    if (ponteiro_temporario == NULL) {
        printf("Erro: Não foi possível redimensionar a memória!\n");
        free(meu_array); 
        return 1;
    }

    meu_array = ponteiro_temporario;

    // Passo 4: Utilizando o espaço novo
    for (int i = tamanho_inicial; i < novo_tamanho; i++) {
        meu_array[i] = (i + 1) * 10;
    }

    printf("\nArray redimensionado com sucesso. Mostrando todos os dados:\n");
    for (int i = 0; i < novo_tamanho; i++) {
        printf("Posição %d: Valor %d\n", i, meu_array[i]);
    }

    // Passo 5: Liberação da memória
    free(meu_array);
    meu_array = NULL;

    printf("\nMemória liberada. Fim do programa.\n");

    return 0;
}