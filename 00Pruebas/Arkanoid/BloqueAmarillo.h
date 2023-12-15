#pragma once

#include "Bloque.h"

class BloqueAmarillo : public Bloque
{
private:
	int dureza;
	Color color;

public:
	BloqueAmarillo(float _x, float _y) : Bloque(_x, _y)
	{
		dureza = 2;
		color = Color::Yellow;
	}
};