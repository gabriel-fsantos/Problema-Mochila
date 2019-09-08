/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Gabriel Ferreira, Rebeca Gaia
Matricula:
Descricao do programa:
Data:
************************************************/
#include <sys/time.h>
#include "produto.h"

int main(int argc, char *argv[]){

	/*
	/ Ainda não vou usar arquivo
	*/

	int max_peso, num_itens, peso, valor;
	scanf("%d %d", &max_peso, &num_itens);

	Produto *vetor, *ptr;
	vetor = (Produto*)malloc(num_itens * sizeof(Produto));
	
	for (int i = 0; i < num_itens; i++){
		scanf("%d %d", &peso, &valor);
		vetor[i] = *(newProduto(peso, valor));
	}

	for (int i = 0; i < num_itens; ++i){	
		printf("%d %d\n", vetor[i].peso, vetor[i].valor);
	}

	return 0;
}
