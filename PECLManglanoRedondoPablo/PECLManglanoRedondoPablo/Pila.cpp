#include "Pila.hpp"

Pila::Pila() // Constructor por defecto
{
    ultimo = nullptr; 
    longitud = 0;
}

Pila::~Pila() // Destructor
{
    while (!estaVacia()) {
        extraer();
    }
}

void Pila::insertar(const Pedido& pedido) // Inserta un elemento en la pila
{
    NodoPila* nuevo = new NodoPila(pedido); // Puntero nuevo apunta al nuevo objeto NodoPila
    nuevo->sig = ultimo; // sig de nuevo apunta al mismo nodo que ultimo 
    ultimo = nuevo; // Puntero ultimo ahora apunta a nuevo 
    longitud++; // Se aumenta 1 en la longitud de la cola 
}

Pedido Pila::extraer() // Extrae el elemento superior de la pila
{
    if (estaVacia()) {
        throw std::out_of_range("La pila está vacía. "); // Imprime el error por pantalla
    }
    Pedido pedido = ultimo->pedido; 
    NodoPila* aux = ultimo;
    ultimo = ultimo->sig;
    delete aux;
    longitud--;
    return pedido;
}


int Pila::cima() // Devuelve el elemento superior de la pila
{
    if (estaVacia()) {
        throw std::out_of_range("La pila está vacía. "); // Imprime el error por pantalla
    }
    return ultimo->pedido.idPedido(); // Reemplaza con el método correcto o miembro de Pedido
}

void Pila::mostrar() // Muestra la pila
{
    if (estaVacia()) {
        std::cout << "La pila está vacia. " << std::endl; // Imprime el error por pantalla
        return;
    }
    NodoPila* aux = ultimo;
    while (aux != nullptr) {
        // Accede a los miembros de Pedido a través del objeto pedido en NodoPila
        std::cout << "ID Pedido: " << aux->pedido.idPedido() << ", "
          << "Numero de Seguimiento: " << aux->pedido.numSeguimiento() << ", "
          << "DNI Cliente: " << aux->pedido.dniCliente() << ", "
          << "Urgencia: " << (aux->pedido.urgencia() ? 1 : 0) << std::endl;

        aux = aux->sig;
    }
    std::cout << std::endl;
}

bool Pila::estaVacia() {
    return ultimo == nullptr;
}

int Pila::getLongitud() // Devuelve la longitud de la pila
{
    return longitud;
}

void Pila::vaciarPila() {
    while (!estaVacia()) {
        NodoPila* siguiente = ultimo->sig;  // Guarda el siguiente nodo antes de eliminar el actual
        delete ultimo;  // Libera la memoria del nodo actual
        ultimo = siguiente;  // Establece el siguiente nodo como la nueva cima
        longitud--;
    }
}


