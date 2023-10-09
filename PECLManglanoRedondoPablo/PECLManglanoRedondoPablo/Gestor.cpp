#include "Gestor.hpp"
#include <iostream>
#include <cstdlib> // Para generar números aleatorios

#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"


// Constructor
Gestor::Gestor() {
    // Inicializa las estructuras de datos y realiza otras inicializaciones necesarias
}

// Destructor
Gestor::~Gestor() {
    // Realiza operaciones de limpieza y libera memoria si es necesario
}

// Comprueba si la pila está llena
bool estaLlena() {
    return cima == nullptr;
}

// Quita el pedido de la cima de la pila
void pop(Pedido& pedido) {
    if (!estaVacia()) {
        Pedido* temp = cima;
        pedido = temp->pedido;
        cima = temp->siguiente;
        delete temp;
    }
}

void Gestor::generarPedidosAleatorios() {
    // Lógica para generar 12 pedidos aleatorios y almacenarlos en la pila
    if (!pila.estaLlena()) {
        for (int i = 0; i < 12; ++i) {
        Pedido nuevoPedido;
        nuevoPedido.id = rand() % 100 + 1; // Número de pedido único entre 1 y 100
        nuevoPedido.numeroSeguimiento = rand() % 499 + 1; // Número de seguimiento entre 1 y 499
        nuevoPedido.dniCliente = rand() % 1000000000 + 1; // DNI del cliente aleatorio
        nuevoPedido.esUrgente = rand() % 2 == 0; // Aleatoriamente urgente o estándar
        pila.push(nuevoPedido);
        }
    }
}

void Gestor::mostrarPedidosEnPila() {
    // Muestra los pedidos almacenados en la pila
    std::cout << "Pedidos en la pila:" << std::endl;
    Pila tempPila = pila; // Crear una copia de la pila para no alterar la original
    Pedido tempPedido;
    while (tempPila.pop(tempPedido)) {
        std::cout << "ID: " << tempPedido.id << ", Número de Seguimiento: " << tempPedido.numeroSeguimiento
                  << ", DNI del Cliente: " << tempPedido.dniCliente << ", Urgente: " << (tempPedido.esUrgente ? "Sí" : "No")
                  << std::endl;
    }
}

void Gestor::borrarPedidosEnPila() {
    // Lógica para borrar todos los pedidos almacenados en la pila
    while (!pila.estaVacia()) {
        Pedido temp;
        pila.pop(temp);
    }
}

void Gestor::moverPedidosAPilas() {
    Pila tempPila = pila; // Copia de la pila original para no alterarla

    while (!tempPila.estaVacia()) {
        Pedido temp;
        tempPila.pop(temp);

        if (temp.esUrgente) {
            if (estacionA.estaVacia() || estacionA.getFrente()->pedido.id >= temp.id) {
                estacionA.encolar(temp);
            } else {
                estacionB.encolar(temp);
            }
        } else {
            if (estacionA.estaVacia() || estacionA.frente->pedido.id >= temp.id) {
                estacionA.encolar(temp);
            } else {
                estacionB.encolar(temp);
            }
        }
    }
}

void Gestor::mostrarPedidosEnEstaciones() {
    std::cout << "Pedidos en la estación A:" << std::endl;
    Cola tempA = estacionA;
    while (!tempA.estaVacia()) {
        Pedido temp;
        tempA.desencolar(temp);
        std::cout << "ID: " << temp.id << ", Urgente: " << (temp.esUrgente ? "Sí" : "No") << std::endl;
    }

    std::cout << "Pedidos en la estación B:" << std::endl;
    Cola tempB = estacionB;
    while (!tempB.estaVacia()) {
        Pedido temp;
        tempB.desencolar(temp);
        std::cout << "ID: " << temp.id << ", Urgente: " << (temp.esUrgente ? "Sí" : "No") << std::endl;
    }
}

void Gestor::borrarPedidosEnEstaciones() {
    while (!estacionA.estaVacia()) {
        Pedido temp;
        estacionA.desencolar(temp);
    }

    while (!estacionB.estaVacia()) {
        Pedido temp;
        estacionB.desencolar(temp);
    }
}

void Gestor::moverPedidosAListas() {
    Cola tempA = estacionA;
    while (!tempA.estaVacia()) {
        Pedido temp;
        tempA.desencolar(temp);
        listaEstándar.insertarEnOrden(temp);
    }

    Cola tempB = estacionB;
    while (!tempB.estaVacia()) {
        Pedido temp;
        tempB.desencolar(temp);
        listaEstándar.insertarEnOrden(temp);
    }
}

void Gestor::mostrarPedidosEnListaEstándar() {
    std::cout << "Pedidos en la Lista Estándar:" << std::endl;
    listaEstándar.mostrarPedidos();
}

void Gestor::mostrarPedidosEnListaUrgente() {
    std::cout << "Pedidos en la Lista Urgente:" << std::endl;
    listaUrgente.mostrarPedidos();
}

void Gestor::buscarPedidos() {
    Pedido pedidoEstándarPrioritario;
    Pedido pedidoUrgentePrioritario;

    // Inicializa los valores para comparación
    pedidoEstándarPrioritario.id = 50;
    pedidoUrgentePrioritario.id = 100;

    NodoLista* tempEstándar = listaEstándar.inicio;
    NodoLista* tempUrgente = listaUrgente.inicio;

    // Encuentra el pedido estándar de mayor prioridad
    while (tempEstándar) {
        if (tempEstándar->pedido.id < pedidoEstándarPrioritario.id) {
            pedidoEstándarPrioritario = tempEstándar->pedido;
        }
        tempEstándar = tempEstándar->siguiente;
    }

    // Encuentra el pedido urgente de menor prioridad
    while (tempUrgente) {
        if (tempUrgente->pedido.id > pedidoUrgentePrioritario.id) {
            pedidoUrgentePrioritario = tempUrgente->pedido;
        }
        tempUrgente = tempUrgente->siguiente;
    }

    // Muestra los pedidos encontrados
    std::cout << "Pedido estándar de mayor prioridad:" << std::endl;
    std::cout << "ID: " << pedidoEstándarPrioritario.id << ", Urgente: " << (pedidoEstándarPrioritario.esUrgente ? "Sí" : "No") << std::endl;

    std::cout << "Pedido urgente de menor prioridad:" << std::endl;
    std::cout << "ID: " << pedidoUrgentePrioritario.id << ", Urgente: " << (pedidoUrgentePrioritario.esUrgente ? "Sí" : "No") << std::endl;
}

void Gestor::reiniciarPrograma() {
    // Elimina los pedidos de la pila
    while (!pila.estaVacia()) {
        Pedido temp;
        pila.pop(temp);
    }

    // Elimina los pedidos de las estaciones A y B
    while (!estacionA.estaVacia()) {
        Pedido temp;
        estacionA.desencolar(temp);
    }

    while (!estacionB.estaVacia()) {
        Pedido temp;
        estacionB.desencolar(temp);
    }

    // Elimina los pedidos de las listas
    while (listaEstándar.inicio) {
        NodoLista* temp = listaEstándar.inicio;
        listaEstándar.inicio = listaEstándar.inicio->siguiente;
        delete temp;
    }

    while (listaUrgente.inicio) {
        NodoLista* temp = listaUrgente.inicio;
        listaUrgente.inicio = listaUrgente.inicio->siguiente;
        delete temp;
    }

    // Vuelve a generar 12 pedidos aleatorios
    generarPedidosAleatorios();
}
