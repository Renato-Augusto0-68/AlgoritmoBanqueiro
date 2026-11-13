#ifndef LERDADOS_H
#define LERDADOS_H

#include "dados.h"
#include "comandos.h"

int lerLinhas();
int estadoSeguro(int **need, dados *matriz, int *disponivel, FILE *x);
int verificarConta(comandos *com, int **need,FILE *x, int *disponivel, dados *matcomp, int modo);
void coletarComandos(comandos *com, dados *matriz, int **need, int *disponivel);
void buscarDados(dados *x, int limit);


#endif