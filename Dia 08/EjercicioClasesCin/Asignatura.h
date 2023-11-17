#pragma once

#include <iostream>

using namespace std;

class Asignatura
{
private:
	static int IdInc;
	int id;
	float trimestres[3];
	string nombre;

public:
	Asignatura(string& nombre)
	{
		IdInc++;
		this->id = IdInc;
		this->nombre = nombre;

		// Inicializar los trimestres a 0
		for (int i = 0; i < 3; i++) {
			trimestres[i] = 0.0f;
		}
	}

	string GetNombre() const { return nombre; } 

	int GetId() { return id; }

	const float* GetTrimestres() { return trimestres; }

	// Método para agregar nota a un trimestre
	void AddTrimestre(float nota, int trimestre) {

		// Verificar que el trimestre sea válido (entre 1 y 3)
		if (trimestre >= 1 && trimestre <= 3) {
			trimestres[trimestre - 1] = nota;
		}
		else {
			cout << "Trimestre no válido." << endl;
		}
	}

};

// Inicializar la variable estática
int Asignatura::IdInc = 0;