#include "ListaC.h"

void main()
{
    No* L = NULL;
    int i=0;

    for (i=0; i<20; i++)
        L = inserir(1,L,i+1);

    mostrar(L);

    for (i=5; i<10; i++)
        L = banir(L,i);
    
    ordenar(L);

    mostrar(L);
    
    
    freeLista(L);
}