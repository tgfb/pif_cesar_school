#include <stdio.h>
#include <string.h>

int main() {
    // Dados brutos (simulando a leitura de um arquivo ou sensor)
    char log_entrada[] = "SENSOR_01: 25.4C";
    
    // Variáveis para armazenar os dados extraídos
    char nome_sensor[20];
    float temperatura;
    char unidade;

    // --- 1. sscanf: "SCAN de String" ---
    // Extrai dados de uma string existente usando um formato específico
    // Funciona como o scanf, mas lê da variável 'log_entrada' em vez do teclado
    // O formato %[^:] no código abaixo diz ao C: "leia tudo até encontrar o caractere :
    sscanf(log_entrada, "%[^:]: %f%c", nome_sensor, &temperatura, &unidade);

    // --- 2. sprintf: "PRINT para String" ---
    // Em vez de exibir na tela, "imprime" o resultado formatado em um array
    char mensagem_formatada[100];
    sprintf(mensagem_formatada, "Alerta! O %s registrou %.1f graus.", nome_sensor, temperatura);

    // --- 3. puts: Saída de String Simples ---
    // Imprime a string e adiciona automaticamente um '\n' (nova linha) ao final
    puts("--- Processamento de Dados ---");
    puts(mensagem_formatada);

    // --- 4. getchar e putchar: Caractere por Caractere ---
    printf("\nPressione Enter para ver a unidade de medida letra por letra: ");
    getchar(); // Limpa o buffer anterior ou espera o Enter

    printf("Unidade extraida: ");
    putchar(unidade); // Imprime apenas um caractere
    putchar('\n');

    // Exemplo de loop com putchar para soletrar o nome do sensor
    printf("Soletrando sensor: ");
    for(int i = 0; nome_sensor[i] != '\0'; i++) {
        putchar(nome_sensor[i]);
        if(nome_sensor[i+1] != '\0') putchar('-');
    }
    putchar('\n');

    return 0;
}