#ifndef NODO_PILA_HPP
#define NODO_PILA_HPP

#include <iostream>
#include "Pedido.hpp"

class NodoPila
{
public:
    NodoPila(Pedido* pedido);
    Pedido* getPedido();
    void setPedido(Pedido* pedido);
    NodoPila* getSiguiente();
    void setSiguiente(NodoPila* siguiente);

private:
    Pedido* pedido_;
    NodoPila* siguiente_;
};

typedef NodoPila* pnodoPila;

#endif // NODO_PILA_HPP
