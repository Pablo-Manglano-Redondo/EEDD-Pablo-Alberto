#include <iostream>
#include <cstdlib> // Para usar la función std::system("CLS") en sistemas Windows

void mostrarMenu() {
    std::cout << "========== Menú ==========" << std::endl;
    std::cout << "A. Generar 12 pedidos aleatorios" << std::endl;
    std::cout << "B. Mostrar pedidos en la pila" << std::endl;
    std::cout << "C. Borrar pedidos en la pila" << std::endl;
    std::cout << "D. Mover pedidos a las estaciones" << std::endl;
    std::cout << "E. Mostrar pedidos en las estaciones" << std::endl;
    std::cout << "F. Borrar pedidos en las estaciones" << std::endl;
    std::cout << "G. Mover pedidos a las listas" << std::endl;
    std::cout << "H. Mostrar pedidos en la Lista Estándar" << std::endl;
    std::cout << "I. Mostrar pedidos en la Lista Urgente" << std::endl;
    std::cout << "J. Buscar pedidos" << std::endl;
    std::cout << "K. Reiniciar programa" << std::endl;
    std::cout << "X. Salir" << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "Seleccione una opción: ";
}

char obtenerOpcion() {
    char opcion;
    std::cin >> opcion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer del teclado
    return std::toupper(opcion);
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
                gestor.reiniciarPrograma();
                break;
            case 'X':
                std::cout << "Saliendo del programa. ¡Hasta luego!" << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Por favor, seleccione una opción válida." << std::endl;
        }

        // Espera hasta que el usuario presione Enter para continuar
        std::cout << "Presione Enter para continuar...";
        std::cin.ignore(); // Espera hasta que el usuario presione Enter

        // Limpia la consola (solo en sistemas Windows)
        std::system("CLS");

    } while (opcion != 'X');

    return 0;
}
