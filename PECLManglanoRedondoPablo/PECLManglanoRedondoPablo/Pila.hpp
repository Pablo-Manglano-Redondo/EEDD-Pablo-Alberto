#ifndef PILA_HPP
#define PILA_HPP

#include "NodoPila.hpp"
#include "Pedido.hpp"
#include <iostream>
#include <stdexcept>
#include <iterator>

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
    bool estaVacia();  

private:
    NodoPila* ultimo;
    int longitud;
};

#endif // PILA_HPP
