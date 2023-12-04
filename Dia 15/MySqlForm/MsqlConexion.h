#pragma once

#include <mysql.h>
#include <Windows.h>
#include <string>
#include <vector>

class MsqlConexion
{
private:

	MYSQL* conectar;  // La variable tipo MYSQL para establecer el resultado de la conexión
	MYSQL_ROW fila; // Variable MYSQL en la que albergaremos datos de una fila de la respuesta de la consulta.
	MYSQL_RES* resultado; // La variable tipo MYSQL para establecer el resultado de la respuesta de una consulta

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


	std::vector<std::string> LeerTodo()
	{
		std::vector<std::string> resultados;
		std::string query = "SELECT * FROM usuario";
		Conexion();
		if (mysql_query(conectar, query.c_str()))
		{
			System::Windows::Forms::MessageBox::Show("No se pudo conectar");
		}
		resultado = mysql_store_result(conectar);
		if (resultado)
		{
			int numColumnas = mysql_num_fields(resultado);
			MYSQL_ROW fila;

			while ((fila = mysql_fetch_row(resultado)))
			{
				for (int i = 0; i < numColumnas; ++i)
				{
					resultados.push_back(fila[i] ? fila[i] : "NULL");
				}
			}
			mysql_free_result(resultado);
		}
		else
		{
			System::Windows::Forms::MessageBox::Show("Error al obtener el resultado de la consulta");
		}
		Desconexion();
		return resultados;
	}
	void Insertar(std::string &nombre, std::string &pass)
	{
		std::string query = "INSERT INTO usuario (Nombre, Pass) VALUES ('" + nombre + "','" + pass + "');";

		Conexion();
		if (mysql_query(conectar, query.c_str()));
		{
			resultado = mysql_store_result(conectar);
		}
		Desconexion();
	}
	void Actualizar(std::string &nombre, std::string &pass)
	{
		std::string query = "UPDATE usuario SET Nombre ='" + nombre + "', Pass = '" + pass + "');";

		Conexion();
		if (mysql_query(conectar, query.c_str()));
		{
			resultado = mysql_store_result(conectar);
		}
		Desconexion();
	}
	void Borrar(int &id)
	{
		std::string query = "DELETE FROM usuario WHERE ID = " + std::to_string(id);

		Conexion();
		if (mysql_query(conectar, query.c_str()));
		{
			resultado = mysql_store_result(conectar);
		}
		Desconexion();
	}
};