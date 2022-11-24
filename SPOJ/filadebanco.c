#include<stdlib.h>
#include<stdio.h>

// LILO ou FIFO

struct nof{
    int T; // momento em que o cliente entra na fila apos abertura
    int D; // tempo necessário para atender o cliente.
    struct nof* anterior; 
};
typedef struct nof No_F;

struct fila{
    struct nof* top;
    struct nof* bot;
};
typedef struct fila Fila;

Fila* criarFila();

int push (Fila* F,int T,int D);

int pop (Fila* F);

int is_empty(Fila* F);

No_F* top(Fila* F);

void free_Fila(Fila* F);

int menor(int* X, int tamanho);

void main(){
    Fila* F = criarFila();

    int i2;
    int C,N,i,x,y;
    int res=0;
    int proxCaixa=0;
    scanf("%d %d",&C,&N);

    int* tCaixas = (int*) malloc(C*sizeof(int)); //quanto esta demorando cada caixa

    if (N>C){
        
    for(i=0; i<C; i++)
        tCaixas[i]=0;

    for (i=0; i<N; i++){
        scanf("%d %d",&x,&y);
        push(F,x,y);
    }
    
    for(i=0; i<C; i++){
        tCaixas[i]= F->top->D;
        pop(F);
    }
    proxCaixa = menor(tCaixas,C);

    while (is_empty(F)!=1){

        //for (i2=0; i2<C; i2++)
            //printf("%d",tCaixas[i2]);
        //printf("\n");

        x = tCaixas[proxCaixa] - F->top->T;

        if (x > 20)
            res++;
        
        tCaixas[proxCaixa] += F->top->D;
        proxCaixa = menor(tCaixas,C);
        pop(F);
    }
    }
    printf("%d\n",res);
}

int menor(int* X, int tamanho){
    int menor=X[0];
    int res=0;
    for (int i=0; i < tamanho; i++){
        if(X[i]<menor){
            menor=X[i];
            res=i;
        }
    }
    return res;
}

Fila* criarFila(){
    Fila* X = (Fila*) malloc(sizeof(Fila));
    X->bot=NULL;
    X->top=NULL;
    
    return X;
}

int push (Fila* F,int T,int D){
    if (F==NULL)
        return 0;

    No_F* X = (No_F*) malloc(sizeof(No_F));
    X->T=T;
    X->D=D;
    X->anterior=NULL;

    if (is_empty(F)){
        F->top=X;
        F->bot=X;
        return 1;
        }
    
    F->bot->anterior=X;
    F->bot=X;

    return 1;
}

int pop (Fila* F){
     if(F==NULL) 
        return 0;
    
     if(is_empty(F))
        return -1;  

    No_F* aux = F->top;

    F->top=F->top->anterior;

     if (aux->anterior=NULL)
        F->bot=NULL;
     
    free(aux);

    return 1;
}

int is_empty(Fila* F){
    if (F==NULL)
        return -1;

    if (F->bot==NULL || F->top==NULL)
        return 1;
    return 0;
}

No_F* top(Fila* F){
    if(is_empty(F)!=0)
        return NULL;
    return F->top;
}

void free_Fila(Fila* F){
    if (F==NULL)
        free(F);
    else{
            while (is_empty(F)!=0)
                pop(F);
            free(F); 
        }
}