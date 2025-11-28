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

    /****
    Mundo mundo(8,8);
    Menu menu(mundo);
    menu.mostrarMenu();
    
    int op; std::cin>>op;
    menu.ejecutarOpcion(op);
    ***/
    
    Mundo mundo(8,8);
    Menu menu(mundo);

    int op;

    while (true) {

        menu.mostrarMenu();

        std::cout << "\nIngrese una opción: ";
        std::cin >> op;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(9999, '\n');
            std::cout << "Opción inválida.\n";
            continue;
        }

        
        if (op == 4) {
            menu.ejecutarOpcion(op);  
            break;                    
        }

        menu.ejecutarOpcion(op);      
    }
    
    return 0;
}
