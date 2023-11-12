
#include <iostream>
#include "View/UsuarioView.h"
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	setlocale(LC_ALL, "es_ES.UTF-8");

	system("cls");

	UsuarioView* view = new UsuarioView();

	view->Logica();

	delete view;

	system("pause");
	return 0;
}
