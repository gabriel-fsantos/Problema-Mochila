/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Gabriel Ferreira, Rebeca Gaia
Matricula:
Descricao do programa:
Data:
************************************************/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "produto.h"

void geraMatrizPossibilidades(int num_linhas, int num_colunas, bool **matriz){
	int cont = 0, soma = 0;
	bool bit = false;

	for(int j = num_colunas-1; j >= 0; j--){
		for(int i = 0; i < num_linhas; i++){
			if(soma == pow(2,cont)){
				bit = !bit;
				soma = 0;
			}
			if(bit){
				matriz[i][j] = true;
			}
			else{
				matriz[i][j] = false;
			}
			soma++;		
		}
		soma = 0;
		bit = false;
		cont++;
	}
}

void preenche(int *vet, unsigned long tamanho, int num){

	for (int i = 0; i < tamanho; i++){
		if(num & (unsigned long)pow(2, i)){
			vet[i] = 1;
		}
		else{
			vet[i] = 0;
		}
	}
}

int main(int argc, char *argv[]){

	// Variaveis relacionadas com a medicao do tempo:

	struct timeval inicio, fim;
	/*estrutura que armazena o tempo total que o programa gasta, relaciona-se com
	a funcao gettimeofday()*/

	long totalmicroseg, totalseg; //tempo total do programa

	/*armazenam a diferenca entre o tempo inicial e o final, ou seja, o tempo
	total gasto pelo programa todo. */

	gettimeofday(&inicio, NULL); //obtendo o tempo em que o programa comeca.

	int who = RUSAGE_SELF; //man: information shall be returned about resources used by thecurrent process
	struct rusage usage;

	long utotalmicroseg, utotalseg; //tempo usuario: tempo que a CPU gasta executando o programa
	long stotalmicroseg, stotalseg; //tempo sistema: tempo que a CPU gasta executando chamadas de sistemas para o programa

	FILE *f1, *f2;
	char str1[40], str2[40];
	int max_peso, num_itens, peso, valor;

	printf("Digite o nome do arquivo de entrada e o de saida:\n");
	scanf("%s", str1);
	scanf("%s", str2);

	f1 = fopen(str1, "r");
	f2 = fopen(str2, "w");

	fscanf(f1, "%d %d", &max_peso, &num_itens);

	Produto *vetor;
	vetor = (Produto*)malloc(num_itens * sizeof(Produto));

	for(int i = 0; i < num_itens; i++){
		fscanf(f1, "%d %d", &peso, &valor);
		vetor[i] = *(newProduto(peso, valor, i+1));
	}

	int totalvalores = 0, totalpesos = 0;
	unsigned long num_linhas = pow(2,num_itens);

	int *vet;
	vet = (int*) malloc(num_itens * sizeof(int));
	int maior = 0, linha;
	
	for (int i = 0; i < num_linhas; i++){
		preenche(vet, num_itens, i);
		for(int j = num_itens; j >= 0; j--){
			if(vet[j] == 1){
				totalvalores += vetor[j].valor;
				totalpesos += vetor[j].peso;
			}
		}
		if(totalvalores > maior && totalpesos <= max_peso){
			linha = i;
			maior = totalvalores;
		}
		totalvalores = 0;
		totalpesos = 0; 
	}

	preenche(vet, num_itens, linha);
	for(int i = 0; i < num_itens; i++){
		if(vet[i] == 1){
			totalvalores += vetor[i].valor;
			totalpesos += vetor[i].peso;
			fprintf(f2, "Produto: %d, Peso: %d, Valor: %d\n", vetor[i].numero, vetor[i].peso, vetor[i].valor);
		}
	}

	fprintf(f2, "\nPeso Total: %d\nValor Total: %d\n", totalpesos, totalvalores);

	fclose(f1);
	fclose(f2);
	free(vet);
	free(vetor);

	gettimeofday(&fim, NULL); //obtem tempo final do programa
	totalseg = fim.tv_sec - inicio.tv_sec; //diferenca em segundos
	totalmicroseg = fim.tv_usec - inicio.tv_usec; //diferenca em microsegundos

	/*se a diferenca em microssegundos for negativa, os segundos terao que
	emprestar uma unidade; 1 microseg = 10E-6 s. */
	if(totalmicroseg < 0){
	 	totalmicroseg += 1000000;
	 	totalseg -= 1;
	};

	printf("\n");
	printf("***************************************************************\n");
	printf("Tempo total: %ld segundos e %ld microssegundos.\n", totalseg, totalmicroseg);
	printf("***************************************************************\n");
	printf("\n");

	getrusage(who, &usage);

	//tempo de usuário na CPU
	utotalseg = usage.ru_utime.tv_sec; //segundos
	utotalmicroseg = usage.ru_utime.tv_usec; //microsegundos

	//tempo de sistema na CPU
	stotalseg = usage.ru_stime.tv_sec; //segundos
	stotalmicroseg = usage.ru_stime.tv_usec; //microsegundos
	printf ("\n");
	printf ("***************************************************************\n");
	printf ("Tempo de usuario: %ld segundos e %ld microssegundos.\n", utotalseg, utotalmicroseg);
	printf ("Tempo de sistema: %ld segundos e %ld microssegundos.\n", stotalseg, stotalmicroseg);
	printf ("***************************************************************\n");
	printf ("\n");

	return 0;
}
