#pragma once

#include "../Conexiones/UsuariosDocument.h"
#include "../Models/Usuario.h"
#include <vector>
#include <algorithm>
#include <memory>


/// <summary>
/// Clase Usuariosrepository es la encargada de conectarme a la base de datos o a otra fuente
/// pero como no tenia claro como acabar se me ha quedado como una capa intermedia.
/// </summary>
class UsuariosRepository
{
private:
	static Usuario* usuario;
	UsuariosDocument* documento;

public:
	// constructor
	UsuariosRepository()
	{
		documento = new UsuariosDocument("Usuarios");
	}
	// Destructor
	~UsuariosRepository() {}

	// Llamo
	bool ExisteUsuario(const Usuario& usuario)
	{
		return documento->Existe(usuario);
	}

	void RegistarUsuario(Usuario usuario)
	{
		// Hacer administrador si es el primer registro
		if (documento->ArchivoVacio())
		{
			usuario.SetPermiso(permisoAdmin);
		}

		// Si no existe Escribir el usuario en el archivo.
		if (!documento->Existe(usuario))
		{
			documento->Escribir(usuario);
		}
	}

	void BorrarUsuario(const Usuario& usuario)
	{
		if (usuario.GetPermiso() == permisoAdmin)
		{
			std::vector<Usuario> usuarios = documento->Leer();

			auto it = find(usuarios.begin(), usuarios.end(), usuario);
			if (it != usuarios.end())
				usuarios.erase(it);

			documento->EscribirUsuarios(usuarios);
		}
	}

	std::shared_ptr<Usuario> GetUsuario(const Usuario& usuario)
	{
		std::vector<Usuario> listausuarios = documento->Leer();

		auto it = std::find(listausuarios.begin(), listausuarios.end(), usuario);
		if (it != listausuarios.end())
		{
			return std::make_shared<Usuario>(*it);
		}

		// Si no se encuentra el usuario, devolver un puntero nulo.
		return nullptr;
	}

};

