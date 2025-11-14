#include <iostream>
using namespace std;

const int FILAS = 5;
const int COLUMNAS = 5;
const int MAX_ORGANISMOS = 10;

// funcion de aleatoriedad 
int semilla = 123; 
int aleatorio(int maximo) {
    semilla = (semilla * 1103515245 + 12345) % 2147483648;
    return semilla % maximo;
}


class Organismo {
public:
    int x, y;
    int vida;
    Organismo(int px = 0, int py = 0, int pvida = 5) : x(px), y(py), vida(pvida) {}

    virtual char simbolo() const = 0;
    virtual void mover(int filas, int columnas) = 0;
    // virtual void comer() {}
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
    void mover(int filas, int columnas) {}

};

class Presa : public Organismo {
public:
    Presa(int px, int py) : Organismo(px, py, 6) {}
    char simbolo() const { return 'P'; }
    void mover(int filas, int columnas) {
    y++;
    if (y >= columnas) y = 0;
}

};

class Depredador : public Organismo {
public:
    Depredador(int px, int py) : Organismo(px, py, 8) {}
    char simbolo() const { return 'D'; }
    void mover(int filas, int columnas) {
    x++;
    if (x >= filas) x = 0;
}

};

class Mundo {
private:
    Organismo* organismos[MAX_ORGANISMOS];
    int cantidad;
    char mapa[FILAS][COLUMNAS];
public:
    Mundo() {
        cantidad = 0;
        for (int i = 0; i < FILAS; i++)
            for (int j = 0; j < COLUMNAS; j++)
                mapa[i][j] = '.';
    }

    void agregar(Organismo* o) {
        if (cantidad < MAX_ORGANISMOS)
            organismos[cantidad++] = o;
    }

    void actualizarMapa() {
        for (int i = 0; i < FILAS; i++)
            for (int j = 0; j < COLUMNAS; j++)
                mapa[i][j] = '.';

        for (int i = 0; i < cantidad; i++) {
            if (organismos[i]->estaVivo()) {
                int x = organismos[i]->x;
                int y = organismos[i]->y;
                if (x >= 0 && x < FILAS && y >= 0 && y < COLUMNAS)
                    mapa[x][y] = organismos[i]->simbolo();
            }
        }
    }

    void mostrar() {
        actualizarMapa();
        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++)
                cout << mapa[i][j] << " ";
            cout << endl;
        }
    }
    void avanzarDia() {
    for (int i = 0; i < cantidad; i++) {
        if (organismos[i]->estaVivo()) {
            organismos[i]->mover(FILAS, COLUMNAS);
            organismos[i]->vivir();
        }
    }
}
};


int main() {
    Mundo mundo;

    Vegetacion v1(0, 0);
    Vegetacion v2(4, 4);
    Presa p1(1, 2);
    Depredador d1(3, 1);

    mundo.agregar(&v1);
    mundo.agregar(&v2);
    mundo.agregar(&p1);
    mundo.agregar(&d1);

    cout << "MUNDO DE CHILL: " << endl;
    mundo.mostrar();

    return 0;
}

