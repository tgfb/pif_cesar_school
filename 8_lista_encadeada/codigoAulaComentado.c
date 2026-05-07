// Envia para o compilador que este programa usa as bibliotecas padrão de entrada e saída, e alocação dinâmica.
#include <stdio.h>
#include <stdlib.h>


// Define o tipo Node para ser uma lista encadeada simples.
// Cada nó contém:
//   - um inteiro "valor"
//   - um ponteiro "next" que aponta para o próximo nó (ou NULL se for o último).
typedef struct Node{
    int valor;              // campo que armazena o valor inteiro do nó
    struct Node *next;      // ponteiro que aponta para o próximo nó da lista
} Node;                    // "Node" é o tipo que você usa em vez de "struct Node"


// Função que cria um novo nó com valor = "val" e next = NULL.
// Passos:
// 1. Aloca memória suficiente para um Node (o tamanho sizeof(Node) bytes).
// 2. Atribui "val" ao campo valor do nó.
// 3. Define o ponteiro next como NULL (novo nó será o último até inserir mais).
// 4. Retorna o endereço do nó criado.
Node* createNode(int val){
    Node* temp = (Node*)malloc(sizeof(Node));   // aloca memória para o nó
    // (*temp).valor = val;                      // (comentado): alternativa de acesso ao campo valor via ponteiro
    temp->valor = val;                           // atribui o valor fornecido ao nó
    temp->next = NULL;                           // seta o ponteiro next como NULL (novo nó começa solto)
    return temp;                                 // retorna o ponteiro para o nó recém-criado
}


// Função que insere um novo nó com valor "valor" ao final da lista apontada por *h.
// Se *h for NULL, o novo nó vira a cabeça da lista.
// Caso contrário, percorre até o último nó e adiciona o novo nó após o último.
void add(Node**h, int valor){
    Node* novo = createNode(valor);             // cria o novo nó com o valor
    if(*h == NULL){                             // se a lista está vazia
        *h = novo;                              // o novo nó vira a cabeça da lista
    } else {                                    // se já existe pelo menos um nó
        Node* aux = *h;                         // começa no primeiro nó
        while(aux->next != NULL){               // percorre até o último nó (aquele que tem next == NULL)
            aux = aux->next;                    // vai para o próximo nó
        }
        aux->next = novo;                       // o último nó agora aponta para o novo nó
    }
}


// Função que imprime todos os valores da lista, começando pela cabeça h.
// Se h for NULL, imprime "Lista Vazia!".
// Se h não for NULL, percorre de h até o final, imprimindo o valor de cada nó.
void imprime(Node* h){
    if(h == NULL){                              // se a lista está vazia
        printf("Lista Vazia!\n");               // imprime mensagem de lista vazia
    } else {                                    // se houver pelo menos um nó
        while (h != NULL){                      // percorre até que h seja NULL
            printf("%d ", h->valor);            // imprime o valor do nó atual
            h = h->next;                        // avança para o próximo nó
        }
    }
    printf("\n");                               // quebra de linha após impressão
}


// Função que remove o nó que está no final da lista (último nó).
// Se a lista for vazia, imprime "Lista Vazia!".
// Se tiver só um nó, libera ele e deixa a cabeça NULL.
// Se tiver mais de um nó, percorre até o penúltimo e libera o último.
void removeUltimo(Node** h){
    if(*h == NULL){                             // se a lista está vazia
        printf("Lista Vazia!\n");               // imprime mensagem
    } else if ((*h)->next == NULL){             // se só existe um nó na lista
        free(*h);                               // libera o nó da cabeça
        *h = NULL;                              // marca a lista como vazia
    } else {                                    // se existem dois ou mais nós
        Node* aux = *h;                         // começa no primeiro nó
        while (aux->next->next != NULL){        // percorre até o penúltimo nó (nó cujo próximo aponta para o último)
            aux = aux->next;                    // avança para o próximo nó
        }
        free(aux->next);                        // libera o último nó da memória
        aux->next = NULL;                       // o penúltimo nó agora aponta para NULL (vira o novo último)
    }
}


