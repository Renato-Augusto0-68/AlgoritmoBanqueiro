#include "lerdados.h"
#include <stdio.h>
#include "dados.h"
#include <stdlib.h>
#include <string.h>
#include "comandos.h"

int lerLinhas(){
    FILE *arq;
    int i=0;
    char ch;
    arq=fopen("customer.txt","r");
    if(arq!=NULL){
        while((ch==fgetc(arq) )!=EOF ){
            if(ch=='\n')
                i++;
        }
        i++;
        fclose(arq);
    }
    return i;
}


void coletarComandos(comandos *com){
    FILE *arq;
    arq=fopen("commands.txt","r");
    com->valores=malloc(sizeof(int)*5);
    if(arq!=NULL){
        while(fscanf(arq,"%s %d %d %d",com->com,com->valores[0],com->valores[1],
            com->valores[2], com->valores[3])!=EOF){
            if(strcmp(com->com, "*")){

            }else{

            }
        }
    }
    fclose(arq);
}


void buscarDados(dados *x, int customer, int **matriz, int limit){
    FILE *arq;
    arq=fopen("customer.txt", "r");
    if(arq!=NULL){
        int comp1,comp2,comp3;
        for(int i=0;fscanf(arq,"%d,%d,%d",&comp1,&comp2,&comp3)!=EOF,i<limit;i++){
               matriz[customer][0]=(comp1);
               matriz[customer][1]=(comp2);
               matriz[customer][2]=(comp3);
        }
    
    }// tá tem
    fclose(arq);    
}
    
