#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include <iostream>

class Pedido {
public:
  Pedido(int id_pedido, int num_seguimiento, int dni_cliente, bool urgencia);

  int id_pedido() const;
  int num_seguimiento() const;
  int dni_cliente() const;
  bool urgencia() const;

private:
  int id_pedido_;
  int num_seguimiento_;
  int dni_cliente_;
  bool urgencia_;
};

std::ostream& operator<<(std::ostream& os, const Pedido& pedido);

#endif