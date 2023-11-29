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
	~Libreria()
	{
		login = nullptr;
	}

	std::vector<Libro> GetAllLibros()
	{
		return _repo.GetAll();
	}

	// Insertar libros
	void InsertLibro(Libro _libro)
	{
		if (login->GetUsuario().GetPermiso() == permisoAdmin)
			_repo.RegistarLibro(_libro);
	}

	void BorrarLibro(Libro libro)
	{
		if (login->GetUsuario().GetPermiso() == permisoAdmin)
		{
			_repo.BorrarLibro(libro);
		}
	}

	void ModificarLibro(Libro libro)
	{
		if (login->GetUsuario().GetPermiso() == permisoAdmin)
		{
			_repo.ModificarLibro(libro);
		}
	}

};

std::string Libreria::nombrelibreria = "Libreria Curso C++";
