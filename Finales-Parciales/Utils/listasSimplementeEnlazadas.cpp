#include <iostream>

using namespace std;

struct NodoLista
{
    int dato;
    NodoLista *siguiente;
};

void insertarEnLista(NodoLista *&punteroLista, int dato)
{
    NodoLista *nuevo, *antecesor, *aux;
    nuevo = new NodoLista;
    nuevo->dato = dato;
    aux = punteroLista;

    while (aux != NULL && aux->dato < dato)
    {
        antecesor = aux;
        aux = aux->siguiente;
    }

    nuevo->siguiente = aux;

    if (aux != punteroLista)
    {
        antecesor->siguiente = nuevo;
    }
    else
    {
        punteroLista = nuevo;
    }
}

void mostrarListado(NodoLista *punteroLista)
{
    NodoLista *aux = punteroLista;

    while (aux != NULL)
    {
        cout << aux->dato << endl;
        aux = aux->siguiente;
    }
}

NodoLista *buscar(NodoLista *lista, int dato)
{
    NodoLista *aux = lista;
    
    while (aux != NULL && aux->dato != dato)
    {
        aux = aux->siguiente;
    }

    return aux;
}

NodoLista *buscarMejor(NodoLista *lista, int dato)
{
    NodoLista *aux = lista;

    while (aux != NULL && aux->dato < dato)
    {
        aux = aux->siguiente;
    }

    return aux;
}

NodoLista* buscarInsertar(NodoLista *&lista,int dato)
{
    NodoLista *aux = lista, *antecesor;

    while (aux != NULL && aux->dato < dato)
    {
        antecesor = aux;
        aux = aux->siguiente;
    }

    if (aux != NULL && aux->dato == dato)
    {
        return aux;
    }
    else
    {
        NodoLista *nuevo = new NodoLista;
        nuevo->dato = dato;
        nuevo->siguiente = aux;

        if (aux != lista)
        {
            antecesor->siguiente = nuevo;
        }
        else
        {
            lista = nuevo;
        }

        return nuevo;
    }
}