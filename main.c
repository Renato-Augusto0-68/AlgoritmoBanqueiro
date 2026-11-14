#include <stdio.h>
#include <stdlib.h>
#include "functions/dados.h"
#include "functions/lerdados.h"


int main(int argc, char *argv[]){
    
    int valor = lerLinhas();
    if((argc+1)<valor || argc<2){
        fprintf(stderr,"quantidade de arguentos inferior ao necessário");
        exit(1);
    }
    dados maximos[valor];
    
    int disponivel[argc-1];
    for(int i=0;i<(argc-1);i++){
        disponivel[i]=(atoi(argv[i+1]));   
    }
    for(int i=0;i<valor;i++){
        maximos[i].informacoes = malloc(sizeof(int)*(argc-1));
        if(maximos[i].informacoes==NULL){
            fprintf(stderr,"Alocação de maximos[i].informacoes falhou");
            exit(1);
        }
        maximos[i].tamanho=(argc-1);
    }
    buscarDados(maximos,valor);
    int ** need = malloc(sizeof(int*)*valor);
    if (need!=NULL){
        for(int i=0;i<valor;i++){
            need[i]=malloc(sizeof(int)*(argc-1));
            if(need[i]==NULL){
                fprintf(stderr,"Alocação de need[i]. falhou");
                exit(1);
            }
        }
    }
    if(need==NULL){
            fprintf(stderr,"Alocação de need falhou");
            exit(1);
        }

    for(int i=0;i<valor;i++){
        for(int g=0;g<(argc-1);g++){
            need[i][g]=maximos[i].informacoes[g];
        }
    }
    comandos atuais;
    atuais.valores=calloc(sizeof(int),((argc)));
    if(atuais.valores!=NULL){
        coletarComandos(&atuais,maximos,need,disponivel);
    }   
    if(atuais.valores==NULL){
            fprintf(stderr,"Alocação de atuais.valores falhou");
            exit(1);
    }
    return 0;
}