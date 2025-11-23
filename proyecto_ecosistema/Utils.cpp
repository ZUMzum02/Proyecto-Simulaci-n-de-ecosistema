#include "Utils.h"

static long long semilla = 12345LL;

long long get_seed() { return semilla; }

int aleatorio(int maximo) {
    if (maximo <= 0) return 0;
    semilla = (semilla * 1103515245LL + 12345LL) % 2147483648LL;
    return (int)(semilla % maximo);
}

int pasoAleatorio() {
    return aleatorio(3) - 1; // -1,0,1
}

void movimientoAleatorioCoord(int &x, int &y) {
    x += pasoAleatorio();
    y += pasoAleatorio();
    if (x < 0) x = 0;
    if (x >= 8) x = 7;
    if (y < 0) y = 0;
    if (y >= 8) y = 7;
}
