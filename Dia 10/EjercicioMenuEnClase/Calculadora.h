#pragma once


class Calculadora {

private:
	string opc;
	double n1;
	double n2;
	double resultado;

	void MenuOperaciones();
	void MenuSumar();
	void MenuRestar();
	void MenuMultiplicar();
	void MenuDividir();

public:
	void Logica();
};


void Calculadora::MenuOperaciones()
{
	system("cls");
	cout << "*******************************************************************" << endl;
	cout << "***************** M E N U   P R I N C I P A L *********************" << endl;
	cout << "*******************************************************************" << endl;
	cout << endl;

	cout << "\t1.- Sumar." << endl;
	cout << "\t2.- Restar." << endl;
	cout << "\t3.- Multiplicar." << endl;
	cout << "\t4.- Dividir." << endl;
	cout << "\t5.- Volver." << endl;
	cout << endl << endl;
	cout << "\t\tElige una opcion [1 / 5]...   ";
	cin >> opc;
	cout << endl;
}

void Calculadora::Logica()
{
	while (opc != "5")
	{
		MenuOperaciones();
		switch (opc[0])
		{
		case '1':
			MenuSumar();
			break;
		case '2':
			MenuRestar();
			break;
		case '3':
			MenuMultiplicar();
			break;
		case '4':
			MenuDividir();
			break;
		case '5':
			system("cls");
			cout << endl << "Te has salido de la calculadora." << endl;
			return;
			break;
		}
		if (opc != "5")
			system("pause");
	}
}

void Calculadora::MenuSumar()
{
	n1 = n2 = resultado = 0;
	cout << endl << "Dime un numero: ";
	cin >> n1;
	cout << endl << "Dime un numero: ";
	cin >> n2;
	resultado = n1 + n2;
	cout << "El resultado de la suma de " << n1 << " + " << n2 << " es: " << resultado << endl;
}

void Calculadora::MenuRestar()
{
	n1 = n2 = resultado = 0;
	cout << endl << "Dime un numero: ";
	cin >> n1;
	cout << endl << "Dime un numero: ";
	cin >> n2;
	resultado = n1 - n2;
	cout << "El resultado de la resta de " << n1 << " - " << n2 << " es: " << resultado << endl;
}

void Calculadora::MenuMultiplicar()
{
	n1 = n2 = resultado = 0;
	cout << endl << "Dime un numero: ";
	cin >> n1;
	cout << endl << "Dime un numero: ";
	cin >> n2;
	resultado = n1 * n2;
	cout << "El resultado de la multiplicacion de " << n1 << " * " << n2 << " es: " << resultado << endl;
}

void Calculadora::MenuDividir()
{
	n1 = n2 = resultado = 0;
	cout << endl << "Dime un numero: ";
	cin >> n1;
	cout << endl << "Dime un numero: ";
	cin >> n2;
	if (n1 > 0 && n2 > 0)
	{
		resultado = n1 / n2;
		cout << "El resultado de la multiplicacion de " << n1 << " / " << n2 << " es: " << resultado << endl;
	}
	else
	{
		cout << "Error al hacer la division..." << endl;
	}
}