#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <locale.h>
#include <conio.h>
using namespace std;

struct Auto
{
    char modelo[20];
    char patente[20];
};
Auto auto1 = {"Vento", "AZ 234 RT"};
Auto auto2 = {"Cronos", "AS 459 GT"};

queue<Auto> Via0;
queue<Auto> Via1;

void insertarV0(Auto auto1)
{
    if (Via0.size() < 5)
    {
        Via0.push(auto1);
        cout << "Ingreso a Via0(via comun), vehiculo: " << auto1.modelo << ", " << auto1.patente << endl;
    }
    else
    {
        cout << "Via0 está llena." << endl;
    }
}

void insertarV1(Auto auto2)
{
    if (Via1.size() < 5)
    {
        Via1.push(auto2);
        cout << "Ingreso a Via1(via rapida), vehiculo: " << auto2.modelo << ", " << auto2.patente << endl;
    }
    else
    {
        cout << "Via1 está llena." << endl;
    }
}

void suprimirV0()
{
    if (!Via0.empty())
    {
        cout << "Egreso de Via0(via comun), vehiculo: " << Via0.front().modelo << ", " << Via0.front().patente << endl;
        Via0.pop();
    }
    else
    {
        cout << "Via0 está vacía." << endl;
    }
}

void suprimirV1()
{
    if (!Via1.empty())
    {
        cout << "Egreso de Via1(via rapida), vehiculo: " << Via1.front().modelo << ", " << Via1.front().patente << endl;
        Via1.pop();
    }
    else
    {
        cout << "Via1 está vacía." << endl;
    }
}

int main()
{

    insertarV0(auto1);
    insertarV1(auto2);
    cout << endl;
    suprimirV1();
    suprimirV0();

    getch();
    return 0;
}
