/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Gabriel Ferreira / Rebeca Gaia
Matricula: 20183025526 / 2018
Descricao do programa: Arquivo header do produto.c
Data: 20/09/2019
************************************************/

// Arquivo que possui somente as assinturas das funções contidas no produto.c

// Estrutura de um produto
typedef struct produto{
	int peso;
	int valor;
	int id;
	double razao;
} Produto;

// Função que aloca memoria de um produto e atribui seus atributos e retorna o produto pronto
Produto* newProduto(int peso, int valor, int id);

// Função que ordena o vetor de produtos, de forma cresente baseado na sua razão
void sort(Produto* vet, int tamanho);
