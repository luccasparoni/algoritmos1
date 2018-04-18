#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double vetor[5]  = {1.0,2.0,5.0,8.0,16.0};
void ve_se_ta_Certo(double a1, double q, int inicio, int fim){
	printf("teste4\n");

	if(fim == inicio || fim == inicio+1){
		double valor = pow(q, fim-1);
		printf("%f\n",a1*valor);
		if(vetor[fim] == a1*valor){
			printf("fim %d\n", fim);
			printf("o valor que falta é %f", a1*valor);
		}else{
			printf("não falta nada\n");
		}
		return;
	}
	printf("teste4\n");
	double novoq = pow(q, (fim+1)/2);
	printf("%f\n", novoq);
	if(vetor[fim/2]+1 == a1*novoq){
		printf("chegou aqui\n");
		ve_se_ta_Certo(a1, q, (fim+1)/2, fim);
	}else{
		printf("chegou aqui2\n");
		ve_se_ta_Certo(a1, q, inicio, (fim+1)/2);
	}
}


int main(){

	//acha a raiz q e o termo inicial a1;

	double q, a1;

	a1 = vetor[0];
	if(vetor[1]/vetor[0] == vetor[2]/vetor[1]){
		q = vetor[1]/vetor[0];
		printf("teste1\n");
	}else if(vetor[1]/vetor[0] > vetor[2]/vetor[1]){
		printf("teste2\n");
		q = vetor[2]/vetor[1];
		printf("o termo que falta é %f ", a1*q);
	}else{
		q = vetor[1]/vetor[0];
		printf("teste3\n");

	}

	ve_se_ta_Certo(a1, q, 0, 4);
}
