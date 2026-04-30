#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *next;
} Node;

Node* createNode(int val){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->valor = val;
    temp->next = NULL;
    return temp;
}

void add(Node** h, int valor){
    Node* novo = createNode(valor);
    if(*h == NULL){
        *h = novo;
    } else {
        Node* aux = *h;
        while (aux->next != NULL){
            aux = aux->next;
        }
        aux->next = novo;
    }
}

void imprime(Node* h){
    Node* aux = h;
    while (aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->next;
    }
    printf("\n");
}

void removeUltimo(Node** h){
    if (*h == NULL){
        printf("Lista Vazia\n");
    } else if ((*h)->next == NULL){
        free(*h);
        *h = NULL;
    } else {
        Node* aux = *h;
        while (aux->next->next != NULL){
            aux = aux->next;
        }
        free(aux->next);
        aux->next = NULL;        
    }
    
}

void removeUltimoDoisPonteiros(Node** h){
    if (*h == NULL){
        printf("Lista Vazia\n");
    } else if ((*h)->next == NULL){
        free(*h);
        *h = NULL;
    } else {
        Node* aux = *h;
        Node* n = *h;
        while (aux->next != NULL){
            n = aux;
            aux = aux->next;
        }
        free(aux);
        n->next = NULL;        
    }
    
}

int main(){
    Node* head = NULL;
    add(&head ,10);
    add(&head, 20);
    add(&head, 30);
    add(&head, 40);
    add(&head, 50);
    add(&head, 60);

    imprime(head);

    removeUltimo(&head);
    removeUltimoDoisPonteiros(&head);

    imprime(head);
    
    
}