#include<stdlib.h>
#include<stdio.h>

typedef char TipoElemento;
typedef enum boolean{false=0, true=1} Boolean;

/**************************************
* DADOS
**************************************/
typedef struct no{
	TipoElemento dado;
	struct no    *prox;
}No;

typedef struct {
	No *topo;
	int qtdeElementos;
}Pilha;

/**************************************
* PROTÓTIPOS
**************************************/
Pilha* pilha_criar();
void pilha_destruir(Pilha* p);
Boolean pilha_empilhar(Pilha* p, TipoElemento elemento);
Boolean pilha_desempilhar(Pilha* p, TipoElemento* saida); // estratégia do scanf
Boolean pilha_topo(Pilha* p, TipoElemento* saida); // estratégia do scanf
Boolean pilha_vazia(Pilha* p);
void pilha_imprimir(Pilha* p);
int pilha_tamanho(Pilha* p);
Pilha* pilha_clone(Pilha* p);
void pilha_inverter(Pilha* p);
Boolean pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor);

/**************************************
* IMPLEMENTAÇÃO
**************************************/

Boolean pilha_ehValida(Pilha* p){
    return (p != NULL? true: false);    
}

No* criar_no(TipoElemento elemento, No* proximoNo){
    No* no = (No*) malloc(sizeof(No));
    no->dado = elemento;
    no->prox = proximoNo;
    return no;
}



Pilha* pilha_criar(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    p->qtdeElementos = 0;
    return p;
}


void pilha_destruir(Pilha* p){
    if(!pilha_ehValida(p)) return;

    No* aux;
    while(p->topo != NULL){
        aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
    }
    
    free(p);
}

Boolean pilha_empilhar(Pilha* p, TipoElemento elemento){
    if(!pilha_ehValida(p)) return false;
    
    No* novo = criar_no(elemento, NULL);
    novo->prox = p->topo;
    p->topo = novo;
    p->qtdeElementos++;
    return true;


}

Boolean pilha_desempilhar(Pilha* p, TipoElemento* saida){ // estratégia do scanf
    if(!pilha_ehValida(p)) return false;
    if(pilha_vazia(p)) return false;

    No* noRemovido = p->topo;
    p->topo = p->topo->prox;
    noRemovido->prox = NULL;
    p->qtdeElementos--;
    *saida = noRemovido->dado;
    free(noRemovido);

    return true;

}

Boolean pilha_topo(Pilha* p, TipoElemento* saida){ // estratégia do scanf
    if(!pilha_ehValida(p)) return false;
    if(pilha_vazia(p)) return false;
    
    *saida = p->topo->dado;
    return true;

}

Boolean pilha_vazia(Pilha* p){
    return (p->qtdeElementos == 0? true: false);
}

void pilha_imprimir(Pilha* p){
    if(!pilha_ehValida(p)) return;
    
    printf("[");
    No* aux = p->topo;
    while(aux != NULL){
        printf("%d", aux->dado);
        if(aux->prox != NULL) printf(", ");
        aux = aux->prox;
    }
    printf("]");
}

int pilha_tamanho(Pilha* p){
    return p->qtdeElementos;
}

Pilha* pilha_clone(Pilha* p){
    if(!pilha_ehValida(p)) return NULL;

    Pilha* clone = pilha_criar();
    No* aux = p->topo;
    while(aux != NULL){
        pilha_empilhar(clone, aux->dado);
        aux = aux->prox;
    }
    return clone;
}

void pilha_inverter(Pilha* p){
    if(!pilha_ehValida(p)) return;
    if(pilha_vazia(p)) return;

    Pilha* pilhaAux = pilha_criar();

    TipoElemento elemento = -1;
    while(!pilha_vazia(p)){
        pilha_desempilhar(p, &elemento);
        pilha_empilhar(pilhaAux, elemento);
    }
    p->topo = pilhaAux->topo;
    p->qtdeElementos = pilhaAux->qtdeElementos;
    free(pilhaAux);
}

Boolean pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor){
    if(!pilha_ehValida(p)) return false;

    int i;
    for(i=0; i < tamVetor ; i++){
        pilha_empilhar(p, vetor[i]);
    }
    return true;
}

