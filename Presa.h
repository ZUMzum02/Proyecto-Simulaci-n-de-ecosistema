#pragma once
#include "Organismo.h"

class Presa : public Organismo {
public:
    Presa(int px = 0, int py = 0);
    virtual ~Presa();
    virtual char simbolo() const override;
    virtual void mover() override;
    virtual void comer(Organismo* lista[], int cantidad) override;
    virtual void actualizar() override;
};
