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

Produto* newProduto(int peso, int valor, int numero){

	Produto* p = (Produto*)malloc(sizeof(Produto));
	p->peso = peso;
	p->valor = valor;
	p->numero = numero;
	if(valor != 0){
		p->razao = (double)peso/valor;
	}
	else{
		p->razao = 0;
	}
	return p;
};

void sortRazao(Produto* vet, int tamanho){

	Produto auxiliar;
	for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){

            if (vet[i].razao < vet[j].razao){
                auxiliar = vet[i];
                vet[i] = vet[j];
                vet[j] = auxiliar;
            }
        }
    }
};

void sortValor(Produto* vet, int tamanho){

	Produto auxiliar;
	for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){

            if (vet[i].valor < vet[j].valor){
                auxiliar = vet[i];
                vet[i] = vet[j];
                vet[j] = auxiliar;
            }
        }
    }
};

bool comparaRazao(Produto p1, Produto p2){

	if(p1.razao > p2.razao){
		return true;
	}
	return false;
};

bool comparaValor(Produto p1, Produto p2){

	if(p1.valor > p2.valor){
		return true;
	}
	return false;
};
