#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAM 10000 

int main(){

	int a, b;
	printf("Digite o maximo da mochila e a quantidade: \n");
	scanf("%d %d", &a, &b);

	FILE *f;
	f = fopen("out.txt", "w");;

	fprintf(f, "%d\n%d\n", a, b);

	int c, d;
	srand(time(NULL));

	for(int i = 0; i < b; i++){
		c = rand() % TAM, d = rand() % TAM;
		fprintf(f, "%d %d\n", c, d);
	}

	return 0;
}