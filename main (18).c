/*

    Lista encadeada com cabeça e cauda.

*/

#include <stdio.h>
#include <stdlib.h>

struct no{
    int num;
    struct no * prox;
};

typedef struct{
    struct no * cabeca;
    struct no * cauda;
}Lista;

void limpar_lista(Lista * l){
    if(l->cabeca != NULL){
        struct no * aux = l->cabeca->prox;
        free(l->cabeca);
        l->cabeca = aux;
        limpar_lista(l);
    }
    
    l->cabeca = NULL;
    l->cauda = NULL;
}

//Função para inicializar_lista(Lista * l), cabeca = NULL e cauda = NULL
Lista * inicializar_lista(){
    Lista * l = (Lista*) malloc(sizeof(Lista));
    
    l->cabeca = NULL;
    l->cauda = NULL;
    
    return l;
}

int vazia(Lista * l){
    return (l->cabeca == NULL && l->cauda == NULL);
}

void imprimir(struct no * aux){
    if(aux != NULL){
        printf("%d ", aux->num);
        imprimir(aux->prox);
    }
}

Lista * inserir_cabeca(Lista * l, int num){
    struct no * aux = (struct no*) malloc(sizeof(struct no));
    
    aux->num = num;
    aux->prox = l->cabeca;
    l->cabeca = aux;
    
    if(l->cauda == NULL){
        l->cauda = aux;
    }
    
    return l;
}

Lista * inserir_cauda(Lista * l, int num){
    struct no * aux = (struct no*) malloc(sizeof(struct no));
    aux->num = num;
    aux->prox = NULL;
    
    if(vazia(l)){
        l->cabeca = aux;
        l->cauda = aux;
    }else{
        l->cauda->prox = aux;
        l->cauda = aux;
    }
   
    return l;
}

void remover(Lista * l, int num){
    struct no * aux = l->cabeca, *anterior = NULL;
    
    while(aux != NULL && aux->num != num){
        anterior = aux;
        aux = aux->prox;
    }
    
    if(aux != NULL){
        
        if(aux == l->cabeca){ //Então, a remoção é na cabeça
        
            l->cabeca = aux->prox;
            if(l->cabeca == NULL){
                l->cauda = NULL;
            }
            
        }else if(aux == l->cauda){ //Então, a remoção é na cauda
        
            anterior->prox = NULL;
            l->cauda = anterior;
            
        }else{ //Então, a remoção é no meio
        
            anterior->prox = aux->prox;
        }
        
        free(aux);
    }
}

int main()
{
    Lista * l1 = inicializar_lista();
    Lista * l2 = inicializar_lista();
    
    printf("Lista 1 é vazia? RESPOSTA: %d\n", vazia(l1));
    
    l1 = inserir_cabeca(l1, 10);
    l1 = inserir_cabeca(l1, 20);
    l1 = inserir_cabeca(l1, 30);
    l1 = inserir_cabeca(l1, 40);
    l1 = inserir_cabeca(l1, 50);
    
    printf("Lista 2 é vazia? RESPOSTA: %d\n", vazia(l2));

    l2 = inserir_cauda(l2, 60);
    l2 = inserir_cauda(l2, 70);
    l2 = inserir_cauda(l2, 80);
    l2 = inserir_cauda(l2, 90);
    
    printf("Lista 1: ");
    imprimir(l1->cabeca);
    printf("\n");
    
    printf("Lista 2: ");
    imprimir(l2->cabeca);
    printf("\n");
    
    printf("Lista 1 é vazia? RESPOSTA: %d\n", vazia(l1));
    printf("Lista 2 é vazia? RESPOSTA: %d\n", vazia(l2));
    
    remover(l1, 30);
    remover(l1, 50);
    remover(l1, 10);
    
    printf("Lista 1 após a remoção: ");
    imprimir(l1->cabeca);
    printf("\n");
    
    remover(l2, 60);
    remover(l2, 90);
    
    printf("Lista 2 após a remoção: ");
    imprimir(l2->cabeca);
    printf("\n");
    
    limpar_lista(l1);
    limpar_lista(l2);
    
    printf("Lista 1 limpa: ");
    imprimir(l1->cabeca);
    printf("\n");
    
    printf("Lista 2 limpa: ");
    imprimir(l2->cabeca);
    printf("\n");
    
    return 0;
}
