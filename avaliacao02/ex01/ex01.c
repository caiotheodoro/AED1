#include <stdio.h>
#include <string.h>
#include "pilha.h"
#include "../arquivosAuxiliares/tad_teste.c"

typedef enum{
    OK = 0, 
    ERRO1 = 1, //Falta um delimitador de abertura
    ERRO2 = 2, //Falta um delimitador de fechamento
    ERRO3 = 3, //Incompatibilidade de delimitadores
}Status;


/**************************************
* EXERCICIO 01
**************************************/
Status valida_expressao(char* exp){
 //IMPLEMENTAR   
    int i=0,j=0,k=0;
    int delimitAbertura[100];
    int delimitFechamento[100];

    while (exp[i] != '\0')
    {
        if(exp[i]== '(' || exp[i]== '[' || exp[i]== '{'){
            delimitAbertura[j] = exp[i];
            printf("delimitador abertura %d = %c\n",j,delimitAbertura[j]);
            j++;
        }
        if(exp[i]== ')' || exp[i]== ']' || exp[i]== '}'){
            delimitFechamento[k] = exp[i];
            printf("delimitador fechadura %d = %c\n",k,delimitFechamento[k]);    
            k++;
        }        
        
        i++;
    }
    
    if(k > j){
        return ERRO1;
    }
    else if(j > k){
        return ERRO2;
    } else {

    int cont = j -1;
    for(int i=0;i<j;i++){

       switch (delimitAbertura[i])
        {
        case '(':
        if(delimitFechamento[cont] != ')') return ERRO3;
        else cont--;
        break;
        case '[':
        if(delimitFechamento[cont] != ']') return ERRO3;
        else cont--;
        break;
        case '{':
        if(delimitFechamento[cont] != '}')  return ERRO3;
        else cont--;
        break;                     
        default:
        break;
        }
    }   
  }
  return OK; 
}




void testeExpressoesCorretas(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTE EXPRESSOES CORRETAS\n");
    printf("------------------------------------------------\n");
    char exp[100];

    strcpy(exp, "(1+2)");
    test(valida_expressao(exp) == OK, "Expressao Ok");
    strcpy(exp, "{ [( ) ] }");
    test(valida_expressao(exp) == OK, "Expressao Ok");
}

void testeErro1(){
    printf("\n--------------------------------------------------\n");
    printf(">>> TESTE ERRO1 Ausencia de delimitador de ABERTURA\n");
    printf("----------------------------------------------------\n");
    char exp[100];
    
    strcpy(exp, "())");
    test(valida_expressao(exp) == ERRO1, "Ausencia de (");
    strcpy(exp, "()]");
    test(valida_expressao(exp) == ERRO1, "Ausencia de [");
    strcpy(exp, "( ) ( ) () ( ) ( ) { ( ) } }");
    test(valida_expressao(exp) == ERRO1, "Ausencia de {");
}

void testeErro2(){
    printf("\n---------------------------------------------------\n");
    printf(">>> TESTE ERRO2 Ausencia de delimitador de FECHAMENTO\n");
    printf("-----------------------------------------------------\n");
    char exp[100];

    strcpy(exp, "(()");
    test(valida_expressao(exp) == ERRO2, "Ausencia de )");
    strcpy(exp, "[()");
    test(valida_expressao(exp) == ERRO2, "Ausencia de ]");
    strcpy(exp, "  {({[]()})");
    test(valida_expressao(exp) == ERRO2, "Ausencia de }");
}
void testeErro3(){
    printf("\n---------------------------------------------------\n");
    printf(">>> TESTE ERRO3 Incompatibilidade de delimitadores   \n");
    printf("-----------------------------------------------------\n");
    char exp[100];

    strcpy(exp, "(]");
    test(valida_expressao(exp) == ERRO3, "Incompatibilidade (]");
    strcpy(exp, "[{[()]}}");
    test(valida_expressao(exp) == ERRO3, "Incompatibilidade [}");
    strcpy(exp, "()[{}{]}");
    test(valida_expressao(exp) == ERRO3, "Incompatibilidade {]");
}



int main(){
    
    testeExpressoesCorretas();
    testeErro1();
    testeErro2();
    testeErro3();

    report();
    

}

