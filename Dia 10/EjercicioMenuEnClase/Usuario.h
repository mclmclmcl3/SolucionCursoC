#pragma once

#include <iostream>

using namespace std;

class Usuario {

private:
	string static nombreUser;
	string static passUser;
	string nombre;
	string pass;

public:
	void SetNombre(string _nombre);
	void SetPass(string _pass);

	string GetNombre();
	string GetPass();

	bool Login();
};

// Iniciacion de variables estaticas
string Usuario::nombreUser = "admin";
string Usuario::passUser = "admin";


// Implementacion de metodos
void Usuario::SetNombre(string _nombre) { nombre = _nombre; }
void Usuario::SetPass(string _pass) { pass = _pass; }

string Usuario::GetNombre() { return nombre; }
string Usuario::GetPass() { return pass; }

bool Usuario::Login() { return (nombre == nombreUser && pass == passUser) ? true : false; }