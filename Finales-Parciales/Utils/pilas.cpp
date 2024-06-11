struct NodoPila{
    int info;
    NodoPila* siguiente;
};

void apilar(NodoPila *&pila, int dato)
{
    NodoPila *nuevo = new NodoPila;
    nuevo->info = dato;
    nuevo->siguiente = pila;
    pila = nuevo;
}

void desapilar(NodoPila *&pila, int &dato)
{
    NodoPila *aux = pila;
    dato = aux->info;
    pila = aux->siguiente;
    
    delete aux;
}