#include "NodoPila.hpp"

NodoPila::NodoPila(const Pedido& pedido) {
  pedido_ = pedido;
  siguiente_ = nullptr;
}

std::ostream& operator<<(std::ostream& os, const NodoPila& nodo_pila) {
  os << "Pedido: " << nodo_pila.pedido_;
  return os;
}
