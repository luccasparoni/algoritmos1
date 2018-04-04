#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long length = 10;
const long max_length = 1000000;

int vetor[1000000];
double media;
unsigned int cont = 0;

void read(){

    int i;
    for(i=0; i<length; i++){
        vetor[i] = (rand()*rand())%length;
    }
    
}


void merge( int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));
    
                                                                        cont+=7;

    while(com1<=meio && com2<=fim){
                                                                        cont+=2;
        if(vetor[com1] <= vetor[com2]){
            vetAux[comAux] = vetor[com1];
            com1++;
                                                                        cont+=3;
        }else{
            vetAux[comAux] = vetor[com2];
            com2++;
                                                                        cont+=2;
        }
        comAux++;
                                                                        cont+=1;
    }
                                                                        cont+=1;
    while(com1<=meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;com1++;
                                                                        cont+=4;
    }
                                                                        cont++;
    while(com2<=fim){   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;com2++;
                                                                        cont+=4;
    }
                                                                        cont+=2;
    for(comAux=comeco;comAux<=fim;comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];                          cont+=3;
    }
    
    free(vetAux);                                                       cont+=1;
}

void mergeSort(int comeco, int fim){
                                                                        cont++;
    if (comeco < fim){
                                                                        cont+=2;
        int meio = (fim+comeco)/2;


        mergeSort(comeco, meio);
        mergeSort(meio+1, fim);
        merge(comeco, meio, fim);
    }
}

void rodaMergeSort(int tamanho){

    length = tamanho;
    int j;
    for(j=0; j < 10; j++){
        read();
        mergeSort(0, tamanho-1);
        
        printf("%d", cont);
        printf("\n");
        media += cont;
        cont =0;
    }
    printf("Media >>>>>  %f  <<<<<< \n", media/10.0);
    media =0;
}

int main(){
    srand(time(NULL));
    //rodaMergeSort(10);
    //rodaMergeSort(100);
    //rodaMergeSort(1000);
    //rodaMergeSort(10000);
    rodaMergeSort(1000000);
}