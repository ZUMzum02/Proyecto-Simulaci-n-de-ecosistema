#include "Vegetacion.h"

const int REGEN_DIAS = 4;

Vegetacion::Vegetacion(int px, int py)
    : Organismo(px, py, 1), activa(true), diasParaRegen(0)
{

}

Vegetacion::~Vegetacion() {}

char Vegetacion::simbolo() const { return activa ? 'V' : '.'; }

void Vegetacion::consumir() {
    if (!activa) return;
    activa = false;
    diasParaRegen = REGEN_DIAS;
    vida = 0;
}

void Vegetacion::actualizar() {
    if (!activa) {
        diasParaRegen--;
        if (diasParaRegen <= 0) {
            activa = true;
            vida = 1;
            diasParaRegen = 0;
        }
    }
}

bool Vegetacion::esVegetacionActiva() const { return activa; }
