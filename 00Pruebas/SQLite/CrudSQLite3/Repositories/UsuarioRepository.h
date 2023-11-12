#pragma once

#include <sqlite3.h>
#include "../Data/Conexion.h"
#include "../Usuario.h"
#include <iomanip>


class UsuarioRepository
{
private:
	Conexion* conexion;
	sqlite3* db;
	char* err_msg = nullptr;
	sqlite3_stmt* stmt;
	int rc;

public:
	UsuarioRepository() : conexion(new Conexion())
	{
		conexion->AbrirConexion();
		db = conexion->Getdb();
	}

	~UsuarioRepository() { delete conexion; }

	void GetAll()
	{
		// Consulta datos después de las operaciones
		string query = "SELECT * FROM Usuarios;";
		rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);

		// conprueba errores en la preparacion de la sentencia
		if (rc != SQLITE_OK) {
			cerr << "Error al preparar la sentencia de consulta: " << sqlite3_errmsg(db) << endl;
			return;
		}

		// Ejecuta la sentencia preparada
		cout << "Datos despues de la base de datos:" << endl << endl;
		cout << setw(5) << "Id" << setw(15) << "Nombre" << setw(35) << "Email" << setw(25) << "Pass" << endl;

		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
			cout << setw(5) << sqlite3_column_int(stmt, 0) << setw(15) << sqlite3_column_text(stmt, 1) << setw(35) << sqlite3_column_text(stmt, 2) << setw(25) << sqlite3_column_text(stmt, 3) << endl;
		}

		// comprueba errores en la ejecucion de la sentencia
		if (rc != SQLITE_DONE) {
			cerr << "Error al ejecutar la sentencia de consulta: " << sqlite3_errmsg(db) << endl;
		}

		// Finaliza la sentencia de consulta
		sqlite3_finalize(stmt);

	}

	bool GetById(int id)
	{
		// Consulta datos después de las operaciones
		string query = "SELECT * FROM Usuarios WHERE id= ?;";
		rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);

		// conprueba errores en la preparacion de la sentencia
		if (rc != SQLITE_OK) {
			cerr << "Error al preparar la sentencia de consulta: " << sqlite3_errmsg(db) << endl;
			return false;
		}

		// Vincula valores a la sentencia de eliminación
		sqlite3_bind_int(stmt, 1, id);

		// Contador de filas
		int rowCount = 0;

		// Verifica si hay datos disponibles antes de entrar en el bucle
		if ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {

			// Ejecuta la sentencia preparada
			cout << "Datos despues de la base de datos:" << endl << endl;
			cout << setw(5) << "Id" << setw(15) << "Nombre" << setw(35) << "Email" << setw(25) << "Pass" << endl;

			while (rc == SQLITE_ROW) {
				// Imprime los datos
				cout << setw(5) << sqlite3_column_int(stmt, 0) << setw(15) << sqlite3_column_text(stmt, 1)
					<< setw(35) << sqlite3_column_text(stmt, 2) << setw(25) << sqlite3_column_text(stmt, 3) << endl;

				// Incrementa el contador de filas
				rowCount++;

				// Llama a sqlite3_step para obtener la siguiente fila
				rc = sqlite3_step(stmt);
			}
		}

		// comprueba errores en la ejecucion de la sentencia
		if (rc != SQLITE_DONE) {
			cerr << "Error al ejecutar la sentencia de consulta: " << sqlite3_errmsg(db) << endl;
			return false;
		}

		// Finaliza la sentencia de consulta
		sqlite3_finalize(stmt);
		return rowCount > 0 ? true : false;
	}

	void Insert(Usuario* usuario)
	{
		const char* query = "INSERT INTO Usuarios (nombre, email, pass) VALUES (?, ?, ?);";
		rc = sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);

		// conprueba errores en la preparacion de la sentencia
		if (rc != SQLITE_OK) {
			cerr << "Error al preparar la sentencia de inserción: " << sqlite3_errmsg(db) << endl;
			return;
		}

		// Vincula valores a la sentencia de inserción
		string nombre = usuario->GetNombre();
		string email = usuario->GetEmail();
		string pass = usuario->GetPass();

		sqlite3_bind_text(stmt, 1, nombre.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(stmt, 2, email.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(stmt, 3, pass.c_str(), -1, SQLITE_STATIC);

		// Ejecuta la sentencia preparada
		rc = sqlite3_step(stmt);

		// comprueba errores en la ejecucion de la sentencia
		if (rc != SQLITE_DONE) {
			cerr << "Error al ejecutar la sentencia de inserción: " << sqlite3_errmsg(db) << endl;
		}

		// Finaliza la sentencia de inserción
		sqlite3_finalize(stmt);

	}

	void Delete(int id)
	{
		// Elimina datos de ejemplo
		const char* delete_data_sql = "DELETE FROM Usuarios WHERE id = ?;";
		rc = sqlite3_prepare_v2(db, delete_data_sql, -1, &stmt, nullptr);

		// conprueba errores en la preparacion de la sentencia
		if (rc != SQLITE_OK) {
			cerr << "Error al preparar la sentencia de eliminación: " << sqlite3_errmsg(db) << endl;
			return;
		}

		// Vincula valores a la sentencia de eliminación
		sqlite3_bind_int(stmt, 1, id);

		// Ejecuta la sentencia preparada
		rc = sqlite3_step(stmt);

		// comprueba errores en la ejecucion de la sentencia
		if (rc != SQLITE_DONE) {
			cerr << "Error al ejecutar la sentencia de eliminación: " << sqlite3_errmsg(db) << endl;
		}

		// Finaliza la sentencia de eliminación
		sqlite3_finalize(stmt);
	}

	void Update(Usuario* usuario)
	{
		string query = "UPDATE Usuarios SET nombre = ?, email = ?, pass = ? WHERE id = ?;";
		rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);

		// conprueba errores en la preparacion de la sentencia
		if (rc != SQLITE_OK) {
			cerr << "Error al preparar la sentencia de actualización: " << sqlite3_errmsg(db) << endl;
			return;
		}
		// Vincula valores a la sentencia de inserción
		string nombre = usuario->GetNombre();
		string email = usuario->GetEmail();
		string pass = usuario->GetPass();
		int id = usuario->GetId();

		sqlite3_bind_text(stmt, 1, nombre.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(stmt, 2, email.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(stmt, 3, pass.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_int(stmt, 4, id);

		// Ejecuta la sentencia preparada
		rc = sqlite3_step(stmt);

		// comprueba errores en la ejecucion de la sentencia
		if (rc != SQLITE_DONE) {
			cerr << "Error al ejecutar la sentencia de actualización: " << sqlite3_errmsg(db) << endl;
		}

		// Finaliza la sentencia de actualización
		sqlite3_finalize(stmt);
	}
};

