#ifndef MENU_H
#define MENU_H
#include "Mundo.h"


class Menu 
{
	private:
	
	    Mundo& db;  
	public:
	
	    Menu(Mundo& database);
	    void mostrarMenu() const;
	    void ejecutarOpcion(int opcion);
	    void iniciar();  
};
#endif

