#include <stdio.h>

/* ============================================================================
 * 1. VARIÁVEIS GLOBAIS
 * Declaradas FORA de qualquer função (geralmente no topo do arquivo).
 * ESCOPO: Podem ser lidas e alteradas por QUALQUER função do programa.
 * TEMPO DE VIDA: Nascem quando o programa começa e só morrem quando ele termina.
 * ============================================================================ */
 
// Simulando uma configuração global para uma rede de sensores IoT
int limiteTemperaturaAlerta = 30; 

/* ============================================================================
 * 2. PROTÓTIPOS DAS FUNÇÕES
 * ============================================================================ */
void verificarTemperatura(int temperaturaAtual, int idSensor);
void ajustarLimiteGlobal(int novoLimite);

/* ============================================================================
 * 3. FUNÇÃO PRINCIPAL
 * ============================================================================ */
int main() {
    // VARIÁVEIS LOCAIS (Escopo da função main)
    // Só existem dentro do bloco {} da função main. Nenhuma outra função 
    // consegue enxergar ou usar 'tempSala' ou 'tempServidor' diretamente.
    int tempSala = 25;
    int tempServidor = 35;

    printf("--- INICIANDO SISTEMA DE MONITORAMENTO ---\n");
    printf("Limite global atual para alertas: %d graus.\n\n", limiteTemperaturaAlerta);

    // Avaliando as leituras locais usando a regra global
    verificarTemperatura(tempSala, 1);
    verificarTemperatura(tempServidor, 2);

    printf("\n--- ATUALIZANDO CONFIGURACOES DO SISTEMA ---\n");
    // Alterando a variável global. Isso afetará todas as próximas verificações.
    ajustarLimiteGlobal(38);

    printf("\n--- REAVALIANDO SENSORES ---\n");
    // Avaliando as mesmas variáveis locais, mas agora a regra global mudou
    verificarTemperatura(tempSala, 1);
    verificarTemperatura(tempServidor, 2);

    return 0; // Ao chegar aqui, tempSala e tempServidor são destruídas da memória.
}

/* ============================================================================
 * 4. IMPLEMENTAÇÃO DAS FUNÇÕES
 * ============================================================================ */

/*
 * Função: verificarTemperatura
 * Objetivo: Compara a leitura de um sensor com o limite global.
 */
void verificarTemperatura(int temperaturaAtual, int idSensor) {
    // 'temperaturaAtual' e 'idSensor' também se comportam como VARIÁVEIS LOCAIS.
    // Elas recebem uma CÓPIA dos valores passados pelo main e só existem aqui.
    
    // 'diferenca' é uma variável puramente local desta função.
    int diferenca; 

    // Acessando a variável GLOBAL 'limiteTemperaturaAlerta' diretamente
    if (temperaturaAtual > limiteTemperaturaAlerta) {
        diferenca = temperaturaAtual - limiteTemperaturaAlerta;
        printf("[ALERTA] Sensor %d: %d graus! Excedeu o limite global em %d graus.\n", 
               idSensor, temperaturaAtual, diferenca);
    } else {
        printf("[ OK ] Sensor %d: %d graus. Dentro do limite global.\n", 
               idSensor, temperaturaAtual);
    }
} // Ao chegar nesta chave }, 'temperaturaAtual', 'idSensor' e 'diferenca' são destruídas.

/*
 * Função: ajustarLimiteGlobal
 * Objetivo: Modificar a variável que é visível para todo o programa.
 */
void ajustarLimiteGlobal(int novoLimite) {
    // 'novoLimite' é local, mas 'limiteTemperaturaAlerta' é global.
    // Como a global está acessível em todo lugar, podemos alterá-la diretamente
    // sem precisar usar ponteiros.
    limiteTemperaturaAlerta = novoLimite;
    printf(">>> O limite global de alerta foi alterado para %d graus <<<\n", limiteTemperaturaAlerta);
}