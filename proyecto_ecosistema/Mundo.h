#pragma once
#include "Organismo.h"
#include "Vegetacion.h"
#include "Presa.h"
#include "Depredador.h"

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

    void agregarOrganismo(Organismo* o);
    void avanzarDia();
    void mostrar() const;
};
