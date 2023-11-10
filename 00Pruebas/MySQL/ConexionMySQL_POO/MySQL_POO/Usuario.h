#pragma once
#include <string>
#include <iostream>

using namespace std;

class Usuario{
private:
	int id;
	string nombre;
	string email;
	string pass;

public:
	// Constructor
	Usuario() {}
	Usuario(int newId, const string& newNombre, const string& newEmail, const string& newPass)
		: id(newId), nombre(newNombre), email(newEmail), pass(newPass) {
	}

	int GetId() { return id; }
	string GetNombre() { return nombre; }
	string GetEmail() { return email; }
	string GetPass() { return pass; }

	void SetId(int newId) { id = newId; }
	void SetNombre(string newNombre) { nombre = newNombre; }
	void SetEmail(string newEmail) { email = newEmail; }
	void SetPass(string newPass) { pass = newPass; }

};

