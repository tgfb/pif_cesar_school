#include <stdio.h>

/*
Enunciado:
Calcular o total a pagar por um item da lanchonete.
O programa deve ler um código do produto (de 1 a 5) e a quantidade comprada.
De acordo com o código informado, deve-se utilizar o preço correspondente
da tabela abaixo e calcular o valor total a ser pago.

Tabela de Preços:
1 - Cachorro Quente    - R$ 4.00
2 - X-Salada           - R$ 4.50
3 - X-Bacon            - R$ 5.00
4 - Torrada Simples    - R$ 2.00
5 - Refrigerante       - R$ 1.50

O valor total deve ser exibido no formato:
Total: R$ X.XX
*/

int main() {
    // Declaração das variáveis
    int codigo, quantidade;
    double total;

    // Leitura do código do produto e da quantidade
    scanf("%d %d", &codigo, &quantidade);

    // Verificação do código e cálculo do total
    if (codigo == 1) {
        total = quantidade * 4.00;
    } else if (codigo == 2) {
        total = quantidade * 4.50;
    } else if (codigo == 3) {
        total = quantidade * 5.00;
    } else if (codigo == 4) {
        total = quantidade * 2.00;
    } else if (codigo == 5) {
        total = quantidade * 1.50;
    }

    // Impressão do valor total no formato especificado
    printf("Total: R$ %.2lf\n", total);

    return 0;
}
