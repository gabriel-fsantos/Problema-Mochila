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

	// Variaveis relacionadas com a medicao do tempo:
	struct timeval inicio, fim;
	/*estrutura que armazena o tempo total que o programa gasta, relaciona-se com
	a funcao gettimeofday()*/

	long totalmicroseg, totalseg; //tempo total do programa

	/* armazenam a diferenca entre o tempo inicial e o final, ou seja, o tempo
	total gasto pelo programa todo. */

	//obtendo o tempo em que o programa comeca.
	gettimeofday(&inicio, NULL);

	int max_peso, num_itens, peso, valor;
	scanf("%d %d", &max_peso, &num_itens);

	Produto *vetor, *ptr;
	vetor = (Produto*)malloc(num_itens * sizeof(Produto));

	//Code

	gettimeofday(&fim, NULL); //obtem tempo final do programa
	totalseg = fim.tv_sec - inicio.tv_sec; //diferenca em segundos
	totalmicroseg = fim.tv_usec - inicio.tv_usec; //diferenca em microsegundos

	/*se a diferenca em microssegundos for negativa, os segundos terao que
	emprestar uma unidade; 1 microseg = 10E-6 s. */
	if (totalmicroseg <0){
	 	totalmicroseg += 1000000;
	 	totalseg -= 1;
	};

	printf("\n");
	printf("***************************************************************\n");
	printf("Tempo total: %ld segundos e %ld microssegundos.\n", totalseg, totalmicroseg);
	printf("***************************************************************\n");
	printf("\n");

	return 0;
}