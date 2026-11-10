#include "lerdados.h"
#include <stdio.h>
#include "dados.h"
#include <stdlib.h>

void buscarDados(dados *x){

    FILE *arq;
    arq=fopen("customer.txt", "r");
    if(arq!=NULL){
        int comp1,comp2,comp3;
        int matriz[5][3];
        

        while(fscanf(arq,"%d,%d,%d",&comp1,&comp2,&comp3)!=EOF){
            if (comp1<=(x->v1)){
                
            }

        }

    }



}
