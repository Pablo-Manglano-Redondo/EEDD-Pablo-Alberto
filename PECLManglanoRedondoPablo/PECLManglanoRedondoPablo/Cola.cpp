#include "Cola.hpp"

Cola::~Cola() // Destructor
{
    while (!estaVacia()) {
        extraer();
    }
}

void Cola::insertar(const Pedido& elemento) // Inserta un elemento en la cola
{
    NodoCola* nuevo = new NodoCola(elemento);
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
    NodoCola* aux = primero;
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
    NodoCola* aux = primero;
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

void Cola::vaciarCola() {
    while (!estaVacia()) {
        NodoCola* siguiente = primero->sig;  // Guarda el siguiente nodo antes de eliminar el actual
        delete primero;  // Libera la memoria del nodo actual
        primero = siguiente;  // Establece el siguiente nodo como el nuevo primero
        if (primero == nullptr) {
            ultimo = nullptr;  // Si hemos eliminado el último nodo, también actualizamos el puntero 'ultimo'
        }
        longitud--;
    }
}
