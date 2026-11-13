#include <stdio.h>
#include <stdlib.h>
#include "functions/dados.h"
#include "functions/lerdados.h"



int main(/* int argc, char *argv[] */){
    int valor = lerLinhas();
    dados maximos[valor];
    int disponivel[3];
    disponivel[0]=10;
    disponivel[1]=5;
    disponivel[2]=7;
    for(int i=0;i<valor;i++)
        maximos[i].informacoes = malloc(sizeof(int)*3);
    buscarDados(maximos,valor);
    int ** need = malloc(sizeof(int*)*valor);
    if (need!=NULL){
        for(int i=0;i<valor;i++){
            need[i]=malloc(sizeof(int)*3);
        }
    }
    for(int i=0;i<valor;i++){
        for(int g=0;g<3;g++){
            need[i][g]=maximos[i].informacoes[g];
        }
    }

    comandos atuais;
    atuais.valores=calloc(sizeof(int),(3+1));
    if(atuais.valores!=NULL){
        coletarComandos(&atuais,maximos,need,disponivel);
    }   
    return 0;
}