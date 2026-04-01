#include <stdio.h>   // Biblioteca para entrada e saída, como printf
#include <math.h>    // Biblioteca para funções matemáticas, como sqrt

// Definição de uma struct chamada point
// Ela representa um ponto no plano cartesiano com coordenadas x e y
struct point {
    int x;  // Coordenada no eixo X
    int y;  // Coordenada no eixo Y
};

int main(){
    // Declaração e inicialização do primeiro ponto
    // Neste exemplo, o ponto pt recebe as coordenadas (0, 1)
    struct point pt;
    pt.x = 0;
    pt.y = 1;

    // Declaração e inicialização do segundo ponto
    // O ponto pt2 recebe as coordenadas (4, 3)
    struct point pt2 = {4, 3};

    // Calcula a diferença entre as coordenadas x dos dois pontos
    int dx = pt.x - pt2.x;

    // Calcula a diferença entre as coordenadas y dos dois pontos
    int dy = pt.y - pt2.y;

    // Calcula a distância entre os dois pontos usando a fórmula:
    // distância = raiz quadrada de ((x1 - x2)^2 + (y1 - y2)^2)
    //
    // Em C, o símbolo ^ NÃO representa potência.
    // Por isso, para elevar ao quadrado, multiplicamos o valor por ele mesmo.
    double dist = sqrt((dx * dx) + (dy * dy));

    // Exibe a distância calculada
    // %lf é o especificador de formato para double no printf
    printf("Distancia entre os pontos: %lf\n", dist);

    // Indica que o programa terminou corretamente
    return 0;
}