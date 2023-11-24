#pragma once

#include <iostream>

using namespace std;

class Usuario
{
private:
	string email;
	string pass;
public:
	Usuario()
	{
		email = pass = "";
	}
	~Usuario() {}

	void SetEmail(string _email) { email = _email; }
	void SetPass(string _pass) { pass = _pass; }

	string GetEmail() { return email; }
	string GetPass() { return pass; }
};
