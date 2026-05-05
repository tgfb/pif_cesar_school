#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *next;
} Node;

Node* createNode(int val){
    Node* temp = (Node*)malloc(sizeof(Node));
    // (*temp).valor = val;
    temp->valor = val;
    temp->next = NULL;
    return temp;
}

void add(Node**h, int valor){
    Node* novo = createNode(valor);
    if(*h == NULL){
        *h = novo;
    } else {
        Node* aux = *h;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = novo;
    }
}

void imprime(Node* h){
    if(h == NULL){
        printf("Lista Vazia!\n");
    } else {
        while (h != NULL){
            printf("%d ", h->valor);
            h = h->next;
        }
    }
    printf("\n");
}

void removeUltimo(Node** h){
    if(*h == NULL){
        printf("Lista Vazia!\n");
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
    if(*h == NULL){
        printf("Lista Vazia\n");
    } else if((*h)->next == NULL){
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

Node* busca(Node* h, int valor){
    if(h == NULL){
        return NULL;
    } else {
        Node* aux = h;
        while (aux != NULL && aux->valor != valor){
            aux = aux->next;
        }
        return aux;
    }
}

void removePos(Node** h, int pos){
    if (*h == NULL){
        printf("Lista vazia\n");
    } else if((*h)->next == NULL && pos > 0){
        printf("Nao eh possivel remover\n");
    } else {
        int cont = 0;
        Node* aux = *h;
        Node* anterior = *h;
        while (aux != NULL && cont != pos){
            cont++;
            anterior = aux;
            aux = aux->next;
        }
        if(aux != NULL){
            anterior->next = aux->next;
            free(aux);
        } else {
            printf("Nao encontrado\n");
        }
    }
}

void inserirPos(Node** h, int pos, int valor){
    Node* novo = createNode(valor);
    if(*h == NULL && pos > 0){
        printf("Nao eh possivel inserir\n");
    } else if(*h == NULL){
        printf("Lista vazia\n");
    } else {
        int posAtual = 0;
        Node* aux = *h;
        Node* anterior = *h;
        while (aux != NULL && posAtual != pos) {
            posAtual++;
            anterior = aux;
            aux = aux->next;
        }
        if(aux != NULL){
            anterior->next = novo;
            novo->next = aux;
        } else {
            printf("Posicao nao existe\n");
        }
        
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

    Node* ret = busca(head, 30);
    if (ret == NULL)
        printf("Nao encontrado\n");
    else
        printf("Valor: %d\nEndereco: %p\n", ret->valor, ret);

    imprime(head);
    
    removePos(&head, 0);
    imprime(head);

    inserirPos(&head, 2, 100);
    // removeUltimo(&head);
    // removeUltimoDoisPonteiros(&head);

    imprime(head);
    
}