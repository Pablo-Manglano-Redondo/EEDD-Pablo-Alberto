#include "Gestor.hpp"

Gestor::Gestor()
{
}

Gestor::~Gestor()
{
}

// ------------------------------------------------

// Creamos la pila
Pila* pilaPedidos = new Pila();

// Creamos dos colas para los pedidos estándar.
Cola* estacionA = new Cola();
Cola* estacionB = new Cola();

// Creamos dos colas para los pedidos urgentes.
Cola* estacionC = new Cola();
Cola* estacionD = new Cola();

// Creamos una lista para los pedidos estándar.
Lista* listaEstandar = new Lista();

//Creamos una lista para los pedidos urgentes.
Lista* listaUrgente = new Lista();

// ------------------------------------------------

// Metodos para visualizar resultados

int Gestor::PedidosEnPila() const {
    return pilaPedidos->getLongitud();
}

int Gestor::PedidosEnSalaA() const {
    return estacionA->getLongitud();
}

int Gestor::PedidosEnSalaB() const {
    return estacionB->getLongitud();
}

int Gestor::PedidosEnSalaC() const {
    return estacionC->getLongitud();
}

int Gestor::PedidosEnSalaD() const {
    return estacionD->getLongitud();
}

int Gestor::PedidosEnListaEstandar() const {
    return listaEstandar->getLongitud();
}

int Gestor::PedidosEnListaUrgentes() const {
    return listaUrgente->getLongitud();
}

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
  
// Opción D. Extraer de la pila y almacenar en las colas en función del pedido.
void Gestor::encolarPedidos() const {
    while (!pilaPedidos->estaVacia()) {
        Pedido pedido = pilaPedidos->extraer();
        if (pedido.urgencia()) {
            if (estacionC->getLongitud() <= estacionD->getLongitud()) {
                estacionC->insertar(pedido);
            } else {
                estacionD->insertar(pedido);
            }
        } else {
            if (estacionA->getLongitud() <= estacionB->getLongitud()) {
                estacionA->insertar(pedido);
            } else {
                estacionB->insertar(pedido);
            }
        }
    }
}


// Opción E. Mostrar los pedidos en las estaciones A y B.
void Gestor::muestraPedidosSalasAyB() const {
    estacionA->mostrar();
    estacionB->mostrar();
}

// Opción F. Mostrar los pedidos en las estaciones C y D.
void Gestor::muestraPedidosSalasCyD() const {
    estacionC->mostrar();
    estacionD->mostrar();
}

// Opción G. Borrar los pedidos almacenados en las colas.
void Gestor::borrarPedidosColas() const {
    estacionA->vaciarCola();
    estacionB->vaciarCola();
    estacionC->vaciarCola();
    estacionD->vaciarCola();
}

// Opción H. Extraer los pedidos de las colas y meterlos ordenados en lista estandar/urgente.
void Gestor::enlistarPedidos() const {
    while (!estacionA->estaVacia()) {
        Pedido pedido = estacionA->extraer();
        int prioridad = pedido.urgencia() ? (rand() % 49) + 51 : (rand() % 49) + 1;        
        Pedido nuevoPedido(pedido.idPedido(), pedido.numSeguimiento(), pedido.dniCliente(), pedido.urgencia(), prioridad);
        listaEstandar->insertar(nuevoPedido);
    }

    while (!estacionB->estaVacia()) {
        Pedido pedido = estacionB->extraer();
        int prioridad = pedido.urgencia() ? (rand() % 49) + 51 : (rand() % 49) + 1;        
        Pedido nuevoPedido(pedido.idPedido(), pedido.numSeguimiento(), pedido.dniCliente(), pedido.urgencia(), prioridad);
        listaEstandar->insertar(nuevoPedido);
    }

    while (!estacionC->estaVacia()) {
        Pedido pedido = estacionC->extraer();
        int prioridad = pedido.urgencia() ? (rand() % 49) + 51 : (rand() % 49) + 1;
        Pedido nuevoPedido(pedido.idPedido(), pedido.numSeguimiento(), pedido.dniCliente(), pedido.urgencia(), prioridad);
        listaUrgente->insertar(nuevoPedido);
    }

    while (!estacionD->estaVacia()) {
        Pedido pedido = estacionD->extraer();
        int prioridad = pedido.urgencia() ? (rand() % 49) + 51 : (rand() % 49) + 1;        
        Pedido nuevoPedido(pedido.idPedido(), pedido.numSeguimiento(), pedido.dniCliente(), pedido.urgencia(), prioridad);
        listaUrgente->insertar(nuevoPedido);
    }
    listaEstandar->ordenarPorID();
    listaUrgente->ordenarPorID();
}

