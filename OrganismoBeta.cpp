#include "OrganismoBeta.h"
#include <iostream>

OrganismoBeta::OrganismoBeta()
    : x(0), y(0), vivo(true), energia(100),
      nombre("SinNombre"),
      especie("Desconocida"), edad(0), peligrosidad("Media"),
      alimentacion("Desconocida"), habitat("Desconocido"),
      peso(0.0f), tamano(0.0f), salud("Normal"),
      nivelAmenaza(0), descripcion("Sin descripcion")
{

}

OrganismoBeta::OrganismoBeta(const myString& nombre_)
    : x(0), y(0), vivo(true), energia(100),
      nombre(nombre_)
{
    asignarDatosPorNombre();
}

OrganismoBeta::OrganismoBeta(int x_, int y_, const myString& nombre_)
    : x(x_), y(y_), vivo(true), energia(100),
      nombre(nombre_)
{
    asignarDatosPorNombre();
}

OrganismoBeta::~OrganismoBeta() {}

void OrganismoBeta::asignarDatosPorNombre() {
    // Valores por defecto
    especie = myString("Desconocida");
    edad = 1;
    peligrosidad = myString("Desconocida");
    alimentacion = myString("Desconocida");
    habitat = myString("Desconocido");
    peso = 1.0f;
    tamano = 0.1f;
    salud = myString("Normal");
    nivelAmenaza = 0;
    descripcion = myString("Sin descripcion");

    // DEPREDADORES (10)

    if (nombre == "Leon") {
        especie = myString("Panthera leo");
        edad = 8;
        peligrosidad = myString("Alta");
        alimentacion = myString("Carnivoro");
        habitat = myString("Sabana");
        peso = 190.0f;
        tamano = 1.2f;
        salud = myString("Buena");
        nivelAmenaza = 5;
        descripcion = myString("Depredador tope, estrategico y social.");
    }

    else if (nombre == "Tigre") {
        especie = myString("Panthera tigris");
        edad = 10;
        peligrosidad = myString("Muy alta");
        alimentacion = myString("Carnivoro");
        habitat = myString("Selva y bosques");
        peso = 220.0f;
        tamano = 1.1f;
        salud = myString("Fuerte");
        nivelAmenaza = 5;
        descripcion = myString("Depredador solitario, sigiloso y poderoso.");
    }

    else if (nombre == "Oso") {
        especie = myString("Ursidae");
        edad = 15;
        peligrosidad = myString("Alta");
        alimentacion = myString("Omnivoro");
        habitat = myString("Bosques");
        peso = 300.0f;
        tamano = 1.5f;
        salud = myString("Robusta");
        nivelAmenaza = 4;
        descripcion = myString("Gran fuerza fisica y resistencia.");
    }

    else if (nombre == "Cocodrilo") {
        especie = myString("Crocodylidae");
        edad = 40;
        peligrosidad = myString("Muy alta");
        alimentacion = myString("Carnivoro");
        habitat = myString("Rios y pantanos");
        peso = 500.0f;
        tamano = 2.5f;
        salud = myString("Excelente");
        nivelAmenaza = 5;
        descripcion = myString("Depredador de emboscada con mordida letal.");
    }

    else if (nombre == "Jaguar") {
        especie = myString("Panthera onca");
        edad = 12;
        peligrosidad = myString("Alta");
        alimentacion = myString("Carnivoro");
        habitat = myString("Selva");
        peso = 100.0f;
        tamano = 0.8f;
        salud = myString("Buena");
        nivelAmenaza = 4;
        descripcion = myString("Cazador silencioso con mordida muy poderosa.");
    }

    else if (nombre == "Aguila") {
        especie = myString("Accipitridae");
        edad = 7;
        peligrosidad = myString("Media");
        alimentacion = myString("Carnivoro");
        habitat = myString("Montanas");
        peso = 6.0f;
        tamano = 0.9f;
        salud = myString("Buena");
        nivelAmenaza = 3;
        descripcion = myString("Cazador aereo con gran vision.");
    }

    else if (nombre == "Zorro") {
        especie = myString("Vulpes vulpes");
        edad = 6;
        peligrosidad = myString("Media");
        alimentacion = myString("Omnivoro");
        habitat = myString("Bosques y praderas");
        peso = 7.0f;
        tamano = 0.4f;
        salud = myString("Normal");
        nivelAmenaza = 2;
        descripcion = myString("Agil, astuto y oportunista.");
    }

    else if (nombre == "Caiman") {
        especie = myString("Caimaninae");
        edad = 25;
        peligrosidad = myString("Alta");
        alimentacion = myString("Carnivoro");
        habitat = myString("Pantanos y rios");
        peso = 200.0f;
        tamano = 1.5f;
        salud = myString("Fuerte");
        nivelAmenaza = 4;
        descripcion = myString("Reptil de emboscada, veloz bajo el agua.");
    }

    else if (nombre == "Anaconda") {
        especie = myString("Eunectes murinus");
        edad = 20;
        peligrosidad = myString("Alta");
        alimentacion = myString("Carnivoro");
        habitat = myString("Rios y selva humeda");
        peso = 250.0f;
        tamano = 5.0f;
        salud = myString("Excelente");
        nivelAmenaza = 4;
        descripcion = myString("Serpiente constrictora de gran tamaño.");
    }

    else if (nombre == "Mantis") {
        especie = myString("Mantodea");
        edad = 1;
        peligrosidad = myString("Baja");
        alimentacion = myString("Insectivoro");
        habitat = myString("Bosques y praderas");
        peso = 0.02f;
        tamano = 0.10f;
        salud = myString("Normal");
        nivelAmenaza = 1;
        descripcion = myString("Depredador pequeño pero preciso y veloz.");
    }

    // PRESAS (10)

    else if (nombre == "Guacamayo") {
        especie = myString("Ara macao");
        edad = 4;
        peligrosidad = myString("Nula");
        alimentacion = myString("Frugivoro");
        habitat = myString("Selva");
        peso = 1.2f;
        tamano = 0.9f;
        salud = myString("Buena");
        nivelAmenaza = 0;
        descripcion = myString("Ave colorida y ruidosa, muy social.");
    }

    else if (nombre == "Capibara") {
        especie = myString("Hydrochoerus hydrochaeris");
        edad = 5;
        peligrosidad = myString("Nula");
        alimentacion = myString("Herbivoro");
        habitat = myString("Humedales");
        peso = 60.0f;
        tamano = 0.5f;
        salud = myString("Buena");
        nivelAmenaza = 0;
        descripcion = myString("Roedor gigante, muy tranquilo.");
    }

    else if (nombre == "Rana") {
        especie = myString("Anura");
        edad = 1;
        peligrosidad = myString("Nula");
        alimentacion = myString("Insectivoro");
        habitat = myString("Humedales");
        peso = 0.1f;
        tamano = 0.05f;
        salud = myString("Normal");
        nivelAmenaza = 0;
        descripcion = myString("Pequena y vulnerable, gran salto.");
    }

    else if (nombre == "Mariposa") {
        especie = myString("Lepidoptera");
        edad = 1;
        peligrosidad = myString("Nula");
        alimentacion = myString("Nectarivoro");
        habitat = myString("Bosques y praderas");
        peso = 0.01f;
        tamano = 0.02f;
        salud = myString("Fragil");
        nivelAmenaza = 0;
        descripcion = myString("Insecto delicado, colorido y polinizador.");
    }

    else if (nombre == "Conejo") {
        especie = myString("Oryctolagus cuniculus");
        edad = 2;
        peligrosidad = myString("Nula");
        alimentacion = myString("Herbivoro");
        habitat = myString("Praderas");
        peso = 2.5f;
        tamano = 0.4f;
        salud = myString("Buena");
        nivelAmenaza = 0;
        descripcion = myString("Rapido y nervioso, presa comun.");
    }

    else if (nombre == "Antilope") {
        especie = myString("Bovidae");
        edad = 6;
        peligrosidad = myString("Nula");
        alimentacion = myString("Herbivoro");
        habitat = myString("Sabana");
        peso = 70.0f;
        tamano = 1.0f;
        salud = myString("Buena");
        nivelAmenaza = 0;
        descripcion = myString("Rapido, alerta, buen corredor.");
    }

    else if (nombre == "Tapir") {
        especie = myString("Tapirus terrestris");
        edad = 8;
        peligrosidad = myString("Baja");
        alimentacion = myString("Herbivoro");
        habitat = myString("Selva humeda");
        peso = 250.0f;
        tamano = 1.0f;
        salud = myString("Buena");
        nivelAmenaza = 1;
        descripcion = myString("Grande pero pacifico, buen nadador.");
    }

    else if (nombre == "Aguti") {
        especie = myString("Dasyprocta");
        edad = 3;
        peligrosidad = myString("Nula");
        alimentacion = myString("Herbivoro");
        habitat = myString("Selva");
        peso = 3.0f;
        tamano = 0.3f;
        salud = myString("Normal");
        nivelAmenaza = 0;
        descripcion = myString("Roedor veloz y atento.");
    }

    else if (nombre == "Tucan") {
        especie = myString("Ramphastos");
        edad = 3;
        peligrosidad = myString("Nula");
        alimentacion = myString("Frugivoro");
        habitat = myString("Selva");
        peso = 0.6f;
        tamano = 0.5f;
        salud = myString("Buena");
        nivelAmenaza = 0;
        descripcion = myString("Ave tropical de pico grande.");
    }

    else if (nombre == "Camaleon") {
        especie = myString("Chamaeleonidae");
        edad = 3;
        peligrosidad = myString("Nula");
        alimentacion = myString("Insectivoro");
        habitat = myString("Bosques");
        peso = 0.2f;
        tamano = 0.25f;
        salud = myString("Normal");
        nivelAmenaza = 0;
        descripcion = myString("Reptil capaz de camuflarse.");
    }
}


myString OrganismoBeta::getNombre() const { return nombre; }
int OrganismoBeta::getX() const { return x; }
int OrganismoBeta::getY() const { return y; }
bool OrganismoBeta::estaVivo() const { return vivo; }
int OrganismoBeta::getEnergia() const { return energia; }

void OrganismoBeta::setPos(int nx, int ny) { x = nx; y = ny; }
void OrganismoBeta::setVivo(bool v) { vivo = v; }
void OrganismoBeta::setEnergia(int e) { energia = e; }

myString OrganismoBeta::getEspecie() const { return especie; }
int OrganismoBeta::getEdad() const { return edad; }
myString OrganismoBeta::getPeligrosidad() const { return peligrosidad; }
myString OrganismoBeta::getAlimentacion() const { return alimentacion; }
myString OrganismoBeta::getHabitat() const { return habitat; }
float OrganismoBeta::getPeso() const { return peso; }
float OrganismoBeta::getTamano() const { return tamano; }
myString OrganismoBeta::getSalud() const { return salud; }
int OrganismoBeta::getNivelAmenaza() const { return nivelAmenaza; }
myString OrganismoBeta::getDescripcion() const { return descripcion; }

void OrganismoBeta::mostrarDatos() const {

}
