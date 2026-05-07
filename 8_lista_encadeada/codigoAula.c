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

void inserirInicio(Node** h, int valor){
    Node* novo = createNode(valor);
    novo->next = *h;
    *h = novo;
    // Node* novo = createNode(valor);
    // Node* aux = *h;
    // *h = novo;
    // novo->next = aux;

}

void removerInicio(Node** h){
    if (*h != NULL){
        Node* aux = *h;
        *h = aux->next;
        free(aux);
    } else {
        printf("Lista vazia\n");
    }
}

void inserirOrdenado(Node** h, int valor){
    Node* novo = createNode(valor);
    if(*h == NULL || valor < (*h)->valor){
        novo->next = *h;
        *h = novo;
    } else {
        Node* aux = *h;
        Node* anterior = *h;
        while (aux != NULL && aux->valor < valor){
            anterior = aux;
            aux = aux->next;
        }
        anterior->next = novo;
        novo->next = aux;        
    }
}

Node* intercala(Node* l1, Node* l2){
    Node* head = createNode(l1->valor);
    Node* aux = head;
    l1 = l1->next;
    while(l1 != NULL || l2 != NULL){
        if(l2 != NULL){
            aux->next = createNode(l2->valor);
            aux = aux->next;
            l2 = l2->next;
        }
        if(l1 != NULL){
            aux->next = createNode(l1->valor);
            aux = aux->next;
            l1 = l1->next;
        }
    }
    return head;
}

int main(){
    Node *l1 = NULL, *l2 = NULL, *resultado = NULL;

    printf("=== Criando e manipulando lista l1 ===\n");
    add(&l1, 30);
    add(&l1, 50);
    add(&l1, 70);
    imprime(l1); // 30 50 70

    printf("Removendo ultimo de l1 (removeUltimo)\n");
    removeUltimo(&l1);
    imprime(l1); // 30 50

    printf("Inserindo no inicio de l1\n");
    inserirInicio(&l1, 10);
    imprime(l1); // 10 30 50

    printf("Inserindo ordenado (20)\n");
    inserirOrdenado(&l1, 20);
    imprime(l1); // 10 20 30 50

    printf("Removendo inicio de l1\n");
    removerInicio(&l1);
    imprime(l1); // 20 30 50

    printf("Inserindo na posicao 2 o valor 40\n");
    inserirPos(&l1, 2, 40);
    imprime(l1); // 20 30 40 50

    printf("Buscando valor 30 em l1\n");
    Node* ret = busca(l1, 30);
    if (ret == NULL)
        printf("Nao encontrado\n");
    else
        printf("Encontrado valor: %d\n", ret->valor);

    printf("Removendo posicao 3 (removePos)\n");
    removePos(&l1, 3);
    imprime(l1); // 20 30 40

    printf("Removendo ultimo com dois ponteiros (removeUltimoDoisPonteiros)\n");
    removeUltimoDoisPonteiros(&l1);
    imprime(l1); // 20 30

    printf("\n=== Criando e manipulando lista l2 ===\n");
    add(&l2, 25);
    add(&l2, 35);
    add(&l2, 45);
    imprime(l2); // 25 35 45

    printf("\n=== Intercalando l1 e l2 ===\n");
    resultado = intercala(l1, l2);
    imprime(resultado); // 20 25 30 35 45

    printf("=== Testando funcoes restantes na lista resultado ===\n");
    inserirInicio(&resultado, 5);
    imprime(resultado); // 5 20 25 30 35 45

    removerInicio(&resultado);
    imprime(resultado); // 20 25 30 35 45

    inserirPos(&resultado, 2, 28);
    imprime(resultado); // 20 25 28 30 35 45

    removePos(&resultado, 4);
    imprime(resultado); // 20 25 28 30 45

    removeUltimo(&resultado);
    imprime(resultado); // 20 25 28 30

    printf("Removendo ultimo com dois ponteiros (removeUltimoDoisPonteiros)\n");
    removeUltimoDoisPonteiros(&resultado);
    imprime(resultado); // 20 25 28

    return 0;
}