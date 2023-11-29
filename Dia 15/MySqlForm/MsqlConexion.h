#pragma once

#include <mysql.h>
#include <Windows.h>
#include <string>

class MsqlConexion
{
private:

	MYSQL* conectar;  // La variable tipo MYSQL para establecer el resultado de la conexión
	MYSQL_ROW fila; // Variable MYSQL en la que albergaremos datos de una fila de la respuesta de la consulta.

	int puerto;
	std::string servidor;
	std::string usuario;
	std::string pass;
	std::string nombreBaseDatos;

	void Conexion()
	{
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, servidor.c_str(), usuario.c_str(), pass.c_str(), nombreBaseDatos.c_str(), puerto, NULL, 0);
	}

	void Desconexion() { mysql_close(conectar); }

public:
	MsqlConexion(int _puerto, std::string _servidor, std::string _usuario, std::string _pass, std::string _nombreBaseDatos)
	{
		puerto = _puerto;
		servidor = _servidor;
		usuario = _usuario;
		pass = _pass;
		nombreBaseDatos = _nombreBaseDatos;
	}
	~MsqlConexion() = default;

	MYSQL_RES* resultado; // La variable tipo MYSQL para establecer el resultado de la respuesta de una consulta

	void LeerTodo(std::string query)
	{
		Conexion();
		if (mysql_query(conectar, query.c_str()))
		{
			System::Windows::Forms::MessageBox::Show("No se pudo conectar");
		}
		resultado = mysql_store_result(conectar);
		Desconexion();
	}
	void Insertar(std::string query)
	{
		Conexion();
		if (mysql_query(conectar, query.c_str()));
		{
			resultado = mysql_store_result(conectar);
		}
		Desconexion();
	}
};