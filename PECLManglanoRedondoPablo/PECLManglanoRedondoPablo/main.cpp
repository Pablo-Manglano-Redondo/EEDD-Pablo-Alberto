#include <iostream>
#include <vector>

#include "Gestor.hpp"

int main(int argc, char** argv) {
  Gestor gestor;
  char opcion;

  do {

    cout << "\n\t------------------------------------------------------------------------\n";
    cout << "\tPedidos en la pila -> " << gestor.PedidosEnPila()
         << "\n\tPedidos en las colas:\n \t\tSala A-> " << gestor.PedidosEnSalaA()
         << "\tSala B-> " << gestor.PedidosEnSalaB() << "\tSala C-> " << gestor.PedidosEnSalaC()
         << "\tSala D-> " << gestor.PedidosEnSalaD()
         << " \n\tPedidos en las listas:\n \t\tEstandar-> "
         << gestor.PedidosEnListaEstandar() << "\tUrgentes-> " << gestor.PedidosEnListaUrgentes()
         << "\n\t----------------------------------------------------------------------\n\n";

    cout << "\tA. Generar 12 Pedidos de forma aleatoria y almacenarlos en la "
            "Pila.\n";
    cout << "\tB. Consultar todos los Pedidos generados en la Pila (pendientes "
            "de entrar en las salas).\n";
    cout << "\tC. Borrar los Pedidos generados en la pila.\n";
    cout << "\tD. Simular llegada de los Pedidos en las colas.\n";
    cout << "\tE. Consultar los Pedidos de las salas A y B.\n";
    cout << "\tF. Consultar los Pedidos de las salas C y D.\n";
    cout << "\tG. Borrar los todos los Pedidos de las salas.\n";
    cout << "\tH. Simular la entrada de los Pedidos a las listas.\n";
    cout << "\tI. Mostrar los Pedidos que hay en la Lista Estándar.\n";
    cout << "\tJ. Mostrar los Pedidos que hay en la Lista Urgente.\n";
    cout << "\tK. Buscar en las listas y mostrar los siguientes 2 pedidos:\n";
    cout << "\t\t* El pedido estándar de mayor prioridad.\n";
    cout << "\t\t* El pedido urgente de menor prioridad.\n";
    cout << "\tL. Reiniciar el programa.\n\n";

    cout << "\tIndique la opcion deseada: ";
    cin >> opcion;
    opcion = toupper(opcion);

    switch(opcion) {

    case 'A':
      gestor.generar12Pedidos();
      break;
    case 'B':
      gestor.muestraPedidos();
      break;
    case 'C':
      gestor.borrarPedidosPila();
      break;
    case 'D':
      gestor.encolarPedidos();
      break;
    case 'E':
      gestor.muestraPedidosSalasAyB();
      break;
    case 'F':
      gestor.muestraPedidosSalasCyD();
      break;
    case 'G':
      gestor.borrarPedidosColas();
      break;
    case 'H':
      gestor.enlistarPedidos();
      break;
    case 'I':
      gestor.muestraPedidosEstandar();
      break;
    case 'J':
      gestor.muestraPedidosUrgentes();
      break;
    case 'K':
      gestor.buscarPedidos();
      break;
    case 'L':
      gestor.reiniciar();
      break;
    case 'M':
        //...;
        break;
    case 'N':
        //...;
        break;
    case 'O':
        //...;
        break;
    case 'P':
        //...;
        break;
    case 'Q':
        //...;
        break;
    case 'R':
        //...;
        break;
    case 'T':
        //...;
        break;
    case 'U':
        //...;
        break;
    default:
      cout << "Opcion incorrecta!\n\n";
      break;
    }
  } while(opcion != 'S');

  return 0;
}
