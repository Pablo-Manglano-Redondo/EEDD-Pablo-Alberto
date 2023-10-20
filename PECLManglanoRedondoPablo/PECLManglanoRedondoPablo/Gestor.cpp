#include "Gestor.hpp"

Gestor::Gestor()
{
}

Gestor::~Gestor()
{
}

// Creamos dos colas para los pedidos estándar.
Cola estacionA;
Cola estacionB;

// Creamos dos colas para los pedidos urgentes.
Cola estacionC;
Cola estacionD;

// Colocamos un pedido estándar en la estación A.
estacionA.insertar(Pedido("Pedido estándar 1"));

// Colocamos un pedido estándar en la estación B.
estacionB.insertar(Pedido("Pedido estándar 2"));

// Colocamos un pedido urgente en la estación C.
estacionC.insertar(Pedido("Pedido urgente 1"));

// Colocamos un pedido urgente en la estación D.
estacionD.insertar(Pedido("Pedido urgente 2"));