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

int estadoSeguro(int **need, dados *matriz, int *disponivel){
    int workBank[3];
    int *aux=calloc(sizeof(int),5);
    int continua;
    int cont=0;
       for(int j=0;j<3;j++)
            workBank[j]=disponivel[j];
       do{
            for(int i=0;i<5;i++){
                int da=0;
                if(aux[i])
                    continue;
                for(int j=0;j<3;j++){
                    if(need[i][j]<=workBank[j]){
                        da=1;
                    }
                }
                if(da){
                    for(int j=0;j<3;j++){
                        workBank[j]+=matriz[i].informacoes[j]-need[i][j];
                    }
                    aux[i]=1;
                    cont++;
                    continua=1;
                }
            }
        }while(continua);

        if(cont==3)
           return 1;
        return 0;
}

int verificarConta(comandos *com,int **need,dados *matriz, int *disponivel){
    int id_cliente = com->valores[0];
    for(int i=0;i<3;i++){
        if(com->valores[i+1]>need[id_cliente][i]){
             printf("The customer %d request ", id_cliente);
              for(int j=0;j<3;j++){
                printf("%d ",com->valores[j+1]);
              }
              printf("was denied because exceed its maximum allocation\n");
              return 0;   
        }
    }
    for(int i=0;i<3;i++){
        if(com->valores[i+1]>disponivel[i]){
            printf("The resources "); 
                for(int g=0;g<3;g++)
                    printf("%d ", disponivel[g]); 
                printf("are not enough to customer %d request ", id_cliente);
                for(int g=0;g<3;g++)
                    printf("%d ", com->valores[g+1]); 
                printf("\n");
                 return 0; 
        }
    }

    for(int i=0;i<3;i++){
        if(!(com->valores[i+1]-need[id_cliente][i]==0)&& (com->valores[i+1]-disponivel[i]==0)){
            printf("The customer %d request ",id_cliente);
            for(int i=0;i<3;i++){
                printf("%d ",com->valores[i+1]);
            } 
            printf("was denied because result in an unsafe state\n");
            return 0;
        }
    }
    return 1;    
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
                        printf("%d ", matriz[i].informacoes[g]-need[i][g]);
                    } 
                    printf("| ");
                    for(int g=0;g<3;g++){
                        printf("%d ", need[i][g]);
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
                    if(verificarConta(com,need,&matriz[com->valores[0]], disponivel)){
                        printf("Allocate to customer %d the resources %d %d %d\n",com->valores[0],com->valores[1],com->valores[2],com->valores[3]);
                        for(int j=0;j<3;j++){
                            need[com->valores[0]][j]-=(com->valores[j+1]);
                            disponivel[j]-=com->valores[j+1];      
                        }
                    }
                }if(strcmp(com->com,"RL")==0){
                    if(verificarConta(com, need,&matriz[com->valores[0]],disponivel)){
                        printf("Release from customer %d the resources %d %d %d\n",com->valores[0],com->valores[1],com->valores[2],com->valores[3]);
                        for(int j=0;j<3;j++){
                            need[com->valores[0]][j]+=(com->valores[j+1]);
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


