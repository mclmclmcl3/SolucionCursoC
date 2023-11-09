#include <iostream>
#include <windows.h>
#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>

using namespace std;

int main() {

	// Definir variables para la conexión y el statement
	SQLHENV hEnv;
	SQLHDBC hDbc;
	SQLHSTMT hStmt;

	// Inicializar el entorno
	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
	SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);

	// Inicializar la conexión
	SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);


	// info DSN "DSN=MySQL;UID=pep;PWD=123456;DATABASE=base;SERVER=localhost"
	const char* connectionString = "DSN=MySQL;UID=root;PWD=root;DATABASE=CursoC;SERVER=localhost;DRIVER={MySQL ODBC 8.2.0 Driver}; PORT=3306";
	// const char* connectionString = "Server=localhost;Port=3306;Database=CursoC;User=root;Password=root";
	SQLDriverConnect(hDbc, NULL, (SQLWCHAR*)connectionString, SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);


	// Crear un statement
	SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);

	// Ejecutar una consulta
	SQLWCHAR query[] = L"SELECT * FROM Usuarios";
	SQLExecDirect(hStmt, query, SQL_NTS);

	// Procesar los resultados
	//SQLCHAR result[255];
	SQLINTEGER id;
	SQLCHAR nombre[100];
	SQLCHAR email[150];
	SQLCHAR pass[10];

	cout << "Inicio..." << endl;
	while (SQLFetch(hStmt) == SQL_SUCCESS) {
		SQLGetData(hStmt, 1, SQL_C_SLONG, &id, 0, NULL);
		SQLGetData(hStmt, 2, SQL_C_CHAR, nombre, sizeof(nombre), NULL);
		SQLGetData(hStmt, 3, SQL_C_CHAR, email, sizeof(email), NULL);
		SQLGetData(hStmt, 4, SQL_C_CHAR, pass, sizeof(pass), NULL);
		//SQLGetData(hStmt, 2, SQL_C_CHAR, pass, sizeof(result), NULL);
		cout << "ID: " << id << ", Nombre: " << nombre << " ,Email: " << email << " ,Pass: " << pass << endl;
	}

	SQLRETURN retCode = SQLExecDirect(hStmt, query, SQL_NTS);
	if (SQL_SUCCEEDED(retCode)) {
		cout << "Query executed successfully." << endl;
	}
	else {
		cout << "Error executing query." << endl;
	}


	// Liberar recursos
	SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	SQLDisconnect(hDbc);
	SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
	SQLFreeHandle(SQL_HANDLE_ENV, hEnv);

	system("pause");
	return 0;
}