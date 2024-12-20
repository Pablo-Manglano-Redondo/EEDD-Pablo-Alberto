#include "Pedido.hpp"

Pedido::Pedido(int idPedido, int numSeguimiento, std::string dniCliente, bool urgencia)
    : idPedido_(idPedido), numSeguimiento_(numSeguimiento), dniCliente_(dniCliente), urgencia_(urgencia) {
    // Inicializamos los miembros en la lista de inicialización del constructor
}

Pedido::Pedido(int idPedido, int numSeguimiento, std::string dniCliente, bool urgencia, int prioridad)
        : idPedido_(idPedido), numSeguimiento_(numSeguimiento), dniCliente_(dniCliente), urgencia_(urgencia), prioridad_(prioridad) {
}


int Pedido::idPedido() const {
    return idPedido_;
}

int Pedido::numSeguimiento() const {
    return numSeguimiento_;
}

std::string Pedido::dniCliente() const {
    return dniCliente_;
}

bool Pedido::urgencia() const {
    return urgencia_;
}

int Pedido::prioridad() const {
    return prioridad_;
}

std::ostream& operator<<(std::ostream& os, const Pedido& pedido) {
    os << "Pedido: " << pedido.idPedido() << ", " << pedido.numSeguimiento() << ", " << pedido.dniCliente() << ", "
       << (pedido.urgencia() ? "urgente" : "estándar");
    return os;
}
