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
    if(arq==NULL){
        fprintf(arq,"Não foi possível abrir o arquivo");
        fclose(arq);
        exit(1);
    }
    fclose(arq);
    return i;
}


int estadoSeguro(int **need, dados *matriz, int *disponivel){
    int comand = lerLinhas();
    int *workBank=calloc(sizeof(int),(matriz->tamanho));
    int *aux=calloc(sizeof(int),(comand));
    if(workBank==NULL|| aux==NULL){
        fprintf(stderr,"Falha de alocação do vetor auxiliar");
        free(aux);
        free(workBank);
        exit(1);
    }
    int continua;
    int cont=0;
       for(int j=0;j<(matriz->tamanho);j++)
            workBank[j]=disponivel[j];
       do{  
            continua=0;
            for(int i=0;i<(comand);i++){
                int da=0;
                if(aux[i])
                    continue;
                for(int j=0;j<(matriz->tamanho);j++){
                    if(need[i][j]<=workBank[j]){
                        da=1;
                    }
                    else{
                        da=0;
                        break;
                    }
                }
                if(da){
                    for(int j=0;j<(matriz->tamanho);j++){
                        workBank[j]+=matriz[i].informacoes[j]-need[i][j];
                    }
                    aux[i]=1;
                    cont++;
                    continua=1;
                }
            }
        }while(continua);
        free(aux);
        free(workBank);
        if(cont==(comand))
           return 1;
        return 0;
}

int verificarConta(comandos *com,int **need,FILE *x, int *disponivel, dados *matcomp, int modo){
    int id_cliente = com->valores[0];
    int total_cliente = lerLinhas();
    if(modo==1){
    for(int i=0;i<matcomp->tamanho;i++){
        
        if(com->valores[i+1]>need[id_cliente][i]){
            fprintf(x,"The customer %d request ", id_cliente);
              for(int j=0;j<matcomp->tamanho;j++){
            fprintf(x,"%d ",com->valores[j+1]);
              }
            fprintf(x,"was denied because exceed its maximum allocation\n");
              return 0;   
        }
    }
    for(int i=0;i<matcomp->tamanho;i++){
        if(com->valores[i+1]>disponivel[i]){
        fprintf(x,"The resources "); 
                for(int g=0;g<matcomp->tamanho;g++)
                fprintf(x,"%d ", disponivel[g]); 
            fprintf(x,"are not enough to customer %d request ", id_cliente);
                for(int g=0;g<matcomp->tamanho;g++)
                fprintf(x,"%d ", com->valores[g+1]); 
            fprintf(x,"\n");
                 return 0; 
        }
    } 
    for(int i=0;i<matcomp->tamanho;i++){
        disponivel[i]-=com->valores[i+1];
        need[id_cliente][i]-=com->valores[i+1];
    }
    int ehSeguro = estadoSeguro(need,matcomp,disponivel);
        for(int i=0;i<matcomp->tamanho;i++){
            disponivel[i]+=com->valores[i+1];
            need[id_cliente][i]+=com->valores[i+1];
        }
        if(!ehSeguro){
        fprintf(x,"The customer %d request ",id_cliente);
            for(int i=0;i<matcomp->tamanho;i++){
            fprintf(x,"%d ",com->valores[i+1]);
            } 
        fprintf(x,"was denied because result in an unsafe state\n");
            return 0;
        }
    }else{
        int quant=0;
        for(int i=0;i<matcomp->tamanho;i++){
            if(com->valores[i+1]<=(matcomp[com->valores[0]].informacoes[i]-need[com->valores[0]][i])){
                quant++;
            }
        }
        if(quant!=matcomp->tamanho){
            for(int i=0;i<matcomp->tamanho;i++){    
            fprintf(x,"The resources "); 
                for(int g=0;g<matcomp->tamanho;g++)
                fprintf(x,"%d ", disponivel[g]); 
            fprintf(x,"are not enough to customer %d request ", com->valores[0]);
                for(int g=0;g<matcomp->tamanho;g++)
                fprintf(x,"%d ", com->valores[g+1]); 
            fprintf(x,"\n");
            }
            return 0;
        }
    }
    return 1;    
}

