
#include <iostream>
using namespace std;

int Pregunta();

int main()
{
	int resultado;
	int contador = 3;

	while (contador > 0)
	{
		resultado = Pregunta();

		if (resultado == 14) {
			break;
		}
		else {
			contador--;
			cout << "No eres un usuario valido. " << endl << " Intenta de nuevo, te quedan " << contador << " intentos." << endl;
		}
	}

	if (contador > 0)
		cout << endl << "Perfecto... puedes entrar." << endl;
	else
		cout << endl << "Has superado el limite de intentos." << endl;

	system("pause");
	return 0;
}

int Pregunta()
{
	int resultado;
	cout << "Dime el resultado de 5 + 9: ";
	cin >> resultado;
	return resultado;
}
