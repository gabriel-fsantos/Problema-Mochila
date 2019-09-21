#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAM 10000
#define PESO 500

int main(){

	int a, b;
	printf("Digite a quantidade de itens: \n");
	scanf("%d", &b);

	FILE *f;
	f = fopen("in.txt", "w");;

	fprintf(f, "%d\n%d\n", PESO, b);

	int c, d;
	srand(time(NULL));

	for(int i = 0; i < b; i++){
		c = rand() % TAM, d = rand() % TAM;
		fprintf(f, "%d %d\n", c, d);
	}

	return 0;
}