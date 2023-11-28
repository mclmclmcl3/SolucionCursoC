#pragma once

#include "Carrito.h"
#include <iostream>
#include "../Utilidades/Permisos.h"

/// <summary>
/// Esta clase sirve para declarar la estructura de datos de Usuario
/// aquí tambien se gestionan los permisos de cada usuario al igual que
/// lo que quiere comprar dicho usuario.
/// 
/// Lo idóneo hubiese sido haber hecho una clase usuario solo con los datos 
/// email, pass y permiso y luego una clase Cliente que herede de usuario y 
/// esta tenga imprementada la propiedad Carrito.
/// Pero he tenido dificultades con muchos errores y he acabado simplificando
/// un poco el código.
/// </summary>
class Usuario
{
private:
	std::string email;
	std::string pass;
	Permisos permiso;
	// Carrito donde se introducen las compras
	Carrito* carrito;

public:
	// constructor inicializando los campos para que no haya problemas en un futuro
	Usuario()
	{
		email = "";
		pass = "";
		carrito = new Carrito();
		SetPermiso(permisoUsuario);
	}
	// destructor por defecto
	~Usuario() = default;

	// Getter
	std::string GetEmail() const { return email; }
	std::string GetPass() const { return pass; }
	Permisos GetPermiso() const { return permiso; }
	Carrito* GetCarrito() { return carrito; }

	// Setter
	void SetEmail(const std::string& _email) { email = _email; }
	void SetPass(const std::string& _pass) { pass = _pass; }
	void SetPermiso(Permisos _permiso) { permiso = _permiso; }
	void SetCarrito(Carrito* _carrito) { carrito = _carrito; }

	// Para hacer las compararciones, equivale a Equal en otros lenguajes
	bool operator==(const Usuario& otro) const {
		return (this->GetEmail() == otro.GetEmail() && this->GetPass() == otro.GetPass() );
	}

};
