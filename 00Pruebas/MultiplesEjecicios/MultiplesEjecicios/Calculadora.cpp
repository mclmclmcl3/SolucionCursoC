//****************************************//
// ORGANIZACION							  //
//****************************************//
// Version 1.0          				  //
// Ultima modificacion documentada        //
// 29/10/2023                             //
// Creaccion							  //
//****************************************//

#include "funcionesCalculadora.h"
#include "MainCalculadora.h"

using namespace calculadora;
using namespace std;

namespace calculadora
{

	// Programa pincipal
	int MainCalculadora()
	{
		double n1, n2, resultado;
		int seleccion = 0;
		string operacion = "";

		while (seleccion != 5)
		{
			resultado = 0;
			seleccion = Menu();
			if (seleccion == 5) {
				Advertencia("Salimos de la calculadora.");
				return 0;
			}

			if (seleccion >= 1 && seleccion <= 4)
			{
				n1 = PedirNumero();
				n2 = PedirNumero();

				switch (seleccion)
				{
				case 1:
					Imprimir(Sumar(n1, n2), "sumar " + doubleToString(n1) + " + " + doubleToString(n2));
					break;

				case 2:
					Imprimir(Restar(n1, n2), "restar " + doubleToString(n1) + " - " + doubleToString(n2));
					break;

				case 3:
					Imprimir(Multiplicar(n1, n2), "multiplicar " + doubleToString(n1) + " x " + doubleToString(n2));
					break;

				case 4:
					if (n2 != 0)
					{
						Imprimir(Dividir(n1, n2), "dividir " + doubleToString(n1) + " / " + doubleToString(n2));
						break;
					}
					else
					{
						Advertencia("No se puede dividir por cero.");
						break;
					}
				}
			}
			else
			{
				Advertencia("Tienes que pulsar un numero entre [0-5].");
			}
		}
		return 0;
	}

}
