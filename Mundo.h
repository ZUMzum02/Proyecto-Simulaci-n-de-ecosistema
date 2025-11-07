#ifndef MUNDO_H
#define MUNDO_H

#include "Organismo.h"



class Mundo 
{

	private:
	    int organismos[100];
	    
	public:
	
	    void agregarOrganismo(const Organismo& org);
	    void listarOrganismos() const;
	    Organismo* buscarOrganismo(const myString& nombre);
	    void mostrarHistorial(const myString& nombre) const;
};




#endif
