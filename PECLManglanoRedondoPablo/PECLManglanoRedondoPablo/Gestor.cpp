#include "Gestor.hpp"

Pila pila_;

Gestor::Gestor() {
  pila_ = Pila<Pedido>();
  colas_ = std::vector<Cola<Pedido>>(4);
  lista_estandar_ = std::vector<Pedido>();
  lista_urgente_ = std::vector<Pedido>();
}

void Gestor::generar12Pedidos() {
  for (int i = 0; i < 12; i++) {
    int id_pedido = rand() % 1000;
    int dni_cliente = rand() % 99999999;
    bool urgencia = rand() % 2 == 0;

    Pedido pedido(id_pedido, dni_cliente, urgencia); // Pasar por valor, no por referencia

    pila_.insertar(pedido);
  }
}

void Gestor::muestraPedidos() {
  std::cout << "Pedidos en la pila:" << std::endl;
  for (const auto& pedido : pila_) {
    std::cout << pedido << std::endl;
  }
}

void Gestor::borrarPedidosPila() {
  pila_ = Pila<Pedido>();
  lista_estandar_.clear();
  lista_urgente_.clear();
}
