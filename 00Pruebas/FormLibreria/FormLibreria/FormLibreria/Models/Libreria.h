#pragma once

#include <iostream>
#include <vector>
#include "Facturacion.h"
#include <memory>
#include "Login.h"
#include "Facturacion.h"
#include "Usuario.h"
#include "Libro.h"
#include "../repositories/LibrosRepository.h"

/// <summary>
/// Esta es la clase principal de la aplicacion, desde esta se gestiona
/// casi todo sobre la libreria.
/// </summary>
class Libreria
{
private:
	// No la uso pero estaba creada para poner un título en todas las ventanas de ahí ser estatica
	static std::string nombrelibreria;

	// Estos son los libros disponibles en la libreria
	vector<Libro> StockLibros;

	// Este es el usuario
	//std::unique_ptr<Usuario> usuario;
	Facturacion* facturacion;
	LibrosRepository _repo;
	Login* login;

public:
	// Constructor de Libreria
	Libreria(Login* _login)
	{
		//usuario = make_unique<Usuario>();
		login = _login;
		facturacion = new Facturacion(login->GetUsuario().GetCarrito());
	}

	// Destructor de Libreria
	~Libreria() = default;

	std::vector<Libro> GetAllLibros()
	{
		// para hacer pruebas

		std::vector<Libro> libros;
		Libro libro1("Titulo1", "Autor1", 56);
		Libro libro2("Titulo2", "Autor2", 43);
		Libro libro3("Titulo3", "Autor3", 32);
		Libro libro4("Titulo4", "Autor4", 55);
		libros.push_back(libro1);
		libros.push_back(libro2);
		libros.push_back(libro3);
		libros.push_back(libro4);

		return libros;
		//return _repo.GetAll();
	}

	// Insertar libros
	void InsertLibro(Libro _libro)
	{
		if (login->GetUsuario().GetPermiso() == permisoAdmin)
			StockLibros.push_back(_libro);
	}

};

std::string Libreria::nombrelibreria = "Libreria Curso C++";
