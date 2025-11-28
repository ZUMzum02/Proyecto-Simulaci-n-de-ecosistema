#ifndef MUNDO_H
#define MUNDO_H
#include "Organismo.h"
#include "Vegetacion.h"
#include "Presa.h"
#include "Depredador.h"
#include "myString.h"

class Mundo {
private:
    int filas, columnas;
    Organismo*** grid; // grid[filas][columns]
    Organismo** lista;
    int total;
    int capacity;
    int dia;

    void ensureCapacity();
    bool enRango(int x, int y) const;
    void colocarEnGrid(Organismo* o);
    void removerDeGrid(Organismo* o);

public:
    Mundo(int filas = 8, int columnas = 8);
    ~Mundo();

    Organismo* getOrganismo(int i) const;
    int totalOrganismos() const;
    void agregarOrganismo(Organismo* o);
    void avanzarDia();
    void mostrar() const;
};
#endif
