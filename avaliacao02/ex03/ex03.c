#include "lista_sentinela.h"
#include "../arquivosAuxiliares/tad_teste.c"

/**************************************
* PROTOTIPOS
**************************************/
void teste01();
void teste02();
void teste03();
void teste04();
void teste05();


int main(){
    teste01();
    teste02();
    teste03();
    teste04();
    teste05();
}


/**************************************
* TESTES
**************************************/
void teste01(){
    printf("\n----------------------------------------------\n");
    printf(">>> TESTE 01                                    \n");
    printf("------------------------------------------------\n");
    Lista* l1 = lista_criar();
    lista_inserirFim(l1, 10);
    lista_inserirFim(l1, 20);
    lista_inserirFim(l1, 30);
    lista_inserirFim(l1, 40);
    lista_inserirFim(l1, 50);
    lista_inserirFim(l1, 60);

    Lista* l2 = lista_criar();
    lista_inserirFim(l2, 70);
    lista_inserirFim(l2, 80);
    lista_inserirFim(l2, 90);
    lista_inserirFim(l2, 100);
    lista_inserirFim(l2, 110);
    lista_inserirFim(l2, 120);

    char str_l1[500];
    char str_l2[500];

    lista_intercalar(l1, l2);
    lista_toString(l1, str_l1);
    lista_toString(l2, str_l2);
    
    test(strcmp(str_l1, "[10,20,30,40,50,60,70,80,90,100,110,120]") == 0, "l1");
    test(strcmp(str_l2, "[]") == 0, "l2");
}

void teste02(){
    printf("\n----------------------------------------------\n");
    printf(">>> TESTE 02                                    \n");
    printf("------------------------------------------------\n");
    Lista* l1 = lista_criar();
    lista_inserirFim(l1, 70);
    lista_inserirFim(l1, 80);
    lista_inserirFim(l1, 90);
    lista_inserirFim(l1, 100);
    lista_inserirFim(l1, 110);
    lista_inserirFim(l1, 120);

    Lista* l2 = lista_criar();
    lista_inserirFim(l2, 10);
    lista_inserirFim(l2, 20);
    lista_inserirFim(l2, 30);
    lista_inserirFim(l2, 40);
    lista_inserirFim(l2, 50);
    lista_inserirFim(l2, 60);


    char str_l1[500];
    char str_l2[500];

    lista_intercalar(l1, l2);
    lista_toString(l1, str_l1);
    lista_toString(l2, str_l2);

    test(strcmp(str_l1, "[10,20,30,40,50,60,70,80,90,100,110,120]") == 0, "l1");
    test(strcmp(str_l2, "[]") == 0, "l2");
}

void teste03(){
    printf("\n----------------------------------------------\n");
    printf(">>> TESTE 03                                    \n");
    printf("------------------------------------------------\n");
    Lista* l1 = lista_criar();
    lista_inserirFim(l1, 10);
    lista_inserirFim(l1, 20);
    lista_inserirFim(l1, 35);
    lista_inserirFim(l1, 50);
    
    
    Lista* l2 = lista_criar();
    lista_inserirFim(l2, 5);
    lista_inserirFim(l2, 15);
    lista_inserirFim(l2, 25);
    lista_inserirFim(l2, 30);
    lista_inserirFim(l2, 60);
    lista_inserirFim(l2, 70);
    
    char str_l1[500];
    char str_l2[500];

    lista_intercalar(l1, l2);
    lista_toString(l1, str_l1);
    lista_toString(l2, str_l2);

    test(strcmp(str_l1, "[5,10,15,20,25,30,35,50,60,70]") == 0, "l1");
    test(strcmp(str_l2, "[]") == 0, "l2");
}

void teste04(){
    printf("\n----------------------------------------------\n");
    printf(">>> TESTE 04                                    \n");
    printf("------------------------------------------------\n");
    Lista* l1 = lista_criar();
    lista_inserirFim(l1, 1);
    lista_inserirFim(l1, 2);
    lista_inserirFim(l1, 3);
    
    Lista* l2 = lista_criar();
    
    char str_l1[500];
    char str_l2[500];

    lista_intercalar(l1, l2);
    lista_toString(l1, str_l1);
    lista_toString(l2, str_l2);

    test(strcmp(str_l1, "[1,2,3]") == 0, "l1");
    test(strcmp(str_l2, "[]") == 0, "l2");
}

void teste05(){
    printf("\n----------------------------------------------\n");
    printf(">>> TESTE 05                                    \n");
    printf("------------------------------------------------\n");
    Lista* l1 = lista_criar();
    
    Lista* l2 = lista_criar();
    lista_inserirFim(l2, 1);
    lista_inserirFim(l2, 2);
    lista_inserirFim(l2, 3);
    
    char str_l1[500];
    char str_l2[500];

    lista_intercalar(l1, l2);
    lista_toString(l1, str_l1);
    lista_toString(l2, str_l2);

    test(strcmp(str_l1, "[1,2,3]") == 0, "l1");
    test(strcmp(str_l2, "[]") == 0, "l2");
}


