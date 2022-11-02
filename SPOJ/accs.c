#include <stdio.h>
#include <stdlib.h>
#include "acclib.h"

int main()
{
ACC* contas;
float valort=100.0;
int i,qtd=2;

contas = (ACC*) malloc((qtd+1)*(sizeof(ACC)));

for (i=0;i<qtd;i++)
    contas[i]=insertACC();

transferACC(&contas[0],&contas[1],valort);

showACC(contas[0]);
showACC(contas[1]);

free(contas);
return 0;
}
