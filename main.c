#include <stdio.h>
#include <stdlib.h>
#include "functions/dados.h"
#include "functions/lerdados.h"



int main(/* int argc, char *argv[] */){
    dados *x = malloc(sizeof(dados));
    x->v1=10;
    x->v2=5;
    x->v3=7;
   int valor = lerLinhas();
   

    //buscarDados(x, matriz);
    printf("Hello world");
    return 0;
}