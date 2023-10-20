#include "Cola.hpp"

Cola::~Cola() // Destructor
{
    while (!estaVacia()) {
        extraer();
    }
}

void Cola::insertar(const Pedido& elemento) // Inserta un elemento en la cola
{
    pnodoCola nuevo = new NodoCola(elemento);
    if (estaVacia()) {
        primero = nuevo;
        ultimo = nuevo;
    } else {
        ultimo->sig = nuevo;
        ultimo = nuevo;
    }
    longitud++;
}

Pedido Cola::extraer() // Extrae el elemento superior de la cola
{
    if (estaVacia()) {
        throw std::out_of_range("La cola está vacía");
    }
    Pedido v = primero->v;
    pnodoCola aux = primero;
    primero = primero->sig;
    delete aux;
    longitud--;
    return v;
}

Pedido Cola::cima() // Devuelve el elemento superior de la cola sin extraerlo
{
    if (estaVacia()) {
        throw std::out_of_range("La cola está vacía");
    }
    return primero->v;
}


void Cola::mostrar() // Muestra la cola
{
    if (estaVacia()) {
        std::cout << "La cola está vacía" << std::endl;
        return;
    }
    pnodoCola aux = primero;
    while (aux != nullptr) {
        std::cout << aux->v << " ";
        aux = aux->sig;
    }
    std::cout << std::endl;
}

int Cola::getLongitud() // Devuelve la longitud de la cola
{
    return longitud;
}