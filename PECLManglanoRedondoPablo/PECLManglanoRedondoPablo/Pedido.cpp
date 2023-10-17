#include "Pedido.hpp"

Pedido::Pedido(int id_pedido, int dni_cliente, bool urgencia)
    : id_pedido_(id_pedido), dni_cliente_(dni_cliente), urgencia_(urgencia) {
    // Inicializamos los miembros en la lista de inicialización del constructor
}

int Pedido::id_pedido() const {
    return id_pedido_;
}

int Pedido::dni_cliente() const {
    return dni_cliente_;
}

bool Pedido::urgencia() const {
    return urgencia_;
}

std::ostream& operator<<(std::ostream& os, const Pedido& pedido) {
    os << "Pedido: " << pedido.id_pedido() << ", " << pedido.dni_cliente() << ", "
       << (pedido.urgencia() ? "urgente" : "estándar");
    return os;
}
