#include<stdlib.h>
#include<stdio.h>

// LILO ou FIFO

struct nof{
    int dados;
    struct nof* anterior; 
};
typedef struct nof No_F;

struct fila{
    struct nof* top;
    struct nof* bot;
};
typedef struct fila Fila;

Fila* criarFila();

int push (Fila* F,int val);

int pop (Fila* F);

int is_empty(Fila* F);

int top(Fila* F);

void free_Fila(Fila* F);

void main(){
    int x=-1;
    Fila* F=criarFila();

    /*
    do
    {
        scanf("%d",&x);
        push(P,x);
    } while (x!=0);
    */

    for (x=0;x<11;x++)
        push(F,x);
    pop(F);
    free_Fila(F);
}

Fila* criarFila(){
    Fila* X = (Fila*) malloc(sizeof(Fila));
    X->bot=NULL;
    X->top=NULL;

    return X;
}

int push (Fila* F,int val){
    if (F==NULL)
        return 0;

    No_F* X = (No_F*) malloc(sizeof(No_F));
    X->dados=val;
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

int top(Fila* F){
    if(is_empty(F)!=0)
        return -1;
    return F->top->dados;
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