#pragma once
#include "Organismo.h"

class Depredador : public Organismo {
public:
    Depredador(int px = 0, int py = 0);
    virtual ~Depredador();
    virtual char simbolo() const override;
    virtual void mover() override;
    virtual void comer(Organismo* lista[], int cantidad) override;
    virtual void actualizar() override;
};
