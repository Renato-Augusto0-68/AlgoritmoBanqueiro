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
    for(int i=0;i<valor;i++){
        for(int g=0;g<3;g++){
            printf("%d ", maximos[i].informacoes[g]);
        }
        printf("\n");
    }


    comandos *atuais=malloc(sizeof(comandos)*valor);
    if(atuais!=NULL){
        coletarComandos(atuais,maximos);
    }
    for(int i=0;i<4;i++){
        printf("%d ", atuais->valores[i]);
    }
        printf("\n");    
    return 0;
}