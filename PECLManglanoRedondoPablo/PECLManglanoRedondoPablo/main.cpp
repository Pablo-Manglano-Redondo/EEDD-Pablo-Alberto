#include <iostream>
#include <cstdlib> // Para usar la función std::system("CLS") en sistemas Windows

using namespace std;

void mostrarMenu() {
    cout << "========== Menú ==========" << endl;
    cout << "A. Generar 12 pedidos aleatorios" << endl;
    cout << "B. Mostrar pedidos en la pila" << endl;
    cout << "C. Borrar pedidos en la pila" << endl;
    cout << "D. Mover pedidos a las estaciones" << endl;
    cout << "E. Mostrar pedidos en las estaciones" << endl;
    cout << "F. Borrar pedidos en las estaciones" << endl;
    cout << "G. Mover pedidos a las listas" << endl;
    cout << "H. Mostrar pedidos en la Lista Estándar" << endl;
    cout << "I. Mostrar pedidos en la Lista Urgente" << endl;
    cout << "J. Buscar pedidos" << endl;
    cout << "K. Reiniciar programa" << endl;
    cout << "==========================" << endl;
    cout << "Seleccione una opción: ";
}

char obtenerOpcion() {
    char opcion;
    cin >> opcion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer del teclado
    return toupper(opcion);
}

int main() {
    Gestor gestor; // Instancia de la clase Gestor

    char opcion;
    do {
        mostrarMenu();
        opcion = obtenerOpcion();

        switch (opcion) {
            case 'A':
                gestor.generarPedidosAleatorios();
                break;
            case 'B':
                gestor.mostrarPedidosEnPila();
                break;
            case 'C':
                gestor.borrarPedidosEnPila();
                break;
            case 'D':
                gestor.moverPedidosAPilas();
                break;
            case 'E':
                gestor.mostrarPedidosEnEstaciones();
                break;
            case 'F':
                gestor.borrarPedidosEnEstaciones();
                break;
            case 'G':
                gestor.moverPedidosAListas();
                break;
            case 'H':
                gestor.mostrarPedidosEnListaEstándar();
                break;
            case 'I':
                gestor.mostrarPedidosEnListaUrgente();
                break;
            case 'J':
                gestor.buscarPedidos();
                break;
            case 'K':
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
        }

        // Espera hasta que el usuario presione Enter para continuar
        cout << "Presione Enter para continuar...";
        cin.ignore(); // Espera hasta que el usuario presione Enter

        // Limpia la consola (solo en sistemas Windows)
        system("CLS");

    } while (opcion != 'X');

    return 0;
}
