
#include <iostream>
#include <locale.h>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	setlocale(LC_CTYPE, "Spanish");

	system("cls");

	cout << "---------------------- union de cadenas -------------------" << endl;

	string hola = "Hola ";
	string mundo = "mundo";
	string holamundo = hola + mundo;
	cout << "Primero: " << hola << " segundo: " << mundo << " union = " << holamundo << endl;

	cout << "-------------------- sumar dos numeros --------------------" << endl;

	int cinco = 5;
	int cuatro = 4;
	int suma = cinco + cuatro;
	cout << cinco << " + " << cuatro << " = " << suma << endl;

	cout << "--------- concatenar dos numeros como string --------------" << endl;

	string cincoString = "5";
	string cuatroString = "4";
	string sumaString = cincoString + cuatroString;
	cout << "CincoString + " << "cuatroString = " << sumaString << endl;

	cout << "---------- concatenar un numero y un string ---------------" << endl;

	string cincoString2 = "5";
	int cuatroint = 4;
	string sumaString2 = cincoString + to_string(cuatroint);
	cout << "CincoString + " << "cuatroInt = " << sumaString2 << endl;

	cout << "------------------- longitud de cadena --------------------" << endl;
	string holaQueTal = "Holaquetal";
	cout << "La longitud de " << holaQueTal << " = " << holaQueTal.length();
	cout << endl;
	cout << "La longitud de " << holaQueTal << " = " << holaQueTal.size();

	cout << "------------------- Arreglos con cadenas ------------------" << endl;
	string caza = "caza";
	cout << caza[0] << "\t";
	cout << caza[1] << "\t";
	cout << caza[2] << "\t";
	cout << caza[3] << endl;
	caza[2] = 'p';
	cout << "Cambiando la z por la p: " << caza << endl;
	caza = "5" + caza;
	cout << caza;

	cout << "------------------- Arreglos con cadenas ------------------" << endl;
	string ingresaNombre;
	cout << "Hola, ingresa tu nombre completo: ";
	getline(cin, ingresaNombre);

	cout << "Hola " << ingresaNombre << endl;



	cout << endl;
	system("pause");
	return 0;
}

