#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info
{
    char base[2];
    int qtd;
    struct info* prox;
    struct info* ant;
};

typedef struct info Info;

struct linfo
{
    struct info* inicio;
    struct info* fim;
};

typedef struct linfo LInfo;

struct gene
{
    char base[4];
    struct gene* prox;
};

typedef struct gene Gene;

void limpar();

void freeL(Gene* G,LInfo* I); 

void freeDL(LInfo* L);

void output(LInfo* L);

Gene* InserirS(Gene* L,char c[4]);

LInfo* criarList();

void inserirD(LInfo* L,char c[2]);

void InserirNo1(LInfo* L,char c[2]);

void InserirNoI(LInfo* L,char c[2]);

void inserirD(LInfo* L,char c[2]);

void ordenar(LInfo* L);

Info* buscaC(LInfo* L,char c[2]);

Gene* input(Gene* G,LInfo* I,int N);

void main()
{
    Gene* LGene;
    LInfo* dados;
    int N; 
    
    scanf("%d",&N);

    while (N!=0)
    {
    LGene = NULL;
    dados = criarList();

    LGene = input(LGene,dados,N);

    ordenar(dados);
    output(dados);

    freeL(LGene,dados);

    limpar();
    scanf("%d",&N);
    } 
}

Info* buscaC(LInfo* L,char c[2])
{
    for (Info* aux=L->inicio; aux != NULL; aux = aux->prox)
        if (aux->base[0]==c[0])
            return aux;
    
    return NULL;
}

Gene* input(Gene* G,LInfo* I,int N)
{
    char input[4];
    char c1[2];
    char c2[2];
    int t=0,i;

    for (i = 0; i<N ; i++)
    {
        limpar();
        fgets (input, 4, stdin);

        if (input[0] != '\n')
        {
        G = InserirS(G,input);

        c1[0]=input[0];
        c1[1]=0; 
        c2[0]=input[2];
        c2[1]=0;
        
        inserirD(I,c1);
        inserirD(I,c2);
        }    
        else
            i--;
    }
    return G;
}

void ordenar(LInfo* L)
{
Info* aux=L->inicio;
Info* auy=L->inicio;
char auc[2];
int dadoT; 

 while (aux != NULL)
    {
        auy=L->inicio;
        while (auy != NULL)
        {
            if (aux->qtd < auy->qtd)
            {
               strcpy(auc,aux->base);
               strcpy(aux->base,auy->base);
               strcpy(auy->base,auc);

               dadoT=aux->qtd;
               aux->qtd=auy->qtd;
               auy->qtd=dadoT;  
            }
            auy=auy->prox;
        }
        aux=aux->prox;
    }
  
}

void inserirD(LInfo* L,char c[2])
{
    if (L!=NULL)
    {
        Info* B=buscaC(L,c);

            if (L->inicio == NULL)  //caso a lista não tenha elementos
                InserirNo1(L,c);
            else if (B==NULL) 
                InserirNoI(L,c);
            else
                B->qtd++;
    }
}

void InserirNoI(LInfo* L,char c[2])
{

        Info* X = (Info*) malloc(sizeof(Info));
        strcpy(X->base,c);
        X->qtd=1;
        X->prox=L->inicio;
        X->ant=NULL;
        X->prox->ant=X;
        L->inicio=X;
}

void InserirNo1(LInfo* L,char c[2])
{
    Info* X = (Info*) malloc(sizeof(Info));

    strcpy(X->base,c);
    X->qtd=1;
    X->prox=NULL;
    X->ant=NULL;
    L->inicio=X;
    L->fim=X;
}

LInfo* criarList()
{
    LInfo* L = (LInfo*) malloc(sizeof(LInfo));

    L->fim = NULL;
    L->inicio = NULL;

    return L;
} 

Gene* InserirS(Gene* L,char c[4])
{
    Gene* X = (Gene*) malloc(sizeof(Gene));
    strcpy(X->base,c);
    X->prox=L;

    return X;
}

void output(LInfo* L)
{
    if (L!=NULL)
    {
        Info* aux = L->inicio;

        do
        {
            printf ("%s %d\n",aux->base,aux->qtd);
            printf("\n");
            aux=aux->prox;
        } while (aux!=NULL);
    }
    else 
        printf("\n");    
}

void limpar()
{
    int leitura;
    while((leitura = getchar()) != '\n' && leitura != EOF)
		/*--*/; 
}

void freeL(Gene* G,LInfo* I)
{
    if (G != NULL)
    {
        Gene* aux = G;

        while (G != NULL)
        {
          aux=G->prox;
          free(G);
          G=aux;  
        }
    }

    if (I!=NULL)
    {
    Info* aux2 = I->inicio;
    Info* auy;

    while ( aux2 != NULL )
    {
        auy=aux2->prox;
        free(aux2);
        aux2=auy;
    }
    free(I);
    }
}
