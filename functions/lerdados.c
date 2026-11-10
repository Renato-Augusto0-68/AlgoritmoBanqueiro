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
    com->valores=malloc(sizeof(int)*4);
    if(arq!=NULL){
        fscanf(arq,"%s %d %d %d %d",com->com, com->valores[0],com->valores[1],
            com->valores[2], com->valores[3]);
    }
}


void buscarDados(dados *x, int customer, int **matriz, int limit){
    FILE *arq;
    arq=fopen("customer.txt", "r");
    if(arq!=NULL){
        int comp1,comp2,comp3;
        for(int i=0;fscanf(arq,"%d,%d,%d",&comp1,&comp2,&comp3)!=EOF,i<limit;i++){
            if (comp1<=(x->v1)){
               matriz[customer][i]=(comp1-(x->v1));
            }
            if (comp2<=(x->v2)){
               matriz[customer][i]=(comp2-(x->v2));
            }
            if (comp3<=(x->v3)){
               matriz[customer][i]=(comp3-(x->v3));
            }
        }// tá tem

    }



}
