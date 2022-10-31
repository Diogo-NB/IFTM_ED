#include <stdio.h>
#include <stdlib.h>

int fatorial(int x); 

void main()
{
int cont=0; 
int n,n2,i,x; 

scanf("%d",&n);

for (i=8;i>=0;i--)
{
x=n/fatorial(i);

    if (x!=0 && i!=0)
    {
        cont=cont+x; //adiciona para contagem de fatoriais usados
        n=n-(x*fatorial(i)); //atribui resto
    }
}
cont=cont+n;

printf("%d\n",cont);
}

 int fatorial(int x)
{
    int j;
    int result=1;

    for (j=1;j<=x;j++)
    {
     result=result*j;
    }
    return result;
}



