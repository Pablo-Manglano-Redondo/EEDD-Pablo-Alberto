#include "Pila.hpp"

Pila::Pila() // Constructor por defecto
{
    ultimo = NULL;
    longitud = 0;
}

Pila::~Pila() // Destructor
{
    while (!estaVacia()) {
        extraer();
    }
}

void Pila::insertar(const Pedido& pedido) // Inserta un elemento en la pila
{
    pnodoPila nuevo = new NodoPila(pedido);
    nuevo->sig = ultimo;
    ultimo = nuevo;
    longitud++;
}


int Pila::extraer() // Extrae el elemento superior de la pila
{
    if (estaVacia()) {
        throw std::out_of_range("La pila está vacía");
    }
    int v = ultimo->v;
    pnodoPila aux = ultimo;
    ultimo = ultimo->sig;
    delete aux;
    longitud--;
    return v;
}

int Pila::cima() // Devuelve el elemento superior de la pila
{
    if (estaVacia()) {
        throw std::out_of_range("La pila está vacía");
    }
    return ultimo->v;
}

void Pila::mostrar() // Muestra la pila
{
    if (estaVacia()) {
        std::cout << "La pila está vacía" << std::endl;
        return;
    }
    pnodoPila aux = ultimo;
    while (aux != NULL) {
        std::cout << aux->v << " ";
        aux = aux->sig;
    }
    std::cout << std::endl;
}

int Pila::getLongitud() // Devuelve la longitud de la pila
{
    return longitud;
}

