#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Cola.hpp"
#include "Pila.hpp"

class Gestor
{
public:
    Gestor();
    ~Gestor();
    
    int PedidosEnPila() const;
    int PedidosEnSalaA() const;
    int PedidosEnSalaB() const;
    int PedidosEnSalaC() const;
    int PedidosEnSalaD() const;
    
    void generar12Pedidos() const;
    void muestraPedidos() const;
    void borrarPedidosPila() const;
    void encolarPedidos() const;
    void borrarPedidosColas() const;
    
private:

};

#endif // GESTOR_HPP