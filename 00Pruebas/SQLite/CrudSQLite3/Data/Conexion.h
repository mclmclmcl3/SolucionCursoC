#pragma once
#include <sqlite3.h>
#include <iostream>

using namespace std;

class Conexion
{
private:
	sqlite3* db;
	sqlite3_stmt* stmt;
	char* err_msg = nullptr;
	int rc;

public:
	sqlite3* Getdb() { return db; };

	void AbrirConexion()
	{
		// Abre la base de datos (creará un nuevo archivo "test.db" si no existe)
		rc = sqlite3_open("test.db", &db);

		if (rc != SQLITE_OK)
			cout << "Error al abrir la base de datos: " << sqlite3_errmsg(db) << endl;

		else
			cout << "Conexion abierta." << endl;
	}

	// Destructor para cerrar la base de datos.
	~Conexion() {
		if (db != nullptr) {
			sqlite3_close(db);
			cout << endl << "Conexion cerrada." << endl;
		}
		delete[] err_msg;
	}
};