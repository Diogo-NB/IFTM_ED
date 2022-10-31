#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int dados;
    struct lista* proximo;
};

typedef struct lista Lista; 

Lista* inputLista(Lista* L,int qtd); //função para receber dados e criar lista com esses dados 

Lista* criarZero(int valor); //inicializando uma lista

Lista* criarLista(Lista* endRef,int i); //adicionando um valor para a lista

Lista* inters(Lista* x,Lista* y); //retorna uma nova lista da interseccao dos dados de duas listas

Lista* uniao(Lista* x,Lista* y); //retorna uma nova lista da uniao dos dados de duas listas

Lista* busca_valor(Lista* endRef,int valor); //busca um valor na lista, e retorna seu endereco, (NULL caso nao exista)

Lista* criarCopia(Lista* L); //retorna uma copia criada de tal lista

void Orderna(Lista* L); //ordena os dados da lista de forma crescente

void mostrar(Lista* endRef); //output dos dados da lista

void freeL(Lista* L); //desalocamento da lista

void main()
{
    Lista* L1=NULL; //Primeiro conjunto
    Lista* L2=NULL; //Segundo conjunto
    Lista* uL=NULL; //Lista da uniao 
    Lista* iL=NULL; //Lista da interseccao 

    int qtdL1,qtdL2;

    scanf("%d %d",&qtdL1,&qtdL2);

    L1=inputLista(L1,qtdL1);
    L2=inputLista(L2,qtdL2);

    iL=inters(L1,L2);
    uL=uniao(L1,L2);

    mostrar(iL);
    printf("\n");
    mostrar(uL);
 
    freeL(iL);
    freeL(uL);
    freeL(L1);
    freeL(L2);
}

Lista* inputLista(Lista* L,int qtd)
{
    if (qtd==0)
        return NULL;

    int i,x;

    scanf("%d",&x);
    L=criarZero(x);

    for (i=1;i<qtd;i++)
     {
        scanf("%d",&x);
        L=criarLista(L,x);
    }

    return L;
}

Lista* criarZero(int valor)
{
    Lista* criado = (Lista*) malloc(sizeof(Lista));

    criado->proximo=NULL;
    criado->dados=valor;
    return criado;
}

Lista* criarLista(Lista* endRef,int valor)
{
    Lista* criado = (Lista*) malloc(sizeof(Lista));
    criado->proximo=endRef;
    criado->dados=valor;
    
    return criado;
}

Lista* criarCopia(Lista* L)
{
    Lista* aux=L;
    Lista* cpy=NULL;

    if (L != NULL)
   {
    cpy=criarZero(aux->dados);
    aux=aux->proximo;

    while (aux!= NULL)
    {
        cpy=criarLista(cpy,aux->dados);
        aux=aux->proximo;
    }
   }

   return cpy;
}

Lista* inters(Lista* x,Lista* y)
{
    Lista* inter=NULL;
    Lista* aux=x;
    Lista* auy=y;
    int t=0;
    
    if (x==NULL || y==NULL)
        return NULL;

    while (aux!= NULL)
    {
        if (busca_valor(y,aux->dados)!=NULL)
        {
           if (t==0)
           {
                inter=criarZero(aux->dados);
                 t++;
           }
           else
                inter=criarLista(inter,aux->dados);
        }
        aux=aux->proximo;
    }

        return(inter);
}

Lista* uniao(Lista* x,Lista* y)
{
    Lista* uni;
    Lista* aux=x;

    if (x==NULL && y==NULL)
        return NULL;
    else if (y==NULL)
        return criarCopia(x);
    else if (x==NULL)
        return criarCopia(y);
    else
    {
    uni=criarCopia(aux);
    
    aux=y;

    while (aux!= NULL)
    {
        if(busca_valor(x,aux->dados)==NULL)
            uni=criarLista(uni,aux->dados);
        aux=aux->proximo;
    }
    Orderna(uni);
    return(uni);
    }
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

void mostrar(Lista* endRef)
{
    if (endRef!=NULL)
    {
        Lista* end = endRef;

        printf("%d",end->dados);
        end=end->proximo;

        while (end != NULL)
        {
            printf(" %d",end->dados);
            end=end->proximo;
        }
    }
    else 
        printf("\n");
}

void freeL(Lista* L)
{
    if (L != NULL)
    {
        Lista* aux = L;

        while (L != NULL)
        {
          aux=L->proximo;
          free(L);
          L=aux;  
        }
    }
}

void Orderna(Lista* L)
{
Lista* aux=L;
Lista* auy=L;

int dadoT; //armazena temporariamente

 while (aux != NULL)
    {
        while (auy != NULL)
        {
            if (aux->dados < auy->dados)
            {
               dadoT=aux->dados;
               aux->dados=auy->dados;
               auy->dados=dadoT;  
            }
            auy=auy->proximo;
        }
        auy=L;
        aux=aux->proximo;
    }
}
