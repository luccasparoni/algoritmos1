#include <stdio.h>
#include <stdlib.h>

int ve_se_a_razao_eh_igual(int* vetor, int tamanho, float razao, int onde_ta){

	if(onde_ta == 1){
		razao = vetor[0]/vetor[1];
		return ve_se_a_razao_eh_igual(vetor, tamanho, razao, 2);
	}
	if(onde_ta = tamanho){
		return 1;
	}
	float nova_razao = vetor[onde_ta-1] / vetor[onde_ta];
	if(nova_razao == razao){
		ve_se_a_razao_eh_igual(vetor, tamanho, razao, onde_ta+1);
	}
	else if(nova_razao != razao){
		return 0;
	}
}

void main(){
	int tamanho=0;

	int input = 1;
	int* vetor = (int*) malloc((1)*sizeof(int));

	while(1){
		vetor = (int*) realloc(vetor,(tamanho+1)*sizeof(int));
		scanf("%d", &input);
		if(input == 0){
			break;
		}
		vetor[tamanho] = input;
		printf("%d", vetor[tamanho]);

		tamanho++;
	}

	float razao;
	int resposta = ve_se_a_razao_eh_igual(vetor, tamanho, razao, 1);
	if(resposta == 1){
		printf("eh pg");
	}else{
		printf("nao eh pg");
	}
}
