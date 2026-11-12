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
    for(int i=0;i<3;i++){
        if(com->valores[i+1]>need[i]){
            if(com->valores[i+1]>){

            }else{
                printf("The resources "); 
                for(int g=0;g<3;g++)
                    printf("%d ", need[i]); 
                printf("are not enough to customer %d request ", com->valores[0]);
                for(int g=0;g<3;g++)
                    printf("%d ", com->valores[i+1]); 
                
            }
        break;
        }
        if(){


        }
    return 0;
}



void coletarComandos(comandos *com, dados *matriz, int **need, int *disponivel){
    FILE *arq;
    arq=fopen("commands.txt","r");
    if(arq!=NULL){
        while(fscanf(arq,"%s",com->com)!=EOF){
            if(strcmp(com->com, "*")==0){
                printf("MAXIMUM | ALLOCATION | NEED\n");
                for(int i=0;i<5;i++){
                    for(int g=0;g<3;g++){
                        printf("%d ", matriz[i].informacoes[g]);
                    }
                    printf("| ");
                    for(int g=0;g<3;g++){
                        printf("%d ", need[i][g]);
                    } 
                    printf("| ");
                    for(int g=0;g<3;g++){
                        printf("%d ", matriz[i].informacoes[g]-need[i][g]);
                    } 
                    printf("\n");
                }
                printf("AVAILABLE ");
                for(int i=0;i<3;i++){
                    printf("%d ",disponivel[i]);
                }
                printf("\n");
            }else{
                fscanf(arq,"%d %d %d %d",&com->valores[0],&com->valores[1],&com->valores[2], &com->valores[3]);
                if(strcmp(com->com,"RQ")==0){
                    if(verificarConta(com,need,&matriz[com->valores[0]])){
                        printf("Allocate to customer %d the resources %d %d %d\n",com->valores[0],com->valores[1],com->valores[2],com->valores[3]);
                        for(int j=0;j<3;j++){
                            need[com->valores[0]][j]+=(com->valores[j+1]);
                            disponivel[j]-=com->valores[j+1];      
                        }
                    }
                }if(strcmp(com->com,"RL")==0){
                    if(verificarConta(com, need,&matriz[com->valores[0]])){
                        printf("Release to customer %d the resources %d %d %d\n",com->valores[0],com->valores[1],com->valores[2],com->valores[3]);
                        for(int j=0;j<3;j++){
                            need[com->valores[0]][j]-=(com->valores[j+1]);
                            disponivel[j]+=(com->valores[j+1]);
                        }
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


