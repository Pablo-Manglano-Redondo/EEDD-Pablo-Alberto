#ifndef COLA_HPP
#define COLA_HPP

#include "NodoCola.hpp"

class Cola
{
public:
    ~Cola();
    void insertar(const Pedido& elemento);
    Pedido extraer();
    Pedido cima();
    void mostrar();
    int getLongitud();
    void vaciarCola();
    bool estaVacia() const { return primero == nullptr; }

private:
    NodoCola* primero;
    NodoCola* ultimo;
    int longitud;
};

#endif // COLA_HPP
