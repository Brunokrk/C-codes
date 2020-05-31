//Programador : Bruno Marchi Pires
//Instagram : @tecno__point
//O código descreve uma pilha dinâmica duplamente encadeada (PDDE)

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    //Struct que descreve cada nodo da pilha
    int x;
    struct nodo *acima;
    struct nodo *abaixo;
}Nodo_PDDE;

typedef struct descritorPDDE{
    Nodo_PDDE *topo;
}DescritorPDDE;

void inicializa_PDDE(DescritorPDDE **descritor_pilha){
    *descritor_pilha = (DescritorPDDE *)malloc(sizeof(DescritorPDDE));
    (*descritor_pilha)->topo = NULL;
}

void push_stack (DescritorPDDE *descritor_pilha, int value){
    //adiciona um nodo na pilha

    Nodo_PDDE *New_Nodo;
    New_Nodo = (Nodo_PDDE *)malloc(sizeof(Nodo_PDDE));

    if(descritor_pilha->topo==NULL){
        //Pilha está vazia, e o primeiro elemento será adicionado
        descritor_pilha->topo = New_Nodo;
        New_Nodo->acima = NULL;
        New_Nodo->abaixo = NULL;
        New_Nodo->x = value;
    }else{
        //Já existem nodos na pilha
        New_Nodo->abaixo = descritor_pilha->topo;
        New_Nodo->acima = NULL;
        New_Nodo->x = value;
        (descritor_pilha->topo)->acima = New_Nodo; //faz o nodo mais superior apontar para o novo superior
        descritor_pilha->topo = New_Nodo;//move o ponteiro topo para o novo nodo, que agora é o topo da pilha
    }
}

void pop_stack(DescritorPDDE *descritor_pilha){
    if(descritor_pilha->topo == NULL){
        printf("\n A pilha está vazia, não existem nodos para retirar!");
        return;
    }

    Nodo_PDDE *aux; //nodo auxiliar para manipular os ponteiros corretamente
    aux=(Nodo_PDDE *)malloc(sizeof(Nodo_PDDE));
    
    if((descritor_pilha->topo)->abaixo ==NULL){
        //Só existe um nodo na pilha
        aux->abaixo = descritor_pilha->topo;
        free(aux->abaixo);
        free(aux);
        descritor_pilha->topo = NULL;
    }else{
        aux->abaixo = descritor_pilha->topo;
        descritor_pilha->topo = (aux->abaixo)->abaixo;
        (descritor_pilha->topo)->acima = NULL;
        free(aux->abaixo);
        free(aux);
    }
}

void print_stack(DescritorPDDE *descritor_pilha){
    //Imprime os elementos da pilha
    Nodo_PDDE *aux;
    if(descritor_pilha->topo == NULL){
        printf("\n A pilha esta vazia, nao possui nodos!");
        return;
    }else{
        aux = descritor_pilha->topo;
        while(aux != NULL){
            printf("\n%d", aux->x);
            aux = aux->abaixo;
        }
    }
}

void reset_stack(DescritorPDDE *descritor_pilha){
    //Reseta a pilha
    Nodo_PDDE *aux = NULL;
    if(descritor_pilha->topo == NULL){
        printf("\n A pilha esta vazia, nao precisa ser resetada!");
        return;
    }else{
        aux = descritor_pilha->topo->abaixo;
        while(aux != NULL){
            free(descritor_pilha->topo);
            descritor_pilha->topo = aux;
            aux = aux->abaixo;
        }
        free(descritor_pilha->topo);
        descritor_pilha->topo = NULL;
        printf("\nPilha resetada!");
    }
}
void destruct_stack(DescritorPDDE *descritor_pilha){
    //Destroi a pilha
    reset_stack(descritor_pilha);
    free(descritor_pilha);
    printf("\n pilha destruida");
}

int main (){
    //Teste para ver se a pilha está funcionando
    DescritorPDDE *descritor_pilha = NULL;
    inicializa_PDDE(&descritor_pilha);

    push_stack(descritor_pilha, 20);
    push_stack(descritor_pilha, 30);
    push_stack(descritor_pilha, 10);
    print_stack(descritor_pilha);
    reset_stack(descritor_pilha);
    print_stack(descritor_pilha);
    push_stack(descritor_pilha, 2);
    push_stack(descritor_pilha, 3);
    push_stack(descritor_pilha, 1);
    destruct_stack(descritor_pilha);
}