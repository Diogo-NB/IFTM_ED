#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

/*LIFO Last In First Out ou FILO First In Last Out

 Criar uma pilha vazia                        P->TOP
 Inserir um elemento no topo da pilha        |_______|
 Remover um elemento do topo de pilha        |_______|
 Consultar  o topo da pilha                  |_______|
 Destruir a pilha                            |_______|
 Verificar se é cheia                        |_______|
 Verificar se é vazia                        |_______|
                                              P->BOT
*/
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

void printP(Pilha* P);

void main()
{
    int n=11;
    Pilha* P=ciar_pilha(P);
    int i;
    for (i=1;i<n;i++)
        push(P,i);

    printP(P);
    free_Pilha(P);
    
}

int push (Pilha* P,int val)
{
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

    No_P* aux = P->top->anterior;
    if (P->bot==P->top){
        free(P->bot);
        free(P);
        P=ciar_pilha();
        }
    
    No_P* temp = P->top;
    P->top=aux;
    free(temp);
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
    if(is_empty(P))
        return -1;
    return P->top->dados;
}

void free_Pilha(Pilha* P){
    if (P==NULL)
        free(P);
    else{

            while (is_empty(P))
                pop(P);
            free(P); 
        }
}

void printP(Pilha* P){
    while (!is_empty(P))
    {
        printf("| %d ",top(P));
        pop(P);
    }
}




    

