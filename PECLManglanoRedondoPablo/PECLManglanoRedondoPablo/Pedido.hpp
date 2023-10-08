#ifndef PEDIDO_HPP
#define PEDIDO_HPP

class Pedido {
public:
    int id;
    int numeroSeguimiento;
    int dniCliente;
    bool esUrgente;

    Pedido();
};

#endif // PEDIDO_HPP
