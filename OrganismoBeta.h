#ifndef ORGANISMOBETA_H
#define ORGANISMOBETA_H
#include "myString.h"

class OrganismoBeta {
private:
    myString nombre;
    int x, y;
    bool vivo;
    int energia;
    myString especie;
    int edad;
    myString peligrosidad;
    myString alimentacion;
    myString habitat;
    float peso, tamano;
    myString salud;
    int nivelAmenaza;
    myString descripcion;
    void asignarDatosPorNombre();

public:
    OrganismoBeta();
    OrganismoBeta(const myString& nombre);
    OrganismoBeta(int x, int y, const myString& nombre);
    ~OrganismoBeta();

    myString getNombre() const;
    int getX() const;
    int getY() const;
    bool estaVivo() const;
    int getEnergia() const;

    void setPos(int nx, int ny);
    void setVivo(bool v);
    void setEnergia(int e);

    myString getEspecie() const;
    int getEdad() const;
    myString getPeligrosidad() const;
    myString getAlimentacion() const;
    myString getHabitat() const;
    float getPeso() const;
    float getTamano() const;
    myString getSalud() const;
    int getNivelAmenaza() const;
    myString getDescripcion() const;

    void mostrarDatos() const;
};

#endif
