//****************************************
// Crear Archivo sin plantilla							  
//****************************************
// Version 1.0          				  
// Ultima modificacion documentada        
// 06/11/2023                             
// Creaccion							  
//****************************************

#include <iostream>

using namespace std;

int main()
{
	string nombre;
	cout << "Introduce tu nombre: ";
	cin >> nombre;

	setlocale(LC_ALL, "Spanish");
	cout << "Compa�ero " << nombre << " eres una m�quina." << endl;

	system("pause");
	return 0;
}