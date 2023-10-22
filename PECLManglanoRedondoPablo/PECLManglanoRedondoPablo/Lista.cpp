#include "Lista.hpp"

Lista::Lista() : cabeza(nullptr) {}

Lista::~Lista() {
    while (cabeza) {
        NodoLista* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

void Lista::insertar(const Pedido& nuevoPedido) {
    NodoLista* nuevoNodo = new NodoLista(nuevoPedido);
    if (!cabeza || nuevoPedido.urgencia() > cabeza->pedido.urgencia()) {
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    } else {
        NodoLista* temp = cabeza;
        while (temp->siguiente && nuevoPedido.urgencia() <= temp->siguiente->pedido.urgencia()) {
            temp = temp->siguiente;
        }
        nuevoNodo->siguiente = temp->siguiente;
        temp->siguiente = nuevoNodo;
    }
}

void Lista::ordenarPorID() {
    if (cabeza == nullptr || cabeza->siguiente == nullptr) {
        // La lista está vacía o tiene un solo elemento, ya está ordenada
        return;
    }

    NodoLista* sorted = nullptr;
    NodoLista* current = cabeza;

    while (current != nullptr) {
        NodoLista* next = current->siguiente;

        // Inserta el nodo actual en la lista ordenada
        if (sorted == nullptr || current->pedido.idPedido() < sorted->pedido.idPedido()) {
            current->siguiente = sorted;
            sorted = current;
        } else {
            NodoLista* temp = sorted;
            while (temp->siguiente != nullptr && current->pedido.idPedido() > temp->siguiente->pedido.idPedido()) {
                temp = temp->siguiente;
            }
            current->siguiente = temp->siguiente;
            temp->siguiente = current;
        }

        current = next;
    }

    // La cabeza ahora apunta al primer nodo ordenado
    cabeza = sorted;
}

void Lista::mostrar() const {
    NodoLista* temp = cabeza;
    while (temp) {
        std::cout << "ID Pedido: " << temp->pedido.idPedido() << ", "
                  << "Prioridad: " << temp->pedido.prioridad() << ", "
                  << "Numero de seguimiento: " << temp->pedido.numSeguimiento() << std::endl;
        temp = temp->siguiente;
    }
    std::cout << std::endl;
}

int Lista::getLongitud() const {
    int longitud = 0;
    NodoLista* temp = cabeza;
    while (temp) {
        ++longitud;
        temp = temp->siguiente;
    }
    return longitud;
}

bool Lista::estaVacia() const {
    return cabeza == nullptr;
}

NodoLista* Lista::getCabeza() const {
    return cabeza;
}