#include "Pila.hpp"

// Constructor de la Pila (si es necesario)
Pila::Pila() {
    cima = nullptr;
}

// Destructor de la Pila (si es necesario)
Pila::~Pila() {
    while (!estaVacia()) {
        Pedido temp;
        pop(temp);
    }
}

// Método para agregar un pedido a la pila
void Pila::push(const Pedido& p) {
    NodoPila* nuevoNodo = new NodoPila(p);
    nuevoNodo->siguiente = cima;
    cima = nuevoNodo;
}

// Método para quitar un pedido de la pila
bool Pila::pop(Pedido& p) {
    if (estaVacia()) {
        return false; // La pila está vacía
    }
    NodoPila* temp = cima;
    p = temp->pedido;
    cima = temp->siguiente;
    delete temp;
    return true;
}

// Método para verificar si la pila está vacía
bool Pila::estaVacia() {
    return cima == nullptr;
}
