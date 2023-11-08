
#include <iostream>
using namespace std;

int main()
{
	const double PI = 3.1416;
	int numero1;
	numero1 = 15;

	int numero2;
	numero2 = 14;

	int resultado;
	resultado = numero1 + numero2;

	string saludo = "El resultado de la suma es: ";

	cout << saludo << resultado << endl;

	int entrada;
	cout << "Introduce un numero: ";
	cin >> entrada;
	int calculoTotal = entrada + resultado;
	cout << "Tu numero es: " << entrada << endl;

	if (calculoTotal < 40)
	{
		cout << "Introduce un numero mauyor" << endl;
	}
	else
	{
		cout << "Genial";
	}

	cout << endl;
	return 0;
}


