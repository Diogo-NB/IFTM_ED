#include<stdlib.h>
#include<stdio.h>

struct nop{
    char dados;
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

char top(Pilha* P); 

int is_empty(Pilha* P); 

void free_Pilha(Pilha* P); 

char cParaFechar(char c);

int verificarExpressao(Pilha* P);

void limpar();

void main(){

    char c;
    int n;
    scanf("%d",&n);
    limpar();

    for (int i=0; i<n; i++){
    Pilha* P = ciar_pilha(P);

    if(verificarExpressao(P))
        printf("S\n");
    else
        printf("N\n");

    free_Pilha(P);
    }
}

void limpar()
{
    int leitura;
    while((leitura = getchar()) != '\n' && leitura != EOF)
		/*--*/; 
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

char top(Pilha* P){
    if(is_empty(P))
        return 0;
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

int verificarExpressao(Pilha* P){

if (is_empty(P)!=1)
    return -1; //informar erro
    
int res=1;
char topAux,CAux;
char c=getchar();
    
while (c!='\n'){

    if (res!=0){ //

        CAux = cParaFechar(c);
    
        if (CAux==0)
            push(P,c);
        else{
            if (is_empty(P))
                res=0;
            else if (top(P)==CAux)
                pop(P);
            else
                res=0;
        }
    } //
    c=getchar();
}

if (res==0)
    return 0;
else if (is_empty(P))
    return 1;
else 
    return 0;
}

char cParaFechar(char c){
if (c==')')
    return '(';

if (c=='}')
    return '{';

if (c==']')
    return '[';

return 0;
}

