#include <stdio.h>

enum StatusPedido {
    PENDENTE = 1,
    PROCESSANDO,
    ENVIADO,
    ENTREGUE
};

int main() {
    enum StatusPedido pedido = ENVIADO;
    printf("Status do pedido: %d\n", pedido);
    return 0;
}