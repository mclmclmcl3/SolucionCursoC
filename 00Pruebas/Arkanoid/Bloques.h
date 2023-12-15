#pragma once

#include "Bloque.h"

class Bloques
{
private:
	vector<Bloque*> listaBloques;
public:
	Bloques() {}
	~Bloques()
	{
		for (int i = 0; i < listaBloques.size(); i++)
		{
			delete listaBloques[i];
		}
	}

	void AgregarBloques(Bloque* bloque)
	{
		listaBloques.push_back(bloque);
	}

	void Mover(Graphics^ g)
	{
		for each (Bloque * bloque in listaBloques)
		{
			bloque->Mover(g);
		}
	}

	void Mostrar(Graphics^ g)
	{
		for (Bloque* bloque : listaBloques)
		{
			bloque->Mostrar(g);
		}
	}
};