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

void Lista::mostrar() const {
    NodoLista* temp = cabeza;
    while (temp) {
        std::cout << "ID Pedido: " << temp->pedido.idPedido() << ", "
                  << "Urgencia: " << temp->pedido.urgencia() << std::endl;
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