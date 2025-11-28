#ifndef DEPREDADOR_H
#define DEPREDADOR_H
#include "Organismo.h"

class Depredador : public Organismo {
public:
     Depredador(int px = 0, int py = 0,
          myString especie = "Depredador",
          myString habitat = "Desconocido",
          int nivel = 4,
          int vidaInicial = 80);

    virtual ~Depredador();
    virtual char simbolo() const override;
    virtual void mover() override;
    virtual void comer(Organismo* lista[], int cantidad) override;
    virtual void actualizar() override;
};
#endif
