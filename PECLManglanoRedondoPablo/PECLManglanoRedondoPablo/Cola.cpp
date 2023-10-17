#include "Cola.hpp"

Cola::Cola() {
  primero_ = nullptr;
  ultimo_ = nullptr;
}

bool Cola::vacia() const {
  return primero_ == nullptr;
}

void Cola::push(const Pedido& pedido) {
  Nodo* nuevo_nodo = new Nodo();
  nuevo_nodo->pedido_ = pedido;
  nuevo_nodo->siguiente_ = nullptr;

  if (vacia()) {
    primero_ = nuevo_nodo;
    ultimo_ = nuevo_nodo;
  } else {
    ultimo_->siguiente_ = nuevo_nodo;
    ultimo_ = nuevo_nodo;
  }
}

Pedido Cola::pop() {
  if (vacia()) {
    throw std::out_of_range("La cola está vacía");
  }

  Nodo* nodo_a_eliminar = primero_;
  Pedido pedido_eliminado = nodo_a_eliminar->pedido_;

  primero_ = primero_->siguiente_;

  if (primero_ == nullptr) {
    ultimo_ = nullptr;
  }

  delete nodo_a_eliminar;

  return pedido_eliminado;
}

std::ostream& operator<<(std::ostream& os, const Cola& cola) {
  if (cola.vacia()) {
    os << "La cola está vacía";
  } else {
    os << "La cola contiene:";
    for (Nodo* nodo = cola.primero_; nodo != nullptr; nodo = nodo->siguiente_) {
      os << " " << nodo->pedido_;
    }
  }

  return os;
}
