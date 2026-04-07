#include <stdio.h>

// struct aluno{
enum DiaDaSemana {
    DOMINGO, //0
    SEGUNDA, // 1
    TERCA, // 2
    QUARTA,
    QUINTA,
    SEXTA,
    SABADO
};

int main() {
    enum DiaDaSemana dia;
    scanf("%d", &dia); // QUARTA <=> 3
    if(dia == QUARTA || dia == SEGUNDA)
        printf("Hoje tem aula de PIF\n");

    return 0;
}