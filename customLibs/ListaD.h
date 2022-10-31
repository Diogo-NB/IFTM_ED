#pragma once
#define LISTAD_H
#include <stdio.h>
#include <stdlib.h> 

struct no
{
    int dados;
    struct no* prox;
    struct no* ant;
};

typedef struct no No;

struct lista
{
    struct no* inicio;
    struct no* fim;
};

typedef struct lista Lista;

void inserir(int parametro,Lista* L,int valor); //insere baseado no parametro dado.

void InserirNo1(Lista* L,int valor); //insere primeiro elemento da lista   

void inserirNoI(Lista* L,int valor); //insere no inicio

void inserirNoF(Lista* L,int valor); //insere no final

void mostrar(Lista* L); //printf dos dados

int contaElementos(Lista* L); //retorna qtd de elementos

No* minimo(Lista* L); //retorna o menor valor

No* maximo(Lista* L); //retorna o maior valor

No* buscaElemento(Lista* L,int valor); //retorna o no que possui o valor buscado

Lista* criarList(); //inicializa uma Lista

Lista* copiarLista(Lista* L); //cria uma lista identica 

void freeLista(Lista* L); //desaloca lista

void ordenar(Lista* L); //ordena os valores da lista de forma crescente

void exclua(Lista* L,No* X); //elimina um no da lista

void banir(Lista* L,int valor); //elimina todos os nos com dados = valor

void inserirEmOrdemCresc(Lista* L,int valor); //insere o numero na sua posicao correta sem mudar a ordem crescente da lista

void inserirEntre(Lista* L, No* A, No* B, int valor); //insira um novo no entre dois outros ( A, B ), para A!=NULL && B!=NULL, 