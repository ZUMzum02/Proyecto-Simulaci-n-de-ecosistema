#ifndef PRESA_H
#define PRESA_H
#include "Organismo.h"

class Presa : public Organismo {
public:
     Presa(int px = 0, int py = 0,
          myString especie = "Presa",
          myString habitat = "Desconocido",
          int nivel = 1,
          int vidaInicial = 50);

    virtual ~Presa();
    virtual char simbolo() const override;
    virtual void mover() override;
    virtual void comer(Organismo* lista[], int cantidad) override;
    virtual void actualizar() override;
};
#endif
