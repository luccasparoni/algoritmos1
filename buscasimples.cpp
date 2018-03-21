#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

long length;
const long max_length = 100000;

unsigned int list[max_length];
long double media;


void cria_lista(unsigned int n){
    int i;
    for(i=0; i<n-1; i++){
        list[i] = (rand()*rand())%n;
    }

}
unsigned int sequentialSearch(int n, unsigned int x){
    unsigned int cont=0;
    int i;
    cont+=2;
    for(i=0; i<n-1; i++){
        cont+=3;
        if (list[i] == x)
            return cont;
    }
    return cont;

}

void rodabusca(int n, unsigned int x){
    unsigned int cont = sequentialSearch(n,x);

    printf("%d\n", cont);
    media = media+cont;
    cont =0;
}

int comeca(int a){
    int u;
    for(u=0; u<10; u++){
        unsigned int key = (rand())%(2*a);
        printf("x = %u =>",key);
        rodabusca(a,key);
    }
    printf("\n\n MEDIA: %Lf\n\n", (media/10.0));
    media = 0.0;
}



int main(){
    srand(time(NULL));

    cria_lista(10);
    comeca(10);
    cria_lista(100);
    comeca(100);
    cria_lista(1000);
    comeca(1000);
    cria_lista(10000);
    comeca(10000);
    cria_lista(100000);
    comeca(100000);
}
