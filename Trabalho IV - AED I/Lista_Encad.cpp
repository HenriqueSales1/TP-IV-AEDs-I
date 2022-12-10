#include <iostream>
#include <windows.h>
#include "Lista_Encad.hpp"

#define MAXTAM 5

using namespace std;

void CriaListaVazia(Lista *lista)
{
    if (!listaCriada)
    {
        lista->primeiro = new Elemento;
        lista->ultimo = lista->primeiro;
        lista->ultimo->prox = NULL;
        listaCriada = true;
    }
    Sleep(1500);
}

bool VerificaListaVazia(Lista *lista)
{
    return (lista->primeiro == lista->ultimo);
}

int TamanhoLista(Lista *lista)
{
    return lista->tamanho;
}

void InsereListaPrimeiro(Lista *lista, Item *item)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = new Elemento;
    lista->primeiro->prox->prox = aux;
    lista->primeiro->prox->item = *item;
    lista->tamanho++;
    AtualizaUltimo(lista);
}

void AtualizaUltimo(Lista *lista)
{
    Apontador aux;
    aux = lista->primeiro;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    lista->ultimo = aux;
}

void InsereListaUltimo(Lista *lista, Item *item)
{
    lista->ultimo->prox = new Elemento;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = *item;
    lista->ultimo->prox = NULL;
    lista->tamanho++;
}

void InsereListaAposElemento(Lista *lista, Item *item, int id)
{
    Apontador aux, pAux, x;
    bool find = false;
    pAux = lista->primeiro->prox;
    while (pAux != NULL)
    {
        if (pAux->item.id == id)
        {
            find = true;
            x = pAux;
            aux = x->prox;
            x->prox = new Elemento;
            x->prox->prox = aux;
            x->prox->item = *item;
            break;
        }
        pAux = pAux->prox; /* próxima célula */
    }
    if (find)
    {
        cout << "Item inserido com sucesso!";
        AtualizaUltimo(lista);
        lista->tamanho++;
    }
    else
    {
        cout << "Elemento anterior não encontrado na lista.";
    }
}

void ImprimeLista(Lista lista)
{
    if (VerificaListaVazia(&lista))
    {
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    Apontador aux;
    aux = lista.primeiro->prox;
    while (aux != NULL)
    {
        cout << "ID: " << aux->item.id << endl;
        cout << "Nome: " << aux->item.nome << endl
             << endl;
        aux = aux->prox;
    }
    system("pause");
}

Apontador PesquisaItem(Lista *lista, int id)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (aux->item.id == id)
        {
            return aux;
        }
        aux = aux->prox;
    }
    return aux;
}

void ImprimeItem(Lista *lista, int id)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (aux->item.id == id)
        {
            cout << "ID: " << aux->item.id << endl;
            cout << "Nome: " << aux->item.nome << endl
                 << endl;
            break;
        }
        aux = aux->prox;
    }
}

void ImprimeItemRecebido(Item item)
{
    cout << "ID: " << item.id << endl;
    cout << "Companhia: " << item.companhia << endl;
}

void RemoveListaPrimeiro(Lista *lista)
{
    if (VerificaListaVazia(lista))
    {
        return;
    }
    Apontador aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = aux->prox;
    delete aux;
    lista->tamanho--;
}

void RemoveListaUltimo(Lista *lista)
{
    if (VerificaListaVazia(lista))
    {
        return;
    }
    Apontador aux, atual;
    atual = lista->primeiro->prox;
    aux = lista->ultimo;
    while (atual->prox != lista->ultimo)
    {
        atual = atual->prox;
    }
    atual->prox = NULL;
    lista->ultimo = atual;
    delete aux;
    lista->tamanho--;
}

void RemoveItemPorId(Lista *lista, int id)
{
    if (VerificaListaVazia(lista))
    {
        return;
    }

    Apontador aux, anterior, x;

    x = lista->primeiro;

    while (x != NULL)
    {
        if (x->prox->item.id == id)
        {
            anterior = x;
            break;
        }
        x = x->prox;
    }
    aux = anterior->prox;
    anterior->prox = aux->prox;
    delete aux;
    lista->tamanho--;
    AtualizaUltimo(lista);
}