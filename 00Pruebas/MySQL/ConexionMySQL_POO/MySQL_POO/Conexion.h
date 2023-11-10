#pragma once

#include <iostream>
#include <mysql.h>
using namespace std;

class Conexion {
private:
	MYSQL* conectar;
	int q_estado;

public:
	void EstaBlecerConexion()
	{
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "root", "root", "CursoC", 3306, NULL, 0);
	};

	MYSQL* getConextar() { return conectar; }
	int getEstado() { return q_estado; }

};

