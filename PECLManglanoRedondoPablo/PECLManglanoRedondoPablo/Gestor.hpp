#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Pila.hpp"
#include "Pedido.hpp"
#include "Cola.hpp"
#include <vector>

class Gestor {
public:
  Gestor();

  void generar12Pedidos();
  void muestraPedidos();
  void borrarPedidosPila();
  void encolarPedidos();
  void muestraPedidosSalasAyB();
  void muestraPedidosSalasCyD();
  void borrarPedidosColas();
  void enlistarPedidos();
  void muestraPedidosEstandar();
  void muestraPedidosUrgentes();
  void buscarPedidos();
  void reiniciar();

private:
  Pila<Pedido> pila;
  std::vector<Cola<Pedido>> colas_;
  std::vector<Pedido> lista_estandar_;
  std::vector<Pedido> lista_urgente_;
};

#endif
