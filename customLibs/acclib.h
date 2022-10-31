#pragma once
#define ACCLIB_H
#include <stdio.h>
#include <stdlib.h> 

struct client
{
char nome[50];
int cep;
int cpf;
};

typedef struct client Client;

struct account
{
int num;
Client cliente;
float saldo;
};

typedef struct account ACC;

void showACC(ACC acctemp);

ACC insertACC();

void transferACC(ACC *acx, ACC *acy,float tval);










