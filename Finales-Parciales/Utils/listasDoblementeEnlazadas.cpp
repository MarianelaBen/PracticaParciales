#include <iostream>

using namespace std;

struct NodoLista{
    int dato;
    NodoLista* anterior;
    NodoLista* siguiente;
};

void insertar(NodoLista*&lis1,NodoLista*&lis2, int nro)
{
    NodoLista*p,*r;
    p = new NodoLista; //p va ser el que agregemos, r ya esta
    p->dato = nro;
    if(lis1 == NULL && lis2 == NULL) //p no va a tener ni sucesor ni antecesor (agrega a lista vac�a)
    {
        p->siguiente = p->anterior = NULL;
        lis1 = lis2 = p;
    }
    else
    {
        r = lis1;
        while(r != NULL && r->dato < nro)
            r = r->siguiente;
       if(r == lis1) //p va a tener sucesor y no antecesor //primero de la lista
        {
            p->anterior  =  NULL;
            p->siguiente  =  r;
            r->anterior  =  p;
            lis1  =  p;
        }
        else
        {
            if(r == NULL) //p va a tener antecesor y no sucesor //acl: p se mete antes de r
            {
                p->anterior = lis2;
                p->siguiente = r;
                lis2->siguiente = p; //se usa lis2 porque es nuestro ultimo nodo, en vez de usar r que seria lo mismo
                lis2 = p;
            }
            else
            {   //p va a tener sucesor y antecesor
                p->anterior = r->anterior;
                p->siguiente = r;
                /*
                Nodo*anterior=r->ant;
                anterior->siguiente=p;
                */
                r->anterior ->siguiente = p;
                r->anterior = p;
            }
        }
    }
}

void eliminar(NodoLista*& lis1, NodoLista*& lis2, int nro) { //esta funcion busca un dato y lo elimina
    NodoLista* p = lis1;
    while (p != NULL && p->dato != nro) {
        p = p->siguiente;
    }
    if (p != NULL) {
        if (p == lis1) {
            lis1 = p->siguiente;
            if (lis1 != NULL) {
                lis1->anterior = NULL;
            }
        } else {
            p->anterior->siguiente = p->siguiente;
            if (p->siguiente != NULL) {
                p->siguiente->anterior = p->anterior;
            } else {
                lis2 = p->anterior;
            }
        }
        delete p;
    }
}

void mostrarAsc(NodoLista*lista)
{    NodoLista*p=lista;
    while(p!=NULL)
    {
        cout<<p->dato<<endl;
        p=p->siguiente;
    }}

void mostrarDesc(NodoLista*lista)
{NodoLista*p=lista;
    while(p!=NULL)
    {
        cout<<p->dato<<endl;
        p=p->anterior;
    }}
