#ifndef NODOPILA_HPP
#define NODOPILA_HPP

#include "Pedido.hpp"

class NodoPila {
public:
    Pedido pedido;  // Objeto de tipo Pedido en el nodo
    NodoPila* sig;  // Puntero al siguiente nodo en la pila

    NodoPila(const Pedido& p); // Constructor que recibe un pedido
};

#endif // NODOPILA_HPP
