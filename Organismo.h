#pragma once

class DatosOrganismo; // forward

class Organismo {
protected:
    int x, y;
    int vida;
    int cooldown;

public:
    Organismo(int px = 0, int py = 0, int pvida = 1);
    virtual ~Organismo();

    int getX() const;
    int getY() const;
    int getVida() const;
    int getCooldown() const;

    void setPos(int nx, int ny);
    void setVida(int v);
    void setCooldown(int c);
    
    virtual char simbolo() const = 0;
    virtual void mover();
    virtual void comer(Organismo* lista[], int cantidad);
    virtual void actualizar();
    virtual bool esVegetacionActiva() const;
    bool estaVivo() const { return vida > 0; }

};
