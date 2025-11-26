#include <iostream>
#include "Utils.h"
#include "myString.h"
#include "Organismo.h"
#include "Vegetacion.h"
#include "Presa.h"
#include "Depredador.h"
#include "Mundo.h"
#include "menu.h"

int main() {


    Mundo mundo(8,8);
    Menu menu(mundo);
    menu.mostrarMenu();

    int op; std::cin>>op;
    menu.ejecutarOpcion(op);

    /*****
    mundo.agregarOrganismo(new Vegetacion(0,0));
    mundo.agregarOrganismo(new Vegetacion(4,4));
    mundo.agregarOrganismo(new Vegetacion(7,7));

    mundo.agregarOrganismo(new Presa(3,2));
    mundo.agregarOrganismo(new Presa(3,3));

    mundo.agregarOrganismo(new Depredador(0,2));

    std::cout << "ESTADO INICIAL:\n";
    mundo.mostrar();

    for (int d = 1; d <= 10; d++) {
        std::cout << "\n--- Día " << d << " ---\n";
        mundo.avanzarDia();
        mundo.mostrar();
    }
    ****/

    return 0;
}
