#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura 'node' (nó) que representa um elemento da lista encadeada
typedef struct node
{
    int valor;          // Valor armazenado no nó (do tipo inteiro)
    struct node *next;  // Ponteiro para o próximo nó da lista
} Node;

// Função que cria um novo nó e inicializa seu valor e ponteiro 'next'
Node *createNode(int valor)
{
    // Aloca memória para o novo nó
    Node *novo = (Node *)malloc(sizeof(Node));

    // Verifica se a alocação foi bem-sucedida
    if (novo == NULL)
    {
        return NULL;  // Retorna NULL se a memória não foi alocada
    }

    novo->valor = valor;   // Atribui o valor passado ao nó
    novo->next = NULL;     // Inicializa o ponteiro 'next' como NULL (indica que não há próximo nó)
    
    return novo;           // Retorna o novo nó criado
}

// Função que adiciona um novo nó ao final da lista
Node *add(Node *head, int valor)
{
    // Cria um novo nó com o valor passado
    Node *novo = createNode(valor);

    // Se a lista estiver vazia (head é NULL), o novo nó se torna o primeiro nó
    if (head == NULL)
    {
        // Retorna o novo nó como a cabeça da lista
        return novo;
    }

    // Caso a lista não esteja vazia, percorre a lista até o último nó
    Node *atual = head;
    while (atual->next != NULL)
    {
        atual = atual->next;  // Move para o próximo nó até chegar ao último
    }

    // Quando encontrar o último nó, atualiza seu ponteiro 'next' para o novo nó
    atual->next = novo;

    // Retorna a cabeça da lista, pois a lista original não foi alterada
    // Ou seja, a cabeça da lista continua a mesma, pois o nó foi adicionado ao final
    return head;
}

int main()
{
    Node *lista = NULL;  // Ponteiro para o primeiro nó da lista, inicialmente é NULL

    // Adiciona três nós à lista, com valores 10, 20 e 30, respectivamente
    // A cada chamada de add, a lista é atualizada e o valor de 'head' é retornado
    lista = add(lista, 10);
    lista = add(lista, 20);
    lista = add(lista, 30);

    // Percorre a lista e imprime o valor de cada nó
    Node *atual = lista;
    while (atual != NULL)
    {
        printf("%d\n", atual->valor);  // Imprime o valor do nó atual
        atual = atual->next;           // Move para o próximo nó
    }

    // Libera a memória alocada para a lista
    // Aqui, a lista é percorrida e a memória de cada nó é liberada
    while (lista != NULL)
    {
        Node *temp = lista;      // Armazena o nó atual em uma variável temporária
        lista = lista->next;     // Avança para o próximo nó
        free(temp);              // Libera a memória do nó anterior
    }

    return 0;  // Indica que o programa foi executado com sucesso
}