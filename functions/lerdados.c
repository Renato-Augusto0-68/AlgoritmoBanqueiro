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
        while((ch=fgetc(arq) )!=EOF ){
            if(ch=='\n')
                i++;
        }
    }
    fclose(arq);
    return i;
}

int verificarConta(comandos *com,int **need,dados *matriz){
    int quant=0;
    for(int i=0;i<3;i++){
        if((com->valores[1+i])<=(matriz->informacoes[i])){
            quant++;
        }
    }
    if(quant==3){
        return 1;
    }
    return 0;
}



void coletarComandos(comandos *com, dados *matriz, int **need){
    FILE *arq;
    arq=fopen("commands.txt","r");
    com->valores=malloc(sizeof(int)*);
    if(arq!=NULL){
        
        while(fscanf(arq,"%s",com->com)!=EOF){
            if(strcmp(com->com, "*")==0){

            }else{
                fscanf(arq,"%d %d %d %d",&com->valores[0],&com->valores[1],&com->valores[2], &com->valores[3]);
                if(strcmp(com->com,"RQ")==0){
                    printf("Allocate to customer %d the resources %d %d %d\n",com->valores[0],com->valores[1],com->valores[2],com->valores[3]);
                    matriz[com->valores[0]];
                }
                if(strcmp(com->com,"RL")==0){
                    if(verificarConta(&com[com->valores[0]], need,&matriz[com->valores[0]])){
                        printf("Release to customer %d the resources %d %d %d\n",com->valores[0],com->valores[1],com->valores[2],com->valores[3]);
                        need[com->valores[0]]+=(com->valores[]);
                    }
                }
            }
        }
    }
    fclose(arq);
}


void buscarDados(dados *matriz, int limit){
    FILE *arq;
    arq=fopen("customer.txt", "r");
    if(arq!=NULL){
        for(int i=0; fscanf(arq,"%d,%d,%d",&matriz[i].informacoes[0],&matriz[i].informacoes[1],&matriz[i].informacoes[2])!=EOF && i<limit;i++){
            
        }
    }// tá tem
    fclose(arq);    
}


