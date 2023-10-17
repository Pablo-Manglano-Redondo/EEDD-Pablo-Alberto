#include "Lista.hpp"

template <typename T>
Lista<T>::Lista() {
  primero_ = nullptr;
  ultimo_ = nullptr;
}

template <typename T>
bool Lista<T>::vacia() const {
  return primero_ == nullptr;
}

template <typename T>
void Lista<T>::push_back(const T& elemento) {
  Nodo* nuevo_nodo = new Nodo();
  nuevo_nodo->elemento_ = elemento;
  nuevo_nodo->siguiente_ = nullptr;

  if (vacia()) {
    primero_ = nuevo_nodo;
    ultimo_ = nuevo_nodo;
  } else {
    ultimo_->siguiente_ = nuevo_nodo;
    ultimo_ = nuevo_nodo;
  }
}

template <typename T>
T Lista<T>::pop_front() {
  if (vacia()) {
    throw std::out_of_range("La lista está vacía");
  }

  Nodo* nodo_a_eliminar = primero_;
  T elemento_eliminado = nodo_a_eliminar->elemento_;

  primero_ = primero_->siguiente_;

  if (primero_ == nullptr) {
    ultimo_ = nullptr;
  }

  delete nodo_a_eliminar;

  return elemento_eliminado;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Lista<T>& lista) {
  if (lista.vacia()) {
    os << "La lista está vacía";
  } else {
    os << "La lista contiene:";
    for (Nodo* nodo = lista.primero_; nodo != nullptr; nodo = nodo->siguiente_) {
      os << " " << nodo->elemento_;
    }
  }

  return os;
}
