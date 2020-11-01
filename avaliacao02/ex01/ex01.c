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

  Pilha* p = pilha_criar();


    TipoElemento topo;
    TipoElemento removido;
    int i=0;

    while (exp[i] != '\0')
    {
      //  se for abertura, empilha e seta o topo.
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
            pilha_empilhar(p,exp[i]);
            topo =  exp[i];
        }
        
        else if(exp[i]== ')' || exp[i]== ']' || exp[i]== '}'){



        //se o topo for diferente de abertura, falta abertura
        if(topo != '(' || topo != '[' || topo != '{')
        return ERRO1; 
     

        // compara o topo com o exp[i], se nao equivaler, gera o erro3 (incompatibilidade)
          switch (topo)
        {
        case '(':
        if(exp[i] != ')') return ERRO3;
        break;
        case '[':
        if(exp[i] != ']') return ERRO3;
        break;
        case '{':
        if(exp[i] != '}')  return ERRO3;
        break;                     
        default:

        break;
        }
        
        
      //se pilha_topo for falso, a pilha foi esvaziada sem erros, logo, OK.
        if(pilha_topo(p,&topo) == false) return OK;
        else{ //se nao for, desempilha os 2 ultimos e seta o topo.
        pilha_desempilhar(p,&removido); 
        pilha_topo(p,&topo);
        }

        }

         i++; 
       
    }
  //se exp[i] ja tiver passado por abertura e nao houver fechamento, sairá do while pela condição, então não há fechamento, logo, erro2.
    return ERRO2;
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