// Opción I. Mostrar los pedidos en la lista estandar.
void Gestor::muestraPedidosEstandar() const {
    listaEstandar->mostrar();
}

// Opción J. Mostrar los pedidos en la lista urgente.
void Gestor::muestraPedidosUrgentes() const {
    listaUrgente->mostrar();
}

// Opción K. Buscar el pedido estándar de mayor prioridad y el pedido urgente de menor prioridad.
void Gestor::buscarPedidos() const {
    if (listaEstandar->estaVacia() && listaUrgente->estaVacia()) {
        std::cout << "Las listas estan vacias." << std::endl;
        return;
    }

    NodoLista* tempEstandar = listaEstandar->getCabeza();
    NodoLista* tempUrgente = listaUrgente->getCabeza();

    Pedido pedidoEstandarMaxPrioridad(0, 0, "prueba", 0, 49);
    Pedido pedidoUrgenteMinPrioridad(0, 0, "prueba", 0, 51);

    bool encontradoEstandar = false;
    bool encontradoUrgente = false;

    // Buscar el pedido estándar de mayor prioridad
    while (tempEstandar) {
        if (!encontradoEstandar || tempEstandar->pedido.getPrioridad() > pedidoEstandarMaxPrioridad.getPrioridad()) {
            pedidoEstandarMaxPrioridad = tempEstandar->pedido;
            encontradoEstandar = true;
        }
        tempEstandar = tempEstandar->siguiente;
    }

    // Buscar el pedido urgente de menor prioridad
    while (tempUrgente) {
        if (!encontradoUrgente || tempUrgente->pedido.getPrioridad() < pedidoUrgenteMinPrioridad.getPrioridad()) {
            pedidoUrgenteMinPrioridad = tempUrgente->pedido;
            encontradoUrgente = true;
        }
        tempUrgente = tempUrgente->siguiente;
    }

    // Mostrar los resultados
    if (encontradoEstandar) {
        std::cout << "Pedido estandar de mayor prioridad:" << std::endl;
        std::cout << "ID Pedido: " << pedidoEstandarMaxPrioridad.idPedido() << ", Prioridad: " << pedidoEstandarMaxPrioridad.getPrioridad() << std::endl;
    } else {
        std::cout << "No hay pedidos estandar en la lista." << std::endl;
    }

    if (encontradoUrgente) {
        std::cout << "Pedido urgente de menor prioridad:" << std::endl;
        std::cout << "ID Pedido: " << pedidoUrgenteMinPrioridad.idPedido() << ", Prioridad: " << pedidoUrgenteMinPrioridad.getPrioridad() << std::endl;
    } else {
        std::cout << "No hay pedidos urgentes en la lista." << std::endl;
    }
}


// Opción L. Reiniciar el programa.
void Gestor::reiniciar() {
    // Liberar memoria de las estructuras de datos existentes
    delete pilaPedidos;
    delete estacionA;
    delete estacionB;
    delete estacionC;
    delete estacionD;
    delete listaEstandar;
    delete listaUrgente;

    // Crear nuevas instancias de las estructuras de datos
    pilaPedidos = new Pila();
    estacionA = new Cola();
    estacionB = new Cola();
    estacionC = new Cola();
    estacionD = new Cola();
    listaEstandar = new Lista();
    listaUrgente = new Lista();
}