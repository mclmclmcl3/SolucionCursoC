// EjercicioClases.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Alumno
{
private:
	// Declaracion de campos
	string nombre;
	string apellido1;
	string apellido2;
	float nota;
public:
	// Constructor
	Alumno(string _nombre, string _apellido1, string _apellido2, float _nota)
	{
		nombre = _nombre;
		apellido1 = _apellido1;
		apellido2 = _apellido2;
		nota = _nota;
	};

	// Declaracion de metodos
	float GetNota() {
		return nota;
	};

	void ToString() {
		cout << setw(10) << "   Nombre: " << setw(10) << nombre << setw(20) << "Primer apellido: " << setw(10) << apellido1 << setw(20) << "Segundo apellido: " << setw(10) << apellido2 << setw(10) << "Nota: " << nota << endl;
	};
};

class SerVicioAlumno
{
private:
	// Declaracion de campos
	Alumno* alumnos[5]{};
	double media;
	int longitud;

	// Declaracion de metodos privados (No es necesario que se vea desde el extrerior de la clase)
	void ImprimirDatos()
	{
		int longitud = sizeof(alumnos) / sizeof(alumnos[0]);
		system("cls");
		cout << endl;
		cout << "**************L I S T A D O   D E   N O T A S * *************" << endl << endl;
		for (int i = 0; i < longitud; i++)
		{
			alumnos[i]->ToString();
			media += alumnos[i]->GetNota();
		}

		cout << endl << setw(91) << "La media de las notas es: " << media / longitud << endl << endl;
		LiberarMemoria();
	};

	void LiberarMemoria()
	{
		for (int i = 0; i < longitud; i++) {
			delete alumnos[i];
		}
	};

public:
	// Declaracion de metodos publicos
	void IntroducirDatos()
	{
		string nombre, apellido1, apellido2;
		float nota;
		int cant = 0;

		while (cant < 5)
		{
			system("cls");
			cout << "Alumno Numero: " << cant + 1 << endl << endl;

			// Formulario
			cout << "Nombre del alumno: "; cin >> nombre; cout << "\n";
			cout << "Primer Apellido del alumno: "; cin >> apellido1; cout << "\n";
			cout << "Segundo Apellido del alumno: "; cin >> apellido2; cout << "\n";
			cout << "Nota del alumno: "; cin >> nota; cout << "\n";

			// Verificar errores en la nota.
			if (cin.fail())
			{
				cout << "La nota debe ser un valor válido. " << endl;
				system("pause");
			}
			else
			{
				Alumno* alumno = new Alumno(nombre, apellido1, apellido2, nota);
				alumnos[cant] = alumno;
				cant++;
			}
			// Se limpia el buffer de cin para la nueva entrada.
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		ImprimirDatos();
	};
};


int main()
{
	SerVicioAlumno sAlumno = SerVicioAlumno();
	sAlumno.IntroducirDatos();

	system("pause");
	return 0;
}

