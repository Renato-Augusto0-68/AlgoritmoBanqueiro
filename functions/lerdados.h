#ifndef LERDADOS_H
#define LERDADOS_H

#include "dados.h"
#include "comandos.h"

int lerLinhas();
void coletarComandos(comandos *com, dados *matriz);
void buscarDados(dados *x, int limit);


#endif