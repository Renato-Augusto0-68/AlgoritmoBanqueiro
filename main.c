#include <stdio.h>
#include <stdlib.h>
#include "functions/dados.h"
#include "functions/lerdados.h"



int main(/* int argc, char *argv[] */){
   int valor = lerLinhas();
   dados *x = malloc(sizeof(dados)*valor);
   dados maximos;
   maximos.informacoes = malloc(sizeof(int)*5);
   buscarDados(x,valor);
   comandos *atuais=malloc(sizeof(comandos)*valor);
   if(atuais!=NULL){
        coletarComandos(atuais);
   }
    //buscarDados(x, matriz);
    printf("Hello world");
    return 0;
}