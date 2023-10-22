#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include <iostream>

class Pedido
{
public:
    Pedido(int idPedido, int numSeguimiento, std::string dniCliente, bool urgencia);
    Pedido(int idPedido, int numSeguimiento, std::string dniCliente, bool urgencia, int prioridad);

    int idPedido() const;
    int numSeguimiento() const;
    std::string dniCliente() const;
    bool urgencia() const;
    int prioridad() const;
    int getPrioridad() const { return prioridad_; }

private:
    int idPedido_;
    int numSeguimiento_;
    std::string dniCliente_;
    bool urgencia_;
    int prioridad_;
};

std::ostream& operator<<(std::ostream& os, const Pedido& pedido);

#endif