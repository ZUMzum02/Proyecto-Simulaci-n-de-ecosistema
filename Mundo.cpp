#include "Mundo.h"
#include "Utils.h"
#include <iostream>

Mundo::Mundo(int f, int c) : filas(f), columnas(c), total(0), capacity(64), dia(0) {
    grid = new Organismo**[filas];
    for (int i = 0; i < filas; i++) {
        grid[i] = new Organismo*[columnas];
        for (int j = 0; j < columnas; j++) grid[i][j] = nullptr;
    }
    lista = new Organismo*[capacity];
}

Mundo::~Mundo() {
    for (int i = 0; i < filas; i++) delete[] grid[i];
    delete[] grid;
    for (int i = 0; i < total; i++) delete lista[i];
    delete[] lista;
}

void Mundo::ensureCapacity() {
    if (total < capacity) return;
    int ncap = capacity * 2;
    Organismo** nlist = new Organismo*[ncap];
    for (int i = 0; i < total; i++) nlist[i] = lista[i];
    delete[] lista;
    lista = nlist;
    capacity = ncap;
}

bool Mundo::enRango(int x, int y) const {
    return x >= 0 && x < filas && y >= 0 && y < columnas;
}

void Mundo::colocarEnGrid(Organismo* o) {
    if (!o) return;
    int x = o->getX(), y = o->getY();
    if (!enRango(x, y)) return;
    grid[x][y] = o;
}

void Mundo::removerDeGrid(Organismo* o) {
    if (!o) return;
    int x = o->getX(), y = o->getY();
    if (!enRango(x, y)) return;
    if (grid[x][y] == o) grid[x][y] = nullptr;
}

void Mundo::agregarOrganismo(Organismo* o) {
    ensureCapacity();
    lista[total++] = o;
    colocarEnGrid(o);
}

// buscar casilla vecina libre alrededor (cx,cy)
bool buscarVecinaLibre(int cx, int cy, int filas, int columnas, Organismo*** grid, int &outX, int &outY) {
    const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int k=0;k<4;k++) {
        int nx = cx + dirs[k][0];
        int ny = cy + dirs[k][1];
        if (nx<0||nx>=filas||ny<0||ny>=columnas) continue;
        if (grid[nx][ny] == nullptr) { outX = nx; outY = ny; return true; }
    }
    return false;
}

void Mundo::avanzarDia() {
    dia++;

    // actualizar vegetacion
    for (int i = 0; i < total; i++) {
        Vegetacion* v = dynamic_cast<Vegetacion*>(lista[i]);
        if (v) v->actualizar();
        if (v && v->esVegetacionActiva()) colocarEnGrid(v);
    }

    // mover y comer (presas first)
    for (int i = 0; i < total; i++) {
        Organismo* o = lista[i];
        if (!o || !o->getVida()) continue;
        removerDeGrid(o);
       o->mover();
        
        if (!enRango(o->getX(), o->getY())) {
            // clamp to valid
            int nx = o->getX(); int ny = o->getY();
            if (nx<0) nx=0; if (nx>=filas) nx=filas-1;
            if (ny<0) ny=0; if (ny>=columnas) ny=columnas-1;
            o->setPos(nx, ny);
        }

        colocarEnGrid(o);

        // comer logic
        Presa* p = dynamic_cast<Presa*>(o);
        if (p) p->comer((Organismo**)lista, total);
        Depredador* d = dynamic_cast<Depredador*>(o);
        if (d) d->comer((Organismo**)lista, total);

        o->actualizar();
    }

    // reproducción por proximidad (presas/depredadores)
    for (int i = 0; i < total; i++) {
        for (int j = i+1; j < total; j++) {
            Organismo* a = lista[i]; Organismo* b = lista[j];
            if (!a || !b) continue;
            if (!a->getVida() || !b->getVida()) continue;
            if (a->simbolo() != b->simbolo()) continue;
            int dx = abs(a->getX() - b->getX());
            int dy = abs(a->getY() - b->getY());
            if (dx + dy != 1) continue;

           
            if (a->getCooldown() > 0 || b->getCooldown() > 0) continue;

            int outX=-1, outY=-1;
            if (!buscarVecinaLibre(a->getX(), a->getY(), filas, columnas, grid, outX, outY)) continue;

            if (a->simbolo() == 'P') {
                Presa* baby = new Presa(outX, outY);
                agregarOrganismo(baby);
                a->setCooldown(3); b->setCooldown(3);
                colocarEnGrid(baby);
            } else if (a->simbolo() == 'D') {
                Depredador* baby = new Depredador(outX, outY);
                agregarOrganismo(baby);
                a->setCooldown(5); b->setCooldown(5);
                colocarEnGrid(baby);
            }
        }
    }

   
    for (int i = 0; i < total; i++) {
        if (lista[i] && lista[i]->getVida() <= 0) {
            removerDeGrid(lista[i]);
        }
    }
}

void Mundo::mostrar() const {
    /****
    char mapa[8][8];
    for (int i=0;i<filas;i++) for (int j=0;j<columnas;j++) mapa[i][j]='.';
    for (int i=0;i<total;i++) {
        Organismo* o = lista[i];
        if (!o || o->getVida()<=0) continue;
        int x = o->getX(), y = o->getY();
        if (x>=0 && x<filas && y>=0 && y<columnas) mapa[x][y] = o->simbolo();
    }
    std::cout << "DIA " << dia << "\n";
    for (int r=0;r<filas;r++) {
        for (int c=0;c<columnas;c++) std::cout << mapa[r][c] << ' ';
        std::cout << '\n';
    }
    ***/
    char mapa[8][8];

    // Inicializar mapa con '.'
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            mapa[i][j] = '.';

    // Colocar organismos
    for (int i = 0; i < total; i++) {
        Organismo* o = lista[i];
        if (!o || o->getVida() <= 0) continue;

        int x = o->getX(), y = o->getY();
        if (x >= 0 && x < filas && y >= 0 && y < columnas)
            mapa[x][y] = o->simbolo();
    }

    // ====== MARCO DEL MENU ======
    std::cout << "**************************************************\n";
    std::cout << "**           SISTEMA DE RESERVA                 **\n";
    std::cout << "**           NATURAL ECOMUNDO                   **\n";
    std::cout << "**           ================                   **\n";
    std::cout << "**                                              **\n";
    std::cout << "**              SIMULACION DEL MUNDO            **\n";
    std::cout << "**                                              **\n";

    // Mostrar día (sin usar iomanip)
    std::string dstr = std::to_string(dia);
    std::cout << "**   DIA " << dstr;

    int usados = 8 + dstr.size(); // letras ya impresas
    int totalEsp = 46;
    for (int i = usados; i < totalEsp; i++) std::cout << " ";
    std::cout << "**\n";

    // Imprimir mapa dentro del marco
    for (int r = 0; r < filas; r++) {
        std::cout << "**   ";
        for (int c = 0; c < columnas; c++)
            std::cout << mapa[r][c] << ' ';

        int usadosFila = 4 + columnas * 2;
        for (int i = usadosFila; i < totalEsp; i++) std::cout << " ";

        std::cout << "**\n";
    }

    std::cout << "**                                              **\n";
    std::cout << "**************************************************\n";
}
