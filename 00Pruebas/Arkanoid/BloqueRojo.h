#pragma once

#include "Bloque.h"


class BloqueRojo : public Bloque
{
private:
	int dureza;
	Color color;

public:
	BloqueRojo(float _x, float _y) : Bloque(_x, _y)
	{
		dureza = 4;
		color = Color::Red;
	}
};