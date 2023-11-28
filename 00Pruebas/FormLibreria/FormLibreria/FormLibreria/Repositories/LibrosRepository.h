#pragma once

#include <vector>
#include "../Conexiones/LibrosDocument.h"

/// <summary>
/// Clase Libros repository es la encargada de conectarme a la base de datos o a otra fuente
/// pero como no tenia claro como acabar se me ha quedado como una capa intermedia.
/// </summary>
class LibrosRepository
{
private:
	LibrosDocument* documento;
public:
	//constructor
	LibrosRepository()
	{
		documento = new LibrosDocument("Libros");
	}
	// Destructor
	~LibrosRepository() {}

	// Conseguir todos los libros llamando a Librosdocument Leer
	std::vector<Libro> GetAll()
	{
		std::vector<Libro> listalibrosusuarios = documento->Leer();
		return listalibrosusuarios;
	}

	// Guardar un libro en el archivo
	void RegistarLibro(Libro libro)
	{
		// Si no existe Escribir el usuario en el archivo.
		if (!documento->Existe(libro))
		{
			documento->Escribir(libro);
		}
	}

	// Borrar un libro en el archivo
	void BorrarLibro(const Libro& libro)
	{
		std::vector<Libro> libros = documento->Leer();

		auto it = find(libros.begin(), libros.end(), libro);
		if (it != libros.end())
			libros.erase(it);

		documento->EscribirLibros(libros);
	}

};