#ifndef COLA_HPP
#define COLA_HPP

#include <iostream>

template <typename T>
class Cola {
public:
  Cola();

  bool vacia() const;
  void push(const T& pedido);
  T pop();

private:
  struct Nodo {
    T pedido_;
    Nodo* siguiente_;
  };

  Nodo* primero_;
  Nodo* ultimo_;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Cola<T>& cola) {
    typename Cola<T>::Nodo* temp = cola.primero_;
    while (temp) {
        os << temp->pedido_ << " ";
        temp = temp->siguiente_;
    }
    return os;
}

template <typename T>
Cola<T>::Cola() : primero_(nullptr), ultimo_(nullptr) {}

template <typename T>
bool Cola<T>::vacia() const {
    return primero_ == nullptr;
}

template <typename T>
void Cola<T>::push(const T& pedido) {
    Nodo* nuevoNodo = new Nodo{pedido, nullptr};
    if (vacia()) {
        primero_ = nuevoNodo;
        ultimo_ = nuevoNodo;
    } else {
        ultimo_->siguiente_ = nuevoNodo;
        ultimo_ = nuevoNodo;
    }
}

template <typename T>
T Cola<T>::pop() {
    if (vacia()) {
        throw std::runtime_error("La cola está vacía");
    }
    T pedido = primero_->pedido_;
    Nodo* temp = primero_;
    primero_ = primero_->siguiente_;
    if (!primero_) {
        ultimo_ = nullptr;
    }
    delete temp;
    return pedido;
}

#endif
