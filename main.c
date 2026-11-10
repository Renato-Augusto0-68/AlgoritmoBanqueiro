#include <stdio.h>
#include <stdlib.h>
#include "functions/dados.h"
#include "functions/lerdados.h"



int main(/* int argc, char *argv[] */){
    int valor = lerLinhas();
    dados maximos[valor];
    for(int i=0;i<valor;i++)
        maximos[i].informacoes = malloc(sizeof(int)*3);
    buscarDados(maximos,valor);
    


    comandos *atuais=malloc(sizeof(comandos)*valor);
    if(atuais!=NULL){
        coletarComandos(atuais,maximos);
    }   
    return 0;
}