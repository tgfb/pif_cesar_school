#include <stdio.h>

// ============================================================================
// BOAS PRÁTICAS: O uso de #define
// Definimos o tamanho da matriz em constantes globais. Isso facilita muito 
// a manutenção. Se precisarmos adicionar um novo sensor no futuro, mudamos
// o número apenas aqui, e todo o código se ajusta automaticamente.
// ============================================================================
#define LINHAS 3
#define COLUNAS 4

/* ============================================================================
 * 1. PROTÓTIPOS DAS FUNÇÕES
 * ============================================================================ */
// REGRA DE OURO DAS MATRIZES EM C:
// Ao declarar uma matriz como parâmetro, o primeiro colchete (linhas) pode 
// ficar vazio [], mas o segundo colchete (colunas) DEVE conter o tamanho.
// O compilador precisa dessa informação para calcular os endereços de memória.
void imprimirMatrizSensores(int matriz[][COLUNAS], int linhas);
void calibrarSensores(int matriz[][COLUNAS], int linhas);

/* ============================================================================
 * 2. FUNÇÃO PRINCIPAL
 * ============================================================================ */
int main() {
    // Inicializando uma matriz 3x4 (3 linhas, 4 colunas).
    // Imagine: 3 sensores IoT, cada um registrando 4 leituras de temperatura.
    int dadosSensores[LINHAS][COLUNAS] = {
        {22, 23, 22, 24}, // Linha 0: Leituras do Sensor 0
        {18, 19, 18, 20}, // Linha 1: Leituras do Sensor 1
        {30, 31, 30, 32}  // Linha 2: Leituras do Sensor 2
    };

    printf("--- DADOS ORIGINAIS DOS SENSORES ---\n");
    // Passamos o nome da matriz (que representa o endereço base) e o número de linhas.
    // O número de colunas já é conhecido pela função através do #define COLUNAS.
    imprimirMatrizSensores(dadosSensores, LINHAS);

    printf("\n--- EXECUTANDO CALIBRACAO (+5 GRAUS EM TUDO) ---\n");
    // Assim como nos vetores unidimensionais, a passagem é por referência.
    // O que fizermos dentro dessa função alterará a matriz 'dadosSensores' real.
    calibrarSensores(dadosSensores, LINHAS);

    printf("\n--- DADOS APOS A CALIBRACAO ---\n");
    imprimirMatrizSensores(dadosSensores, LINHAS);

    return 0;
}

/* ============================================================================
 * 3. IMPLEMENTAÇÃO DAS FUNÇÕES
 * ============================================================================ */

/*
 * Função: imprimirMatrizSensores
 * Objetivo: Mostrar os dados em formato de tabela.
 */
void imprimirMatrizSensores(int matriz[][COLUNAS], int linhas) {
    // Para percorrer matrizes, sempre usamos DOIS loops 'for' aninhados.
    // O loop externo (i) desce pelas linhas.
    for (int i = 0; i < linhas; i++) {
        // Imprime o rótulo da linha (ex: "Sensor 0: "). O '%d' é substituído pelo valor atual de 'i' (contador do loop externo), identificando de qual dispositivo são as leituras que o loop interno imprimirá logo em seguida.
        printf("Sensor %d: ", i);
        
        // O loop interno (j) caminha pelas colunas daquela linha específica.
        for (int j = 0; j < COLUNAS; j++) {
            // Imprime o elemento da linha 'i' e coluna 'j'.
            // O %3d formata a saída para ocupar sempre 3 espaços, alinhando a tabela.
            printf("%3d ", matriz[i][j]); 
        }
        printf("\n"); // Pula uma linha apenas quando termina todas as colunas do sensor
    }
}

/*
 * Função: calibrarSensores
 * Objetivo: Somar 5 a todos os valores registrados na matriz.
 */
void calibrarSensores(int matriz[][COLUNAS], int linhas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            // Acessamos o valor atual, somamos 5 e guardamos de volta
            // no mesmo endereço de memória.
            matriz[i][j] = matriz[i][j] + 5;
        }
    }
}