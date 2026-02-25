#include <stdio.h>

/* ============================================================================
 * 1. PROTÓTIPOS DAS FUNÇÕES
 * ============================================================================ */
// Quando passamos um vetor, SEMPRE precisamos passar 
// também o seu tamanho (quantidade de elementos). O C não sabe o tamanho 
// de um vetor apenas olhando para ele dentro da função.
void imprimirVetor(int vetor[], int tamanho);
void dobrarValores(int vetor[], int tamanho);

/* ============================================================================
 * 2. FUNÇÃO PRINCIPAL
 * ============================================================================ */
int main() {
    // Declarando e inicializando um vetor de 5 posições inteiras
    int tamanhoVetor = 5;
    int notas[5] = {10, 20, 30, 40, 50};    

    printf("--- ANTES DA MODIFICACAO ---\n");
    // CHAMADA 1: Apenas imprimindo os dados
    // Enviamos o nome do vetor ('notas') e o seu tamanho ('tamanhoVetor')
    // IMPORTANTE: O nome do vetor sozinho já representa o seu endereço de memória!
    imprimirVetor(notas, tamanhoVetor);

    // CHAMADA 2: Modificando os dados
    // A função vai até o endereço do vetor original e altera os valores lá dentro
    dobrarValores(notas, tamanhoVetor);

    printf("\n--- DEPOIS DA MODIFICACAO ---\n");
    // CHAMADA 3: Imprimindo os dados novamente para provar que foram alterados
    imprimirVetor(notas, tamanhoVetor);

    return 0;
}

/* ============================================================================
 * 3. IMPLEMENTAÇÃO DAS FUNÇÕES
 * ============================================================================ */

/*
 * Função: imprimirVetor
 * Objetivo: Percorrer o vetor e imprimir cada elemento.
 * Parâmetros:
 * - vetor[]: O endereço do vetor original (poderia ser escrito como *vetor).
 * - tamanho: A quantidade de elementos para sabermos quando parar o 'for'.
 */
void imprimirVetor(int vetor[], int tamanho) {
    printf("Valores do vetor: ");
    
    // O loop 'for' é o melhor amigo dos vetores. Ele vai da posição 0 até tamanho-1.
    for(int i = 0; i < tamanho; i++) {
        // Acessamos cada posição usando o índice [i]
        printf("%d ", vetor[i]);
    }
    printf("\n"); // Pula uma linha no final para ficar organizado
}

/*
 * Função: dobrarValores
 * Objetivo: Multiplicar o valor de cada elemento do vetor por 2.
 * Parâmetros:
 * - vetor[]: O endereço do vetor original.
 * - tamanho: A quantidade de elementos.
 */
void dobrarValores(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        // Pegamos o valor atual que está em vetor[i], multiplicamos por 2,
        // e guardamos o resultado de volta na MESMA posição.
        // Como recebemos o endereço de memória, isso altera o vetor original lá no main!
        vetor[i] = vetor[i] * 2; 
    }
}