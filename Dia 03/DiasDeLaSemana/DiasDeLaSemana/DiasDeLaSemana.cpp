
#include <iostream>
using namespace std;

int main()
{
	bool bandera = true;
	int dia = 1;

	while (bandera)
	{
		system("cls");
		cout << "Escribe un numero del 1 al 7. " << endl;
		cout << "Escribe otro numero para salir. "; 
		cin >> dia;

		switch (dia) {
		case 1:
			cout << "Lunes" << endl;
			break;
		case 2:
			cout << "Martes" << endl;
			break;
		case 3:
			cout << "Miercoles" << endl;
			break;
		case 4:
			cout << "Jueves" << endl;
			break;
		case 5:
			cout << "Viernes" << endl;
			break;
		case 6:
			cout << "Sabado" << endl;
			break;
		case 7:
			cout << "domingo" << endl;
			break;
		default:
			bandera = false;
		}
		if (dia >= 1 && dia <= 7)
			system("pause");
	}

	cout << "Fin de la aplicacion." << endl;
	system("pause");
	return 0;
}
