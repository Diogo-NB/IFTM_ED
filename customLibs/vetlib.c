#include "vetlib.h"

int* insertV(int tamanho){
    int i;
    int *vet;

    vet = (int*) malloc(tamanho*sizeof(int));

    for (i=0;i< tamanho; i++)
    {
        printf("\nInsira o valor n %d : ",i+1);
        scanf("%d",&vet[i]);
    }
    return vet;
}

int contarvet(int Y,int* vet,int contar)
{
    int i,x=0;

    for (i=0;i<Y; i++)
     {
        if (vet[i]>=contar)
            x++;
     }
     return x;
}