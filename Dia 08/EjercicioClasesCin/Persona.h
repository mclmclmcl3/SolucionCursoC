#pragma once


#include <iostream>

using namespace std;

class Persona
{
private:
	string nombre;
	string apellido1;
	string apellido2;
	int edad;

public:
	// Constuctor Vacio
	Persona() {}

	// Constructor con parametros
	Persona(string nombre, string apellido1, string apellido2, int edad){
		this->nombre = nombre;
		this->apellido1 = apellido1;
		this->apellido2 = apellido2;
		this->edad = edad;
	};

	// Metodos Set
	void SetNombre(string newNombre);
	void SetApellido1(string newApellido1);
	void SetApellido2(string newApellido2);
	void SetEdad(int newEdad);

	// Métodos Get
	string GetNombre();
	string GetApellido1();
	string GetApellido2();
	int GetEdad();
};

