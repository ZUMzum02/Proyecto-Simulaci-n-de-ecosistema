#include "Presa.h"
#include "Vegetacion.h"
#include "Utils.h"

Presa::Presa(int px, int py) : Organismo(px, py, 6) {}
Presa::~Presa() {}

char Presa::simbolo() const { return 'P'; }

void Presa::mover() {
    
    int dx = pasoAleatorio(); int dy = pasoAleatorio();
    int nx = x + dx; int ny = y + dy;
    if (nx < 0) nx = 0; if (nx >= 8) nx = 7;
    if (ny < 0) ny = 0; if (ny >= 8) ny = 7;
    x = nx; y = ny;
}

void Presa::comer(Organismo* lista[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        Vegetacion* v = dynamic_cast<Vegetacion*>(lista[i]);
        if (v && v->esVegetacionActiva() && v->getX() == x && v->getY() == y) {
            v->consumir();
            vida += 3;
            cooldown = 3; 
            return;
        }
    }
}

void Presa::actualizar() {
    if (cooldown > 0) cooldown--;
    vida--;
}
