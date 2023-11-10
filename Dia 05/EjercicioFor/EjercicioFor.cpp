
#include <iostream>
#include <locale.h>
#include <Windows.h>
#include <string>

using namespace std;
void ImprimirArreglo(string frutero, int size);

int main()
{
	// Idioma español
	setlocale(LC_ALL, "Es-es.UFT-8");
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);

	string fruta;
	string frutero[20] = { "pera", "manzana", "platano" };
	int size = sizeof(frutero) / sizeof(frutero[0]);
	fruta = frutero[1];
	cout << fruta << endl;

	cout << "---------------------------" << endl;

	frutero[1] = "Naranja";

	cout << fruta << endl;
	cout << frutero[1] << endl;
	fruta = frutero[1];
	cout << fruta << endl;

	cout << "---------------------------" << endl;

	frutero[1] = "Fresa";
	ImprimirArreglo(frutero, size);

	system("pause");
	return 0;
}

void ImprimirArreglo(string frutero[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << frutero[i] << " ";
	}
}