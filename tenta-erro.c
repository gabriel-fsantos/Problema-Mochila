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

void geraMatrizPossibilidades(int num_linhas, int num_colunas, int **matriz){
	int cont = 0, soma = 0;
	bool bit = false;

	for(int j = num_colunas-1; j >= 0; j--){
		for(int i = 0; i < num_linhas; i++){
			if(soma == pow(2,cont)){
				bit = !bit;
				soma = 0;
			}
			if(bit){
				matriz[i][j] = 1;
			}
			else{
				matriz[i][j] = 0;
			}
			soma++;		
		}
		soma = 0;
		bit = false;
		cont++;
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
	long num_linhas = pow(2,num_itens);
	int **matriz;

	printf("1\n");

	matriz = (int **) malloc (num_linhas * sizeof (int *));

	for(int i = 0; i < num_linhas; i++){
		matriz[i] = (int *) malloc (num_itens * sizeof(int));
	}

	printf("2\n");

	geraMatrizPossibilidades(num_linhas, num_itens, matriz);
	int maior = 0, linha;

	printf("3\n");

	for(int i = 0; i < num_linhas; i++){
		for(int j = 0; j < num_itens; j++){
			if(matriz[i][j] == 1){
				totalvalores += vetor[j].valor;
				totalpesos += vetor[j].peso;
			}	
		}
		if(totalvalores > maior && totalpesos <= max_peso){
			maior = totalvalores;
			linha = i;
		}
		totalvalores = 0;
		totalpesos = 0;
	}

	printf("4\n");

	for(int j = 0; j < num_itens; j++){
		if(matriz[linha][j] == 1){
			totalvalores += vetor[j].valor;
			totalpesos += vetor[j].peso;
			fprintf(f2, "Produto: %d, Peso: %d, Valor: %d\n", vetor[j].numero, vetor[j].peso, vetor[j].valor);
		}
	}

	fprintf(f2, "\nPeso Total: %d\nValor Total: %d\n", totalpesos, totalvalores);
	fclose(f1);
	fclose(f2);

	for(int i = 0; i < num_linhas; i++){
		free(matriz[i]);	
	}

	free(matriz);

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

