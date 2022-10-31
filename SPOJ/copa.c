#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct time
{
char letra[1];      // letra que representa o time. A letra vai de A a P

char nome[30];      // nome do time (pais). Por exemplo: BRASIL.

int  continente;    // Continente do país. 1: AMERICA; 2: EUROPA; 3: AFRICA; 4: ASIA; 5: OCEANIA.

int qtde_partidas;  // quantidade de partidas realizadas na Fase Final. De 1 a 4.

int gols_a_favor;   // todos os gols realizados pela equipe na Fase Final.

int gols_contra;    // todos os gols que a equipe sofreu na Fase Final.

int saldo_gols;     // gols a favor – gols contra na Fase Final.
};

struct partida
{
int codigo;      // codigo da partida. Por exemplo: 3, significa a partida entre E e F nas oitavas de final.

char time1[1];      // letra do time 1. Por exemplo E.

char time2[1];      // letra do time 2. Por exemplo F.

int gols_time1;  // a quantidade de gols que o time 1 realizou na partida.

int gols_time2;  // a quantidade de gols que o time 2 realizou na partida.
};

typedef struct time Time;

typedef struct partida Partida;

void InicializaTimes(Time *VetorTimes,int tamanho);         // zera os int para cada estrutura criada (quantidade=tamanho) 
void InicializaPartidas(Partida *VetorPartida, int tamanho);

void zerar_int_time(Time *VetorTimes);         // coloca todo int da estrutura como zero
void zerar_int_partida(Partida *VetorPartida);

void ReceberTimes(Time *VetorTimes, int tamanho);         // armazena para cada estrutura criada (quantidade=tamanho)
void ReceberPartidas(Partida *VetorPartida, int tamanho);

void lerTime(Time *VetorTimes);         // faz leitura para armazenar
void lerPartida(Partida *VetorPartidas);

void atualizaGols(Time *VetorTimes,Partida *VetorPartida, int qtdt, int qtdp);

void limpar(); //discarta caractere indesejavel, sempre usar depois de scanf com inteiro

void Output(Time time); // saida dos valores

Time MelhorSaldoGols(Time *VetorTimes, int tam_times);
Time PiorSaldoGols(Time *VetorTimes, int tam_times);
Time MelhorClassificadoContinente(Partida *VetorPartidas, int tam_part, Time *VetorTimes, int tam_times, int continente);
Time MelhorDoContinente(Time *VetorTimes,int qtdt, int c);

int main()
{
    Time* VetorTimes;
    Partida* VetorPartidas;
    int qtdt,qtdp,i,j;  

    Time melhorPorContinente[5];
    Time melhorSaldo,piorSaldo;

    scanf("%d",&qtdt); //quantidade de times
    limpar(); 

        if (qtdt!=0){

    VetorTimes = (Time *) malloc((qtdt) * sizeof(Time)); 

    InicializaTimes(VetorTimes,qtdt);
    ReceberTimes(VetorTimes,qtdt);

    limpar(); 
    scanf("%d",&qtdp); // quantidade de partidas
    limpar(); 
    
    VetorPartidas = (Partida *) malloc((qtdp) * sizeof(Partida)); 

    InicializaPartidas(VetorPartidas,qtdp);
    ReceberPartidas(VetorPartidas,qtdp); 
    
    atualizaGols(VetorTimes,VetorPartidas,qtdt,qtdp);

    melhorSaldo = MelhorSaldoGols(VetorTimes,qtdt);
    piorSaldo = PiorSaldoGols(VetorTimes,qtdt);

    printf("\n%c\n%c\n",melhorSaldo.letra[0],piorSaldo.letra[0]);
    
    for (i=0;i<5;i++)
    {
    melhorPorContinente[i]=MelhorDoContinente(VetorTimes,qtdt,i+1);
    printf("%d:%c\n",i+1,melhorPorContinente[i].letra[0]);
    }
    
    free(VetorPartidas);
    free(VetorTimes);

        }
}

