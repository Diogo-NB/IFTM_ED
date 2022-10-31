#include "acclib.h"

ACC insertACC (){
        ACC acctemp;
        char dump;
        printf("Insira os dados da conta:\nNumero: ");
        scanf("%d",&acctemp.num);
        dump=getc(stdin);
        printf("Nome: ");
        fgets(acctemp.cliente.nome,50,stdin);
        /*
        printf("CEP: ");
        scanf("%d",&acctemp.cliente.cep);
        printf("CPF: ");
        scanf("%d",&acctemp.cliente.cpf);
        */
        printf("Saldo: ");
        scanf("%f",&acctemp.saldo);

        return acctemp;
}

void showACC(ACC acctemp){
    printf("\nMostrando dados da conta numero: %d",acctemp.num);
    printf("\nNome: ");
    puts(acctemp.cliente.nome);
     /*
        printf("CEP: %d\nCPF: %d ",acctemp.cliente.cep,acctemp.cliente.cpf);
    */
    printf("Saldo: %.4f",acctemp.saldo);
    printf("\n");
}

void transferACC(ACC *acx, ACC *acy,float tval){ // operações de acy para acx

    if ((acy->saldo)>=tval)
    {
        acy->saldo=(acy->saldo)-tval;
        acx->saldo=(acx->saldo)+tval;
        printf("\nTransação no valor de %.4f, de conta n %d para conta n %d foi confirmada.\n",tval,acy->num,acx->num);
        printf("Saldos atualizados: %.4f  e %.4f  ",acy->saldo,acx->saldo);
    }
    else
        printf("Conta n %d nao tem saldo o suficiente para completar a transferencia.\nTransferencia cancelada.",acy->num);
     
}

