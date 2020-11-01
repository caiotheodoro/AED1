
#include "string.h"
#include "stdio.h"
#include "stdlib.h"


typedef int TipoElemento;
typedef enum boolean{false=0, true=1} Boolean;

/**************************************
* DADOS
**************************************/
typedef struct no{
	TipoElemento dado;
	struct no    *ant;
	struct no    *prox;
}No;

typedef struct lista{
	No *sentinela;
	int qtde;
}Lista;

/**************************************
* PROTÓTIPOS
**************************************/
Lista* lista_criar();
void lista_destruir(Lista* l);
Boolean lista_inserirFim(Lista* l, TipoElemento elemento);
Boolean lista_inserir(Lista* l, TipoElemento elemento, int posicao);
Boolean lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco);
int lista_removerElemento(Lista* l, TipoElemento elemento);
Boolean lista_substituir(Lista* l, int posicao, TipoElemento novoElemento);
int lista_posicao(Lista* l, TipoElemento elemento);
Boolean lista_buscar(Lista* l, int posicao, TipoElemento* endereco);
Boolean lista_contem(Lista* l, TipoElemento elemento);
int lista_tamanho(Lista* l);
Boolean lista_toString(Lista* l, char* enderecoString);
void lista_imprimir(Lista* l);
void lista_intercalar(Lista* a, Lista* b);

// PROTOTIPOS DAS FUNCOES AUXILIARES
No* criar_no(TipoElemento elemento);
No* criar_noSentinela();
void insere_esquerda(No* referencia, No* novo);
void insere_direita(No* referencia, No* novo);
void desconecta_no(No* no);

Boolean lista_ehValida(Lista* l);
Boolean posicao_ehValida(Lista* l, int pos);
Boolean posicao_ehPreenchida(Lista* l, int pos);
int converte_posicao(Lista* l, int pos);
No* devolve_enderecoNo(Lista* l, int pos);


/**************************************
* EXERCICIO 03
**************************************/
void lista_intercalar(Lista* a, Lista* b){
// IMPLEMENTAR

TipoElemento i=0,j=0,k=0;
TipoElemento val1,val2,removido;
TipoElemento size = lista_tamanho(a) + lista_tamanho(b);

while(i!=size){

// busca lista
    lista_buscar(a,j,&val1);
    lista_buscar(b,k,&val2);


// se o valor de B for menor que valor de A ou a lista de A ja tiver sido percorrida,
// insere valor de B na posicao i, remove a posicao de B e vai pro proximo elemento de B;
if(val1>val2 || j == lista_tamanho(a)){
  lista_inserir(a,val2,i);
  lista_removerPosicao(b,k,&removido);
  k++;
}
else if(val2>val1){ //se o valor de A for maior que o de B, vai pro proximo elemento de A;
  j++;

}
      lista_imprimir(a);
       i++;
}


}


/**************************************
* FUNÇÕES AUXILIARES
**************************************/
No* criar_no(TipoElemento elemento){
    No* no = (No*) malloc(sizeof(No));
    no->dado = elemento;
    return no;
}

No* criar_noSentinela(){
    No* no = (No*) malloc(sizeof(No));
    no->ant = no;
    no->prox = no;
    return no;
}

Boolean lista_ehValida(Lista* l){
    return (l != NULL? true: false);    
}

Boolean posicao_ehValida(Lista* l, int pos){
    if(pos < 0) return false;
    if(pos > l->qtde) return false;

    return true;
}

Boolean posicao_ehPreenchida(Lista* l, int pos){
    if(pos < 0) return false;
    if(pos >= l->qtde) return false;

    return true;
}

int converte_posicao(Lista* l, int pos){
    return (pos < 0? l->qtde + pos : pos);
}

No* devolve_enderecoNo(Lista* l, int pos){
    No* aux = l->sentinela;
    int i;
    for(i=0; i <= pos; i++) 
        aux = aux->prox;
    return aux;
}

void insere_esquerda(No* referencia, No* novo){
    novo->prox = referencia;
    novo->ant = referencia->ant;

    referencia->ant->prox = novo;
    referencia->ant = novo;
}

void insere_direita(No* referencia, No* novo){
    novo->ant = referencia;
    novo->prox = referencia->prox;

    referencia->prox->ant = novo;
    referencia->prox = novo;
}

