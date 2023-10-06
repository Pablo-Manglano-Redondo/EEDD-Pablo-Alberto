#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Pedido {
    int id;
    string tipo;
    // Puedes agregar más atributos según tus necesidades
};

int main() {
    stack<Pedido> pilaPedidos;
    queue<Pedido> estacionA, estacionB, estacionC, estacionD;
    vector<Pedido> listaEstándar, listaUrgente;

    char opcion;

    cout << "-------------------------------------------------\n";
    cout << "Pedidos en la pila:\n";
    cout << "Pedidos en las colas:\n";
    cout << "Pedidos en las listas:\n";
    cout << "Pedidos en el árbol:\n";
    cout << "-------------------------------------------------\n";

    do {
        cout << "Opciones:\n"
             << "A: Generar y almacenar pedidos aleatorios\n"
             << "B: Mostrar pedidos almacenados en la pila\n"
             << "C: Borrar pedidos almacenados en la pila\n"
             << "D: Extraer pedidos de la pila y almacenar en estaciones\n"
             << "E: Mostrar pedidos en estaciones A y B\n"
             << "F: Mostrar pedidos en estaciones C y D\n"
             << "G: Borrar pedidos en las estaciones\n"
             << "H: Extraer pedidos de las estaciones y almacenar en listas\n"
             << "I: Mostrar pedidos en Lista Estándar\n"
             << "J: Mostrar pedidos en Lista Urgente\n"
             << "K: Mostrar pedidos estándar de mayor prioridad y urgente de menor prioridad\n"
             << "L: Reiniciar el programa\n"
             << "X: Salir del programa\n";

        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 'A':
                // Implementa la opción A
                break;
            case 'B':
                // Implementa la opción B
                break;
            case 'C':
                // Implementa la opción C
                break;
            case 'D':
                // Implementa la opción D
                break;
            case 'E':
                // Implementa la opción E
                break;
            case 'F':
                // Implementa la opción F
                break;
            case 'G':
                // Implementa la opción G
                break;
            case 'H':
                // Implementa la opción H
                break;
            case 'I':
                // Implementa la opción I
                break;
            case 'J':
                // Implementa la opción J
                break;
            case 'K':
                // Implementa la opción K
                break;
            case 'L':
                // Implementa la opción L
                break;
            case 'X':
                cout << "Saliendo del programa. Hasta luego.\n";
                break;
            default:
                cout << "Opción no válida. Por favor, elige una opción válida.\n";
                break;
        }

    } while (opcion != 'X');

    return 0;
}
