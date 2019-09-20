/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Gabriel Ferreira, Rebeca Gaia
Matricula:
Descricao do programa:
Data:
************************************************/

//Arquivo que possui somente as assinturas das funções contidas no produto.c

typedef struct produto{
	int peso;
	int valor;
	int id;
	double razao;
} Produto;

Produto* newProduto(int peso, int valor, int id);

void sort(Produto* vet, int tamanho);
