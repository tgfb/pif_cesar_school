#include <stdio.h>  // Biblioteca para usar funções de entrada e saída (printf e scanf)

// Função que recebe o vetor e o tamanho dele por referência
void substituir(int *vetor, int *n) {

    // Percorre o vetor do índice 0 até n-1
    for (int i = 0; i < *n; i++) {

        // Verifica se o elemento do vetor é par
        if (vetor[i] % 2 == 0) {
            vetor[i] = 0;  // Se for par, substitui o valor por 0
        } else {
            vetor[i] = 1;  // Se for ímpar, substitui o valor por 1
        }
    }
}

int main() {

    int N;  // Variável que armazenará o tamanho do vetor

    // Pede para o usuário informar o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);  // Lê o valor digitado e guarda em N (usa & para passar o endereço)

    int vetor[N];  // Cria um vetor de inteiros com tamanho N

    // Pede para o usuário digitar os elementos do vetor
    printf("Digite os elementos do vetor:\n");

    // Loop para preencher o vetor
    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);  // Lê cada número e armazena na posição i do vetor
    }

    // Chama a função passando o vetor e o endereço de N
    substituir(vetor, &N);

    // Mostra o vetor depois da modificação
    printf("Vetor modificado:\n");

    // Loop para imprimir cada elemento do vetor
    for (int i = 0; i < N; i++) {
        printf("%d ", vetor[i]);  // Imprime o valor da posição i
    }

    printf("\n");  // Apenas quebra de linha no final

    return 0;  // Indica que o programa terminou corretamente
}
