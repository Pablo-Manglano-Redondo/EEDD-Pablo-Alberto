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
    NodoPila* nuevo = new NodoPila(pedido);
    nuevo->sig = ultimo;
    ultimo = nuevo;
    longitud++;
}

int Pila::extraer() // Extrae el elemento superior de la pila
{
    if (estaVacia()) {
        throw std::out_of_range("La pila está vacía");
    }
    int v = ultimo->pedido.id_pedido(); // Reemplaza con el método correcto o miembro de Pedido
    NodoPila* aux = ultimo;
    ultimo = ultimo->sig;
    delete aux;
    longitud--;
    return v;
}

int Pila::cima() // Devuelve el elemento superior de la pila
{
    if (estaVacia()) {
        throw std::out_of_range("La pila está vacía");
    }
    return ultimo->pedido.id_pedido(); // Reemplaza con el método correcto o miembro de Pedido
}

void Pila::mostrar() // Muestra la pila
{
    if (estaVacia()) {
        std::cout << "La pila está vacía" << std::endl;
        return;
    }
    NodoPila* aux = ultimo;
    while (aux != nullptr) {
        // Accede a los miembros de Pedido a través del objeto pedido en NodoPila
        std::cout << aux->pedido.id_pedido() << " ";
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
