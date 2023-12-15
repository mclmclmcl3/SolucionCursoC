#pragma once

#include "Dependencias.h"

class Base
{
protected:
	float x, y;
	float dx, dy;
	int ancho, alto;
	int velocidad;

public:
	Base()
	{
		x = y = 0;
		dx = dy = 0;
		ancho = alto = 0;
		velocidad = 0;
	}

	Rectangle Area()
	{
		// Devuelve la posicion actual
		return Rectangle(x, y, ancho, alto);
	}

	Rectangle NextArea()
	{
		// Devuelve la siguiente posicion
		return Rectangle(x + dx, y + dy, ancho, alto);
	}


	virtual void Mostrar(Graphics^ g)
	{
		x += dx;
		y += dy;
	}
	virtual void Mover(Graphics^ g)
	{
		g->FillRectangle(Brushes::Black, Area());
	}
};