#pragma once

#include "IDocument.h"
#include "../Models/Usuario.h"
#include "../Utilidades/CryptoUtils.h"
#include "../Utilidades/Permisos.h"
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace System::Windows::Forms;

/// <summary>
/// Clase para acceder al archivo csv donde guardo los libros
/// </summary>
class UsuariosDocument 
{
private:
	// declaro campos privados
	std::string nombreArchivo;
	std::string key;
	std::ofstream conexion;

	// declaro estos metodos privados, ya que desde fuera de la clase no quiero que abran o cierren la conexion
	void Open() { conexion.open(nombreArchivo + ".txt"); }
	void Close() { conexion.close(); }

	// codigo extraido de la web para comprobar si existe el archivo
	bool ExisteFiechero() {
		std::string fichero = nombreArchivo + ".txt";
		DWORD atributos = GetFileAttributesA(fichero.c_str());
		return (atributos != INVALID_FILE_ATTRIBUTES && !(atributos & FILE_ATTRIBUTE_DIRECTORY));
	}

public:
	// Constructor para introducir el nombre del archivo que quiera, así vale para otros proyectos
	// y generamos una key la que queramos
	UsuariosDocument(std::string _nombreArchivo)
	{
		nombreArchivo = _nombreArchivo;
		key = "UsuarioSecretKey";
	}

	// Destructor
	~UsuariosDocument() = default;

	// Para escribir datos en el archivo
	void Escribir(Usuario usuario)
	{
		std::ofstream conexion(nombreArchivo + ".txt", std::ios_base::app); // abrir en modo append se añaden los datos al final
		if (conexion.is_open())
		{
			// Escribir el correo electrónico y la contraseña en el archivo
			conexion << "Email:" << CryptoUtils::Encrypt(usuario.GetEmail(), key) << "\n";
			conexion << "Pass:" << CryptoUtils::Encrypt(usuario.GetPass(), key) << "\n";
			conexion << "Permiso:" << CryptoUtils::Encrypt(enumToString(usuario.GetPermiso()), key) << "\n";

			MessageBox::Show("Datos guardados con exito.\n");
		}
		else
			MessageBox::Show("No se a podido abir el archivo para escritura.\n");

		Close();
	}

	// Para leer libros del archivo
	std::vector<Usuario> Leer()
	{
		// vector provisional para almacenar los libros
		std::vector<Usuario> usuarios;

		// compruebo si existe el fichero, si no existe salgo de leer con un vector vacio
		if (!ExisteFiechero()) return usuarios;

		// Enfoco al archivo deseado
		std::ifstream conexion(nombreArchivo + ".txt");

		if (!conexion.is_open())
		{
			// Si no se puede abrir la conseion devuelvo el vector vacio
			MessageBox::Show("No se pudo abrir el archivo.\n");
			return usuarios;
		}

		// Declaro un string linea donde iré metiendo cada linea del archivo
		std::string linea;
		int contPropiedad = 0; // Usuario tiene 3 propiedades.
		Usuario usuario;

		// Ejecuto el while mientras haya datos
		while (getline(conexion, linea))
		{
			// busco la posicion dentro de la linea donde hay ":"
			size_t pos = linea.find(':');
			// es un valor constante especial que representa una posición inválida o una posición que no se encuentra dentro de la cadena.
			if (pos != std::string::npos)
			{
				// Como tengo la posicon separo la clave y el valor en dos string distintos
				std::string clave = linea.substr(0, pos);
				std::string valor = linea.substr(pos + 1);

				if (clave == "Email")
				{
					// Si la clave es Email lo introducco en usuario y aumento contpropiedad para saber cuando se ha completado el usuario
					usuario.SetEmail(CryptoUtils::Decrypt(valor, key));
					contPropiedad++;
				}
				else if (clave == "Pass")
				{
					// Si la clave es Pass lo introducco en usuario y aumento contpropiedad para saber cuando se ha completado el usuario
					usuario.SetPass(CryptoUtils::Decrypt(valor, key));
					contPropiedad++;
				}
				else if (clave == "Permiso")
				{
					// Si la clave es Permiso lo introducco en usuario y aumento contpropiedad para saber cuando se ha completado el usuario
					usuario.SetPermiso(stringToEnum(CryptoUtils::Decrypt(valor, key)));
					contPropiedad++;
				}
			}
			// Si son 3 propiedades es que el usuario está compeltado por lo que lo introducco en el vector usuarios
			if (contPropiedad == 3)
			{
				usuarios.push_back(usuario);
				contPropiedad = 0;
			}
		}

		Close();
		return usuarios;
	}

	// Metodo para comprobar si el libro existe, te devuelve true o false
	bool Existe(Usuario usuario)
	{
		// si no existe el archivo evidentemente devuelve false
		if (!ExisteFiechero()) return false;
		// Ya que he hecho un metodo leer lo uso
		std::vector<Usuario> usuarios = Leer();

		// Los recorro y comparo la propiedad titulo para saber si existe, devolviendo true en tal caso
		for (Usuario& user : usuarios)
		{
			if (user.GetEmail() == usuario.GetEmail()) return true;
		}

		// Si lelgo aquí no existe
		return false;
	}

	/// <summary>
	/// Uso la opcion de trunc para que primero borre el archivo completo y luego lo vuelva
	/// a escribir, este método solo se usa para borrar un dato del archivo, por lo que 
	/// tengo que leer todo y reescribirlo sin el dato que quiero mantener en el archivo.
	/// </summary>
	/// <param name="usuarios"></param>
	void EscribirUsuarios(const std::vector<Usuario>& usuarios)
	{
		std::ofstream conexion(nombreArchivo + ".txt", std::ios::trunc);  // Abre el archivo en modo de truncamiento para borrar su contenido

		if (conexion.is_open())
		{
			for (const Usuario& usuario : usuarios)
			{
				// Escribir el correo electrónico y la contraseña en el archivo
				conexion << "Email: " << CryptoUtils::Encrypt(usuario.GetEmail(), key) << "\n";
				conexion << "Pass: " << CryptoUtils::Encrypt(usuario.GetPass(), key) << "\n";
				conexion << "Permiso: " << CryptoUtils::Encrypt(enumToString(usuario.GetPermiso()), key) << "\n";
			}
			conexion.close();
		}
	}

	// Aqui compruebo que el archivo no esté vacio ya que se pueden dar el caso de que exista el 
	// arhivo pero esté vacio o que no exista el archivo.
	bool ArchivoVacio()
	{
		if (!ExisteFiechero()) return true;

		std::ifstream conexion(nombreArchivo + ".txt");

		if (!conexion.is_open())
		{
			MessageBox::Show("No se pudo abrir el archivo.\n");
			Close();
			return true;
		}

		// Verificar si el archivo está vacío
		bool respuesta = (conexion.peek() == std::ifstream::traits_type::eof());

		Close();
		return respuesta;
	}




};