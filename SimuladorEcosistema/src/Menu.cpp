#include <iostream>
#include "menu.h"

Menu::Menu(Mundo& mundo) : db(mundo)
{

}



void Menu::mostrarMenu() const{

    std::cout<<"**************************************************"<<std::endl;
    std::cout<<"**           SISTEMA DE RESERVA                 **"<<std::endl;
    std::cout<<"**           NATURAL ECOMUNDO                   **"<<std::endl;
    std::cout<<"**           ================                   **"<<std::endl;
    std::cout<<"**                                              **"<<std::endl;
    std::cout<<"**                                              **"<<std::endl;
    std::cout<<"**      [1] Mostrar datos organismos            **"<<std::endl;
    std::cout<<"**      [2] Inspeccionar Organismo              **"<<std::endl;
    std::cout<<"**      [3] Historial Organismo                 **"<<std::endl;
    std::cout<<"**      [4] Salir                               **"<<std::endl;
    std::cout<<"**                                              **"<<std::endl;
    std::cout<<"**                                              **"<<std::endl;
    std::cout<<"**                                              **"<<std::endl;
    std::cout<<"**                                              **"<<std::endl;
    std::cout<<"**                                              **"<<std::endl;
    std::cout<<"**                                              **"<<std::endl;
    std::cout<<"**                                              **"<<std::endl;
    std::cout<<"**                                              **"<<std::endl;
    std::cout<<"**                                              **"<<std::endl;
    std::cout<<"**************************************************"<<std::endl;
}

void Menu::ejecutarOpcion(int opcion) {

     if(opcion==2){


	    db.agregarOrganismo(new Vegetacion(0,0));
	    db.agregarOrganismo(new Vegetacion(4,4));
	    db.agregarOrganismo(new Vegetacion(7,7));

	    db.agregarOrganismo(new Presa(3,2));
	    db.agregarOrganismo(new Presa(3,3));

	    db.agregarOrganismo(new Depredador(0,2));

	    std::cout << "ESTADO INICIAL:\n";
	    db.mostrar();

	    for (int d = 1; d <= 10; d++) {
		std::cout << "\n--- Día " << d << " ---\n";
		db.avanzarDia();
		db.mostrar();
	    }
            return ;
     }


}
