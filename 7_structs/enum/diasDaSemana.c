#include <stdio.h>

enum DiaDaSemana {
    DOMINGO,
    SEGUNDA,
    TERCA,
    QUARTA,
    QUINTA,
    SEXTA,
    SABADO
};

int main() {
    enum DiaDaSemana hoje = QUARTA;
    printf("Hoje é o dia número: %d\n", hoje);
    return 0;
}