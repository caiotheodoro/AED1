#include "pilha.h"


/**************************************
* DADOS
**************************************/

typedef struct {
	Pilha* p1;
    Pilha* p2;
	int qtdeElementos;
}Fila;

/**************************************
* PROTÓTIPOS
**************************************/
Fila* fila_criar();
void fila_destruir(Fila* f);
Boolean fila_inserir(Fila* f, TipoElemento elemento);
Boolean fila_remover(Fila* f, TipoElemento* saida); // estratégia do scanf
Boolean fila_primeiro(Fila* f, TipoElemento* saida); // estratégia do scanf
Boolean fila_vazia(Fila* f);


/**************************************
* EXERCICIO 02
**************************************/

Fila* fila_criar(){
   
}

void fila_destruir(Fila* f){
   
}

Boolean fila_inserir(Fila* f, TipoElemento elemento){
   
}

Boolean fila_remover(Fila* f, TipoElemento* saida){ // estratégia do scanf
   
}

Boolean fila_primeiro(Fila* f, TipoElemento* saida){// estratégia do scanf
    
}

Boolean fila_vazia(Fila* f){

}



