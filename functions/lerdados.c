#include "lerdados.h"
#include <stdio.h>
#include "dados.h"
#include <stdlib.h>
#include "comandos.h"

int lerLinhas(){
    FILE *arq;
    int i=0;
    arq=fopen("customer.txt","r");
    if(arq!=NULL){
        while(fscanf(arq,"",NULL)!=EOF){
            i++;
        }
    }
    fclose(arq);
    return i;
}


void coletarComandos(comandos *com){
    FILE *arq;
    arq=fopen("commands.txt","r");
    if(arq!=NULL){
        fscanf(arq,"%S %d %d %d %d",);
        if ()
    }
}


void buscarDados(dados *x, int customer){
    FILE *arq;
    arq=fopen("customer.txt", "r");
    if(arq!=NULL){
        int comp1,comp2,comp3;
        int matriz[5][3];
        int j=0;
        while(fscanf(arq,"%d,%d,%d",&comp1,&comp2,&comp3)!=EOF){
            if (comp1<=(x->v1)){
               matriz[customer][0]=(comp1-(x->v1));
            }
            if (comp2<=(x->v2)){
               matriz[customer][1]=(comp2-(x->v2));
            }
            if (comp3<=(x->v3)){
               matriz[customer][2]=(comp3-(x->v3));
            }
        }

    }



}
