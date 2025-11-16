#include <iostream>
using namespace std;

const int FILAS = 8;
const int COLUMNAS = 8;
const int MAX_ORGANISMOS = 20;


int semilla = 123;

int aleatorio(int maximo) {
    semilla = (semilla * 1103515245 + 12345) % 2147483648;
    return semilla % maximo;
}

int pasoAleatorio() {
    return aleatorio(3) - 1; // -1, 0, 1
}

void movimientoAleatorio(int &x, int &y) {
    int dx = pasoAleatorio();
    int dy = pasoAleatorio();

    x += dx;
    y += dy;

    if (x < 0) x = 0;
    if (x >= FILAS) x = FILAS - 1;
    if (y < 0) y = 0;
    if (y >= COLUMNAS) y = COLUMNAS - 1;
}

class Organismo {
public:
    int x, y;
    int vida;

    Organismo(int px = 0, int py = 0, int pvida = 10)
        : x(px), y(py), vida(pvida) {}

    virtual char simbolo() const = 0;

    virtual void mover() {
        movimientoAleatorio(x, y);
    }

    virtual void comer(Organismo* otros[], int cantidad) {}

    virtual void vivir() {
        vida--;
    }

    bool estaVivo() const {
        return vida > 0;
    }
};

class Vegetacion : public Organismo {
public:
    Vegetacion(int px, int py) : Organismo(px, py, 4) {}
    char simbolo() const { return 'V'; }
    void mover() override {}  // no se mueve
};

class Presa : public Organismo {
public:
    Presa(int px, int py) : Organismo(px, py, 6) {}
    char simbolo() const { return 'P'; }

    void mover() override {
        movimientoAleatorio(x, y);
    }

    void comer(Organismo* otros[], int cantidad) override {
        for (int i = 0; i < cantidad; i++) {
            Vegetacion* v = dynamic_cast<Vegetacion*>(otros[i]);
            if (v && v->estaVivo() && v->x == x && v->y == y) {
                vida += 3;
                v->vida = 0;
                return;
            }
        }
    }
};

class Depredador : public Organismo {
public:
    Depredador(int px, int py) : Organismo(px, py, 8) {}
    char simbolo() const { return 'D'; }

    void mover() override {
        movimientoAleatorio(x, y);
    }

    void comer(Organismo* otros[], int cantidad) override {
        for (int i = 0; i < cantidad; i++) {
            Presa* p = dynamic_cast<Presa*>(otros[i]);
            if (p && p->estaVivo() && p->x == x && p->y == y) {
                vida += 5;
                p->vida = 0;
                return;
            }
        }
    }
};

class Mundo {
private:
    Depredador* depredadores[MAX_ORGANISMOS];
    int totalDepredadores;

    Presa* presas[MAX_ORGANISMOS];
    int totalPresas;

    Vegetacion* vegetaciones[MAX_ORGANISMOS];
    int totalVegetacion;

    char mapa[FILAS][COLUMNAS];
    int dia;

public:
    Mundo() : totalDepredadores(0), totalPresas(0), totalVegetacion(0), dia(0) {
        for (int i = 0; i < FILAS; i++)
            for (int j = 0; j < COLUMNAS; j++)
                mapa[i][j] = '.';
    }

    // Agregar organismos por tipo
    void agregarDepredador(Depredador* d) {
        if (totalDepredadores < MAX_ORGANISMOS)
            depredadores[totalDepredadores++] = d;
    }

    void agregarPresa(Presa* p) {
        if (totalPresas < MAX_ORGANISMOS)
            presas[totalPresas++] = p;
    }

    void agregarVegetacion(Vegetacion* v) {
        if (totalVegetacion < MAX_ORGANISMOS)
            vegetaciones[totalVegetacion++] = v;
    }
    void actualizarMapa() {
        for (int i = 0; i < FILAS; i++)
            for (int j = 0; j < COLUMNAS; j++)
                mapa[i][j] = '.';

        for (int i = 0; i < totalVegetacion; i++)
            if (vegetaciones[i]->estaVivo())
                mapa[vegetaciones[i]->x][vegetaciones[i]->y] = 'V';

        for (int i = 0; i < totalPresas; i++)
            if (presas[i]->estaVivo())
                mapa[presas[i]->x][presas[i]->y] = 'P';

        for (int i = 0; i < totalDepredadores; i++)
            if (depredadores[i]->estaVivo())
                mapa[depredadores[i]->x][depredadores[i]->y] = 'D';
    }

    void mostrar() {
        actualizarMapa();

        cout << "DIA " << dia << endl;

        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++)
                cout << mapa[i][j] << " ";
            cout << endl;
        }
    }


    void avanzarDia() {
        dia++;

        // Vegetación
        for (int i = 0; i < totalVegetacion; i++)
            if (vegetaciones[i]->estaVivo())
                vegetaciones[i]->vivir();

        // Presas
        for (int i = 0; i < totalPresas; i++)
            if (presas[i]->estaVivo()) {
                presas[i]->mover();
                presas[i]->comer((Organismo**)vegetaciones, totalVegetacion);
                presas[i]->vivir();
            }

        // Depredadores
        for (int i = 0; i < totalDepredadores; i++)
            if (depredadores[i]->estaVivo()) {
                depredadores[i]->mover();
                depredadores[i]->comer((Organismo**)presas, totalPresas);
                depredadores[i]->vivir();
            }
    }
};

int main() {
    Mundo mundo;

    mundo.agregarVegetacion(new Vegetacion(0, 0));
    mundo.agregarVegetacion(new Vegetacion(4, 4));
    mundo.agregarPresa(new Presa(3, 2));
    mundo.agregarDepredador(new Depredador(0, 2));

    cout << "ESTADO INICIAL:\n";
    mundo.mostrar();

    for (int i = 1; i <= 3; i++) {
        mundo.avanzarDia();
        cout << "\nLuego del día " << i << ":\n";
        mundo.mostrar();
    }

    return 0;
}



