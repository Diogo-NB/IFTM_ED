#include "ListaD.h"

void inserir(int parametro,Lista* L,int valor)
{
    if (L!=NULL)
    {
            if (L->inicio == NULL)  //caso a lista não tenha elementos
                InserirNo1(L,valor);
            else if (parametro == 1)
                inserirNoI(L,valor);
            else if (parametro == 2)
                inserirNoF(L,valor);
            else if (parametro ==3)
                inserirEmOrdemCresc(L,valor);
            else
                printf("\nErro no inserir, Parametro passado incorretamente.\n");
    }
    else
        printf("\n\nFoi passado lista nula\n\n");
}

Lista* criarList()
{
    Lista* L = (Lista*) malloc(sizeof(Lista));

    L->fim = NULL;
    L->inicio = NULL;

    return L;
} 

void InserirNo1(Lista* L,int valor)
{
    No* X = (No*) malloc(sizeof(No));
    X->dados=valor;
    X->prox=NULL;
    X->ant=NULL;
    L->inicio=X;
    L->fim=X;

}

void inserirNoI(Lista* L,int valor)
{
    No* X = (No*) malloc(sizeof(No));

    X->dados=valor;
    X->prox=L->inicio;
    X->ant=NULL;
    X->prox->ant=X;
    L->inicio=X;
    
}

void inserirNoF(Lista* L,int valor)
{
    No* X = (No*) malloc(sizeof(No));

    L->fim->prox=X;
    X->dados = valor;
    
    X->prox = NULL;
    X->ant = L->fim;
    L->fim=X;

}

void inserirEmOrdemCresc(Lista* L,int valor)
{ 
    No* aux = L->inicio;

    if (valor <= aux->dados)
        inserirNoI(L,valor);
    else
    {
        for (aux; aux!=NULL && aux->dados < valor ; aux=aux->prox )
         {/**/}

        if (aux==NULL)
            inserirNoF(L,valor); 
        else
            inserirEntre(L,aux->ant,aux,valor);
    }  
} 

void inserirEntre(Lista* L, No* A, No* B, int valor)
{
    No* X = (No*) malloc(sizeof(No));
    X->dados=valor;
    X->ant=A;
    X->prox=B;
    A->prox=X;
    B->ant=X;
}

int contaElementos(Lista* L)
{
    if (L==NULL || L->inicio==NULL || L->fim==NULL)
        return 0;

    No* aux = L->inicio;
    int c=0;

    for (aux;aux!=NULL;aux=aux->prox)
        c++;

    return c;
}

void mostrar(Lista* L)
{
    printf("\n[");

    if (!(L==NULL || L->inicio==NULL || L->fim==NULL))
        {
            for (No* aux = L->inicio;aux!=NULL;aux=aux->prox)
               printf(" %d",aux->dados);
        }

    printf(" ]\n");
}

No* maximo(Lista* L)
{
    if (L == NULL || L->inicio == NULL)
        return NULL;
    
        No* max=L->inicio;
        No* aux=L->inicio;

        for (aux; aux!=NULL; aux=aux->prox)
        {
            if (aux->dados >= max->dados)
                max=aux;
        }

    return max;
}

No* minimo(Lista* L)
{
    if (L == NULL || L->inicio == NULL)
        return NULL;
    
        No* min=L->inicio;
        No* aux=L->inicio;

        for (aux; aux!=NULL; aux=aux->prox)
        {
            if (aux->dados < min->dados)
                min=aux;
        }

    return min;
}

Lista* copiarLista(Lista* L)
{
    if (L==NULL || L->inicio==NULL)
        return NULL;
        
    Lista* copia=criarList();   
    No* aux=L->inicio;

    for (aux; aux!=NULL ; aux=aux->prox)
        inserir(2,copia,aux->dados);

    return copia;
}   

void freeLista(Lista* L)
{
    No* aux = L->inicio;
    No* auy;

    while ( aux != NULL )
    {
        auy=aux->prox;
        free(aux);
        aux=auy;
    }
}

void ordenar(Lista* L)
{
No* aux=L->inicio;
No* auy=L->inicio;

int dadoT; 

 while (aux != NULL)
    {
        auy=L->inicio;
        while (auy != NULL)
        {
            if (aux->dados < auy->dados)
            {
               dadoT=aux->dados;
               aux->dados=auy->dados;
               auy->dados=dadoT;  
            }
            auy=auy->prox;
        }
        aux=aux->prox;
    }
  
}

No* buscaElemento(Lista* L,int valor)
{
    for (No* aux=L->inicio; aux != NULL; aux = aux->prox)
        if (aux->dados==valor)
            return aux;
    
    return NULL;
}

void exclua(Lista* L,No* X)
{
    if (!(L==NULL || L->inicio==NULL || X==NULL))
    {
        if (X == L->fim && X == L->inicio){
                L->fim=NULL;
                L->inicio=NULL;
            }
        else if (X == L->fim){
                L->fim = X->ant;
                X->ant->prox = NULL;
            }
        else if (X == L->inicio){
                L->inicio = X->prox;
                X->prox->ant = NULL;
            }
        else {
                X->ant->prox = X->prox;
                X->prox->ant = X->ant;
            }
        free(X);
    }
}

void banir(Lista* L,int valor)
{
    for ( No* aux = buscaElemento(L,valor) ; aux != NULL ; aux = buscaElemento(L,valor) )
        exclua(L,aux);
}
