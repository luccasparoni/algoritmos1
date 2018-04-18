#include <stdio.h>
#include <stdlib.h>

int razaoEhIgual(float* vetor, int tam, float razao, int onde_ta){

	if(onde_ta == tam) return 1;

	if((vetor[onde_ta]) / (vetor[onde_ta-1]) == razao)
		return razaoEhIgual(vetor, tam, razao, onde_ta+1);

	return 0;
}

void main(){

	int tam = 0;
	int input = 1;
	float* vetor = (float*) malloc(sizeof(float));

	while(1){
		vetor = (float*) realloc(vetor,(tam+1)*sizeof(float));
		scanf("%d", &input);
		if(input == 0)break;

		vetor[tam] = input;
		tam++;
	}

	razaoEhIgual(vetor, tam, vetor[1]/vetor[0], 1) ? printf("eh pg"):printf("nao eh pg");

}
