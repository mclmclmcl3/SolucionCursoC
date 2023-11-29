#pragma once

#include "Views/FormLibreria.h"
#include "Models/Libreria.h"

using namespace System::Windows::Forms;



int main()
{
	Application::Run(gcnew FormLibreria::FormLibreria);
	//Application::Run(gcnew FormLibreria::FormLogin);
	//Application::Run(gcnew FormLibreria::PruebasRapidas);
	return 0;
};

/*

El primer usuario registrado es el administrador, el administrador podrá añadir libros borrar libros o actualizar el precio de los
libros, pero no podra hacer compras. Para las funciones de administrador, hay que entrar desde el boton administrador.
Se podria automatizar....

El usuario comun puede comprar libros pero no hacer gestiones de administrador

Tenemos una clase principal Libreria encargada de gestionar la aplicacion
una clase Login, que es la encargada de gestionar el login y permisos para entrar en ciertos elementos como he comentado antes.
Esta clase login la voy pasando por las ventanas.

No he querido tener en memoria todo el rato la ventana login, por lo que he iniciado la aplicacion en la ventana
principal y desde esta he llamado a formLogin de forma modal, pasandole login.

En la ventana principal inicio la clase Libreria

Tiene un sistema de encriptado para el usuario, y los libros por cambiar los creo en un archivo csv.

La idea primaria era hacer una aplicacion robusta, pero por falta de concocimientos avanzados en este lenguaje, me he quedado aquí.


*/