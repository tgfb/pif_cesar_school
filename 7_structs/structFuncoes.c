#include <stdio.h>    // Biblioteca para entrada e saída, como printf
#include <stdlib.h>   // Biblioteca necessária para usar a função abs

// Define uma struct chamada point e cria um apelido chamado Ponto
// Essa struct representa um ponto no plano cartesiano
typedef struct point{
    int x;   // Coordenada no eixo X
    int y;   // Coordenada no eixo Y
} Ponto;

// Define uma struct chamada Retangulo e cria um apelido chamado Rect
// Essa struct representa um retângulo formado por dois pontos
typedef struct Retangulo{
    Ponto pt1;   // Primeiro ponto do retângulo
    Ponto pt2;   // Segundo ponto do retângulo
} Rect;

// Função que recebe dois pontos como parâmetro
// e retorna uma struct do tipo Rect
Rect criarRetangulo(Ponto p1, Ponto p2) {
    // Declara uma variável local do tipo Rect
    Rect r;

    // Atribui o primeiro ponto recebido ao campo pt1 do retângulo
    r.pt1 = p1;

    // Atribui o segundo ponto recebido ao campo pt2 do retângulo
    r.pt2 = p2;

    // Retorna a struct retângulo já preenchida
    return r;
}

// Função que recebe um retângulo como parâmetro
// e retorna um valor inteiro correspondente à área
int calcularArea(Rect r) {
    // Calcula a base do retângulo pela diferença entre os valores de x
    // abs é usada para garantir que o valor fique positivo
    int base = abs(r.pt2.x - r.pt1.x);

    // Calcula a altura do retângulo pela diferença entre os valores de y
    // abs também garante que o valor fique positivo
    int altura = abs(r.pt2.y - r.pt1.y);

    // Retorna a área do retângulo
    return base * altura;
}

int main() {
    // Declara e inicializa o primeiro ponto
    Ponto p1 = {1, 3};

    // Declara e inicializa o segundo ponto
    Ponto p2 = {4, 7};

    // Chama a função criarRetangulo, passando os dois pontos
    // O retângulo retornado é armazenado na variável ret
    Rect ret = criarRetangulo(p1, p2);

    // Chama a função calcularArea, passando o retângulo criado
    // O valor retornado é armazenado na variável area
    int area = calcularArea(ret);

    // Exibe as coordenadas do primeiro ponto do retângulo
    printf("Ponto 1: (%d, %d)\n", ret.pt1.x, ret.pt1.y);

    // Exibe as coordenadas do segundo ponto do retângulo
    printf("Ponto 2: (%d, %d)\n", ret.pt2.x, ret.pt2.y);

    // Exibe a área calculada
    printf("Area: %d\n", area);

    // Retorna 0 para indicar que o programa foi finalizado com sucesso
    return 0;
}