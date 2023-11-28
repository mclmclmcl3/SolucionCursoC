#pragma once

#include <iostream>
#include <vector>
#include "Libro.h"
#include "Carrito.h"

/// <summary>
/// Cada usuario tiene un carrito con sus precios, pero la libreria
/// no tiene o sabe lo que se va a comprar el cliente, así que
/// en facturación ingreso el Carrito del usuario, aquí luego
/// se podran implementar metodos como quitar unidades de libros
/// que haya en el stock de la libreria, etc.
/// </summary>
class Facturacion
{
private:
	Carrito* carrito;
	double total;
	double iva;
	double totalIva;

public:
	Facturacion()
	{
		carrito = nullptr;
	}
	Facturacion(Carrito* _carrito)
	{
		carrito = _carrito;
	}

	~Facturacion() {}

	
};