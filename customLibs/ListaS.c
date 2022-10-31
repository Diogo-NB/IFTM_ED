#include "ListaS.h"

Lista* criarLista(Lista* endRef,int valor)
{
    Lista* criado = (Lista*) malloc(sizeof(Lista));
    criado->proximo=endRef;
    criado->dados=valor;
    return criado;
}

Lista* criarZero()
{
    Lista* criado = (Lista*) malloc(sizeof(Lista));

    criado->proximo=NULL;
    criado->dados=0;

    return criado;
}

void mostrar(Lista* endRef)
{
    Lista* end = endRef;

    while (end != NULL)
    {
        printf("\n%d",end->dados);
        end=end->proximo;
    }
}

void freeLista(Lista* endRef)
{
    Lista* aux = endRef;

    while (aux != NULL)
    {
        endRef = endRef->proximo;
        free(aux);
        aux=endRef;
    }
}

void inserir(Lista* endRef,int valorX,int valorY)
{
    Lista* endVal = NULL;
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->dados=valorY;

    endVal=busca_valor(endRef,valorX);
    novo->proximo=endVal->proximo;
    endVal->proximo=novo;
}

Lista* busca_valor(Lista* endRef,int valor)
{
    Lista* end = endRef;

    while (end != NULL)
    {
        if (end->dados==valor)
            return end;
        end=end->proximo;
    }

    return NULL;
}