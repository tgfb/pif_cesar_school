#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct node
{
    int valor;          // Valor armazenado no nó
    struct node *next;  // Ponteiro para o próximo nó
} Node;

// Cria um novo nó
Node *createNode(int valor)
{
    Node *novo = (Node *)malloc(sizeof(Node));

    // Verifica se a alocação funcionou
    if (novo == NULL)
        return NULL;

    novo->valor = valor;
    novo->next = NULL;

    return novo;
}

// 🔹 Insere mantendo a lista ORDENADA (crescente)
// 🔹 Permite valores duplicados
void add(Node **head, int valor)
{
    Node *novo = createNode(valor);

    // Caso 1: lista vazia OU inserir no início
    if (*head == NULL || valor < (*head)->valor)
    {
        novo->next = *head; // Novo aponta para o antigo início
        *head = novo;       // Novo vira o primeiro nó
        return;
    }

    Node *atual = *head;

    // Percorre até encontrar a posição correta
    while (atual->next != NULL && atual->next->valor < valor)
    {
        atual = atual->next;
    }

    // Insere o novo nó
    novo->next = atual->next;
    atual->next = novo;
}

// Imprime a lista
void printList(Node *head)
{
    Node *atual = head;

    while (atual != NULL)
    {
        printf("%d\n", atual->valor);
        atual = atual->next;
    }
}

// Libera memória da lista
void freeList(Node *head)
{
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node *head = NULL;

    // Inserções fora de ordem
    add(&head, 30);
    add(&head, 10);
    add(&head, 20);
    add(&head, 20); // duplicado permitido
    add(&head, 5);

    printf("Lista ordenada (com duplicatas):\n");
    printList(head);

    freeList(head);
    return 0;
}