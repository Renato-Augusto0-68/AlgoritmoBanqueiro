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

int estadoSeguro(int **need, dados *matriz, int *disponivel, FILE *x){
    int *workBank=calloc(sizeof(int),3);
    int *aux=calloc(sizeof(int),5);
    int continua;
    int cont=0;
       for(int j=0;j<3;j++)
            workBank[j]=disponivel[j];
       do{  
            continua=0;
            for(int i=0;i<5;i++){
                int da=0;
                if(aux[i])
                    continue;
                for(int j=0;j<3;j++){
                    if(need[i][j]<=workBank[j]){
                        da=1;
                    }
                    else{
                        da=0;
                        break;
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
        free(aux);
        free(workBank);
        if(cont==5)
           return 1;
        return 0;
}

int verificarConta(comandos *com,int **need,FILE *x, int *disponivel, dados *matcomp, int modo){
    int id_cliente = com->valores[0];
    if(modo==1){
    for(int i=0;i<3;i++){
        if(com->valores[i+1]>need[id_cliente][i]){
            fprintf(arq,"The customer %d request ", id_cliente);
              for(int j=0;j<3;j++){
            fprintf("%d ",com->valores[j+1]);
              }
            fprintf("was denied because exceed its maximum allocation\n");
              return 0;   
        }
    }
    for(int i=0;i<3;i++){
        if(com->valores[i+1]>disponivel[i]){
        fprintf("The resources "); 
                for(int g=0;g<3;g++)
                fprintf("%d ", disponivel[g]); 
            fprintf("are not enough to customer %d request ", id_cliente);
                for(int g=0;g<3;g++)
                fprintf("%d ", com->valores[g+1]); 
            fprintf("\n");
                 return 0; 
        }
    } 
    for(int i=0;i<3;i++){
        disponivel[i]-=com->valores[i+1];
        need[id_cliente][i]-=com->valores[i+1];
    }
    int ehSeguro = estadoSeguro(need,matcomp,disponivel);
        for(int i=0;i<3;i++){
            disponivel[i]+=com->valores[i+1];
            need[id_cliente][i]+=com->valores[i+1];
        }
        if(!ehSeguro){
        fprintf("The customer %d request ",id_cliente);
            for(int i=0;i<3;i++){
            fprintf("%d ",com->valores[i+1]);
            } 
        fprintf("was denied because result in an unsafe state\n");
            return 0;
        }
    }else{
        int quant=0;
        for(int i=0;i<3;i++){
            if(com->valores[i+1]<=(matcomp[com->valores[0]].informacoes[i]-need[com->valores[0]][i])){
                quant++;
            }
        }
        if(quant!=3){
            for(int i=0;i<3;i++){    
            fprintf(arq2,"The resources "); 
                for(int g=0;g<3;g++)
                fprintf("%d ", disponivel[g]); 
            fprintf("are not enough to customer %d request ", com->valores[0]);
                for(int g=0;g<3;g++)
                fprintf("%d ", com->valores[g+1]); 
            fprintf("\n");
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
    arq2=fopen("results2.txt","w");
    if(arq2==NULL){
        fprintf(stderr,"Não foi possível criar o arquivo");
        exit(1);
    }

    if(arq!=NULL){
        while(fscanf(arq,"%s",com->com)!=EOF){
            if(strcmp(com->com, "*")==0){
                
                fprintf(arq2,"MAXIMUM | ALLOCATION | NEED\n");
                for(int i=0;i<5;i++){
                    for(int g=0;g<3;g++){
                        fprintf(arq2,"%d ", matriz[i].informacoes[g]);
                    }
                    fprintf(arq2,"| ");
                    for(int g=0;g<3;g++){
                        fprintf(arq2,"%d ", matriz[i].informacoes[g]-need[i][g]);
                    } 
                    fprintf(arq2,"| ");
                    for(int g=0;g<3;g++){
                        fprintf(arq2,"%d ", need[i][g]);
                    } 
                    fprintf(arq2,"\n");
                }
            fprintf(arq2,"AVAILABLE ");
                for(int i=0;i<3;i++){
                fprintf(arq2,"%d ",disponivel[i]);
                }
            fprintf(arq2,"\n");
            }else{
                fscanf(arq,"%d %d %d %d",&com->valores[0],&com->valores[1],&com->valores[2], &com->valores[3]);
                if(strcmp(com->com,"RQ")==0){
                    if(verificarConta(com,need,&matriz[com->valores[0]], disponivel,matriz,1)){
                    fprintf(arq2,"Allocate to customer %d the resources %d %d %d\n",com->valores[0],com->valores[1],com->valores[2],com->valores[3]);
                        for(int j=0;j<3;j++){
                            need[com->valores[0]][j]-=(com->valores[j+1]);
                            disponivel[j]-=com->valores[j+1];      
                        }
                    }
                }if(strcmp(com->com,"RL")==0){
                    if(verificarConta(com, need,&matriz[com->valores[0]],disponivel,matriz,0)){
                    fprintf(arq2,"Release from customer %d the resources %d %d %d\n",com->valores[0],com->valores[1],com->valores[2],com->valores[3]);
                        for(int j=0;j<3;j++){
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
        exit(1);
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
    if(arq==NULL){
        fprintf(stderr,"Não foi possível abrir o arquivo customer.txt");
        exit(1);
    }
    fclose(arq);    

}


