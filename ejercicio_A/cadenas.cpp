#include <iostream>
#include <string.h>
#include <string>
#include <conio.h>
#include <locale.h>
#include <Windows.h>
using namespace std;

void determinarLongitud(const char *cadena) {
    cout << "La longitud de la cadena es: " << strlen(cadena) << " caracteres." << endl;
}

void verificarSubcadena(const char *cadena, const char *subcadena) {
    if (strstr(cadena, subcadena) != NULL) {
        cout << "La subcadena '" << subcadena << "' se encuentra en la cadena." << endl;
    } else {
        cout << "La subcadena '" << subcadena << "' no se encuentra en la cadena." << endl;
    }
}

void anexarYComparar(char *cadena, const char *anexo) {
    char cadenaCopia[100];
    strcpy(cadenaCopia, cadena);

    strcat(cadenaCopia, " - ");
    strcat(cadenaCopia, anexo);

    cout << "Cadena resultante: " << cadenaCopia << endl;
    cout << "La longitud de la cadena resultante es: " << strlen(cadenaCopia) << " caracteres." << endl;
    cout << "La longitud de la cadena original es: " << strlen(cadena) << " caracteres." << endl;

    if (strlen(cadenaCopia) > strlen(cadena)) {
        cout << "La cadena resultante es más larga que la cadena original." << endl;
    } else {
        cout << "La cadena original es más larga que la cadena resultante." << endl;
    }
}

void verificarLetra(const char *cadena, char letra) {
    if (strchr(cadena, letra) != NULL) {
        cout << "La letra '" << letra << "' se encuentra en la cadena." << endl;
    } else {
        cout << "La letra '" << letra << "' no se encuentra en la cadena." << endl;
    }
}

void compararCadenas(const char *cadena1, const char *cadena2) {
    if (strcasecmp(cadena1, cadena2) == 0) {
        cout << "Las cadenas son iguales (ignorando mayúsculas/minúsculas)." << endl;
    } else {
        cout << "Las cadenas no son iguales." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "spanish");

    char palabra1[100] = "palabra";
    char parte[100];
    char otraCadena[100];
    char letra;
    char cadenaConstante[] = "Examen de EDA";

    cout << "Ingrese otra parte para anexar a 'palabra': ";
    cin.getline(parte, 100);
    //cin.ignore();
    strcat(palabra1, parte);
    cout << "Resultado -> palabra1 queda con: " << palabra1 << endl;

    int opcion;
    do {
        cout << "\nMenu de opciones:" << endl;
        cout << "\t1. Determinar la longitud de la cadena" << endl;
        cout << "\t2. Solicitar otra cadena y verificar si es una subcadena" << endl;
        cout << "\t3. Anexar otra cadena y comparar longitudes" << endl;
        cout << "\t4. Verificar si una letra está en la cadena" << endl;
        cout << "\t5. Comparar con la cadena 'Examen de EDA'" << endl;
        cout << "\t0. Salir" << endl;
        cout << "\nSeleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                determinarLongitud(palabra1);
                break;
            case 2:
                cout << "Ingrese otra cadena para verificar subcadena: ";
                cin.ignore();
                cin.getline(otraCadena, 100);
                verificarSubcadena(palabra1, otraCadena);
                break;
            case 3:
                cout << "Ingrese otra cadena para anexar: ";
                cin.ignore();
                cin.getline(otraCadena, 100);
                anexarYComparar(palabra1, otraCadena);
                break;
            case 4:
                cout << "Ingrese una letra para verificar: ";
                cin >> letra;
                verificarLetra(palabra1, letra);
                break;
            case 5:
                cout << "Ingrese una cadena para comparar con 'Examen de EDA': ";
                cin.ignore(); // Ignorar el salto de línea previo
                cin.getline(otraCadena, 100);
                compararCadenas(cadenaConstante, otraCadena);
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Inténtelo de nuevo." << endl;
        }
    } while (opcion != 0);

    getch();
    return 0;
}
