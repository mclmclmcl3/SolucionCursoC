
#include "funcionesCalculadora.h"

//****************************************//
// FUNCIONES							  //
//****************************************//
// Version 1.0          				  //
// Ultima modificacion documentada        //
// 29/10/2023                             //
// Creaccion							  //
//****************************************//

namespace calculadora
{

	int Menu()
	{
		int numero;
		cout << "CALCULADORA" << endl << endl;

		cout << " 1.- Sumar" << endl;
		cout << " 2.- Restar" << endl;
		cout << " 3.- Multiplicar" << endl;
		cout << " 4.- Dividir" << endl;
		cout << " 5.- Salir" << endl << endl;
		cout << "Elige una opcion [1-5]" << endl << endl;
		cin >> numero;

		return numero;
	}

	double PedirNumero()
	{
		double numero;
		cout << endl << "Dime un numero: ";
		cin >> numero;
		return numero;
	}

	double Sumar(double n1, double n2)
	{
		return n1 + n2;
	}

	double Restar(double n1, double n2)
	{
		return n1 - n2;
	}

	double Multiplicar(double n1, double n2)
	{
		return n1 * n2;
	}

	double Dividir(double n1, double n2)
	{
		if (n1 > 0 && n2 > 0)
		{
			return n1 / n2;
		}
		return 0;
	}

	void Imprimir(double resultado, string operacion)
	{
		cout << endl << "El resultado de " << operacion << " es :   " << resultado << endl << endl;

		Advertencia("");
	}

	void Advertencia(string mensaje)
	{
		if (mensaje != "") {
			cout << endl << mensaje << endl;
		}

		system("pause");
		system("cls");
	}

	string doubleToString(double numero)
	{
		ostringstream ss;
		ss << numero;
		string cadena = ss.str();
		string cadenaoutZero;
		int indice = 0;

		for (int i = 0; i < cadena.length(); i++)
		{
			if (cadena[i] == '.') { indice = i; }
			if (i >= indice + 3) { break; }
			cadenaoutZero += cadena[i];
		}

		return cadenaoutZero;
	}
}