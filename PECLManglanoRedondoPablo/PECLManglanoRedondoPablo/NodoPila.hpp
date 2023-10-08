#ifndef NODOPILA_HPP
#define NODOPILA_HPP

#include "Pedido.hpp"

class NodoPila {
public:
    Pedido pedido;
    NodoPila* siguiente;

    NodoPila(const Pedido& p) : pedido(p), siguiente(nullptr) {}
};

#endif // NODOPILA_HPP