// Função alternativa de remoção do último nó, usando dois ponteiros.
// Faz basicamente a mesma coisa que removeUltimo, só que guarda sempre o nó anterior explicitamente.
void removeUltimoDoisPonteiros(Node** h){
    if(*h == NULL){                             // se a lista está vazia
        printf("Lista Vazia\n");                // imprime mensagem
    } else if((*h)->next == NULL){              // se só existe um nó
        free(*h);                               // libera o nó
        *h = NULL;                              // lista fica vazia
    } else {                                    // se existem dois ou mais nós
        Node* aux = *h;                         // ponteiro que percorre a lista
        Node* n = *h;                           // guarda o nó anterior a aux
        while (aux->next != NULL){              // enquanto não chegar ao último nó
            n = aux;                            // n aponta para o nó anterior a aux
            aux = aux->next;                    // aux avança para o próximo
        }
        free(aux);                              // libera o último nó
        n->next = NULL;                         // o penúltimo nó (n) agora aponta para NULL
    }
}


// Função busca(Node* h, int valor) que procura o nó que tem o campo "valor" igual ao valor passado.
// Retorna o ponteiro para o nó encontrado, ou NULL se não encontrar.
Node* busca(Node* h, int valor){
    if(h == NULL){                              // se a lista está vazia
        return NULL;                            // não há nada para buscar
    } else {                                    // se a lista não está vazia
        Node* aux = h;                          // começa na cabeça
        while (aux != NULL && aux->valor != valor){ // enquanto houver nó e o valor não for o procurado
            aux = aux->next;                    // avança para o próximo
        }
        return aux;                             // retorna o nó encontrado (ou NULL se não encontrou)
    }
}


// Função que remove o nó que está na posição "pos" da lista (0‑indexada).
// Se a lista estiver vazia ou pos > 0 e tiver só 1 nó, imprime uma mensagem de erro.
// Percorre até a posição pos; se o nó existe, salva um ponteiro para ele, atualiza o anterior->next e libera o nó.
void removePos(Node** h, int pos){
    if (*h == NULL){                            // se a lista está vazia
        printf("Lista vazia\n");                // imprime mensagem
    } else if((*h)->next == NULL && pos > 0){   // se tem só um nó e quer remover posição > 0
        printf("Nao eh possivel remover\n");    // removeação em posição inválida
    } else {                                    // se a posição pode existir
        int cont = 0;                           // contador de posição atual
        Node* aux = *h;                         // ponteiro que percorre a lista
        Node* anterior = *h;                    // ponteiro que guarda o nó anterior a aux
        while (aux != NULL && cont != pos){     // enquanto ainda houver nó e não chegou na posição desejada
            cont++;                             // incrementa o contador da posição
            anterior = aux;                     // atualiza o nó anterior
            aux = aux->next;                    // avança para o próximo nó
        }
        if(aux != NULL){                        // se encontrou o nó na posição pos
            anterior->next = aux->next;         // faz o nó anterior pular o nó atual (remove o elo)
            free(aux);                          // libera o nó da posição pos
        } else {                                // se chegou ao fim sem achar a posição
            printf("Nao encontrado\n");         // imprimimos que a posição não existe
        }
    }
}


// Função que insere um novo nó com valor "valor" na posição "pos" da lista (0‑indexada).
// Cria o nó, percorre até a posição desejada e ajusta os ponteiros para "abraçar" o novo nó.
void inserirPos(Node** h, int pos, int valor){
    Node* novo = createNode(valor);             // cria o novo nó com o valor desejado
    if(*h == NULL && pos > 0){                  // se a lista está vazia e pos > 0
        printf("Nao eh possivel inserir\n");    // não é possível inserir em posição maior que 0
    } else if(*h == NULL){                      // se a lista está vazia e pos == 0
        printf("Lista vazia\n");                // (na prática, seria o primeiro nó, mas aqui só avisa)
    } else {                                    // se a lista não está vazia
        int posAtual = 0;                       // contador da posição atual
        Node* aux = *h;                         // ponteiro que percorre a lista
        Node* anterior = *h;                    // ponteiro que guardará o nó anterior
        while (aux != NULL && posAtual != pos) { // enquanto houver nó e não chegou na posição pos
            posAtual++;                         // avança a posição
            anterior = aux;                     // atualiza o nó anterior
            aux = aux->next;                    // avança para o próximo nó
        }
        if(aux != NULL){                        // se a posição pos existe (nó aux foi encontrado)
            anterior->next = novo;              // o nó anterior aponta agora para o novo nó
            novo->next = aux;                   // o novo nó aponta para o nó que estava nessa posição (desloca ele para frente)
        } else {                                // se chegou ao fim sem achar a posição pos
            printf("Posicao nao existe\n");     // mensagem de erro
        }
    }
}


