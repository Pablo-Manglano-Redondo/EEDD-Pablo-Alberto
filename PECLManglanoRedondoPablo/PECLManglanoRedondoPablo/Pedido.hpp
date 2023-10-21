#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include <iostream>

class Pedido {
public:
  Pedido(int idPedido, int numSeguimiento, std::string dniCliente, bool urgencia);

  int idPedido() const;
  int numSeguimiento() const;
  std::string dniCliente() const;
  bool urgencia() const;

private:
  int idPedido_;
  int numSeguimiento_;
  std::string dniCliente_;
  bool urgencia_;
};

std::ostream& operator<<(std::ostream& os, const Pedido& pedido);

#endif