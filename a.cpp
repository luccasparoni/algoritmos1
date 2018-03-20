#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

long length;
double t1, t2;
const long max_length = 100000;

int list[max_length];



//AQUI COMEÇA DO DE INSERTION SORT


void read()
{
    ifstream fin("random.dat", ios::binary);
    for (long i = 0; i < length; i++)
    {
        fin.read((char*)&list[i], sizeof(int));
    }
    fin.close();
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
void roda(long n){
    length = n;
    int u;
    double media=0;
    for(u=0; u<10; u++){

        read();
        t1 = clock();
        insertionSort();
        t2 = clock();
        media = media + (t2 - t1)/CLOCKS_PER_SEC;
    }
    cout << "\n\nInsertion sort media "<< n <<":"<< media/10.0;
}



//AQUI COMEÇA O DE BUSCA BINARIA


long double media2=0.0;

int binarySearch(int list[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;

        // If the element is present at the middle
        // itself
        if (list[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (list[mid] > x)
            return binarySearch(list, l, mid-1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(list, mid+1, r, x);
   }

   // We reach here when element is not
   // present in array
   return -1;
}

void rodabinario(int n, int x){
    printf("\nN: %d >>>>>",n);
    long double t1, t2;
    t1 = clock();

    int result = binarySearch(list, 0, n-1, x);
    t2 = clock();

    long double time;
    time = (t2-t1)/CLOCKS_PER_SEC;

    printf(" time: %.6Lf", time);
    media2 = media2+time;
}
int inicia(int a){
    int u;
    for(u=0; u<10; u++){
        int x = rand()%2*a;
        rodabinario(a,x);
    }
    printf("\n\n MEDIA: %.7Lf\n\n", (media2/10.0));
    media2 = 0.0;
}


//AQUI COMEÇA O DE BUSCA SIMPLES

int main()
{
    roda(10);
    roda(100);
    roda(1000);
    roda(10000);
    roda(100000);

    inicia(10);
    inicia(100);
    inicia(1000);
    inicia(10000);
    inicia(100000);

    return 0;
}
