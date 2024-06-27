#include <iostream>
#include <queue>
#include <conio.h>
#include <locale.h>
using namespace std;

enum rol
{
    RECOLECTORA,
    EXCAVADORA,
    CRIADORA
};
enum tam
{
    CHICA,
    MEDIANA,
    GRANDE
};

struct Hormiga
{
    tam tamanyo;
    rol tipo;
    bool recolecto;

    void crearHormiga()
    {
        int t, r;
        cout << "Selecciona el tamaño (0: CHICA, 1: MEDIANA, 2: GRANDE): ";
        cin >> t;
        tamanyo = static_cast<tam>(t);

        cout << "Selecciona el tipo (0: RECOLECTORA, 1: EXCAVADORA, 2: CRIADORA): ";
        cin >> r;
        tipo = static_cast<rol>(r);

        cout << "¿Recolectó hoja? (1: Sí, 0: No): ";
        cin >> recolecto;
    }
};

queue<Hormiga> senderoA;
queue<Hormiga> senderoB;
queue<Hormiga> senderoC;

void derivarASenderoA(Hormiga h)
{
    senderoA.push(h);
}

void derivarASenderoBoC()
{
    if (senderoA.empty())
    {
        cout << "El sendero A está vacío." << endl;
        return;
    }

    Hormiga h = senderoA.front();
    senderoA.pop();

    if (h.tipo == RECOLECTORA && h.recolecto)
    {
        senderoB.push(h);
    }
    else
    {
        senderoC.push(h);
    }
}

void derivarDeSenderoBaA()
{
    if (senderoB.empty())
    {
        cout << "El sendero B está vacío." << endl;
        return;
    }

    Hormiga h = senderoB.front();
    senderoB.pop();
    h.recolecto = false;
    senderoA.push(h);
}

void mostrarYVaciarSenderoC()
{
    while (!senderoC.empty())
    {
        Hormiga h = senderoC.front();
        cout << "Hormiga:\n Tipo: " << h.tipo << ",\n Tamaño: " << h.tamanyo << ",\n Recolectó: " << (h.recolecto ? "Sí" : "No") << endl;
        senderoC.pop();
    }
}

int main()
{
    setlocale(LC_ALL, "spanish");

    int op;

    do
    {
        cout << endl << endl;
        cout << "Selecciona una opción: " << endl;
        cout << "  0_ Salir" << endl;
        cout << "  1_ Crear hormiga" << endl;
        cout << "  2_ Cargar hormiga a sendero A" << endl;
        cout << "  3_ Derivar a sendero B o C" << endl;
        cout << "  4_ Quitar hoja, regresar del sendero B a A" << endl;
        cout << "  5_ Mostrar y vaciar sendero C" << endl;
        cin >> op;

        switch (op)
        {
        case 0:
            cout << "Saliendo del programa, presiona una tecla para salir..." << endl;
            break;
        case 1:
        {
            Hormiga h;
            h.crearHormiga();
            cout << "Hormiga creada." << endl;
            derivarASenderoA(h);
            break;
        }
        case 2:
            cout << "Las hormigas se crean y se cargan automáticamente en el sendero A al ser creadas." << endl;
            break;
        case 3:
            derivarASenderoBoC();
            cout << "Hormiga derivada a sendero B o C." << endl;
            break;
        case 4:
            derivarDeSenderoBaA();
            cout << "Hormiga regresada de sendero B a A." << endl;
            break;
        case 5:
            mostrarYVaciarSenderoC();
            cout << "Mostrando y vaciando sendero C." << endl;
            break;
        default:
            cout << "No has ingresado una opción válida, inténtalo de nuevo." << endl;
            break;
        }
    } while (op != 0);

    getch();
    return 0;
}
