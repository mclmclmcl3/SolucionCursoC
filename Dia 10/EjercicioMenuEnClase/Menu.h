#pragma once
#include <iostream>
#include "Usuario.h"
#include "Calculadora.h"

using namespace std;

class Menu {

private:
	string opc;
	Usuario* user;

	bool siguiente = false;
	void MenuPrincipal();
	void MenuLogin();
	void MenuError();
	void Bienvenida();
	void Calculo();
public:
	void Logica();
};

void Menu::Logica()
{
	while (opc != "4")
	{
		MenuPrincipal();
		switch (opc[0])
		{
		case '1':
			MenuLogin();
			break;
		case '2':
			if (siguiente)
				Bienvenida();
			else
				cout << "Tienes que estar logeado para poder entrar..." << endl << endl << endl;
			break;
		case '3':
			if (siguiente)
				Calculo();
			else
				cout << "Tienes que estar logeado para poder entrar..." << endl << endl << endl;
			break;
		case '4':
			system("cls");
			cout << endl << "Ha terminado la aplicacion." << endl;
			system("pause");
			exit(0);
			break;
		}
		system("pause");
	}
}


void Menu::MenuPrincipal()
{
	system("cls");
	cout << "*******************************************************************" << endl;
	cout << "***************** M E N U   P R I N C I P A L *********************" << endl;
	cout << "*******************************************************************" << endl;
	cout << endl;
	if (!siguiente)
		cout << "\t1.- Login." << endl;
	else
		cout << "\t1.- Logout." << endl;
	cout << "\t2.- Mensaje Bienvenida." << endl;
	cout << "\t3.- Calculadora." << endl;
	cout << "\t4.- Salir." << endl;
	cout << endl << endl;
	cout << "\t\tElige una opcion [1 / 4]...   ";
	cin >> opc;
	cout << endl;
}

void Menu::MenuLogin()
{
	if (!siguiente)
	{
		string nombre, pass;
		user = new Usuario();

		for (int i = 3; i > 0; i--)
		{
			system("cls");
			cout << "*******************************************************************" << endl;
			cout << "******************************* L O G I N *************************" << endl;
			cout << "*******************************************************************" << endl;
			cout << endl << endl;
			cout << "Intento: " << i;
			cout << endl << endl;
			cout << "Nombre: "; cin >> nombre;
			cout << "Pass: "; cin >> pass;

			Usuario* user = new Usuario();
			user->SetNombre(nombre);
			user->SetPass(pass);

			if (user->Login())
			{
				siguiente = true;
				return;
			}
			siguiente = false;
			delete user;

			system("cls");
			cout << "Has hagotado el numero de intentos de login..." << endl;
		}
	}
	else
	{
		delete user;
		siguiente = false;
		system("cls");
		cout << "Para volver a entrar tienes que logearte otra vez." << endl;
	}
}

void Menu::MenuError()
{
	system("cls");
	cout << "Para acceder al sistema, primero hay que logearse." << endl;
}

void Menu::Bienvenida()
{
	system("cls");
	cout << "*******************************************************************" << endl;
	cout << "********************* B I E N V E N I D O *************************" << endl;
	cout << "*******************************************************************" << endl;
	cout << endl << endl;
	cout << "\n\tBienVenido " << user->GetNombre() << endl << endl << endl;
}


void Menu::Calculo()
{
	Calculadora* calculadora = new Calculadora();
	calculadora->Logica();

	delete calculadora;
	calculadora = nullptr;
}