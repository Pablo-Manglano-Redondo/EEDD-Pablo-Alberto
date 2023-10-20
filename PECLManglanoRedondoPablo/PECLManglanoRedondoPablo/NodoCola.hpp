#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP

#include "Pedido.hpp"

class NodoCola {
public:
    NodoCola(const Pedido& elemento);
    ~NodoCola();

    Pedido v;
    NodoCola* sig;
};

#endif // NODOCOLA_HPP