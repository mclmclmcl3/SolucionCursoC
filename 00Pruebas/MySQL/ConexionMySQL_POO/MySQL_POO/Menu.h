#pragma once
#include "UsuarioRepository.h"
#include <iostream>
#include <mysql.h>
#include <iomanip>
#include <string>
#include <limits> 

using namespace std;

class Menu {
private:
	MYSQL_ROW fila; // variable para recorrer cada fila.
	string opc;
	UsuarioRepository repo;
	MYSQL_RES* resultado; // puntero de donde se almacena el resultado.

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

	void GetAll()
	{
		if (repo.GetConectar()) {
			system("cls");
			cout << "Conexion exitosa..." << endl;
			cout << endl;
			repo.GetUsuarios("SELECT * FROM Usuarios");
			Imprimir();
		}
		else {
			cout << "Error en la conexion..." << endl;
		}
	}

	void GetById()
	{
		if (repo.GetConectar()) {
			system("cls");
			cout << "Conexion exitosa..." << endl;
			cout << endl;
			int id;
			PedirId(id);
			system("cls");
			repo.GetUsuarios("SELECT * FROM Usuarios WHERE ID=" + to_string(id));

			if (repo.GetResultado() != NULL)
			{
				if (repo.GetResultado()->row_count > 0)
					Imprimir();
				else
					cout << "No hay datos." << endl;
			}
			else
				cout << "No existe ese usuario." << endl;
		}
		else {
			cout << "Error en la conexion..." << endl;
		}
	}

	void Insert()
	{
		if (repo.GetConectar()) {
			system("cls");
			cout << "Conexion exitosa..." << endl;
			cout << endl;

			Usuario usuario = Usuario();
			usuario = Formulario(usuario);
			repo.Insertar(usuario);
		}
		else {
			cout << "Error en la conexion..." << endl;
		}
	}

	void Update()
	{
		if (repo.GetConectar()) {
			system("cls");
			cout << "Conexion exitosa..." << endl;

			cout << endl;
			int id;
			PedirId(id);
			system("cls");

			// Utilizar un puntero a la clase Usuario
			Usuario* user = nullptr;

			repo.GetUsuarios("SELECT * FROM Usuarios WHERE ID=" + to_string(id));

			if (repo.GetResultado() != nullptr)
			{
				Imprimir();
				fila = mysql_fetch_row(repo.GetResultado());

				if (fila != NULL)
				{
					// Crear un objeto Usuario con los datos de la base de datos
					user = new Usuario(id, fila[1], fila[2], fila[3]);
				}
				else
				{
					repo.GetUsuarios("SELECT * FROM Usuarios WHERE ID=" + to_string(id));
					fila = mysql_fetch_row(repo.GetResultado());
					// Crear un objeto Usuario con los datos de la base de datos
					user = new Usuario(id, fila[1], fila[2], fila[3]);
				}
				// Modificar el objeto Usuario
				Formulario(*user);
				repo.Modificar(*user);
			}
			else
				cout << "No existe ese usuario." << endl;


			// Liberar la memoria del objeto Usuario después de utilizarlo
			delete user;
		}
		else {
			cout << "Error en la conexion..." << endl;
		}
	}

	void Delete()
	{
		if (repo.GetConectar()) {
			system("cls");
			cout << "Conexion exitosa..." << endl;

			cout << endl;
			int id;
			PedirId(id);
			system("cls");

			// Utilizar un puntero a la clase Usuario
			Usuario* user = nullptr;

			repo.GetUsuarios("SELECT * FROM Usuarios WHERE ID=" + to_string(id));

			if (repo.GetResultado() != nullptr)
			{
				fila = mysql_fetch_row(repo.GetResultado());
				cout << "Esta seguro que quiere borrar Id: " << fila[0] << " ,Nombre: " << fila[1] << " [S/N] ";
				string confirmacion = "N";
				cin >> confirmacion;
				if (confirmacion == "s" || confirmacion == "S")
				{
					system("cls");
					repo.Delete(id);
				}
			}
			else
				cout << "No existe ese usuario." << endl;

			// Liberar la memoria del objeto Usuario después de utilizarlo
			delete user;
		}
		else {
			cout << "Error en la conexion..." << endl;
		}
	}

	void PedirId(int& id)
	{
		id = -1;
		while (id <= 0) {
			cin.clear();
			cin.ignore();  // Limpia el búfer de entrada
			system("cls");
			cout << "Ingrese un número: ";

			if (cin >> id && id > 0) {
				break;  // Salir del bucle si se ingresa un entero positivo válido
			}

			cout << "Entrada no válida. Por favor, ingrese un número entero positivo." << endl;
			system("pause");
		}
	}

	void Imprimir()
	{
		cout << setw(5) << "Id" << setw(15) << "Nombre" << setw(35) << "Email" << setw(25) << "Pass" << endl;
		for (int i = 0; i < 80; i++)
		{
			cout << '-';
		}
		cout << endl;
		while (fila = mysql_fetch_row(repo.GetResultado()))
		{
			cout << setw(5) << fila[0] << setw(15) << fila[1] << setw(35) << fila[2] << setw(25) << fila[3] << endl;
		}
		cout << endl;
	}

	Usuario Formulario(Usuario& usuario)
	{
		string nombre;
		cout << "Ingrese Nombre: "; cin >> nombre;
		usuario.SetNombre(nombre);
		cout << endl;

		string email;
		cout << "Ingrese Email: "; cin >> email;
		usuario.SetEmail(email);
		cout << endl;

		string pass;
		cout << "Ingrese Pass: "; cin >> pass;
		usuario.SetPass(pass);
		cout << endl;

		return usuario;
	}

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
				break;
				break;
			}
			system("pause");
		}
	}


public:
	Menu()
	{
		repo = UsuarioRepository();
		Logica();
	}
};

