#include <stdio.h>
#include <stdlib.h>

typedef struct Wynik_{
  int indeks;
  int nz;
} wynik;

wynik * szukajka(float* tab, int tabSize){
    int i;
    wynik *result;
    result = malloc(sizeof(wynik));
    result->indeks=0;
    result->nz=0;
    //Zerujemy zmienne, coby smieci tam nie bylo
    for(i=0;i<tabSize;i++){
        if(tab[i]){
            if(result->indeks){
                //Znalezlismy drugie nie zero. Poprawiamy wynik i wychodzimy
                result->nz++;
                return result;
            } else {
                result->indeks = i;
                //Znalezlismy pierwsze niezero
            }
        }
    }
    return result;
}

void szukajka2(float* tab, int tabSize, int* indeks, int* nz){
    int i;
    *indeks = 0;
    *nz = 0;
    for(i=0;i<tabSize;i++){
        if(tab[i]){
            if(*indeks){
                *nz = 1;
                return;
            } else {
                *indeks = i;
            }
        }
    }
    if(!*indeks){
        *indeks=i;
    }
}

int main(void)
{
    //printf("Hello World!\n");
    float tab[5] = {0,0,5,0,2};

    wynik* result;
    result = szukajka(tab,5);
    printf("Wyniki: indeks=%d, nz=%d\n",result->indeks,result->nz);

    int indeks, nz;
    szukajka2(tab,5,&indeks,&nz);
    printf("Wyniki: indeks=%d, nz=%d\n",indeks,nz);

    return 0;
}
