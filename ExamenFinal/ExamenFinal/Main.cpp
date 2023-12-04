#include "TiendaOnline.h"

using namespace System::Windows::Forms;

int main()
{
	Application::Run(gcnew ExamenFinal::TiendaOnline);
	return 0;
}

/*

CREATE DATABASE IF NOT EXISTS ExamenFinal;
USE ExamenFinal;

CREATE TABLE IF NOT EXISTS Tienda (
    Id INT PRIMARY KEY AUTO_INCREMENT,
    Titulo VARCHAR(150),
    Autor VARCHAR(150),
    Precio DOUBLE
);


INSERT INTO Tienda (Titulo, Autor, Precio) VALUES ("La Catedral del Mar","Ildefonso Falcones", 19.80);
INSERT INTO Tienda (Titulo, Autor, Precio) VALUES ("La sombra del viento","Carlos Ruiz Zafon", 15.20);
INSERT INTO Tienda (Titulo, Autor, Precio) VALUES ("Los Pilares de la Tierra","Ken Follet", 21.20);



*/