// Função que insere um novo nó no início da lista, fazendo esse nó a nova cabeça.
void inserirInicio(Node** h, int valor){
    Node* novo = createNode(valor);             // cria o novo nó com o valor fornecido
    novo->next = *h;                            // o novo nó aponta para o que antes era a cabeça
    *h = novo;                                  // agora o novo nó é a cabeça da lista
    // Node* novo = createNode(valor);          // (comentado): alternativa duplicada, redundante
    // Node* aux = *h;                          // (comentado): código comentado que fazia exatamente o mesmo
    // *h = novo;                               // (comentado): alternativa de atualização da cabeça
    // novo->next = aux;                        // (comentado): alternativa equivalente ao novo->next = *h;
}


// Função que remove o nó que está no início da lista (cabeça).
// Se a lista não estiver vazia, salva a cabeça, atualiza o ponteiro cabeça para o próximo nó e libera o nó removido.
void removerInicio(Node** h){
    if (*h != NULL){                            // se a lista não está vazia
        Node* aux = *h;                         // salva o nó da cabeça
        *h = aux->next;                         // a nova cabeça passa a ser o próximo nó
        free(aux);                              // libera o nó que saiu da cabeça
    } else {                                    // se a lista está vazia
        printf("Lista vazia\n");                // imprime mensagem de erro
    }
}


// Função que insere o valor na lista mantendo a ordem crescente do campo "valor".
// Se a lista estiver vazia ou o valor for menor que o valor da cabeça, insere na cabeça.
// Caso contrário, percorre até achar a posição correta (aux->valor >= valor) e insere o novo nó logo antes dele.
void inserirOrdenado(Node** h, int valor){
    Node* novo = createNode(valor);             // cria o novo nó com o valor desejado
    if(*h == NULL || valor < (*h)->valor){      // se a lista está vazia ou o valor for menor que o valor da cabeça
        novo->next = *h;                        // novo nó aponta para o que antes era a cabeça
        *h = novo;                              // novo nó vira a nova cabeça
    } else {                                    // se precisa inserir no meio ou no final
        Node* aux = *h;                         // começa na cabeça
        Node* anterior = *h;                    // guarda o nó anterior
        while (aux != NULL && aux->valor < valor){ // percorre enquanto o valor do nó atual for menor que o valor desejado
            anterior = aux;                     // atualiza o nó anterior
            aux = aux->next;                    // avança para o próximo nó
        }
        anterior->next = novo;                  // o nó anterior aponta para o novo nó
        novo->next = aux;                       // o novo nó aponta para o nó que vinha logo depois
    }
}


// Função que intercala os elementos de duas listas (l1 e l2) em uma nova lista, começando com o primeiro nó de l1,
// e depois alternando l2, l1, l2, l1...
// Retorna a cabeça da nova lista intercalada.
Node* intercala(Node* l1, Node* l2){
    Node* head = createNode(l1->valor);         // cria o primeiro nó com o valor do primeiro nó de l1
    Node* aux = head;                           // aux percorrerá a lista intercalada
    l1 = l1->next;                              // passa para o próximo nó de l1 (o primeiro já foi usado)
    while(l1 != NULL || l2 != NULL){            // enquanto ainda houver nó em l1 ou em l2
        if(l2 != NULL){                         // se ainda houver nó em l2
            aux->next = createNode(l2->valor);  // cria um nó com o valor de l2 e o liga ao final da lista
            aux = aux->next;                    // aux avança para o novo nó (último)
            l2 = l2->next;                      // avança o ponteiro de l2 para o próximo nó
        }
        if(l1 != NULL){                         // se ainda houver nó em l1
            aux->next = createNode(l1->valor);  // cria um nó com o valor de l1 e o liga ao final
            aux = aux->next;                    // aux avança para o novo nó (último)
            l1 = l1->next;                      // avança o ponteiro de l1 para o próximo nó
        }
    }
    return head;                                // retorna a cabeça da nova lista intercalada
}


