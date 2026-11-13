#include <stdio.h>
#include <stdlib.h>
#include "functions/dados.h"
#include "functions/lerdados.h"



int main(int argc, char *argv[]){
    
    int valor = lerLinhas();
    if((argc+2)!=valor){
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
        maximos[i].tamanho=(argc-1);
    }
    buscarDados(maximos,valor);
    int ** need = malloc(sizeof(int*)*valor);
    if (need!=NULL){
        for(int i=0;i<valor;i++){
            need[i]=malloc(sizeof(int)*(argc-1));
        }
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
    return 0;
}