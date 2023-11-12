//
//#include <iostream>
//#include <stdio.h>
//#include "sqlite3.h"
//
//using namespace std;
//// https://www.youtube.com/watch?v=-C5HSdPU3TI&t=1s
//// https://www.youtube.com/watch?v=AdrukzQZDk0&list=PLfLTVALFJVQJ22XeGZ2b2i2sQnMygbCHh&index=3
//// https://www.youtube.com/watch?v=L-hnA82JsEM&list=PL_mvCTR_h6cwdKlIywXsXIKeoJtRrUU3v
//
//
//void Insert(sqlite3* db, char* err, string query);
//void GetAll(sqlite3* db, char* err, string query);
//void connection();
//void Delete();
//
//int main1()
//{
//	char* err;
//	sqlite3* db;
//	int rc;
//
//	// Abre la base de datos o la crea si no existe
//	rc = sqlite3_open("test.db", &db);
//
//	if (rc != SQLITE_OK) {
//		cout << "Error al abrir la base de datos: " << sqlite3_errmsg(db) << endl;
//		return rc;
//	}
//
//	const char* create_table_sql = "CREATE TABLE IF NOT EXISTS Usuarios(id INTEGER PRIMARY KEY AUTOINCREMENT, nombre VARCHAR(100), email VARCHAR(150), pass VARCHAR(10))";
//
//	// Ejecuta la sentencia para crear la tabla
//	rc = sqlite3_exec(db, create_table_sql, NULL, NULL, &err);
//
//	if (rc != SQLITE_OK) {
//		cout << "Error al crear la tabla: " << err << endl;
//		sqlite3_free(err); // Libera la memoria asignada por sqlite3_exec
//	}
//	else {
//		cout << "Tabla creada correctamente" << endl;
//	}
//
//	//string nombre = "Mariano", email = "Mariano@hotmail.com", pass = "lkjñlfa";
//	//string query = "INSERT INTO Usuarios (nombre, email, pass) values('" + nombre + "', '" + email + "', '" + pass + "'); ";
//	//Insert(db, err, query);
//
//	string query = "SELECT * FROM Usuarios; ";
//
//	GetAll(db, err, query);
//
//	// Cierra la base de datos
//	sqlite3_close(db);
//
//	return 0;
//}
//
//void Insert(sqlite3* db, char* err, string query)
//{
//	int rc;
//	rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
//	if (rc != SQLITE_OK) {
//		cout << "Insert error:  " << err << endl;
//	}
//}
//void Delete(int id, sqlite3* db)
//{
//	int rc;
//	sqlite3_stmt* stmt;
//	string query = "DELETE FROM Usuarios WHERE id = ?";
//	rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
//
//	sqlite3_bind_int(stmt, 1, id);
//	sqlite3_step(stmt);
//	sqlite3_finalize(stmt);
//
//	if (rc == SQLITE_OK)
//	{
//		cout << "\n Data Deleted Successfully! \n";
//	}
//	else {
//		cout << "\n Error al borrar los datos. \n";
//	}
//
//}
//void connection()
//{
//
//}
//
//void GetAll(sqlite3* db, char* err, string query)
//{
//	sqlite3_stmt* stmt;
//	int rc;
//	sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, 0);
//	int id;
//	const unsigned char* nombre;
//	const unsigned char* email;
//	const unsigned char* pass;
//
//	while (sqlite3_step(stmt)!= SQLITE_DONE)
//	{
//		id = sqlite3_column_int(stmt, 0);
//		nombre = sqlite3_column_text(stmt, 1);
//		email = sqlite3_column_text(stmt, 2);
//		pass = sqlite3_column_text(stmt, 3);
//
//		cout << "Id: " << id << ", Nombre: " << nombre << " ,Email: " << email << " ,Pass: " << pass << endl;
//	}
//
//	
//}