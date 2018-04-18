#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double vetor[5]  = {1.0,2.0,4.0,8.0,32.0};
void ve_se_ta_Certo(double a1, double q, int inicio, int fim){

	if(fim == inicio){
		double valor = pow(q, fim);
		printf("%f\n",a1*valor);


		if(fim > 0 && vetor[fim]/vetor[fim-1] != q){
			printf("falta o %f\n", a1*pow(q, fim));
		}else if(fim > 0 && vetor[fim+1]/vetor[fim] !=q){
			printf("falta o %f\n", a1*pow(q, fim+1));
		}


		/*
		if(vetor[fim] != a1*valor){
			printf("falta o %f", a1*valor);
		}else{
			printf("falta o %f\n", a1*valor/q);
		}
		printf("entrou aqui %f %d %d\n", vetor[fim], fim, inicio);
		*/


		return;
	}else{
		double novoq = pow(q, (fim+1)/2);
		printf("%f\n", novoq);
		if(vetor[(fim-inicio)/2] == a1*novoq){
			printf("chegou aqui\n");
			ve_se_ta_Certo(a1, q, inicio+(fim-inicio+2)/2, fim);
		}else{
			printf("chegou aqui2\n");
			printf("%d, %d *******",inicio, fim);
			ve_se_ta_Certo(a1, q, inicio, inicio+(fim-inicio)/2);
		}
	}
}


int main(){

	//acha a raiz q e o termo inicial a1;

	double q, a1;

	a1 = vetor[0];
	if(vetor[1]/vetor[0] == vetor[2]/vetor[1]){
		q = vetor[1]/vetor[0];
	}else if(vetor[1]/vetor[0] > vetor[2]/vetor[1]){
		q = vetor[2]/vetor[1];
		printf("o termo que falta é %f ", a1*q);
	}else{
		q = vetor[1]/vetor[0];

	}

	ve_se_ta_Certo(a1, q, 0, 4);
}