void atualizaGols(Time *VetorTimes,Partida *VetorPartidas, int qtdt, int qtdp)
{
    int i,j;

    for (i=0;i<qtdt;i++)
    {
        for (j=0;j<qtdp;j++)
        {
            if (VetorTimes[i].letra[0]==VetorPartidas[j].time1[0])
            {
                VetorTimes[i].gols_a_favor = VetorTimes[i].gols_a_favor + VetorPartidas[j].gols_time1;
                VetorTimes[i].gols_contra = VetorTimes[i].gols_contra + VetorPartidas[j].gols_time2;
                (VetorTimes[i].qtde_partidas)++;
                
            }
            else if (VetorTimes[i].letra[0]==VetorPartidas[j].time2[0])
            {
                VetorTimes[i].gols_a_favor = VetorTimes[i].gols_a_favor + VetorPartidas[j].gols_time2;
                VetorTimes[i].gols_contra = VetorTimes[i].gols_contra + VetorPartidas[j].gols_time1;
                (VetorTimes[i].qtde_partidas)++;
                
            }
        } 
        VetorTimes[i].saldo_gols = VetorTimes[i].saldo_gols + VetorTimes[i].gols_a_favor - VetorTimes[i].gols_contra;
    }
}

void ReceberTimes(Time *VetorTimes, int tamanho)
{
int i;
    for (i=0;i<tamanho;i++)
    {
        if (i!=0)     
            limpar(); 
        lerTime(&VetorTimes[i]); 
    }
}

void ReceberPartidas(Partida *VetorPartidas, int tamanho)
{
    int i;

    for (i=0;i<tamanho;i++)
        lerPartida(&VetorPartidas[i]); 
}

void lerTime(Time *VetorTimes)
{
    scanf("%s",VetorTimes->letra);
    scanf("%s",VetorTimes->nome);
    scanf("%d",&VetorTimes->continente);
}

void lerPartida(Partida *VetorPartidas)
{
    scanf("%d",&VetorPartidas->codigo);
    limpar(); 
    scanf("%s",VetorPartidas->time1);
    scanf("%s",VetorPartidas->time2);
    scanf("%d",&VetorPartidas->gols_time1);
    scanf("%d",&VetorPartidas->gols_time2);
    limpar();   
}

void InicializaTimes(Time *VetorTimes, int tamanho)
{
    int i;
    for (i=0;i<tamanho;i++)
        zerar_int_time(&VetorTimes[i]); 
}

void InicializaPartidas(Partida *VetorPartida, int tamanho)
{
    int i;
    for (i=0;i<tamanho;i++)
        zerar_int_partida(&VetorPartida[i]); 
}

void zerar_int_time(Time *VetorTimes)
{
    VetorTimes->continente = 0;
    VetorTimes->gols_a_favor = 0;
    VetorTimes->gols_contra = 0;
    VetorTimes->qtde_partidas = 0;
    VetorTimes->saldo_gols = 0;
}

void zerar_int_partida(Partida *VetorPartida)
{
    VetorPartida->codigo = 0;
    VetorPartida->gols_time1 = 0;
    VetorPartida->gols_time2 = 0;
}

void limpar()
{
    int leitura;
    while((leitura = getchar()) != '\n' && leitura != EOF)
		/*Discartando caractere indesejado*/;
}


Time MelhorSaldoGols(Time *VetorTimes,int tam_times)
{
    Time melhorSaldoGols = VetorTimes[0];

	for(int i=1;i<tam_times;i++)
        {
		if(VetorTimes[i].saldo_gols>melhorSaldoGols.saldo_gols)
			melhorSaldoGols=VetorTimes[i];
	}
	return(melhorSaldoGols);
}

Time PiorSaldoGols(Time *VetorTimes,int tam_times)
{
    Time piorSaldoGols = VetorTimes[0];

    for (int i = 0; i < tam_times; i++) 
    {     
       if(VetorTimes[i].saldo_gols < piorSaldoGols.saldo_gols)  
            piorSaldoGols=VetorTimes[i]; 
    }  
	return(piorSaldoGols);
}

Time MelhorDoContinente(Time *VetorTimes,int qtdt,int c)
{
    int i,conti=0;
    Time MPContinente[qtdt];
    Time res;

        for (i=0;i<qtdt;i++)
        {
            if (VetorTimes[i].continente == c)
            {
                MPContinente[conti]=VetorTimes[i];
                conti++;
            }
        }

    res =  MPContinente[0];

	for(int i=1;i<conti;i++)
        {
		if(MPContinente[i].qtde_partidas>=res.qtde_partidas)
        {
            if (MPContinente[i].qtde_partidas==res.qtde_partidas)
            {
                if(MPContinente[i].saldo_gols>=res.saldo_gols)
                {
                    if  (MPContinente[i].saldo_gols==res.saldo_gols)
                    {
                       if (MPContinente[i].gols_a_favor>res.gols_a_favor)
                            res=MPContinente[i];
                    }
                    else    
                        res=MPContinente[i];
                }
            }
            else
                res=MPContinente[i];
        }
	}
    
	return(res);
}