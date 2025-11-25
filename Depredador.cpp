#include "Depredador.h"
#include "Presa.h"
#include "Utils.h"

Depredador::Depredador(int px, int py)
    : Organismo(px, py, 8)
{
    especie = myString("Depredador");
    habitat = myString("Selva");
    nivelAmenaza = 3;
}

Depredador::~Depredador() {}

char Depredador::simbolo() const { return 'D'; }

void Depredador::mover() {
    int dx = pasoAleatorio(); int dy = pasoAleatorio();
    int nx = x + dx; int ny = y + dy;
    if (nx < 0) nx = 0; if (nx >= 8) nx = 7;
    if (ny < 0) ny = 0; if (ny >= 8) ny = 7;
    x = nx; y = ny;
}

void Depredador::comer(Organismo* lista[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        Presa* p = dynamic_cast<Presa*>(lista[i]);
        if (p && p->estaVivo() && p->getX() == x && p->getY() == y) {
            p->setVida(0);
            vida += 5;
            cooldown = 5;
            return;
        }
    }
}

void Depredador::actualizar() {
    if (cooldown > 0) cooldown--;
    vida--;
}
