#pragma once

#include "Jugador.h"
#include "Pelota.h"
#include "Bloques.h"

class Juego
{
private:
	Jugador* jugador;
	Pelota* pelota;
	Bloques* bloques;

public:
	Juego(Graphics^ g)
	{
		jugador = new Jugador();
		pelota = new Pelota(g);
		bloques = new Bloques();
	}
	~Juego()
	{
		delete jugador;
		delete pelota;
		delete bloques;
	}

	// Encargado de mover todos los componentes del juego
	void Mover(Graphics^ g)
	{
		jugador->Mover(g);
		pelota->Mover(g);
		bloques->Mover(g);
	}

	// Encargado de mostrar todos los componentes del juego
	void Mostrar(Graphics^ g)
	{
		jugador->Mostrar(g);
		pelota->Mostrar(g);
		bloques->Mostrar(g);
	}
};