#include <stdio.h>

enum StatusPedido {
    PENDENTE = 2,
    PROCESSANDO = 1,
    ENVIADO = 4,
    ENTREGUE = 4
};

int main() {
    enum StatusPedido pedido = ENVIADO;
    printf("Status do pedido: %d\n", pedido);
    return 0;
}