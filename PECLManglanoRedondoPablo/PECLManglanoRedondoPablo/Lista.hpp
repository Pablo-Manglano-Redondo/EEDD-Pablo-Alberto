#ifndef LISTA_HPP
#define LISTA_HPP

#include <iostream>

template <typename T>
class Lista {
public:
  Lista();

  bool vacia() const;
  void push_back(const T& elemento);
  T pop_front();

private:
  struct Nodo {
    T elemento_;
    Nodo* siguiente_;
  };

  Nodo* primero_;
  Nodo* ultimo_;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Lista<T>& lista);

#endif
