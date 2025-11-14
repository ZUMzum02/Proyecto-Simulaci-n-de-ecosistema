#include <iostream>
#include <cstring>
using namespace std;

class Interfaz {
public:

    // ==================================================================
    // Imprime una línea dentro del marco ****** ... ******
    // ==================================================================
    static void imprimirLinea(const char contenido[]) {
        int total = 76; 
        int longitud = strlen(contenido);
        int espacios = total - longitud;
        if (espacios < 0) espacios = 0;

        cout << "****** " << contenido;
        for (int i = 0; i < espacios; i++) cout << " ";
        cout << " ******\n";
    }

    // ==================================================================
    // Muestra el menú dentro del marco ASCII
    // ==================================================================
    static void mostrar(const char* opciones[], int cantidad, const char titulo[]) {
        system("clear"); // o system("cls") en Windows

        cout << "   /***********\n\n";
        cout << "************************************************************************************\n";
        cout << "************************************************************************************\n";

        imprimirLinea(" ");
        imprimirLinea(titulo);
        imprimirLinea(" ");

        for (int i = 0; i < cantidad; i++) {
            char linea[120] = "";
            char num[10];

            sprintf(num, "[%d] ", i + 1);
            strcat(linea, num);
            strcat(linea, opciones[i]);

            imprimirLinea(linea);
            imprimirLinea(" ");
        }

        cout << "************************************************************************************\n";
        cout << "************************************************************************************\n";
    }

    // ==================================================================
    // Leer opción ingresada
    // ==================================================================
    static int leerOpcion(int max) {
        int op;
        cout << "\nSeleccione una opcion: ";
        cin >> op;
        return op;
    }
};

// ======================================================================
//              MENÚS ANIDADOS (USANDO SOLO ARRAYS)
// ======================================================================

void menuOrganismos();

// ---------------------------- MENÚ PRINCIPAL ---------------------------
void menuPrincipal() {
    const char* opciones[] = {
        "Organismos",
        "Estadisticas",
        "Configuracion",
        "Salir"
    };
    int n = 4;

    while (true) {
        Interfaz::mostrar(opciones, n, "MENU PRINCIPAL");
        int op = Interfaz::leerOpcion(n);

        switch (op) {
            case 1: menuOrganismos(); break;
            case 2:
                cout << "Mostrando estadisticas...\n";
                cin.get(); cin.get();
                break;
            case 3:
                cout << "Configuracion...\n";
                cin.get(); cin.get();
                break;
            case 4:
                exit(0);
        }
    }
}

// ---------------------------- MENÚ ORGANISMOS --------------------------
void menuOrganismos() {
    const char* opciones[] = {
        "Listar todos",
        "Buscar organismo",
        "Historial",
        "Volver"
    };
    int n = 4;

    while (true) {
        Interfaz::mostrar(opciones, n, "MENU ORGANISMOS");
        int op = Interfaz::leerOpcion(n);

        switch (op) {
            case 1:
                cout << "Listando organismos...\n";
                cin.get(); cin.get();
                break;
            case 2:
                cout << "Buscando organismo...\n";
                cin.get(); cin.get();
                break;
            case 3:
                cout << "Mostrando historial...\n";
                cin.get(); cin.get();
                break;
            case 4:
                return; // volver al menú principal
        }
    }
}

// ======================================================================
//                                   MAIN
// ======================================================================
int main() {
    menuPrincipal();
    return 0;
}

