#include <iostream>
#include "Lista_2Encad.cpp"
#ifndef LISTA_H
#define LISTA_H

using namespace std;

typedef struct Item
{
    int id = 1;
    int idParada = 0;
    string nome;
    string linha;
    string companhia;

    Lista2 paradas;
};

typedef struct Elemento *Apontador;

typedef struct Elemento
{
    Item item;
    Apontador prox;
};

typedef struct Lista
{
    Apontador primeiro;
    Apontador ultimo;
    int tamanho = 0;
};

bool listaCriada = false;

void CriaListaVazia(Lista *lista);
bool VerificaListaVazia(Lista *lista);

void InsereListaPrimeiro(Lista *lista, Item *item);
void InsereListaAposElemento(Lista *lista, Item *item, int id);
void InsereListaUltimo(Lista *lista, Item *item);
void AtualizaUltimo(Lista *lista);

void ImprimeLista(Lista lista);
Apontador PesquisaItem(Lista *lista, int id);
void ImprimeItem(Lista *lista, int id);

void RemoveListaPrimeiro(Lista *lista);
void RemoveListaUltimo(Lista *lista);
void RemoveItemPorId(Lista *lista, int id);

int TamanhoLista(Lista *lista);

#endif