#pragma once

#include "Dependencias.h"

class Base
{
protected:
	int x, y;
	int dx, dy;
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

	virtual void Dibujar(Graphics^ g);
	virtual void Mover(Graphics^ g);
};