#ifndef COLA_HPP
#define COLA_HPP

#include "Pedido.hpp"
#include "NodoCola.hpp"
#include <iterator>

class Cola
{
public:
    ~Cola();
    void insertar(const Pedido& elemento);
    Pedido extraer();
    Pedido cima();
    void mostrar();
    int getLongitud();

private:
    NodoCola* primero;
    NodoCola* ultimo;
    int longitud;
};

#endif // COLA_HPP