#ifndef COLA_HPP
#define COLA_HPP

#include <iostream>

class Cola {
public:
  Cola();

  bool vacia() const;
  void push(const Pedido& pedido);
  Pedido pop();

private:
  struct Nodo {
    Pedido pedido_;
    Nodo* siguiente_;
  };

  Nodo* primero_;
  Nodo* ultimo_;
};

std::ostream& operator<<(std::ostream& os, const Cola& cola);

#endif
