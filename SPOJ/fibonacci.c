#include <stdio.h>
#include <stdlib.h>

int fib(int* C,int n){
    if (n <= 1)
        return n;
    *C = *C+2; // soma o valor de chamadas
    return fib(C,n - 1) + fib(C,n - 2);
}

void main(){
    int qtd,n,chamadas=0;
    int* C = &chamadas;
    int val;
    scanf("%d",&qtd);

    for (int i=0; i<qtd; i++){
    scanf("%d",&n);
    val = fib(C,n);
    printf("fib(%d) = %d, fazendo %d chamadas\n",n,val,*C);
    *C=0;
    }
}