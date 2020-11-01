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

 Fila* nova = (Fila*)malloc(sizeof(Fila));
 nova->p1 = pilha_criar();
 nova->p2 = pilha_criar();
 nova->qtdeElementos = 0;

return nova;

}

void fila_destruir(Fila* f){

   pilha_destruir(f->p1);
   pilha_destruir(f->p2);
   free(f);
}

Boolean fila_inserir(Fila* f, TipoElemento elemento){
	if(!pilha_vazia(f->p2)){
		TipoElemento saida;
		for(int i=0;i<f->qtdeElementos;i++){

		pilha_desempilhar(f->p2, &saida);
		pilha_empilhar(f->p1,saida);

		}
	}
	pilha_empilhar(f->p1,elemento);
	f->qtdeElementos++;
   return true;
}

Boolean fila_remover(Fila* f, TipoElemento* saida){ // estratégia do scanf

  if(fila_vazia(f)) return false;

	if(!pilha_vazia(f->p1)){
		TipoElemento temp;
		for(int i=0;i<f->qtdeElementos;i++){

		pilha_desempilhar(f->p1, &temp);
		pilha_empilhar(f->p2,temp);

		}
	}

		pilha_desempilhar(f->p2,saida);
		f->qtdeElementos--;
		return true;
}



Boolean fila_vazia(Fila* f){
	  return (f->qtdeElementos == 0? true: false);
}

Boolean fila_primeiro(Fila* f, TipoElemento* saida){
  // estratégia do scanf
    if(fila_vazia(f)) return false;
	if(!pilha_vazia(f->p1)){
		TipoElemento temp;
		for(int i=0;i<f->qtdeElementos;i++){

		pilha_desempilhar(f->p1, &temp);
		pilha_empilhar(f->p2,temp);

		}
	}
		pilha_topo(f->p2,saida);
		return true;
}

