// Arquivo que possui somente as assinturas das funções contidas no produto.c

// Estrutura de um produto
typedef struct produto{
	int peso;
	int valor;
	int id;
	double razao;
} Produto;

// Função que aloca memória de um produto e atribui seus atributos e retorna o produto pronto
Produto* newProduto(int peso, int valor, int id);

// Função que ordena o vetor de produtos, de forma cresente baseado na sua razão
void sort(Produto* vet, int tamanho);
