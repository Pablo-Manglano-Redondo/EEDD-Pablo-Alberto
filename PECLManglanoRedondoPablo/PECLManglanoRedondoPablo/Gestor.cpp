#include "Gestor.hpp"

Gestor::Gestor()
{
}

Gestor::~Gestor()
{
}

// Creamos un pedido
Pedido pedido1(444,123789,12341,1);

// Creamos dos colas para los pedidos estándar.
Cola estacionA;
Cola estacionB;

// Creamos dos colas para los pedidos urgentes.
Cola estacionC;
Cola estacionD;

void Gestor::insertarPedidoCola() {
    estacionA.insertar(pedido1);
    std::cout << "hola";
}
