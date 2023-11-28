#pragma once

#include <iostream>
#include "Usuario.h"
#include "../Repositories/UsuariosRepository.h"

using namespace std;

/// <summary>
/// Clase para gestionar el registro/Login y Logout
/// Esta clase estára activa mientras dure la aplicacion
/// ya que gestiona partes fundamentales para dar permisos
/// 
/// </summary>
/// 
class Login
{
private:
	// Acceso a los datos para sacar los usuarios del archivo.
	UsuariosRepository _repo;
	// Usuario siempre activo para saber que usuario es y si estas logeado por eso static
	Usuario usuario;

public:
	Login() { }
	~Login() = default;

	// Para saber si está logeado o no.
	bool IsLogin() { return !usuario.GetEmail().empty(); }

	// Metodo para logearse
	void Logear(const Usuario& _usuario)
	{
		std::shared_ptr<Usuario> user = _repo.GetUsuario(_usuario);
		if (user != nullptr)
		{
			usuario.SetEmail(user->GetEmail());
			usuario.SetPass(user->GetPass());
			usuario.SetPermiso(user->GetPermiso());
		}
	}

	// Metodo para Deslogearse
	void Logout() { usuario = Usuario(); }

	// Metodo para registrarse en la aplicacion
	void Registrar(const Usuario& _usuario)
	{
		// Guardar el usuario en el archivo
		_repo.RegistarUsuario(_usuario);
	}

	// Setter
	void SetUsuario(Usuario _usuario) { usuario = _usuario; }

	// Getter
	Usuario GetUsuario() { return usuario; }
};