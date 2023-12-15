#pragma once


#include "Bloque.h"

class BloqueBlanco : public Bloque
{
private:
	int dureza;
	Color color;

public:
	BloqueBlanco(float _x, float _y) : Bloque(_x, _y)
	{
		dureza = 1;
		color = Color::White;
	}
};