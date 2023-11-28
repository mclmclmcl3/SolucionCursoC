#pragma once

#include "Libro.h"
#include <vector>

// Definición de la clase Carrito
class Carrito {
private:
	int id;
	std::vector<Libro> libros;
	double total;
	double iva;

public:
	// Insertar libros
	void ComprarLibro(const Libro& _libro)
	{
		libros.push_back(_libro);

		total = 0;
		if (libros.size() > 0)
		{
			for each (Libro libro in libros)
			{
				total += libro.GetPrecio();
			}
		}
		iva = total * 0.21;
	}

	// Muestro el estado del carrito
	std::vector<Libro> ListadoCarrito() const { return libros; }

	// Quitar libro del carrito
	void QuitarLibro(const Libro& libro)
	{
		// Buscar la posición del elemento en el vector
		auto it = std::find(libros.begin(), libros.end(), libro);
		if (it != libros.end()) libros.erase(it);
	}

	void BorrarCarrito()
	{
		std::vector<Libro> nuevaLista;
		libros = nuevaLista;

		total = 0;
		iva = 0;
	}

	double GetTotal() { return total; }

	double GetIva() { return iva; }

	double GetTotalIva() { return  total + iva; }


};
