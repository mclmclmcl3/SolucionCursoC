#pragma once

#include "../Repositories/UsuarioRepository.h"
#include <iostream>

using namespace std;

class UsuarioView
{
private:
	UsuarioRepository* urepo;
	string opc;
	int id;
	Usuario* user;

	void MenuPrincipal()
	{
		system("cls");
		cout << "*******************************************************************" << endl;
		cout << "***************** M E N U   P R I N C I P A L *********************" << endl;
		cout << "*******************************************************************" << endl;
		cout << endl;
		cout << "\t1.- Listar todos los usuarios." << endl;
		cout << "\t2.- Listar un usuario por su Id." << endl;
		cout << "\t3.- Insertar nuevo usuario." << endl;
		cout << "\t4.- Modificar usuario según Id." << endl;
		cout << "\t5.- Borrar usuario." << endl;
		cout << "\t6.- Salir." << endl;
		cout << endl << endl;
		cout << "\t\tElige una opcion [1 / 6]...   ";
		cin >> opc;

	}

	void Formulario()
	{
		user->SetId(id);

		string nombre;
		cout << "Ingrese Nombre: "; cin >> nombre;
		user->SetNombre(nombre);
		cout << endl;

		string email;
		cout << "Ingrese Email: "; cin >> email;
		user->SetEmail(email);
		cout << endl;

		string pass;
		cout << "Ingrese Pass: "; cin >> pass;
		user->SetPass(pass);
		cout << endl;
	}

	void GetAll()
	{
		urepo = new UsuarioRepository();
		system("cls");
		urepo->GetAll();
		delete urepo;
	}

	bool GetById()
	{
		urepo = new UsuarioRepository();
		//system("cls");
		cout << "Dime el id del usuario: ";
		cin >> id;

		bool bandera;
		bandera = urepo->GetById(id);

		if (!bandera)
		{
			system("cls");
			cout << "\nEse usuario no existe.\n\n";
		}

		delete urepo;
		return bandera;
	}

	void Insert()
	{
		user = new Usuario();
		urepo = new UsuarioRepository();
		Formulario();
		urepo->Insert(user);

		delete urepo;
		delete user;
	}

	void Update()
	{
		GetAll();

		if (GetById())
		{
			user = new Usuario();
			user->SetId(id);
			Formulario();

			user = new Usuario();
			urepo = new UsuarioRepository();
			urepo->Update(user);

			delete urepo;
			delete user;
		}
	}

	void Delete()
	{
		GetAll();
		if (GetById())
		{
			string seleccion;
			cout << "Estas seguro de querer borrarlo [s/n] ";
			cin >> seleccion;

			if (seleccion == "s" || seleccion == "S")
			{
				urepo = new UsuarioRepository();
				urepo->Delete(id);
				delete urepo;
			}
		}
	}

public:

	void Logica()
	{
		while (opc != "6")
		{
			MenuPrincipal();
			switch (opc[0])
			{
			case '1':
				GetAll();
				break;
			case '2':
				system("cls");
				GetById();
				break;
			case '3':
				Insert();
				break;
			case '4':
				Update();
				break;
			case '5':
				Delete();
				break;
			case '6':
				system("cls");
				cout << endl << "Ha terminado la aplicacion." << endl;
				system("pause");
				exit(0);
				break;
			}
			system("pause");
		}
	}

};

