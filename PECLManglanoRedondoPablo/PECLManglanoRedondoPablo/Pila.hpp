#ifndef PILA_HPP
#define PILA_HPP

#include "NodoPila.hpp"
#include <iterator>

template <typename T>
class Pila
{
public:
    Pila(); // Constructor por defecto
    ~Pila();
    void insertar(const Pedido& pedido);
    int extraer();
    int cima();
    void mostrar();
    int getLongitud();

private:
    pnodoPila ultimo;
    int longitud;
};

#endif // PILA_HPP