void desconecta_no(No* no){
    no->prox->ant = no->ant;
    no->ant->prox = no->prox;
    no->ant = no->prox = NULL;
}


/**************************************
* IMPLEMENTAÇÃO
**************************************/

Lista* lista_criar(){
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->sentinela = criar_noSentinela();
    lista->qtde = 0;
    return lista;
}

void lista_destruir(Lista* l){
    No* aux;
    while(l->sentinela->prox != l->sentinela){
        aux = l->sentinela->prox;
        l->sentinela = l->sentinela->prox;
        free(aux);
    }
    free(l->sentinela);
    free(l);
}

Boolean lista_inserirFim(Lista* l, TipoElemento elemento){
    if(!lista_ehValida(l)) return false;

    lista_inserir(l, elemento, l->qtde);

    return true;
}

Boolean lista_inserir(Lista* l, TipoElemento elemento, int posicao){
    if(!lista_ehValida(l)) return false;
    posicao = converte_posicao(l, posicao);
    if(!posicao_ehValida(l, posicao)) return false;
    
    No* novo = criar_no(elemento);
    No* aux = devolve_enderecoNo(l, posicao-1);

    insere_direita(aux, novo);

    l->qtde++;
    return true;

}

Boolean lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco){
    if(!lista_ehValida(l)) return false;
    posicao = converte_posicao(l, posicao);
    if(!posicao_ehPreenchida(l, posicao)) return false;
    

    No* aux = devolve_enderecoNo(l, posicao);
    desconecta_no(aux);
    *endereco = aux->dado;
    free(aux);
    l->qtde--;
    return true;
}

int lista_removerElemento(Lista* l, TipoElemento elemento){
    if(!lista_ehValida(l)) return false;

    int posicao = lista_posicao(l, elemento);
    if(posicao == -1) return -1;
    
    TipoElemento item;
    lista_removerPosicao(l, posicao, &item);
    return posicao;
}

Boolean lista_substituir(Lista* l, int posicao, TipoElemento novoElemento){
    if(!lista_ehValida(l)) return false;
    posicao = converte_posicao(l, posicao);
    if(!posicao_ehPreenchida(l, posicao)) return false;

    No* no = devolve_enderecoNo(l, posicao);
    no->dado = novoElemento;
    return true;
}

int lista_posicao(Lista* l, TipoElemento elemento){
    if(!lista_ehValida(l)) return -1;

    int i = 0;
    No* aux = l->sentinela->prox;
    while(aux != l->sentinela){
        if(elemento == aux->dado) return i;
        aux = aux->prox;
        i++;
    }
    return -1;

}

Boolean lista_buscar(Lista* l, int posicao, TipoElemento* endereco){
    if(!lista_ehValida(l)) return false;
    posicao = converte_posicao(l, posicao);
    if(!posicao_ehPreenchida(l, posicao)) return false;

    No* no = devolve_enderecoNo(l, posicao);
    *endereco = no->dado;
    return true;

    
}
Boolean lista_contem(Lista* l, TipoElemento elemento){
    if(!lista_ehValida(l)) return false;

    int posicao = lista_posicao(l, elemento);
    return (posicao != -1? true : false);

}
int lista_tamanho(Lista* l){
    if(!lista_ehValida(l)) return -1;

    return l->qtde;
}

Boolean lista_toString(Lista* l, char* enderecoString){
    if(!lista_ehValida(l)) return false;

    int qtde = 0;
    char str[10];
    
    enderecoString[qtde++] = '[';
    No* aux = l->sentinela->prox;
    while(aux != l->sentinela){
        sprintf(str, "%d", aux->dado);
        int numCaracteres = strlen(str);
        memcpy(enderecoString+qtde, str, numCaracteres*sizeof(char));
        qtde += numCaracteres;

        if(aux->prox != l->sentinela){
            enderecoString[qtde++] = ',';
        }

        aux = aux->prox;
    }

    enderecoString[qtde++] = ']';
    enderecoString[qtde] = '\0';
    return true;
}

void lista_imprimir(Lista* l){
    if(!lista_ehValida(l)) return;

    printf("[");
    No* aux = l->sentinela->prox;
    while(aux != l->sentinela){
        printf("%d", aux->dado);
        if(aux->prox != l->sentinela) printf(", ");
        aux = aux->prox;
    }
    printf("]\n");
}
