#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

// Definiendo estructura Fecha
struct Fecha {
	int dia;
	int mes;
	int anio;
};

// Definiendo estructura Persona
struct Persona {
	char nombre[21];
	int edad;
	float peso;
	Fecha fechaNacimiento;
};

// Definiendo estructura Empleado
struct Empleado {
	Persona persona;
	float salario;
	Fecha fechaContratacion;
};

// Creando las funciones
void imprimirPersona(const Persona &p) {
	cout << "Nombre: " << p.nombre << endl;
	cout << "Edad: " << p.edad << endl;
	cout << "Peso: " << p.peso << endl;
	cout << "Edad: " << p.fechaNacimiento.dia << "/"
		<< p.fechaNacimiento.mes << "/" << p.fechaNacimiento.anio << endl;
}

void imprimirEmpleado(const Empleado &e) {
	imprimirPersona(e.persona);
	cout << "Salario: $" << e.salario << endl;
	cout << "Fecha de contratacion: " << e.fechaContratacion.dia << "/"
		<< e.fechaContratacion.mes << "/" << e.fechaContratacion.anio << endl;
}


int main(int argc, char** argv) {
	
	// Creando y precargando los datos
	Persona veronica;
	strcpy(veronica.nombre, "Veronica");
	veronica.edad = 20;
	veronica.peso = 45.0;
	veronica.fechaNacimiento = {2, 12, 1997};
	
	Empleado esteban;
	strcpy(esteban.persona.nombre, "Esteban");
	esteban.persona.edad = 19;
	esteban.persona.peso = 60.0;
	esteban.persona.fechaNacimiento = {22, 7, 1998};
	esteban.salario = 351667.19;
	esteban.fechaContratacion = {1, 6, 2024};
	
	// Mostrando datos de Veronica y Esteban
	cout << "Datos de Veronica: " << endl;
	imprimirPersona(veronica);
	cout << endl;
	
	cout << "Datos de Esteban: " << endl;
	imprimirEmpleado(esteban);
	cout << endl;
	
	// Creando array de empleados y cargar los datos
	Empleado trabajadores[3];
	trabajadores[0] = esteban;
	
	// Cargando datos de otros empleados
	Empleado trabajador1;
	strcpy(trabajador1.persona.nombre, "Carlos");
	trabajador1.persona.edad = 25;
	trabajador1.persona.peso = 70.0;
	trabajador1.persona.fechaNacimiento = {15, 8, 1998};
	trabajador1.salario = 450000.00;
	trabajador1.fechaContratacion = {1, 3, 2023};
	
	Empleado trabajador2;
	strcpy(trabajador2.persona.nombre, "Maria");
	trabajador2.persona.edad = 30;
	trabajador2.persona.peso = 55.0;
	trabajador2.persona.fechaNacimiento = {10, 5, 1993};
	trabajador2.salario = 500000.00;
	trabajador2.fechaContratacion = {10, 1, 2022};
	
	trabajadores[1] = trabajador1;
	trabajadores[2] = trabajador2;
	
	// Mostrando datos de todos los trabajadores
	for (int i = 0; i < 3; i++) {
		cout << "Datos del trabajador " << i + 1 << ":" << endl;
		imprimirEmpleado(trabajadores[i]);
		cout << endl;
	}
	
	getch();
	return 0;
}
