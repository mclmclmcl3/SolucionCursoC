#include "Profesor.h"


using namespace std;

// Implementación de los métodos de Profesor

vector<Alumno> Profesor::GetAlumnos() {
	return alumnos;
}

void Profesor::SetAlumnos(const vector<Alumno>& _alumnos) {
	alumnos = _alumnos;
}

void Profesor::AddAlumno(const Alumno& alumno) {
	alumnos.push_back(alumno);
}

void Profesor::CambiarAsignatura(Asignatura _asignatura)
{
	asignatura = _asignatura;
}

int Profesor::CantidadAlumnos(const string& asig) {
	int cantidad = 0;

	for (int i = 0; i < alumnos.size(); i++)
	{
		auto it = find(alumnos[i].GetAsignaturas().begin(), alumnos[i].GetAsignaturas().end(), asig);
		if (it != alumnos[i].GetAsignaturas().end())
		{
			cantidad++;
		}
	}

	return cantidad;
}