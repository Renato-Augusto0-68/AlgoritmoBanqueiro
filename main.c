#include <stdio.h>
#include <stdlib.h>

void buscarDados(int valor1, int valor2, int valor3){

    FILE *arq;
    arq=fopen("customer.txt", "r");
    if(arq!=NULL){
        int comp1,comp2,comp3;
        while(fscanf(arq,"%d,%d,%d",&comp1,&comp2,&comp3)!=EOF){
            if (comp1<=valor1){
                valor1-=comp1;
                comp1-=valor1;
            }
            
        }

    }



}


int main(/* int argc, char *argv[] */){
    printf("Hello world");
    return 0;
}