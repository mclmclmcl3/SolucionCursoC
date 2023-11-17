#pragma once

#include "Persona.h"
#include "Alumno.h"
#include <vector>
#include "Asignatura.h"

using namespace std;

class Profesor : public Persona
{
private:
	vector<Alumno> alumnos;
	Asignatura asignatura;

public:
	//// Constructor de Profesor que recibe un objeto Persona y asigna sus propiedades
	//Profesor(Asignatura _asignatura, Persona persona)
	//	: Persona(persona), asignatura(_asignatura) {}

	// Constructor
	Profesor(Asignatura _asignatura, string nombre, string apellido1, string apellido2, int edad)
		: asignatura(_asignatura), Persona(nombre, apellido1, apellido2, edad) {}

	vector<Alumno> GetAlumnos();
	void SetAlumnos(const vector<Alumno>& _alumnos);

	void CambiarAsignatura(Asignatura asignatura);
	void AddAlumno(const Alumno& alumno);

	int CantidadAlumnos(const string& asignatura);
};
