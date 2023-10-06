#ifndef PEDIDO_HPP
#define PEDIDO_HPP

class Pedido
{
private:
    int id;
    int numSeguimiento;
    std::string dniCliente;
    bool urgente;
    
public:
    Pedido();
    ~Pedido();

};

#endif // PEDIDO_HPP
