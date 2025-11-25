#ifndef VEGETACION_H
#define VEGETACION_H
#include "Organismo.h"

class Vegetacion : public Organismo {
private:
    bool activa;
    int diasParaRegen;
public:
    Vegetacion(int px = 0, int py = 0);
    virtual ~Vegetacion();
    virtual char simbolo() const override;
    void consumir();
    virtual void actualizar() override;
    bool esVegetacionActiva() const override;
};
#endif
