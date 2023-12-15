#pragma once

#include "Base.h"

class Jugador : public Base
{
public:
	Jugador()
	{
		x = 60; y = 60;
		dx = dy = 0;
		ancho = alto = 40;
	}
	void Mover(Graphics^ g)
	{
		// VisibleClipBounds.Width => ancho de la pantalla
		if (x + dx >= 0 && (x + ancho + dx) < g->VisibleClipBounds.Width)
		{
			x += dx;
		}
		if (y + dy >= 0 && (x + alto + dy) < g->VisibleClipBounds.Height)
		{
			y += dy;
		}
	}

	void Mostrar(Graphics^ g)
	{
		g->FillRectangle(Brushes::Green, Area());
	}
};