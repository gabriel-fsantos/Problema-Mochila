/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Gabriel Ferreira, Rebeca Gaia
Matricula:
Descricao do programa:
Data:
************************************************/
#include <stdlib.h>
#include <math.h>
#include "produto.h"

Produto* newProduto(int peso, int valor){
	Produto* p = (Produto*)malloc(sizeof(Produto));
	p->peso = peso;
	p->valor = valor;
	return p;
};

