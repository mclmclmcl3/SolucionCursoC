
#include "funcionesPunteros.h"
#include "MainPunteros.h"

using namespace std;

namespace punteros
{
	void Consumir();



	void MainPunteros()
	{

		// Consumir();


		int vector[5] = { 1,3,5,7,9 };
		int* pVector;
		pVector = vector;

		int* puntero;
		puntero = &vector[3];
		cout << puntero << endl;

		cout << puntero[-2];

		//cout << (pVector + 1) << endl;

		//for (int i = 0; i < 5; i++)
		//{
		//	cout << (*pVector)++ << endl;			// Valor
		//	cout << "   " << pVector++ << endl;		// Direccion

		//}


		cout << endl;

	}


	void Consumir()
	{
		char cadenaArray[] = "Hola Mundo";
		int longitud = longitudCadena(cadenaArray);

		cout << "Longitud de cadeana: " << longitud;
		cout << endl;
		cout << "La cadena: " << cadenaArray << " tiene una u en el caracter: " << BuscaCaracter(cadenaArray, 'u');

		cout << endl << endl;
	}

}