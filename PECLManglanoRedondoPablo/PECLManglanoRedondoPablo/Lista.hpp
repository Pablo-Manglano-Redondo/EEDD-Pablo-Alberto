#ifndef LISTA_HPP
#define LISTA_HPP

#include "NodoLista.hpp"

class Lista {
private:
    NodoLista* cabeza;
public:
    Lista();
    ~Lista();
    void insertar(const Pedido& nuevoPedido);
    void mostrar() const;
    int getLongitud() const;
};

#endif // LISTA_HPP
