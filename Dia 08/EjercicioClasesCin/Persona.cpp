#include "Persona.h"


// Metodos Set
void Persona::SetNombre(string newNombre)
{
	nombre = newNombre;
}
void Persona::SetApellido1(string newApellido1)
{
	apellido1 = newApellido1;
}
void Persona::SetApellido2(string newApellido2)
{
	apellido2 = newApellido2;
}
void Persona::SetEdad(int newEdad)
{
	edad = newEdad;
}

// Métodos Get
string Persona::GetNombre()
{
	return nombre;
}
string Persona::GetApellido1()
{
	return apellido1;
}
string Persona::GetApellido2()
{
	return apellido2;
}
int Persona::GetEdad()
{
	return edad;
}