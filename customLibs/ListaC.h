#pragma once
#define LISTAC_H
#include <stdio.h>
#include <stdlib.h> 

struct no
{
    int dados;
    struct no* prox;
    struct no* ant;
};

typedef struct no No;

No* inserir(int t,No* L, int valor); //insere baseado no parametro dado.

No* InserirNo1(int valor); //insere primeiro elemento da lista   

void inserirDir(No* L,int valor); //insere na direita 

void inserirEsq(No* L,int valor); //insere na esquerda

No* inserirOrdenado(No* L,int valor); //insere o numero na sua posicao correta sem mudar a ordem crescente da lista

void ordenar(No* L); //coloca a lista em ordem crescente

void mostrar(No* L); //printf dos dados

void freeLista(No* L); //desalocar Lista

No* buscaElemento(No* L,int valor); //retorna o ponteiro de valor, caso não exista = NUL

void exclua(No* X); //remove um no da lista

void banir(No* L,int valor); //remove todos nos com dados = valor