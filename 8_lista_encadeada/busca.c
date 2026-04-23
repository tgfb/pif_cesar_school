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
        return NULL;

    novo->valor = valor;
    novo->next = NULL;

    return novo;
}

// 🔹 Inserção ordenada (permite duplicatas)
void add(Node **head, int valor)
{
    Node *novo = createNode(valor);

    // Inserção no início
    if (*head == NULL || valor < (*head)->valor)
    {
        novo->next = *head;
        *head = novo;
        return;
    }

    Node *atual = *head;

    // Percorre até a posição correta
    while (atual->next != NULL && atual->next->valor < valor)
    {
        atual = atual->next;
    }

    novo->next = atual->next;
    atual->next = novo;
}

// 🔍 FUNÇÃO DE BUSCA
// Retorna ponteiro para o nó encontrado ou NULL se não existir
Node *search(Node *head, int valor)
{
    Node *atual = head;

    // Percorre a lista
    while (atual != NULL)
    {
        // 🔹 Se encontrou o valor
        if (atual->valor == valor)
        {
            return atual;
        }

        // 🔹 Otimização: como a lista está ordenada,
        // se o valor atual já for maior, não precisa continuar
        if (atual->valor > valor)
        {
            return NULL;
        }

        atual = atual->next;
    }

    // 🔹 Valor não encontrado
    return NULL;
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

// Libera memória
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

    add(&head, 30);
    add(&head, 10);
    add(&head, 20);
    add(&head, 25);

    printf("Lista:\n");
    printList(head);

    int valorBusca = 20;

    // 🔍 Chamando a busca
    Node *resultado = search(head, valorBusca);

    if (resultado != NULL)
    {
        printf("\nValor %d encontrado!\n", valorBusca);
    }
    else
    {
        printf("\nValor %d NÃO encontrado.\n", valorBusca);
    }

    freeList(head);
    return 0;
}