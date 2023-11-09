
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
	int numero;
	cout << "Dime un numero entero positivo: ";
	cin >> numero;
	system("cls");
	cout << endl;

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

	system("pause");
	return 0;
}

