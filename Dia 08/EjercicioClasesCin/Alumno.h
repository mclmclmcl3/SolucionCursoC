#pragma once
#include "Persona.h"
#include <vector>
#include <string>
#include "Asignatura.h"

using namespace std;

class Alumno : public Persona {
private:
    vector<Asignatura> asignaturas;

public:
    // Constructor con parámetros
    Alumno(const string& nombre, const string& apellido1, const string& apellido2, int edad)
        : Persona(nombre, apellido1, apellido2, edad) {}


    // Métodos Set y Get para asignaturas
    const vector<Asignatura>& GetAsignaturas() const {  return asignaturas; }

    // Método para agregar asignatura
    void AddAsignatura(string nuevaAsignatura) 
    {
        Asignatura asig(nuevaAsignatura);
        asignaturas.push_back(asig);
    }

    // Método para eliminar asignatura
    void EliminarAsignatura(const string& asignatura)
    {
        for (int i = 0; i < asignaturas.size(); i++) {
            if (asignaturas[i].GetNombre() == asignatura) {
                asignaturas.erase(asignaturas.begin() + i);
                // Resta 1 a i para evitar errores después de la eliminación
                i--;
            }
        }
    }

    // Añadir una nota
    void AddNota(float nota, int trimestre, string asignatura) 
    {
        for (int i = 0; i < asignaturas.size(); i++) {
            if (asignaturas[i].GetNombre() == asignatura)
            {
                asignaturas[i].AddTrimestre(nota, trimestre);
            }
        }
    }

};

