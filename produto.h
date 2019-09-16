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
	int numero;
	double razao;
} Produto;

Produto* newProduto(int peso, int valor, int numero);

bool comparaRazao(Produto p1, Produto p2);

bool comparaValor(Produto p1, Produto p2);

void sortRazao(Produto* vet, int tamanho);

void sortValor(Produto* vet, int tamanho);

