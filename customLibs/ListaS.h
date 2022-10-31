#pragma once
#define LISTAS_H
#include <stdio.h>
#include <stdlib.h> 

struct lista
{
    int dados;
    struct lista* proximo;
};

typedef struct lista Lista; 

Lista* criarZero();

Lista* criarLista(Lista* endRef,int i);

Lista* busca_valor(Lista* endRef,int valor);

void mostrar(Lista* endRef);

void freeLista(Lista* endRef);

void inserir(Lista* endRef,int x,int valor);

