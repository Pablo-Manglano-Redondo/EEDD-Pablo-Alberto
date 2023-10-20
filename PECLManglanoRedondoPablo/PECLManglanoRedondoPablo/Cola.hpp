#ifndef COLA_HPP
#define COLA_HPP

#include "NodoCola.hpp"

class Cola {
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

    bool estaVacia() const {
        return primero == nullptr;
    }
};

#endif // COLA_HPP
