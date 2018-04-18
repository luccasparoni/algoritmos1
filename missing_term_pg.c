#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double vetor[5]  = {32,16,8,2,1};
void ve_se_ta_Certo(double a1, double q, int inicio, int fim){

	if(fim == inicio){

		if(fim > 0 && vetor[fim]/vetor[fim-1] != q){
			printf("falta o %f\n", a1*pow(q, fim));
		}else if(fim > 0 && vetor[fim+1]/vetor[fim] !=q){
			printf("falta o %f\n", a1*pow(q, fim+1));
		}
		return;
	}else{
		if(vetor[(fim-inicio)/2] == a1*pow(q, (fim+1)/2)){
			ve_se_ta_Certo(a1, q, inicio+(fim-inicio+2)/2, fim);
		}else{
			ve_se_ta_Certo(a1, q, inicio, inicio+(fim-inicio)/2);
		}
	}
}


int main(){

	double q, a1;

	a1 = vetor[0];
	if(vetor[1]/vetor[0] == vetor[2]/vetor[1]) q = vetor[1]/vetor[0];
	else if(vetor[1]/vetor[0] > vetor[2]/vetor[1] && vetor[1]/vetor[0] > 1){
		printf("o termo que falta é %f ", a1*q);
		return 0;
	}else if(vetor[1]/vetor[0] > vetor[2]/vetor[1] && vetor[1]/vetor[0] < 1){
		printf("o termo que falta é %f\n", a1*q );
		return 0;
	}else{
		q = vetor[1]/vetor[0];

	}

	ve_se_ta_Certo(a1, q, 0, 4);
}
