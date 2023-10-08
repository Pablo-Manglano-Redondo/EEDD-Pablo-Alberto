#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Pedido.hpp"
#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"

class Gestor {
public:
    Gestor();
    ~Gestor();

    void generarPedidosAleatorios();
    void mostrarPedidosEnPila();
    void borrarPedidosEnPila();
    void moverPedidosAPilas();
    void mostrarPedidosEnEstaciones();
    void borrarPedidosEnEstaciones();
    void moverPedidosAListas();
    void mostrarPedidosEnListaEstándar();
    void mostrarPedidosEnListaUrgente();
    void buscarPedidos();
    void reiniciarPrograma();
};

#endif // GESTOR_HPP
