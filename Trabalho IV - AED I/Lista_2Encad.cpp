#include <iostream>
#include "Lista_2Encad.hpp"

using namespace std;

void CriaListaVazia2(Lista2 *lista)
{
    lista->primeiro = new Elemento2;
    lista->ultimo = lista->primeiro;
    lista->ultimo->prox = lista->ultimo;
    lista->ultimo->ante = lista->ultimo;
    lista->tamanho = 0;
}

bool VerificaListaVazia2(Lista2 *lista)
{
    if (lista->tamanho == 0 && lista->ultimo == lista->primeiro)
    {
        return true;
    }
    return false;
}

void InsereListaUltimo2(Lista2 *lista, Item2 item)
{
    lista->ultimo->prox = new Elemento2;
    lista->ultimo->prox->ante = lista->ultimo;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = item;
    lista->ultimo->prox = lista->primeiro;
    lista->primeiro->ante = lista->ultimo;
    lista->tamanho++;
}

void InsereListaPrimeiro2(Lista2 *lista, Item2 item)
{
    Apontador2 inserido = new Elemento2;
    inserido->item = item;

    inserido->prox = lista->primeiro->prox;
    inserido->ante = lista->primeiro;
    lista->primeiro->prox->ante = inserido;
    lista->primeiro->prox = inserido;
    lista->tamanho++;
}

void InsereAposElemento2(Lista2 *lista, Item2 item, int id)
{
    Apontador2 atual = LocalizaID2(lista, id);

    if (atual == NULL)
    {
        cout << "\nCidade inexistente.\n" << endl;
        return;
    }
    else
    {
        cout << "\nParada inserida.\n";
        return;
    }

    Apontador2 inserido = new Elemento2;
    inserido->item = item;

    if (atual == lista->ultimo)
    {
        InsereListaUltimo2(lista, item);
    }
    else
    {
        inserido->prox = atual->prox;
        inserido->ante = atual;
        inserido->prox->ante = inserido;
    }
    atual->prox = inserido;
    lista->tamanho++;
}

Apontador2 LocalizaID2(Lista2 *lista, int id)
{
    Apontador2 aux = lista->primeiro->prox;
    while (aux != lista->primeiro)
    {
        if (aux->item.id == id)
        {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

Item2 RetiraID2(Lista2 *lista, int id)
{
    Item2 retorno;
    retorno.id = -1;

    if (VerificaListaVazia2(lista))
    {
        return retorno;
    }
    Apontador2 atual = LocalizaID2(lista, id);

    if (atual != lista->primeiro)
    {
        // Atualiza o proximo do anterior.
        atual->ante->prox = atual->prox;

        // Caso o item removido seja o ultimo, atualiza o ultimo para o antecessor do removido.
        if (atual == lista->ultimo)
        {
            lista->ultimo = atual->ante;
            lista->primeiro->ante = lista->ultimo;
        }
        // Caso não, atualiza o anterior do proximo.
        else
        {
            atual->prox->ante = atual->ante;
        }

        // Guarda o item removido para retorno.
        retorno = atual->item;
        delete atual;
    }
    lista->tamanho--;
    return retorno;
}

void ImprimeItem2(Item2 item)
{
    if (item.id == -1)
    {
        cout << "Item inexistente!" << endl;
        return;
    }

    cout << "ID: " << item.id << endl;
    cout << "Cidade: " << item.cidade << endl;
    cout << "Chegada: " << item.horario << endl;
    cout << "Saída: " << item.horario2 << endl;
    cout << "Preço da passagem: " << item.passagem << endl;
    cout << endl;
}

void ImprimeLista2(Lista2 *lista)
{
    Apontador2 aux = lista->primeiro->prox;
    while (aux != lista->primeiro)
    {
        ImprimeItem2(aux->item);
        aux = aux->prox;
    }
}

void ImprimeContrario2(Lista2 *lista)
{
    Apontador2 aux = lista->ultimo;
    while (aux != lista->primeiro)
    {
        ImprimeItem2(aux->item);
        aux = aux->ante;
    }
}