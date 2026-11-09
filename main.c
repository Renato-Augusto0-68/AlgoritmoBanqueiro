#include <stdio.h>
#include <stdlib.h>
#include "functions/dados.h"

void buscarDados(dados *x){

    FILE *arq;
    arq=fopen("customer.txt", "r");
    if(arq!=NULL){
        int comp1,comp2,comp3;
        while(fscanf(arq,"%d,%d,%d",&comp1,&comp2,&comp3)!=EOF){
            if (comp1<=(x->v1)){
                (x->v1)-=comp1;
                comp1-=(x->v1);
            }

        }

    }



}


int main(/* int argc, char *argv[] */){
    dados *x = malloc(sizeof(dados));
    x->v1=10;
    x->v2=5;
    x->v3=7;
    buscarDados(x);
    printf("Hello world");
    return 0;
}