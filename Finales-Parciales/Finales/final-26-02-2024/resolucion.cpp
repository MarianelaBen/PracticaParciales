#include <iostream>

using namespace std;

// Punto 1
struct NodoPila{
    int dato;
    NodoPila* siguiente;
};

struct NodoLista{
    int dato;
    NodoLista* siguiente;
};

// Función para crear un nodo de lista
NodoLista* crearNodoLista(int dato) {
    NodoLista* nuevoNodo = (NodoLista*)malloc(sizeof(NodoLista));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para insertar un elemento al final de la lista
void insertarEnLista(NodoLista** cabeza, int dato) {
    NodoLista* nuevoNodo = crearNodoLista(dato);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        return;
    }
    NodoLista* temp = *cabeza;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }
    temp->siguiente = nuevoNodo;
}

NodoLista* retornarDeInterseccion(NodoLista* lista, NodoPila* pila){
    NodoLista* auxiliar = NULL;
    NodoLista* inicioLista = lista;

    while(pila != NULL){
        lista = inicioLista;
        while(lista != NULL){
            if(lista->dato == pila->dato){
                insertarEnLista(&auxiliar, pila->dato);
            }
            lista = lista->siguiente;
        }
        pila = pila->siguiente;
    }

    return auxiliar;
}

// Punto 2

struct Cuenta{
    int numeroCuenta;
    int cantidadTransacciones;
    int saldo;
};

struct NodoTransaccion{
    int numeroCuenta;
    int monto;
    NodoTransaccion* siguiente;
};

const int cantidadCuentas = 150;

Cuenta cuentas[cantidadCuentas];
NodoTransaccion* transacciones;

void actualizarCuentas(Cuenta cuentas[], NodoTransaccion* transacciones){

    while(transacciones != NULL){
        for(int i = 0 ; i<cantidadCuentas ; i++){
            if(cuentas[i].numeroCuenta == transacciones->numeroCuenta){
                cuentas[i].saldo -= transacciones->monto;
                cuentas[i].cantidadTransacciones ++;
            }
        }
        transacciones = transacciones->siguiente;
    }
}