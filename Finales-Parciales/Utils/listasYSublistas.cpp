#include <iostream>

using namespace std;

struct NodoSubLista {
    int dato;
    NodoSubLista* siguiente;
};

struct NodoLista {
    int dato;
    NodoLista* siguiente;
    NodoSubLista* sublista;
};

void insertarEnSubLista(NodoSubLista*& cabezaSubLista, int dato) {
    NodoSubLista* nuevoNodo = new NodoSubLista;
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = cabezaSubLista;
    cabezaSubLista = nuevoNodo;
}

void insertarEnListaPrincipal(NodoLista*& cabezaLista, int dato) {
    NodoLista* nuevoNodo = new NodoLista;
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = cabezaLista;
    nuevoNodo->sublista = NULL; // La sublista inicial está vacía
    cabezaLista = nuevoNodo;
}

void imprimirSubLista(NodoSubLista* cabezaSubLista) {
    NodoSubLista* temp = cabezaSubLista;
    while (temp != NULL) {
        cout << temp->dato << " -> ";
        temp = temp->siguiente;
    }
    cout << "NULL";
}

void imprimirListaConSublistas(NodoLista* cabezaLista) {
    NodoLista* tempLista = cabezaLista;
    while (tempLista != NULL) {
        cout << tempLista->dato << ": ";
        imprimirSubLista(tempLista->sublista);
        cout << endl;
        tempLista = tempLista->siguiente;
    }
}