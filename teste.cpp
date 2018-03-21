#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;
long length = 10;
const long max_length = 100000;

int list[max_length];
unsigned int contins = 0;

void read(){
    int i;
    for(i=0; i<length; i++){
        list[i] = rand()%length;
    }
}

void insertionSort(){
    int temp;                               contins++;
    for(long i = 1; i < length; i++){
                                            contins+=2;
        temp = list[i];                     contins++;
        long j;
                                            contins+=3;
        for(j = i-1; j >= 0 && list[j] > temp; j--){contins+=3;
            list[j+1] = list[j];            contins++;
        }
        list[j+1] = temp;                   contins++;
    }
}
double media=0;
void roda(unsigned int tamanho){
        media =0;
        length = tamanho;
        for(int i=0; i<10; i++){
            double t1,t2;
            read();
            insertionSort();
            cout << "contador insertion sort: "<< contins << "\n";
            media = media + contins;
            contins = 0;
        }

}

int cont=0;
double mediabin=0;

void PesquisaBinaria (int chave, int Tam)
{
     int inf = 0;     // limite inferior (o primeiro índice de vetor em C é zero          )
     int sup = Tam-1; // limite superior (termina em um número a menos. 0 a 9 são 10 números)
     int meio;
     while (inf <= sup)
     {
          cont++;
          meio = (inf + sup)/2;cont++;
          if (chave == list[meio]){
                cont++;
               return;
          }cont++;
          if (chave < list[meio]){
               sup = meio-1;
               cont++;
          }
          else{
            inf = meio+1;
            cont++;
          }
     }
     cont++;
     return;   // não encontrado
}

void binarysearch(unsigned int tamanho){

    int y;
    for(y=0; y<10; y++){
        unsigned int key = (rand()*rand())%(2*tamanho);
        PesquisaBinaria(key,tamanho);
        mediabin = mediabin +  cont;
        cout << "\ncontador binario:" << cont;
        cont =0;
    }
    cout << "\n\n\nMedia binary search:" << mediabin/10.0;
    mediabin =0;
}


int main()
{
    srand(time(NULL));

    cout << "\n\n\n\n***********Quando N = 10**************** \n\n";
    roda(10);
    cout << "-------media do insertion: " << media/10.0;
    binarysearch(10);

    cout << "\n\n\n\n***********Quando N = 100**************** \n\n";
    roda(100);
    cout << "----------media do insertion: " << media/10.0;
    binarysearch(100);

    cout << "\n\n\n\n***********Quando N = 1000**************** \n\n";
    roda(1000);
    cout << "----------media do insertion: " << media/10.0;
    binarysearch(1000);

    cout << "\n\n\n\n***********Quando N = 10000**************** \n\n";
    roda(10000);
    cout << "----------media do insertion: " << media/10.0;
    binarysearch(10000);

    cout << "\n\n\n\n***********Quando N = 100000**************** \n\n";
    roda(100000);
    cout << "-----------media do insertion:" << media/10.0;
    binarysearch(100000);

    return 0;
}
