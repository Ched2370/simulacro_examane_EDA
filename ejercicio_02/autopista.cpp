#include <iostream>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

// Definición de la estructura Auto
struct Auto {
    char modelo[20];
    char patente[20];
};
    Auto auto1 = {"vento", "AZ 234 RT"};
 

    Auto auto2 = {"Cronos", "AS 459 GT"};
    
// Dos colas para las dos vías
queue<Auto> Via0;
queue<Auto> Via1;

// Funciones para insertar en las vías
void insertarV0(Auto auto1) {
    if (Via0.size() < 5) { // Verificar si hay espacio en Via0
        Via0.push(auto1);
        cout << "Vehículo ingresado en Via0: " << auto1.modelo << ", " << auto1.patente << endl;
    } else {
        cout << "Via0 está llena." << endl;
    }
}

void insertarV1( Auto auto2) {
    if (Via1.size() < 5) { // Verificar si hay espacio en Via1
        Via1.push(auto2);
        cout << "Vehículo ingresado en Via1: " << auto2.modelo << ", " << auto2.patente << endl;
    } else {
        cout << "Via1 está llena." << endl;
    }
}

// Funciones para suprimir de las vías
void suprimirV0() {
    if (!Via0.empty()) {
        Via0.front();
        cout << "Vehículo eliminado de Via0: "<< endl;
        Via0.pop();
    } else {
        cout << "Via0 está vacía." << endl;
    }
}

void suprimirV1() {
    if (!Via1.empty()) {
       Via1.front();
        cout << "Vehículo eliminado de Via1: " << endl;
        Via1.pop();
    } else {
        cout << "Via1 está vacía." << endl;
    }
}

int main() {
   

    insertarV0(auto1);
    insertarV1(auto2);

    suprimirV0();
    suprimirV1();

    return 0;
}
