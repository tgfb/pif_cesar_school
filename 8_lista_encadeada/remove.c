#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct node
{
    int valor;          // Valor armazenado
    struct node *next;  // Ponteiro para o próximo nó
} Node;

// Cria um novo nó
Node *createNode(int valor)
{
    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo == NULL)
    {
        return NULL; // Falha na alocação
    }

    novo->valor = valor;
    novo->next = NULL;

    return novo;
}

// Adiciona no final da lista
void add(Node **head, int valor)
{
    Node *novo = createNode(valor);

    if (*head == NULL)
    {
        *head = novo;
        return;
    }

    Node *atual = *head;

    while (atual->next != NULL)
    {
        atual = atual->next;
    }

    atual->next = novo;
}

// 🔴 Remove a primeira ocorrência de um valor na lista
void removeNode(Node **head, int valor)
{
    // Se a lista está vazia, não há nada para remover
    if (*head == NULL)
        return;

    Node *atual = *head;     // Ponteiro para percorrer a lista
    Node *anterior = NULL;   // Guarda o nó anterior

    // 🔹 Caso especial: o primeiro nó contém o valor
    if (atual->valor == valor)
    {
        *head = atual->next; // Atualiza o início da lista
        free(atual);         // Libera memória do nó removido
        return;
    }

    // 🔹 Percorre a lista procurando o valor
    while (atual != NULL && atual->valor != valor)
    {
        anterior = atual;     // Guarda o nó atual como anterior
        atual = atual->next;  // Avança para o próximo nó
    }

    // 🔹 Se chegou ao final e não encontrou o valor
    if (atual == NULL)
        return;

    // 🔹 Remove o nó encontrado
    anterior->next = atual->next; // "Pula" o nó atual na lista
    free(atual);                  // Libera memória
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

int main()
{
    Node *head = NULL;

    add(&head, 10);
    add(&head, 20);
    add(&head, 30);
    add(&head, 20);

    printf("Lista original:\n");
    printList(head);

    // Remove o valor 20 (apenas a primeira ocorrência)
    removeNode(&head, 20);

    printf("\nLista após remover 20:\n");
    printList(head);

    // Libera toda a memória da lista
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}