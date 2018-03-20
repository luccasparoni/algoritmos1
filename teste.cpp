#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;
long length = 10;
const long max_length = 100000;

int list[max_length];

void read()
{
    int i;
    for(i=0; i<length; i++){
        list[i] = rand()%length;
    }
}

void bubbleSort()
{
    int temp;
    for(long i = 0; i < length; i++)
    {
        for(long j = 0; j < length-i-1; j++)
        {
            if (list[j] > list[j+1])
            {
                temp        = list[j];
                list[j]     = list[j+1];
                list[j+1]   = temp;
            }
        }
    }
}

void insertionSort()
{
    int temp;
    for(long i = 1; i < length; i++)
    {
        temp = list[i];
        long j;
        for(j = i-1; j >= 0 && list[j] > temp; j--)
        {
            list[j+1] = list[j];
        }
        list[j+1] = temp;
    }
}

long partition(long left, long right)
{
    int pivot_element = list[left];
    int lb = left, ub = right;
    int temp;

    while (left < right)
    {
        while(list[left] <= pivot_element)
            left++;
        while(list[right] > pivot_element)
            right--;
        if (left < right)
        {
            temp        = list[left];
            list[left]  = list[right];
            list[right] = temp;
        }
    }
    list[lb] = list[right];
    list[right] = pivot_element;
    return right;
}

void quickSort(long left, long right)
{
    if (left < right)
    {
        long pivot = partition(left, right);
        quickSort(left, pivot-1);
        quickSort(pivot+1, right);
    }
}
double media;
void roda(int tamanho){
        length = tamanho;
        for(int i=0; i<10; i++){
            double t1,t2;
            read();
            t1 = clock();
            insertionSort();
            t2 = clock();
            double tempo = (t2 - t1)/CLOCKS_PER_SEC;
            //cout << tempo << " sec\n";
            media = media + tempo;
            }
}

int cont=0;
double mediabin;

void PesquisaBinaria (int chave, int Tam)
{
     int inf = 0;     // limite inferior (o primeiro índice de vetor em C é zero          )
     int sup = Tam-1; // limite superior (termina em um número a menos. 0 a 9 são 10 números)
     int meio;
     while (inf <= sup)
     {
          cont++;
          meio = (inf + sup)/2;
          if (chave == list[meio])
               return;
          if (chave < list[meio])
               sup = meio-1;
          else
               inf = meio+1;
     }
     return;   // não encontrado
}

void binarysearch(int tamanho){

    double t1,t2;
    int y;
    for(y=0; y<10; y++){
        int key = rand()%tamanho;

        PesquisaBinaria(key,tamanho);
        media = media +  cont;
        cont =0;
    }
    cout << "\nMedia binary search:" << media/10.0;
    media =0;
}



int main()
{
    cout << "\n\n\n\n***********Quando N = 10**************** \n\n";
    roda(10);
    cout << "media do insertion: " << media/10.0;
    binarysearch(10);

    cout << "\n\n\n\n***********Quando N = 100**************** \n\n";
    roda(100);
    cout << "media do insertion: " << media/10.0;
    binarysearch(100);

    cout << "\n\n\n\n***********Quando N = 1000**************** \n\n";
    roda(1000);
    cout << "media do insertion: " << media/10.0;
    binarysearch(1000);

    cout << "\n\n\n\n***********Quando N = 10000**************** \n\n";
    roda(10000);
    cout << "media do insertion: " << media/10.0;
    binarysearch(10000);

    cout << "\n\n\n\n***********Quando N = 100000**************** \n\n";
    roda(100000);
    cout << "media do insertion:" << media/10.0;
    binarysearch(100000);

    return 0;
}
