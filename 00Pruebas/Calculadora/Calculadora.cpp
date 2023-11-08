
#include <iostream>

using namespace std;
double Sumar(double n1, double n2);
double Restar(double n1, double n2);
double Multiplicar(double n1, double n2);
double Dividir(double n1, double n2);
void Imprimir(double resultado);
double PedirNumero();
int Menu();

int main()
{
	double n1, n2, resultado;
	int seleccion = 0;

	while (seleccion != 5)
	{
		seleccion = Menu();

		if (seleccion >= 1 && seleccion <= 4)
		{
			n1 = PedirNumero();
			n2 = PedirNumero();

			switch (seleccion)
			{
			case 1:
				resultado = Sumar(n1, n2);
				Imprimir(resultado);
				break;

			case 2:
				resultado = Restar(n1, n2);
				Imprimir(resultado);
				break;

			case 3:
				resultado = Multiplicar(n1, n2);
				Imprimir(resultado);
				break;

			case 4:
				if(n2!=0)
				{
					resultado = Dividir(n1, n2);
					Imprimir(resultado);
				}
				else
				{
					cout << "No se puede dividir por cero." << endl << endl;
				}
				break;
			}
		}
	}
	return 0;
}


static int Menu()
{
	system("cls");
	int numero;
	cout << "CALCULADORA" << endl << endl;

	cout << " 1.- Sumar" << endl;
	cout << " 2.- Restar" << endl;
	cout << " 3.- Multiplicar" << endl;
	cout << " 4.- Dividir" << endl;
	cout << " 5.- Salir" << endl << endl;
	cout << "Elije una opcion... ";
	cin >> numero;
	
	return numero;
}

static double PedirNumero()
{
	double numero;
	cout << endl << "Dime un numero: ";
	cin >> numero;
	return numero;
}

static double Sumar(double n1, double n2)
{
	return n1 + n2;
}

static double Restar(double n1, double n2)
{
	return n1 - n2;
}

static double Multiplicar(double n1, double n2)
{
	return n1 * n2;
}

static double Dividir(double n1, double n2)
{
	if (n1 > 0 && n2 > 0)
	{
		return n1 / n2;
	}
	return 0;
}

static void Imprimir(double resultado)
{
	cout << endl << "El resultado es :   " << resultado << endl << endl;
	system("pause");
}