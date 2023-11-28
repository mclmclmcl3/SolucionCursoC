
#include <iostream>
#include <mysql.h>
#include <iomanip>
#include <string>
#include <limits> 

using namespace std;
int q_estado;
// Configuracion de mysql => https://www.youtube.com/watch?v=gPcYDjWKutE
// Post => https://www.youtube.com/watch?v=RIEe514Sxt8
// Get => https://www.youtube.com/watch?v=z0pZ2e9aN6k
// Completo => https://www.youtube.com/playlist?list=PLurnDCBwo4BcO-dMkFrzT7k9bPZcRKCQu

struct datos {
	int id;
	string nombre;
	string email;
	string pass;
};

MYSQL* conectar; // puntero del nombre de la conexion
MYSQL_ROW fila; // variable para recorrer cada fila.
MYSQL_RES* resultado; // puntero de donde se almacena el resultado.

void EstablecerConexion();
void Insertar();
void Modificar(int& id);
void GetUsuarios(string query);
void Imprimir();
void Formulario(struct datos* datos);
void MenuPrincipal(string& opc);
void PedirId(int& id);


int main()
{
	string opc;
	EstablecerConexion();

	while (opc != "6")
	{
		MenuPrincipal(opc);
		switch (opc[0])
		{
		case '1':
			if (conectar) {
				system("cls");
				cout << "Conexion exitosa..." << endl;
				cout << endl;
				GetUsuarios("SELECT * FROM Usuarios");
				Imprimir();
				system("pause");
			}
			else {
				cout << "Error en la conexion..." << endl;
			}
			break;
		case '2':
			if (conectar) {
				system("cls");
				cout << "Conexion exitosa..." << endl;
				cout << endl;
				int id;
				PedirId(id);
				system("cls");
				GetUsuarios("SELECT * FROM Usuarios WHERE ID=" + to_string(id));

				if (resultado != NULL)
				{
					Imprimir();
				}
				else
					cout << "No existe ese usuario." << endl;
				system("pause");
			}
			else {
				cout << "Error en la conexion..." << endl;
			}
			break;
		case '3':
			if (conectar) {
				system("cls");
				cout << "Conexion exitosa..." << endl;
				cout << endl;
				Insertar();
				system("pause");
			}
			else {
				cout << "Error en la conexion..." << endl;
			}
			break;
		case '4':
			if (conectar) {
				system("cls");
				cout << "Conexion exitosa..." << endl;

				cout << endl;
				int id;
				PedirId(id);
				system("cls");
				GetUsuarios("SELECT * FROM Usuarios WHERE ID=" + to_string(id));

				if (resultado != NULL)
				{
					Imprimir();
					Modificar(id);
				}
				else
					cout << "No existe ese usuario." << endl;

				system("pause");
			}
			else {
				cout << "Error en la conexion..." << endl;
			}
			break;
		case '5':
			if (conectar) {
				system("cls");
				cout << "Conexion exitosa..." << endl;
				cout << endl;

				int id;
				PedirId(id);
				GetUsuarios("SELECT * FROM Usuarios WHERE ID=" + to_string(id));

				fila = mysql_fetch_row(resultado);
				if (fila != NULL)
				{
					cout << "Esta seguro que quiere borrar Id:" << fila[0] << " ,Nombre:" << fila[1] << " [S/N]";
					string confirmacion = "N";
					cin >> confirmacion;
					if (confirmacion == "s" || confirmacion == "S")
					{

						system("cls");
						GetUsuarios("DELETE FROM Usuarios WHERE ID=" + to_string(id));

						Imprimir();
						Modificar(id);
					}
				}
				else
					cout << "No existe ese usuario." << endl;

				system("pause");
			}
			else {
				cout << "Error en la conexion..." << endl;
			}
			break;
		case '6':
			system("cls");
			cout << endl << "Ha terminado la aplicacion." << endl;
			system("pause");
			return 0;
			break;
		}
	}

	system("pause");
	return 0;
}

void EstablecerConexion()
{
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "root", "CursoC", 3306, NULL, 0);

}
void MenuPrincipal(string& opc)
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

void GetUsuarios(string query)
{
	const char* c = query.c_str();

	q_estado = mysql_query(conectar, c);
	if (!q_estado) {
		resultado = mysql_store_result(conectar);
	}
	else {
		cout << "Error al Consultar..." << endl;
	}
}
void Insertar()
{
	struct datos* datos = new struct datos;
	Formulario(datos);

	string insert = "INSERT INTO Usuarios (nombre, email, pass) values ('" + datos->nombre + "','" + datos->email + "','" + datos->pass + "')";

	// Las dos siguientes lineas es para ejecutar el query
	const char* i = insert.c_str();
	q_estado = mysql_query(conectar, i);
	if (!q_estado) {
		cout << "Ingreso exitoso..." << endl;
		cout << endl << endl;
		GetUsuarios("SELECT * FROM Usuarios");
	}
	else {
		cout << "Error al Ingresar..." << endl;
	}
}
void Modificar(int& id)
{
	struct datos* datos = new struct datos;

	Formulario(datos);
	GetUsuarios("SELECT * FROM Usuarios WHERE ID=");

	string modificar = "UPDATE Usuarios SET nombre = '" + datos->nombre + "', email='" + datos->email + "', pass='" + datos->pass + "' WHERE ID=" + to_string(id);

	// Las dos siguientes lineas es para ejecutar el query
	const char* i = modificar.c_str();
	q_estado = mysql_query(conectar, i);
	if (!q_estado) {
		cout << "Modificacion exitosa..." << endl;
		cout << endl << endl;
	}
	else {
		cout << "Error al Ingresar..." << endl;
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
	while (fila = mysql_fetch_row(resultado))
	{
		cout << setw(5) << fila[0] << setw(15) << fila[1] << setw(35) << fila[2] << setw(25) << fila[3] << endl;
	}
	cout << endl;
}
void Formulario(struct datos* datos)
{
	cout << "Ingrese Nombre: "; cin >> datos->nombre;
	cout << endl;

	cout << "Ingrese Email: "; cin >> datos->email;
	cout << endl;

	cout << "Ingrese Pass: "; cin >> datos->pass;
	cout << endl;
}

