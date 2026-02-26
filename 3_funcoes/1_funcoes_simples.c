#include <stdio.h>

/* ============================================================================
 * 1. PROTÓTIPOS DAS FUNÇÕES (Declaração)
 * Boa prática: Avisamos ao compilador o nome da função, o que ela precisa 
 * receber (parâmetros) e o que ela vai devolver (tipo de retorno), antes 
 * da função principal (main).
 * ============================================================================ */

float calcularAreaRetangulo(float base, float altura);
void exibirMensagemBoasVindas(void);


/* ============================================================================
 * 2. FUNÇÃO PRINCIPAL (Ponto de entrada do programa)
 * É aqui que a execução do programa sempre começa.
 * ============================================================================ */
int main() {
    // Declaração das variáveis que usaremos na função principal
    float valorBase = 0.0;
    float valorAltura = 0.0;
    float resultadoArea = 0.0;

    // CHAMADA DE FUNÇÃO 1: Função sem retorno e sem parâmetros
    // O programa "pula" para a função exibirMensagemBoasVindas, executa o 
    // que está lá e depois volta para a próxima linha.
    exibirMensagemBoasVindas();
    
    // INTERAÇÃO COM O USUÁRIO: Solicitando a Base
    printf("Por favor, digite o valor da BASE do retangulo: ");
    
    // O scanf lê o que o usuário digitou. 
    // %f indica que esperamos um número decimal (float).
    // O '&' (E comercial) é crucial aqui: ele indica o "endereço de memória" 
    // da variável valorBase, dizendo ao scanf exatamente onde guardar o valor.
    scanf("%f", &valorBase);

    // INTERAÇÃO COM O USUÁRIO: Solicitando a Altura
    printf("Agora, digite o valor da ALTURA do retangulo: ");
    scanf("%f", &valorAltura);

    // CHAMADA DE FUNÇÃO 2: Função com retorno e com parâmetros
    // Enviamos 'valorBase' e 'valorAltura' como argumentos. A função faz o
    // cálculo e o valor devolvido (return) é guardado na variável 'resultadoArea'.
    resultadoArea = calcularAreaRetangulo(valorBase, valorAltura);

    // ========================================================================
    // EXIBINDO O RESULTADO FINAL
    // Entendendo o formato '%.2f\n':
    //  %    -> Avisa ao printf que vamos inserir o valor de uma variável aqui.
    //  .2   -> Formatação de precisão: limita a exibição a 2 casas decimais.
    //  f    -> Especifica o tipo de dado esperado: 'f' para float.
    //  \n   -> Caractere de escape de nova linha (pula para a linha de baixo).
    // ========================================================================
    printf("A area calculada do retangulo eh: %.2f\n", resultadoArea);

    return 0; // Indica que o programa terminou com sucesso
}


/* ============================================================================
 * 3. IMPLEMENTAÇÃO DAS FUNÇÕES (O corpo da função)
 * Aqui escrevemos a lógica real de cada função declarada lá em cima.
 * ============================================================================ */

/*
 * Função: calcularAreaRetangulo
 * Objetivo: Multiplicar a base pela altura.
 * Parâmetros:
 * - base (float): a medida da base.
 * - altura (float): a medida da altura.
 * Retorno (float): O valor da área calculada.
 */
float calcularAreaRetangulo(float base, float altura) {
    float area = base * altura; // Variável local, só existe dentro desta função
    
    return area; // Devolve o resultado para o local onde a função foi chamada
}

/*
 * Função: exibirMensagemBoasVindas
 * Objetivo: Apenas imprimir um cabeçalho no console.
 * Parâmetros: void (não recebe nada).
 * Retorno: void (não devolve nada, apenas executa uma ação).
 */
void exibirMensagemBoasVindas(void) {
    printf("----------------------------------------\n");
    printf("   BEM-VINDO AO CALCULADOR DE AREAS     \n");
    printf(" Aula Pratica: Introducao as Funcoes    \n");
    printf("----------------------------------------\n\n");
}