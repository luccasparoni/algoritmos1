#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
  
double vetor[5]  = {32,16,8,2,1}; //vetor arbitrário para teste 
void ve_se_ta_certo(double a1, double q, int inicio, int fim){ 
  
    if(fim == inicio){//nesse ponto, o tamanho do vetor é 1, e só há um elemento presente - condição de parada 
  
        if(fim > 0 && vetor[fim]/vetor[fim-1] != q){ // se o valor encontrado dividido pelo elemento à sua esquerda for difernete da razão, o valor ausente é o anterior ao encontrado(da posição vetor[fim] 
            printf("falta o %f\n", a1*pow(q, fim)); 
        }else if(fim > 0 && vetor[fim+1]/vetor[fim] !=q){//se o valor encontrado dividido pelo elemento à sua direita for difenrete da razão, sabe-se que o elemento faltante é o posterior ao encontrado(de posicao vetor[fim] 
            printf("falta o %f\n", a1*pow(q, fim+1)); 
        } 
        return; 
    }else{ 
        if(vetor[(fim-inicio)/2] == a1*pow(q, (fim+1)/2)){ // o elemento faltante está na segunda metade do vetor analisado 
            ve_se_ta_Certo(a1, q, inicio+(fim-inicio+2)/2, fim); 
        }else{ // o elemento faltante está na primeira metade do vetor analisado 
            ve_se_ta_Certo(a1, q, inicio, inicio+(fim-inicio)/2); 
        } 
    } 
}  
  
int main(){  
    double q, a1;  
    a1 = vetor[0]; 
 
//Os próximos condicionais são usados para verificar se o termo faltante está entre os 3 primeiros e achar o termo inicial a1 e a razão q da progressão geométrica 
      if(vetor[1]/vetor[0] == vetor[2]/vetor[1]) q = vetor[1]/vetor[0]; 
    else if(vetor[1]/vetor[0] > vetor[2]/vetor[1] && vetor[1]/vetor[0] > 1){ 
        q = vetor[2]/vetor[1]; 
        printf("o termo que falta é %f ", a1*q); 
        return 0; 
    }else if(vetor[1]/vetor[0] > vetor[2]/vetor[1] && vetor[1]/vetor[0] < 1){ 
        q = vetor[1]/vetor[0] 
        printf("o termo que falta é %f\n", a1*q*q ); 
        return 0; 
    }else{ 
        q = vetor[1]/vetor[0]; 
    } 
  
    ve_se_ta_Certo(a1, q, 0, 4); 
    return 0; 
} 
