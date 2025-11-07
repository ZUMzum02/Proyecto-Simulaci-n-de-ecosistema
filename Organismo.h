#ifndef ORGANISMO_H
#define ORGANISMO_H
#include "myString.h"


class Organismo
{
	private:
	    myString nombre;
	    myString especie;
	    myString historial;

	public:
	    Organismo(const myString& n, const myString& e, const myString& h);
	    myString getNombre() const;
	    myString getEspecie() const;
	    myString getHistorial() const;
	    void setHistorial(const myString& h);
};
#endif
