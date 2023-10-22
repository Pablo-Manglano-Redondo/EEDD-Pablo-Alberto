#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Cola.hpp"
#include "Pila.hpp"
#include "Lista.hpp"

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
    int PedidosEnListaEstandar() const;
    int PedidosEnListaUrgentes() const;
    
    void generar12Pedidos() const;
    void muestraPedidos() const;
    void borrarPedidosPila() const;
    void encolarPedidos() const;
    void borrarPedidosColas() const;
    void muestraPedidosSalasAyB() const;
    void muestraPedidosSalasCyD() const;
    void enlistarPedidos() const;
    void muestraPedidosEstandar() const;
    void muestraPedidosUrgentes() const;
    void buscarPedidos() const;
    void reiniciar();
    
private:

};

#endif // GESTOR_HPP