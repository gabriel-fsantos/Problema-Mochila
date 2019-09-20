/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Gabriel Ferreira, Rebeca Gaia
Matricula:
Descricao do programa:
Data:
************************************************/

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "produto.h"

Produto* newProduto(int peso, int valor, int id){

	Produto* p = (Produto*)malloc(sizeof(Produto));
	p->peso = peso;
	p->valor = valor;
	p->id = id;
	if(peso != 0){
		p->razao = (double)valor/peso;
	}
	else{
		p->razao = valor;
	}
	return p;
};

void sort(Produto* vet, int tamanho){

	Produto auxiliar;
	for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){

            if (vet[i].razao > vet[j].razao){
                auxiliar = vet[i];
                vet[i] = vet[j];
                vet[j] = auxiliar;
            }
        }
    }
};
