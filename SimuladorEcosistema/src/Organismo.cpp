#include "Organismo.h"

Organismo::Organismo(int px, int py, int pvida, myString pespecie, myString phabitat, int nivel)
    : x(px),
      y(py),
      vida(pvida),
      cooldown(0),
      especie(pespecie),
      habitat(phabitat),
      nivelAmenaza(nivel) {}

Organismo::~Organismo() {}

int Organismo::getX() const { return x; }
int Organismo::getY() const { return y; }
int Organismo::getVida() const { return vida; }
int Organismo::getCooldown() const { return cooldown; }
myString Organismo::getEspecie() const {return especie;}
myString Organismo::getHabitat() const {return habitat;}
int Organismo::getNivel() const {return nivelAmenaza;}

void Organismo::setPos(int nx, int ny) { x = nx; y = ny; }
void Organismo::setVida(int v) { vida = v; }
void Organismo::setCooldown(int c) { cooldown = c; }

void Organismo::mover() {  }
void Organismo::comer(Organismo* lista[], int cantidad) { (void)lista; (void)cantidad; }
void Organismo::actualizar() { if (cooldown>0) cooldown--; vida--; }
