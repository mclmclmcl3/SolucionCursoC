
#include <iostream>

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
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

