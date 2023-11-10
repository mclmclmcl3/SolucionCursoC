#pragma once
#include "Usuario.h"
#include "Conexion.h"


class UsuarioRepository
{
private:
	Conexion con;
	int q_estado;
	MYSQL* conectar;
	MYSQL_ROW fila; // variable para recorrer cada fila.
	MYSQL_RES* resultado; // puntero de donde se almacena el resultado.

public:
	UsuarioRepository()
	{
		con = Conexion();
		con.EstaBlecerConexion();
		q_estado = con.getEstado();
		conectar = con.getConextar();
	}
	MYSQL_RES* GetResultado() { return resultado; }
	
	MYSQL* GetConectar() { return conectar; }
	
	void EstablecerConexion() { con.EstaBlecerConexion(); }

	void GetUsuarios(string query)
	{
		const char* c = query.c_str();

		q_estado = mysql_query(conectar, c);
		if (!q_estado) {
			resultado = mysql_store_result(conectar);
		}
	}

	void Insertar(Usuario &usuario)
	{
		string insert = "INSERT INTO Usuarios (nombre, email, pass) values ('" + usuario.GetNombre() + "','" + usuario.GetEmail() + "','" + usuario.GetPass() + "')";

		// Las dos siguientes lineas es para ejecutar el query
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);

		if (!q_estado) {
			GetUsuarios("SELECT * FROM Usuarios");
		}
	}

	void Modificar(Usuario &usuario)
	{
		string modificar = "UPDATE Usuarios SET nombre = '" + usuario.GetNombre() + "', email='" + usuario.GetEmail() + "', pass='" + usuario.GetPass() + "' WHERE ID=" + to_string(usuario.GetId());

		// Las dos siguientes lineas es para ejecutar el query
		const char* i = modificar.c_str();
		q_estado = mysql_query(conectar, i);
	}
	
	void Delete(int &id)
	{
		string modificar = "DELETE FROM Usuarios WHERE ID = " + to_string(id);

		// Las dos siguientes lineas es para ejecutar el query
		const char* i = modificar.c_str();
		q_estado = mysql_query(conectar, i);
	}
};

