
#include "Gestor.hpp"

Gestor::Gestor()
{
}

Gestor::~Gestor()
{
}


// Creamos la pila
Pila* pilaPedidos = new Pila();

// Creamos dos colas para los pedidos estándar.
Cola estacionA;
Cola estacionB;

// Creamos dos colas para los pedidos urgentes.
Cola estacionC;
Cola estacionD;


// ------------------------------------------------

// Metodos para visualizar resultados

int Gestor::PedidosEnPila() const {
    return pilaPedidos->getLongitud();
}

int Gestor::PedidosEnSalaA() const {
    return estacionA.getLongitud();
}

int Gestor::PedidosEnSalaB() const {
    return estacionB.getLongitud();
}

int Gestor::PedidosEnSalaC() const {
    return estacionC.getLongitud();
}

int Gestor::PedidosEnSalaD() const {
    return estacionD.getLongitud();
}

/*int Gestor::PedidosEnListaEstandar() const {
    return listaEstandar.size();
}

int Gestor::PedidosEnListaUrgentes() const {
    return listaUrgentes.size();
}*/

// ------------------------------------------------
 
// Opción A. Generamos 12 pedidos y los almacenamos en la pila (maximo 48).
void Gestor::generar12Pedidos() const {
    const int maxPedidos = 48;
    const int pedidosAGenerar = 12;

    for (int i = 0; i < pedidosAGenerar; i++) {
        // Verificar si ya se han generado 48 pedidos
        if (pilaPedidos->getLongitud() >= maxPedidos) {
            std::cout << "¡Se alcanzo el limite maximo de 48 pedidos!" << std::endl;
            break;  // Salir del bucle si se alcanzó el límite máximo
        }

        int idPedido = rand();
        int numeroSeguimiento = rand();
        std::string dniCliente = "1234567890" + std::to_string(i);
        bool urgente = rand() % 2 == 0;

        Pedido pedido(idPedido, numeroSeguimiento, dniCliente, urgente);
        pilaPedidos->insertar(pedido);
    }
}

// Opción B. Mostramos todos los pedidos almacenados en la pila.
void Gestor::muestraPedidos() const {
    pilaPedidos->mostrar();
}

// Opción C. Borrar los pedidos almacenados en A.
void Gestor::borrarPedidosPila() const {
    pilaPedidos->vaciarPila();
  }
  
// Opción D. Extraer de la pila y almacenar en las colas en función del pedido

void Gestor::encolarPedidos() const {
    Pedido pedido = pilaPedidos->extraer();
    if (pedido.urgencia()) {
        estacionC.insertar(pedido);
        /*o
        estacionD.insertar(pedido);*/
    } else {
        estacionA.insertar(pedido);
        /*o
        estacionB.insertar(pedido);*/
    }
}