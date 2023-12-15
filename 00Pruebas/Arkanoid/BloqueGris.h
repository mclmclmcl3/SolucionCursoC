#pragma once


#include "Bloque.h"

class BloqueGris : public Bloque
{
private:
	int dureza;
	Color color;

public:
	BloqueGris(float _x, float _y) : Bloque(_x, _y)
	{
		dureza = 1000;
		color = Color::Gray;
	}
};