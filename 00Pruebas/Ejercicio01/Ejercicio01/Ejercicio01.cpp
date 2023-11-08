
#include <iostream>
using namespace std;

int Pregunta();

int main()
{
	int resultado;
	bool logeado = false;

	while (!logeado)
	{
		resultado = Pregunta();

		if (resultado == 14) {
			logeado = true;
		}
		else {
			cout << "No eres un usuario valido. Intenta de nuevo." << endl;
		}
	}

	cout << endl << "Perfecto... puedes entrar." << endl;
	return 0;
}

static int Pregunta()
{
	int resultado;
	cout << "Dime el resultado de 5 + 9: ";
	cin >> resultado;
	return resultado;
}
