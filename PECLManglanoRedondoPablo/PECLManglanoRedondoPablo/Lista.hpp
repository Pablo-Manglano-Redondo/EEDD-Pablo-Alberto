#ifndef LISTA_HPP
#define LISTA_HPP

#include "NodoLista.hpp"

class Lista {
public:
    Lista();
    ~Lista();
    void insertar(const Pedido& nuevoPedido);
    void mostrar() const;
    int getLongitud() const;
    bool estaVacia() const;
    NodoLista* getCabeza() const;
    NodoLista* cabeza;
    void ordenarPorID();
};

#endif // LISTA_HPP
