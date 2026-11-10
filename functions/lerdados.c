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
        while(fscanf(arq,"%s %d %d %d %d",com->com,&com->valores[0],&com->valores[1],
            &com->valores[2], &com->valores[3])!=EOF){
            if(strcmp(com->com, "*")==0){

            }else{

            }
        }
    }
    fclose(arq);
}


void buscarDados(dados *matriz, int limit){
    FILE *arq;
    arq=fopen("customer.txt", "r");
    if(arq!=NULL){
        for(int i=0;fscanf(arq,"%d,%d,%d",&matriz[i].v1,&matriz[i].v2,&matriz[i].v3)!=EOF,i<limit;i++){
        
        }
    
    }// tá tem
    fclose(arq);    
}
    