void coletarComandos(comandos *com, dados *matriz, int **need, int *disponivel){
    FILE *arq;
    arq=fopen("commands.txt","r");
    
    FILE *arq2;
    arq2=fopen("result.txt","w");
    if(arq2==NULL){ 
        fprintf(stderr,"Não foi possível criar/abrir o arquivo");
        fclose(arq);
        fclose(arq2);
        exit(1);
    }
    int comand = lerLinhas();
    if(arq!=NULL){
        while(fscanf(arq,"%s",com->com)!=EOF){
            if(strcmp(com->com, "*")==0){
                fprintf(arq2,"MAXIMUM  |   ALLOCATION  |   NEED\n");
                for(int i=0;i<comand;i++){
                    for(int g=0;g<matriz->tamanho;g++){
                        fprintf(arq2,"%d ", matriz[i].informacoes[g]);
                    }
                    fprintf(arq2,"   |   ");
                    for(int g=0;g<matriz->tamanho;g++){
                        fprintf(arq2,"%d ", matriz[i].informacoes[g]-need[i][g]);
                    } 
                    fprintf(arq2,"      |   ");
                    for(int g=0;g<matriz->tamanho;g++){
                        fprintf(arq2,"%d ", need[i][g]);
                    } 
                    fprintf(arq2,"\n");
                }
            fprintf(arq2,"AVAILABLE ");
                for(int i=0;i<matriz->tamanho;i++){
                fprintf(arq2,"%d ",disponivel[i]);
                }
            fprintf(arq2,"\n");
            }else{
                int ret=fscanf(arq,"%d ",&com->valores[0]);
                if(ret!=1){
                    fprintf(stderr,"Falha crítica, Id ausente");
                    fclose(arq);
                    fclose(arq2);
                    exit(1);
                }
                if(com->valores[0]<0 || com->valores[0]>=comand){
                    fprintf(stderr,"Id %d inválido por ser maior ou menor que o total de clientes",com->valores[0]);
                    fclose(arq);
                    fclose(arq2);
                    exit(1);
                }
                for(int i=0;i<matriz->tamanho;i++){
                    int ret2=fscanf(arq,"%d ",&com->valores[i+1]);
                    if(ret2!=1){
                        fprintf(stderr,"Falha crítica, comando ausente");
                        fclose(arq);
                        fclose(arq2);
                        exit(1);
                    }
                }
                if(strcmp(com->com,"RQ")==0){
                    if(verificarConta(com,need,arq2, disponivel,matriz,1)){
                    fprintf(arq2,"Allocate to customer %d the resources ",com->valores[0]);
                    for(int i=0;i<matriz->tamanho;i++)
                        fprintf(arq2,"%d ",com->valores[i+1]);
                    fprintf(arq2,"\n");
                        for(int j=0;j<matriz->tamanho;j++){
                            need[com->valores[0]][j]-=(com->valores[j+1]);
                            disponivel[j]-=com->valores[j+1];      
                        }
                    }
                }if(strcmp(com->com,"RL")==0){
                    if(verificarConta(com, need,arq2,disponivel,matriz,0)){
                    fprintf(arq2,"Release from customer %d the resources ",com->valores[0]);
                    for(int i=0;i<matriz->tamanho;i++)
                        fprintf(arq2,"%d ",com->valores[i+1]);
                    fprintf(arq2,"\n");
                        for(int j=0;j<matriz->tamanho;j++){
                            need[com->valores[0]][j]+=(com->valores[j+1]);
                            disponivel[j]+=(com->valores[j+1]);
                        }
                    }             
                }
            }
        }
    }
    if(arq==NULL){
        fprintf(stderr,"Não foi possível abrir o arquivo");
        fclose(arq);
        fclose(arq2);
        exit(1);
    }
    fclose(arq);
    fclose(arq2);
}


void buscarDados(dados *matriz, int limit){
    FILE *arq;
    arq=fopen("customer.txt", "r");
    if(arq!=NULL){
        for(int i=0;i<(limit);i++){
            for(int g=0;g<(matriz->tamanho);g++){
                int val=fscanf(arq, "%d",&matriz[i].informacoes[g]);
                if(val!=1){
                    fprintf(stderr,"Formatação inadequada no arquivo customer.txt");
                    fclose(arq);
                    exit(1);
                }
                if(g < matriz->tamanho - 1) {
                char virgula;
                int val2=fscanf(arq, " %c", &virgula);
                if(val2!=1){
                    fprintf(stderr,"Falha por falta de virgula em customer.txt");
                    fclose(arq);
                    exit(1);
                } 
            }
            }
        }
    }// tá tem
    if(arq==NULL){
        fprintf(stderr,"Não foi possível abrir o arquivo customer.txt");
        fclose(arq);
        exit(1);
    }
    fclose(arq);    

}


