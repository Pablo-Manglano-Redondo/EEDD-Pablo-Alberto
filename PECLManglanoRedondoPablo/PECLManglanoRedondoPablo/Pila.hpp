// Pila.hpp
#ifndef PILA_HPP
#define PILA_HPP

#include "NodoPila.hpp"

class Pila {
private:
    NodoPila* cima;

public:
    Pila();
    ~Pila();
    void push(int id, int numeroSeguimiento, int DNI, bool urgente);
    bool pop(int &id, int &numeroSeguimiento, int &DNI, bool &urgente);
    bool estaVacia() const;
};

#endif // PILA_HPP
