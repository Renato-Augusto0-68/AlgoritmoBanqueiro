#ifndef LERDADOS_H
#define LERDADOS_H

#include "dados.h"

int lerLinhas();

void coletarComandos(comandos *com);
void buscarDados(dados *x, int customer, int **matriz, int limit);


#endif