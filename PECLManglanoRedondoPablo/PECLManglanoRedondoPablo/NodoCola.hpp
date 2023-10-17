#ifndef NODO_COLA_HPP
#define NODO_COLA_HPP

#include <iostream>

class NodoCola {
public:
  NodoCola(const Pedido& pedido);

  Pedido pedido_;
  NodoCola* siguiente_;
};

std::ostream& operator<<(std::ostream& os, const NodoCola& nodo_cola);

#endif