// Função principal que demonstra o uso de todas as funções definidas.
// 1. Cria duas listas l1 e l2.
// 2. Adiciona vários valores em l1 e l2.
// 3. Usa diversas funções (remoção, inserção, busca, intercalação) e imprime o estado da lista a cada passo.
int main(){
    Node *l1 = NULL, *l2 = NULL, *resultado = NULL; // inicializa três ponteiros de lista como NULL (listas vazias)


    printf("=== Criando e manipulando lista l1 ===\n");   // mensagem de início do teste de l1
    add(&l1, 30);                                         // insere 30 no final de l1
    add(&l1, 50);                                         // insere 50 no final de l1
    add(&l1, 70);                                         // insere 70 no final de l1
    imprime(l1);                                          // imprime estado atual de l1 (30 50 70)


    printf("Removendo ultimo de l1 (removeUltimo)\n");    // mensagem de remoção do último
    removeUltimo(&l1);                                    // remove o último nó de l1
    imprime(l1);                                          // novo estado: 30 50


    printf("Inserindo no inicio de l1\n");                // mensagem de inserção no início
    inserirInicio(&l1, 10);                               // insere 10 no início de l1
    imprime(l1);                                          // estado: 10 30 50


    printf("Inserindo ordenado (20)\n");                  // mensagem de inserção ordenada
    inserirOrdenado(&l1, 20);                             // insere 20 em ordem crescente em l1
    imprime(l1);                                          // estado: 10 20 30 50


    printf("Removendo inicio de l1\n");                   // mensagem de remoção da cabeça
    removerInicio(&l1);                                   // remove o primeiro nó de l1
    imprime(l1);                                          // estado: 20 30 50


    printf("Inserindo na posicao 2 o valor 40\n");        // mensagem
    
    printf("Buscando valor 30 em l1\n");          // mensagem de busca por 30
    Node* ret = busca(l1, 30);                    // chama busca na lista l1 procurando valor 30
    if (ret == NULL)                              // se ret for NULL, o valor não foi encontrado
        printf("Nao encontrado\n");               // imprime mensagem de não encontrado
    else                                          // se ret != NULL, o valor foi encontrado
        printf("Encontrado valor: %d\n", ret->valor); // imprime o valor encontrado (30)


    printf("Removendo posicao 3 (removePos)\n");  // mensagem de remoção na posição 3
    removePos(&l1, 3);                            // remove o nó na posição 3 de l1
    imprime(l1);                                  // imprime a lista após a remoção (20 30 40)


    printf("Removendo ultimo com dois ponteiros (removeUltimoDoisPonteiros)\n"); // mensagem de remoção do último com a função alternativa
    removeUltimoDoisPonteiros(&l1);               // remove o último nó de l1 usando dois ponteiros
    imprime(l1);                                  // resultado: 20 30


    printf("\n=== Criando e manipulando lista l2 ===\n"); // início da manipulação da lista l2
    add(&l2, 25);                                 // insere 25 no final de l2
    add(&l2, 35);                                 // insere 35 no final de l2
    add(&l2, 45);                                 // insere 45 no final de l2
    imprime(l2);                                  // impressão de l2: 25 35 45


    printf("\n=== Intercalando l1 e l2 ===\n");   // mensagem de início da intercalação
    resultado = intercala(l1, l2);                // chama função intercala com l1 e l2; l1 = 20→30, l2 = 25→35→45
    imprime(resultado);                           // imprime a lista intercalada: 20 25 30 35 45


    printf("=== Testando funcoes restantes na lista resultado ===\n"); // mensagem de início de novos testes em "resultado"
    inserirInicio(&resultado, 5);                 // insere 5 no início de resultado
    imprime(resultado);                           // resultado: 5 20 25 30 35 45


    removerInicio(&resultado);                    // remove o primeiro nó de resultado
    imprime(resultado);                           // resultado: 20 25 30 35 45


    inserirPos(&resultado, 2, 28);                // insere 28 na posição 2 (0-indexada) de resultado
    imprime(resultado);                           // resultado: 20 25 28 30 35 45


    removePos(&resultado, 4);                     // remove o nó na posição 4 de resultado
    imprime(resultado);                           // resultado: 20 25 28 30 45


    removeUltimo(&resultado);                     // remove o último nó de resultado
    imprime(resultado);                           // resultado: 20 25 28 30


    printf("Removendo ultimo com dois ponteiros (removeUltimoDoisPonteiros)\n"); // mensagem de remoção do último com a função alternativa
    removeUltimoDoisPonteiros(&resultado);        // remove o último nó de resultado usando dois ponteiros
    imprime(resultado);                           // resultado final: 20 25 28


    return 0;                                     // termina main com status de sucesso (0)
}