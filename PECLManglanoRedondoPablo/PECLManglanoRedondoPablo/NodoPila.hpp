#ifndef NODOPILA_HPP
#define NODOPILA_HPP

class NodoPila
{
private:
    Pedido pedido;
    NodoPila* siguiente;
    friend class Pila;

public:
    NodoPila(Pedido _pedido); // Constructor
    // Métodos Getters y Setters
};

#endif // NODOPILA_HPP

