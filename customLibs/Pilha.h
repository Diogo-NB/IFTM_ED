#pragma once
#define PILHA_H
#include <stdio.h>
#include <stdlib.h>

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

