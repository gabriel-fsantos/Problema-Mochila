/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Gabriel Ferreira, Rebeca Gaia
Matricula:
Descricao do programa:
Data:
************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "produto.h"

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

	FILE *arq_entrada, *arq_saida;
	char nome_entrada[50], nome_saida[50];
	int max_peso, num_itens, peso, valor;

	printf("Digite o nome do arquivo de entrada e de saida:\n");
	scanf("%s", nome_entrada);
	scanf("%s", nome_saida);
	
	arq_entrada = fopen(nome_entrada, "r");
	arq_saida = fopen(nome_saida, "w");

	if (arq_entrada == NULL){
		printf("ERRO não foi encontrado o arquivo de entrada\n");
		return 0;
	}

	fscanf(arq_entrada, "%d %d", &max_peso, &num_itens);

	Produto *vetor;
	vetor = (Produto*) malloc(num_itens * sizeof(Produto));

	for(int i = 0; i < num_itens; i++){
		fscanf(arq_entrada, "%d %d", &peso, &valor);
		vetor[i] = *(newProduto(peso, valor, i + 1));
	}

	fclose(arq_entrada);
	sort(vetor, num_itens);

	//Debug Printa o vetor
	/*for(int i = 0; i < num_itens; ++i){	
		printf("%d %d %.4lf\n", vetor[i].peso, vetor[i].valor, vetor[i].razao);
	}*/

	int j = 0, totalvalores = 0, totalpesos = 0; 
	while(j < num_itens){

		if(vetor[j].peso <= max_peso){
			max_peso -= vetor[j].peso;
			totalpesos += vetor[j].peso;
			totalvalores += vetor[j].valor;
			fprintf(arq_saida, "Produto: %d, Peso: %d, Valor: %d\n", vetor[j].id, vetor[j].peso, vetor[j].valor);
		}
		j++;
	}

	fprintf(arq_saida, "\nPeso Total: %d\nValor Total: %d\n", totalpesos, totalvalores);
	fclose(arq_saida);
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
