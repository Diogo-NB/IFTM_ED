#include "ListaC.h"

No* inserir(int t,No* L, int valor)
{
    if (L == NULL)
        L = InserirNo1(valor);
    else if ( t == 1 )
       inserirDir(L,valor);
    else if ( t == 2 )
        inserirEsq(L,valor);
    else if ( t == 3 )
        L = inserirOrdenado(L,valor);
    else
        printf("\n\nParametro errado em inserir\n\n");
    return L;
}

No* InserirNo1(int valor)
{
    No* X = (No*) malloc(sizeof(No));

    X->dados=valor;
    X->prox=X;
    X->ant=X;

    return X;
}

void inserirDir(No* L,int valor)
{
    No* X = (No*) malloc(sizeof(No));

    X->dados = valor;
    X->ant = L;
    X->prox = L->prox;
    L->prox->ant = X;
    L->prox = X;

}

void inserirEsq(No* L,int valor)
{
    No* X = (No*) malloc(sizeof(No));

    X->dados = valor;
    X->ant = L->ant;
    X->prox = L;
    L->ant->prox=X;
    L->ant=X;
    
}

No* inserirOrdenado(No* L,int valor)
{
    No* aux = L;

    do
    {
        aux=aux->prox;    
    } while (aux != L && valor >= aux->dados);

    if (valor <= L->dados)
        {inserirEsq(L,valor); return L->ant;}
    inserirEsq(aux,valor);

    return L;
}

void mostrar(No* L)
{
    printf("\n[");

    No* aux = L;

    do {
        printf(" %d ",aux->dados);
        aux=aux->prox;

       } while (aux != L);

    printf("]\n");
}

void ordenar(No* L)
{
No* aux=L;
No* auy;

int dadoT; 

  do
  {
    auy=L;

    do
    {
        if (aux->dados < auy->dados)
            {
               dadoT=aux->dados;
               aux->dados=auy->dados;
               auy->dados=dadoT;  
            }
            auy=auy->prox;
            
    } while (auy != L);

    aux=aux->prox;

  } while (aux != L);
  
}

No* buscaElemento(No* L,int valor)
{
    No* aux = L;

    do
    {
        if (valor == aux->dados)
            return aux;
            
        aux = aux->prox;
    } while (aux!=L);
    
    return NULL;
}

No* exclua(No* L,No* X)
{
if (X==NULL)
    return NULL;

if (X->prox==X){   //caso seja o unico elemento
    free(X);
    return NULL;    
}

No* retorno;

if (X==L)
    retorno = L->prox;
else
    retorno = L;

X->ant->prox=X->prox;
X->prox->ant=X->ant;
free(X);

return retorno;
}

No* banir(No* L,int valor)
{
    No* aux = buscaElemento(L,valor);

    while ( aux != NULL )
    {
        L = exclua(L,aux);
        aux = buscaElemento(L,valor);
    }

    return L;
}

void freeLista(No* L)
{
    No* aux = L;
    No* auy;

    do {
        auy=aux->prox;
        free(aux);
        aux=auy;
    } while ( aux != L );

}



