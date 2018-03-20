#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

long length;
const long max_length = 100000;

int list[max_length];
long double media2;


void read()
{
    ifstream fin("random.dat", ios::binary);
    for (long i = 0; i < length; i++)
    {
        fin.read((char*)&list[i], sizeof(int));
    }
    fin.close();
}

void sequentialSearch(int n, int x){

    int i;
    for(i=0; i<n-1; i++){
        if (list[i] == x)
            return;
    }

}

void rodabusca(int n, int x){
    printf("\nN: %d >>>>>",n);
    long double t1, t2;
    t1 = clock();

    sequentialSearch(n,x);
    t2 = clock();

    long double time;
    time = (t2-t1)/CLOCKS_PER_SEC;

    printf(" time: %.6Lf", time);
    media2 = media2+time;
}

int comeca(int a){
    int u;
    for(u=0; u<10; u++){
        int x = rand()%a;
        rodabusca(a,x);
    }
    printf("\n\n MEDIA: %.7Lf\n\n", (media2/10.0));
    media2 = 0.0;
}



int main(){
    comeca(10);
    comeca(100);
    comeca(1000);
    comeca(10000);
    comeca(100000);
}
