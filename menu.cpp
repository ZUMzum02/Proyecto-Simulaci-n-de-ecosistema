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

      if (opcion == 1) {

	    const int ancho = 62; // marco grande
	    auto linea = [&]() {
		for (int i = 0; i < ancho; i++) std::cout << "*";
		std::cout << "\n";
	    };

	    linea();
	    std::cout << "**    SISTEMA DE RESERVA - DATOS ORGANISMOS (PRINCIPALES)   **";
	    for (int i = 0; i < ancho - 51; i++) std::cout << " ";
	    std::cout << "\n";
	    linea();

	    std::cout << "**";
	    for (int i = 0; i < ancho - 4; i++) std::cout << " ";
	    std::cout << "**\n";

	    std::cout << "**  +---------------------------------+                     **\n";
	    std::cout << "**  | TIPO       | POSICIÓN | VIDA    |                     **\n";
	    std::cout << "**  +---------------------------------+                     **\n";

	    for (int i = 0; i < db.totalOrganismos(); i++) {

		Organismo* o = db.getOrganismo(i);
		if (!o || !o->estaVivo()) continue;

		char s = o->simbolo();
		if (s != 'P' && s != 'D') continue;  // solo presas y depredadores

		std::cout << "**   | ";

		if (s == 'P') std::cout << "PRESA      ";
		else          std::cout << "DEPREDADOR ";

		// Posición
		std::cout << "| (" << o->getX() << "," << o->getY() << ")    ";

		// Vida
		std::cout << "| " << o->getVida() << "    ";

		

		std::cout << "|                      **\n";
	    }

	    std::cout << "**  +--------------------------------+                      **\n";

	    std::cout << "**";
	    for (int i = 0; i < ancho - 4; i++) std::cout << " ";
	    std::cout << "**\n";

	    std::cout << "**                   [ENTER PARA VOLVER]                    **\n";

	    linea();

	    std::cin.ignore();
	    std::cin.get();

            return;
    }




     if(opcion==2){
        
        
	     std::cout << "ESTADO INICIAL DEL MUNDO:\n";
             db.mostrar();

             std::string command;

	    while (true) {
		std::cout << "\nPresiona ENTER para avanzar un día";
		std::cout << " (o escribe 'salir' para volver al menú): ";

		std::cin>>command;  // permite ENTER vacío

		if (command == "salir" || command == "SALIR") {
		    std::cout << "Regresando al menú...\n";
		    break;
		}

                db.avanzarDia();
                db.mostrar();
           }

     }
     
     
     if(opcion==3){
     
            std::cout << "**************************************************************\n";
	    std::cout << "**                 SISTEMA DE RESERVA - HISTORIAL          **\n";
	    std::cout << "**************************************************************\n\n";

	    int total = db.totalOrganismos();

	    std::cout << "Ingrese el ID del organismo (0 - " << total - 1 << "): ";
	    int id;
	    std::cin >> id;
	    std::cin.ignore();

	    if (id < 0 || id >= total) {
		std::cout << "\n Organismo no válido.\n";
		std::cout << " [ENTER PARA VOLVER]";
		std::cin.get();
		return;
	    }

	    Organismo* o = db.getOrganismo(id);

	    if (!o) {
		std::cout << "\n Organismo no válido.\n";
		std::cout << " [ENTER PARA VOLVER]";
		std::cin.get();
		return;
	    }

	    std::cout << "\n**************************************************************\n";
	    std::cout << "**                     DATOS DEL ORGANISMO                 **\n";
	    std::cout << "**************************************************************\n\n";

	    std::cout << "  ID             : " << id << "\n";
	    std::cout << "  TIPO           : " 
		      << (o->simbolo() == 'P' ? "PRESA" :
		         o->simbolo() == 'D' ? "DEPREDADOR" : "VEGETACION")
		      << "\n";

	    std::cout << "  ESPECIE        : " << o->getEspecie().getData() << "\n";
	    std::cout << "  HÁBITAT        : " << o->getHabitat().getData() << "\n";
	    std::cout << "  POSICIÓN       : (" << o->getX() << " , " << o->getY() << ")\n";
	    std::cout << "  VIDA ACTUAL    : " << o->getVida() << "\n";
	    std::cout << "  NIVEL AMENAZA  : " << o->getNivel() << "\n";
	    std::cout << "  COOLDOWN       : " << o->getCooldown() << " turnos\n";
	    std::cout << "  ESTADO         : " << (o->estaVivo() ? "VIVO" : "MUERTO") << "\n";

	    std::cout << "\n**************************************************************\n";
	    std::cout << " [ENTER PARA VOLVER]";
	    std::cin.get();

	    return;
        
     }
     
     if(opcion==4){
     
            std::cout<<"**************************************************"<<std::endl;
	    std::cout<<"**           SISTEMA DE RESERVA                 **"<<std::endl;
	    std::cout<<"**           NATURAL ECOMUNDO                   **"<<std::endl;
	    std::cout<<"**           ================                   **"<<std::endl;
	    std::cout<<"**                                              **"<<std::endl;
	    std::cout<<"**                                              **"<<std::endl;
	    std::cout<<"**      Gracias                                 **"<<std::endl;
	    std::cout<<"**      por                                     **"<<std::endl;
	    std::cout<<"**      su                                      **"<<std::endl;
	    std::cout<<"**      visita                                  **"<<std::endl;
	    std::cout<<"**      !!!!!!!!!!!                             **"<<std::endl;
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

}

