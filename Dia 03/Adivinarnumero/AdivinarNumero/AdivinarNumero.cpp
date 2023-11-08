
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

void DibujarPantalla(string historial);
int SolicitarNumero(int intentos);

int main()
{
	srand(time(NULL));
	int intentos = 10, numero = 0;
	int numeroSecreto = rand() % 100;
	string historial = "";

	while (intentos > 0)
	{
		DibujarPantalla(historial);
		numero = SolicitarNumero(intentos);
		if (numero > numeroSecreto) {
			historial += static_cast<char>(25);
		}
		else if (numero < numeroSecreto) {
			historial += static_cast<char>(24);
		}
		else {
			system("cls");
			cout << "*****************************************************" << endl;
			cout << endl << "     Ha adivinado el numero " << numeroSecreto << " en " << 10 - intentos << " intentos." << endl << endl;
			cout << "*****************************************************" << endl;
			system("pause");
			return 0;
		}
		historial += " " + historial + to_string(numero) + "  ";
		intentos--;
	}
	system("cls");
	cout << "**********************************************************" << endl;
	cout << "     Lo siento, has perdido, el numero a adivinar era " << numeroSecreto << endl;
	cout << "**********************************************************" << endl;
	system("pause");
	return 0;
}

int SolicitarNumero(int intentos)
{
	int numero = 0;
	cout << "Te quedan " << intentos << " intentos." << endl;
	cout << "Elige un Numero entre [0 - 100]: ";
	cin >> numero;
	return numero;
}
void DibujarPantalla(string historial)
{
	system("cls");
	cout << "*****************************************************" << endl;
	cout << "********** Juego de Adivinar un numero **************" << endl;
	cout << "*****************************************************" << endl;
	if (historial != "")
		cout << endl << endl << "   Historial : " << historial;
	cout << endl << endl;
}