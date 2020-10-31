
#include "filaComPilha.h"
#include "../arquivosAuxiliares/tad_teste.c"


int main(){

    TipoElemento elemento;

    Fila* f = fila_criar();
    fila_inserir(f, 10);
    fila_inserir(f, 20);
    fila_inserir(f, 30);


    fila_primeiro(f, &elemento);
    test(elemento == 10, "Obtendo o primeiro elemento");

    fila_remover(f, &elemento);
    test(elemento == 10, "Remocao");
    

    fila_primeiro(f, &elemento);
    test(elemento == 20, "Obtendo o primeiro elemento");

    fila_remover(f, &elemento);
    test(elemento == 20, "Remocao");
    fila_remover(f, &elemento);
    test(elemento == 30, "Remocao");

    int resultado = fila_remover(f, &elemento);
    test(resultado == 0, "Remocao na fila vazia");
    
    resultado = fila_primeiro(f, &elemento);
    test(resultado == 0, "Obtendo primeiro elemento na fila vazia");

    Fila* f2 = NULL;
    test(fila_inserir(f2,10)==0, "Insercao na fila invalida");
    test(fila_remover(f2, &elemento)==false, "Remocao na fila invalida");
    test(fila_primeiro(f2, &elemento)==0, "Obtendo primeiro elemento na fila invalida");




}