#pragma once

#include <iostream>
#include "Asignatura.h"
#include "Profesor.h"
using namespace std;

class Menu
{
private:
	string opc;

	void MenuPrincipal()
	{
		system("cls");
		cout << "*******************************************************************" << endl;
		cout << "***************** M E N U   P R I N C I P A L *********************" << endl;
		cout << "*******************************************************************" << endl;
		cout << endl;
		cout << "\t1.- Ingresar profesores." << endl;
		cout << "\t2.- Ingresar alumnos." << endl;
		cout << "\t3.- Cantidad alumnos por asignatura." << endl;
		cout << "\t4.- Listado Alumnos." << endl;
		cout << "\t5.- Salir." << endl;
		cout << endl << endl;
		cout << "\t\tElige una opcion [1 / 5]...   ";
		cin >> opc;
	}



	void IngresoProfesor()
	{
		system("cls");
		cout << "*******************************************************************" << endl;
		cout << "***************** I N G R E S A R   P R O F E S O R ***************" << endl;
		cout << "*******************************************************************" << endl;
		cout << endl;

		string asignatura =FormularioAsignatura();

		Persona persona = FormularioPersona();
		Profesor profesor(Asignatura (asignatura), persona.GetNombre(), persona.GetApellido1(), persona.GetApellido2(), persona.GetEdad());
	}

	string FormularioAsignatura()
	{
		string asignatura;
		cout << "Ingrese Asignatura a impartir: "; cin >> asignatura;
		cout << endl;
		cout << "*******************************************************************" << endl;
		cout << endl;

		return asignatura;
	}

	Persona FormularioPersona()
	{
		string nombre;
		cout << "Ingrese Nombre: "; cin >> nombre;
		cout << endl;

		string apellido1;
		cout << "Ingrese primer Apellido: "; cin >> apellido1;
		cout << endl;

		string apellido2;
		cout << "Ingrese segundo Apellido: "; cin >> apellido2;
		cout << endl;

		int edad;
		cout << "Ingrese Pass: "; cin >> edad;
		cout << endl;

		Persona persona(nombre, apellido1, apellido2, edad);
		return persona;
	}

	void IngresoAlumnos()
	{

	}

	void ListadoAlumnos()
	{

	}

	void IngresoAsignaturas()
	{

	}

	void IngresoNotas()
	{

	}

	void CantAlumnosPorAsignatura()
	{

	}


public:
	void Logica()
	{
		while (opc != "5")
		{
			MenuPrincipal();
			switch (opc[0])
			{
			case '1':
				IngresoProfesor();
				break;
			case '2':
				IngresoAlumnos();
				break;
			case '3':
				CantAlumnosPorAsignatura();
				break;
			case '4':
				ListadoAlumnos();
				break;
			case '5':
				system("cls");
				cout << endl << "Ha terminado la aplicacion." << endl;
				system("pause");
				exit(0);
				break;
			}
			system("pause");
		}
	}
};

