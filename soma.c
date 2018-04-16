#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ve_se_ta_Certo(double a1, double q, int inicio, int fim){
	if(fim == inicio){
		double valor = pow(q, fim-1);
		printf("o valor que falta é %f", a1*valor);
	}
	double novoq = pow(q, fim/2);
	if(vetor[fim/2] == a1*novoq){
		ve_se_ta_Certo(a1, q, fim/2, fim);
	}else{
		ve_se_ta_Certo(a1, q, inicio, fim/2);
	}
}


int main(){

	//acha a raiz q e o termo inicial a1;

	double q, a1;

	a1 = vetor[0]
	if(vetor[1]/vetor[0] == vetor[2]/vetor[1]){
		q = vetor[1]/vetor[0];
	}else if(vetor[1]/vetor[0] > vetor[2]/vetor[1]){
		q = vetor[2]/vetor[1];
		printf("o termo que falta é ", a1*q);
	}else{
		q = vetor[1]/vetor[0];
	}

	ve_se_ta_Certo(a1, q, 0, n);
}
