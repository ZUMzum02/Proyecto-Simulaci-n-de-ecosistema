#ifndef ORGANISMO_H
#define ORGANISMO_H
#include "myString.h"

class Organismo {
protected:
    int x, y;
    int vida;
    int cooldown;
    myString especie;
    myString habitat;
    int nivelAmenaza;

public:
     Organismo(int px = 0, int py = 0, int pvida = 1,
              myString pespecie = "Desconocida", myString phabitat = "Desconocido", int nivel=0 );


    virtual ~Organismo();

    int getX() const;
    int getY() const;
    int getVida() const;
    int getCooldown() const;
    myString getEspecie() const;
    myString getHabitat() const;
    int getNivel() const;

    void setPos(int nx, int ny);
    void setVida(int v);
    void setCooldown(int c);

    virtual char simbolo() const = 0;
    virtual void mover();
    virtual void comer(Organismo* lista[], int cantidad);
    virtual void actualizar();
    bool estaVivo() const { return vida > 0; }

};
#endif
