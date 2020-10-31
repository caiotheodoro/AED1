#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct no{
    int dado;
    struct no* prox;
}No;



No* criar_no(int  elemento){
    No* no = (No*) malloc(sizeof(No));
    no->dado = elemento;
    no->prox = NULL;
    return no;
}

void listaOcorrencia_toString(No** lista, int numLinhas, char* saida){
    int i, pos = 0;
    
    for(i=0; i<numLinhas; i++){
        saida[pos++] = '[';
        No* aux = lista[i];
        while(aux != NULL){
            char str[10];
            sprintf(str, "%d", aux->dado);
            int numCaracteres = (int)strlen(str);
            memcpy(saida+pos, str, numCaracteres*sizeof(char));            
            pos += numCaracteres;

            if(aux->prox != NULL) saida[pos++] = ',';
            aux = aux->prox;
        }
        saida[pos++] = ']';
        saida[pos++] = '\n';
        saida[pos] = '\0';

    }


}

/**************************************
* EXERCICIO 04
**************************************/
No** listaOcorrencia(int* mat, int linhas, int colunas){
    int i,j;

    // cria um vetor de ponteiros de nós e inicializa as posicoes com NULL
    No** lista = (No**)calloc(linhas, sizeof(No*));
    for(i=0; i<linhas; i++) lista[i] = NULL;
    

    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            printf("%3d ", *(mat + (i*colunas) + j));

            
            
        }

        printf("\n");
    }
    return lista;
} 


int main(){
    char string[200];

    printf("\n----------------------------------------------\n");
    printf(">>> TESTE 01                                    \n");
    printf("------------------------------------------------\n");
    int matriz1[4][3] ={{1,0,2},{0,0,0},{3,4,5}, {0,0,6}};  

    No** lista1 = listaOcorrencia(&matriz1[0][0], 4, 3);
    listaOcorrencia_toString(lista1, 4, string);
    printf("\n%s\n", string);

    printf("\n----------------------------------------------\n");
    printf(">>> TESTE 02                                    \n");
    printf("------------------------------------------------\n");
    int matriz2[3][3] ={{0,0,0},{0,0,0},{0,50,0}};  

    No** lista2 = listaOcorrencia(&matriz2[0][0], 3, 3);
    listaOcorrencia_toString(lista2, 3, string);
    printf("\n%s\n", string);

    printf("\n----------------------------------------------\n");
    printf(">>> TESTE 03                                    \n");
    printf("------------------------------------------------\n");
    int matriz3[3][3] ={{1,2,3},{4,5,6},{7,8,9}};  

    No** lista3 = listaOcorrencia(&matriz3[0][0], 3, 3);
    listaOcorrencia_toString(lista3, 3, string);
    printf("\n%s\n", string);




}