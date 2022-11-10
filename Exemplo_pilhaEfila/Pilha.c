#include<stdlib.h>
#include<stdio.h>

struct nop{
    int dados;
    struct nop* anterior; 
};
typedef struct nop No_P;

struct pilha{
    struct nop* top;
    struct nop* bot;
};
typedef struct pilha Pilha;

Pilha* ciar_pilha();

int push (Pilha* P,int val);
 
int pop (Pilha* P); 

int top (Pilha* P); 

int is_empty(Pilha* P); 

void free_Pilha(Pilha* P); 

Pilha* printP(Pilha* P); // print da pilha sem destruir-la (retornando a sua copia)

Pilha* invertP(Pilha* P);

void main(){
    int x=-1;
    Pilha* P=ciar_pilha();

    /*
    do
    {
        scanf("%d",&x);
        push(P,x);
    } while (x!=0);
    */

    for (x=0;x<11;x++)
        push(P,x);

    P = printP(P);
    free_Pilha(P);
}

int push (Pilha* P,int val){
    if (P==NULL)
        return 0;

    No_P* X = (No_P*) malloc(sizeof(No_P));
    X->dados=val;

    if (P->bot==NULL){
        P->bot=X;
        P->top=X;
        X->anterior=NULL;
        return 1;}

    X->anterior=P->top;
    P->top=X;
    return 1;
}

int pop (Pilha* P){
     if (P==NULL) 
        return 0;
    
     if (is_empty(P))
        return -1;  

    No_P* aux = P->top;

    if (P->bot==P->top){
        P->top=NULL;
        P->bot=NULL;
        free(aux); 
        return 1;
    }

    P->top=P->top->anterior;
    free(aux);
    return 1;
}

Pilha* ciar_pilha(){
    Pilha* X = (Pilha*) malloc(sizeof(Pilha));
    X->bot=NULL;
    X->top=NULL;
    return X;
}

int is_empty(Pilha* P){
    if (P==NULL)
        return -1;
    if (P->bot==NULL || P->top==NULL)
        return 1;
    return 0;
}

int top(Pilha* P){
    if(is_empty(P)!=0)
        return -1;
    return P->top->dados;
}

void free_Pilha(Pilha* P){
    if (P==NULL)
        free(P);
    else{
            while (!is_empty(P))
                pop(P);
            free(P); 
        }
}

Pilha* printP(Pilha* P){
/*EX 7. função que mostre todos os elementos de p sem desrespeitar as restrições
e usando apenas uma outra pilha como auxiliar*/

if (P==NULL || is_empty(P)==1)
    return P;

Pilha* x = ciar_pilha();
int t;
    while (!is_empty(P))
    {
        t=top(P);
        printf("\n%d",t);
        push(x,t);
        pop(P);
    }
    free_Pilha(P);

    P=x;
}

Pilha* invertP(Pilha* P){
/*EX 8. Função que inverte a ordem dos elementos dessa pilha
Definir adequadamente a estrutura auxiliar e prever a possibilidade da pilha estar vazia. */

if (is_empty(P)!=0)
    return P;

Pilha* x = ciar_pilha();
int t;
    while (!is_empty(P))
    {
        t=top(P);
        push(x,t);
        pop(P);
    }
    return x;
}
