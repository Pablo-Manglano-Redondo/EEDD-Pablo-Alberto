#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP

#include "Pedido.hpp"

class NodoLista {
public:
    NodoLista();
    Pedido pedido;
    NodoLista* siguiente;

    NodoLista(const Pedido& nuevoPedido) : pedido(nuevoPedido), siguiente(nullptr) {}
};

#endif // NODOLISTA_HPP

