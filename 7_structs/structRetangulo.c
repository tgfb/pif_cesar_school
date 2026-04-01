#include <stdio.h>   // Biblioteca para entrada e saída, como printf
#include <stdlib.h>  // Biblioteca que fornece funções utilitárias gerais,
                     // como abs para valor absoluto, malloc, free, rand, entre outras

// Define uma struct chamada point e cria um apelido (typedef) chamado Ponto
// Essa struct representa um ponto no plano cartesiano com coordenadas x e y
typedef struct point {
    int x;  // Coordenada no eixo X
    int y;  // Coordenada no eixo Y
} Ponto;

// Define uma struct chamada Retangulo e cria um apelido chamado Rect
// Um retângulo será representado por dois pontos:
// pt1 -> um canto do retângulo
// pt2 -> canto oposto do retângulo
typedef struct Retangulo {
    Ponto pt1;  // Primeiro ponto do retângulo
    Ponto pt2;  // Segundo ponto do retângulo
} Rect;

int main(int argc, char const *argv[])
{
    // Declara uma variável ret do tipo Rect
    // Ela armazenará os dois pontos que definem o retângulo
    Rect ret;

    // Define as coordenadas do primeiro ponto do retângulo
    ret.pt1.x = 1;
    ret.pt1.y = 3;

    // Define as coordenadas do segundo ponto do retângulo
    ret.pt2.x = 4;
    ret.pt2.y = 7;
    
    // Calcula a base do retângulo
    // A base é a diferença entre os valores de x dos dois pontos
    // abs é usada para garantir que o resultado seja positivo,
    // mesmo se pt1.x for maior que pt2.x
    double base = abs(ret.pt2.x - ret.pt1.x);

    // Calcula a altura do retângulo
    // A altura é a diferença entre os valores de y dos dois pontos
    // abs também garante um valor positivo
    double altura = abs(ret.pt2.y - ret.pt1.y);

    // Calcula a área do retângulo
    // Fórmula: área = base * altura
    double area = base * altura;

    // Exibe a área calculada
    // %lf é usado para mostrar valores do tipo double
    printf("A área do retangulo é %.2lf", area);

    // Retorna 0 para indicar que o programa terminou corretamente
    return 0;
}