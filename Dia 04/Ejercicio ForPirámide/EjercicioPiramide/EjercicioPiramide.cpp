
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
void ResultadoForWhile(int numero);
void ResultadoForFor(int numero);

int main()
{
	int numero;
	cout << "Dime un numero entero positivo: ";
	cin >> numero;
	system("cls");
	cout << endl;

	cout << "\nCon For + While" << endl << endl;
	ResultadoForWhile(numero);

	cout << "\nCon For + For" << endl << endl;
	ResultadoForFor(numero);

	system("pause");
	return 0;
}

void ResultadoForWhile(int numero)
{
	for (int i = numero; i > 0; i--)
	{
		int longitud = i;
		while (longitud > 0)
		{
			cout << "*";
			longitud--;
			this_thread::sleep_for(chrono::milliseconds(100));
		}
		cout << endl;
	}
}
void ResultadoForFor(int numero)
{
	for (int i = numero; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "*";
			this_thread::sleep_for(chrono::milliseconds(100));
		}
		cout << endl;
	}
}