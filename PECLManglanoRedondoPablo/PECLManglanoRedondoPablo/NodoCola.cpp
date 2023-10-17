#include "NodoCola.hpp"

NodoCola::NodoCola(const Pedido& pedido) {
  pedido_ = pedido;
  siguiente_ = nullptr;
}

std::ostream& operator<<(std::ostream& os, const NodoCola& nodo_cola) {
  os << "Pedido: " << nodo_cola.pedido_;
  return os;
}
