#include <iostream>

#ifndef LISTA_H2
#define LISTA_H2

using namespace std;

struct Item2
{
    int id;
    string cidade;
    string horario;
    string horario2;
    float passagem;
};

typedef struct Elemento2 *Apontador2;

struct Elemento2
{
    Apontador2 ante;
    Item2 item;
    Apontador2 prox;
};

struct Lista2
{
    Apontador2 primeiro;
    Apontador2 ultimo;
    int tamanho;
};

void CriaListaVazia2(Lista2 *lista);
bool VerificaListaVazia2(Lista2 *lista);

void InsereListaUltimo2(Lista2 *lista, Item2 item);
void InsereListaPrimeiro2(Lista2 *lista, Item2 item);
void InsereAposElemento2(Lista2 *lista, Item2 item, int id);

Apontador2 LocalizaID2(Lista2 *lista, int id);
Item2 RetiraID2(Lista2 *lista, int id);

void ImprimeItem2(Item2 item);
void ImprimeLista2(Lista2 *lista);
void ImprimeContrario2(Lista2 *lista);

#endif