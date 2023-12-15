#pragma once

#include "Bloque.h"

class BloqueNaranja : public Bloque
{
private:
	int dureza;
	Color color;

public:
	BloqueNaranja(float _x, float _y) : Bloque(_x, _y)
	{
		dureza = 3;
		color = Color::Orange;
	}
};