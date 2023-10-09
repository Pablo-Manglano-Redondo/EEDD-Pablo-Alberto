#include "Cola.hpp"

Cola::Cola()
{
}

Cola::~Cola()
{
}

// Comprueba si la cola está vacía
    bool estaVacia() const {
        return frente == nullptr;
    }

    // Encola un pedido al final de la cola
    void encolar(Pedido pedido) {
        NodoCola* nuevoNodo = new NodoCola(pedido);
        if (frente == nullptr) {
            frente = nuevoNodo;
            atras = nuevoNodo;
        } else {
            atras->siguiente = nuevoNodo;
            atras = nuevoNodo;
        }
    }

    // Desencola un pedido del principio de la cola
    void desencolar(Pedido& pedido) {
        if (!estaVacia()) {
            pedido = frente->pedido;
            NodoCola* temp = frente;
            frente = frente->siguiente;
            delete temp;
        }
    }

