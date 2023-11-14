
#include <iostream>
#include <locale>
#include <Windows.h>
#include <string>

using namespace std;

class Clase
{
private:
	int edad;
	string nombre;

public:
	Clase() {};
	Clase(int newEdad, string newNombre) : edad(newEdad), nombre(newNombre) {};

	int GetEdad() { return edad; }
	string GetNombre() { return nombre; }

	void SetEdad(int newEdad) { edad = newEdad; }
	void SetNombre(string newNombre) { nombre = newNombre; }

	void Escribe() {
		cout << "El alumno  " << nombre << ", te saluda" << endl << endl;
	}
};

void ClasePuntero();
void ClaseNormal();
void ClaseNormal2();

int main()
{
	setlocale(LC_ALL, "es_ES.UTF-8");
	system("cls");

	// distintos casos
	ClaseNormal();
	ClaseNormal2();
	ClasePuntero();

	system("pause");
	return 0;
}

// Declaracion simple
void ClaseNormal()
{
	cout << "\nClase alumno;\n\n";
	Clase alumno;
	alumno.SetEdad(18);
	alumno.SetNombre("Mariano");

	cout << "Nombre: " << alumno.GetNombre() << " , edad: " << alumno.GetEdad() << endl;
	alumno.Escribe();
}

// Declaracion inicializando el constructor
void ClaseNormal2()
{
	cout << "\nClase alumno = Clase();\n\n";
	Clase alumno = Clase();
	alumno.SetEdad(18);
	alumno.SetNombre("Mariano");

	cout << "Nombre: " << alumno.GetNombre() << " , edad: " << alumno.GetEdad() << endl;
	alumno.Escribe();
}

// Inicio como puntero.
void ClasePuntero()
{
	cout << "\nClase* alumno = new Clase();\n\n";
	Clase* alumno = new Clase();
	alumno->SetEdad(18);
	alumno->SetNombre("Mariano");

	cout << "Nombre: " << alumno->GetNombre() << " , edad: " << alumno->GetEdad() << endl;
	alumno->Escribe();
	delete alumno;
}