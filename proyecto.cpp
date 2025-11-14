#include <iostream>
using namespace std;

const int FILAS = 8;
const int COLUMNAS = 8;
const int MAX_ORGANISMOS = 10;

// funcion de aleatoriedad
int semilla = 123;
int aleatorio(int maximo) {
    semilla = (semilla * 1103515245 + 12345) % 2147483648;
    return semilla % maximo;
}

int pasoAleatorio() {
    return aleatorio(3) - 1;  // da -1, 0 o 1
}

void movimientoAleatorio(int &x, int &y) {
    int dx = pasoAleatorio();
    int dy = pasoAleatorio();

    x += dx;
    y += dy;

    // Limitar dentro del mapa
    if (x < 0) x = 0;
    if (x >= FILAS) x = FILAS - 1;
    if (y < 0) y = 0;
    if (y >= COLUMNAS) y = COLUMNAS - 1;
}


class Organismo {
public:
    int x, y;
    int vida;
    Organismo(int px = 0, int py = 0, int pvida = 15) : x(px), y(py), vida(pvida) {}

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
    void mover() override {
    }

};

class Presa : public Organismo {
public:
    Presa(int px, int py) : Organismo(px, py, 6) {}
    char simbolo() const { return 'P'; }
    void mover() override {
        movimientoAleatorio(x,y);
    }
    void comer(Organismo* otros[], int cantidad){
        for (int i=0; i < cantidad;i++){
            Vegetacion* v = dynamic_cast < Vegetacion*>(otros[i]);
            if (v && v->estaVivo() &&
            v->x == x && v->y == y)
        {
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
        movimientoAleatorio(x,y);
    }
    void comer(Organismo* otros[], int cantidad){
        for (int i=0; i < cantidad;i++){
            Presa* p = dynamic_cast < Presa*>(otros[i]);
            if (p && p->estaVivo() &&
            p->x == x && p->y == y)
        {
            vida += 5;
            p->vida = 0;
            return;
        }
    }
    }

};


class Mundo {
private:
    Organismo* organismos[MAX_ORGANISMOS];
    int cantidad;
    char mapa[FILAS][COLUMNAS];
    int dia;

public:
    Mundo() : cantidad(0), dia(0) {
        // Inicializa el mapa vacío
        for (int i= 0;i < FILAS; i++)
            for (int j= 0; j <COLUMNAS; j++)
                mapa[i][j] = '.';
    }

    void agregar(Organismo* o) {
        if (cantidad < MAX_ORGANISMOS)
            organismos[cantidad++] = o;
    }

    void actualizarMapa() {
        // Limpia el mapa
        for (int i = 0; i < FILAS; i++)
            for (int j = 0; j < COLUMNAS; j++)
                mapa[i][j] = '.';

        // Coloca los organismos en sus posiciones
        for (int i =0;i< cantidad; i++) {
            if (organismos[i]->estaVivo()) {
                int x = organismos[i]->x;
                int y = organismos[i]->y;
                mapa[x][y] = organismos[i]->simbolo();

            }
        }
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
        dia++; // incrementa el tiempo del mundo

        for (int i= 0; i <cantidad; i++) {
            if (organismos[i]->estaVivo()) {
                organismos[i]->mover();
                organismos[i]->comer(organismos, cantidad);
                organismos[i]->vivir();
            }
        }
    }

    int getDia() const {
        return dia;
    }
};


int main() {
    Mundo mundo;

    // Crear organismos
    Vegetacion v1(0, 0);
    Vegetacion v2(4, 4);
    Presa p1(3, 2);
    Depredador d1(0, 2);

    // Agregar al mundo
    mundo.agregar(&v1);
    mundo.agregar(&v2);
    mundo.agregar(&p1);
    mundo.agregar(&d1);

    cout << "ESTADO INICIAL DE CHILL:" << endl;
    mundo.mostrar();
    cout << endl;

    // Avanzar hasta el día 3
    for (int i = 1; i <= 3; i++) {
        mundo.avanzarDia();
        cout << "\nLuego del dia " << i << ":" << endl;
        mundo.mostrar();
    }

    return 0;
}





