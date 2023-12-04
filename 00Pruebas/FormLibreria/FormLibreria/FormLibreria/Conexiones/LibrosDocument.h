#pragma once

#include "IDocument.h"
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "../Models/Libro.h"
#include "../Utilidades/CryptoUtils.h"

using namespace System::Windows::Forms;

/// <summary>
/// Clase para acceder al archivo csv donde guardo los libros
/// </summary>
class LibrosDocument 
{
private:
	// declaro campos privados
	std::string nombreArchivo;
	std::string key;
	std::ofstream conexion;

	// declaro estos metodos privados, ya que desde fuera de la clase no quiero que abran o cierren la conexion
	void Open() { conexion.open(nombreArchivo + ".csv"); }
	void Close() { conexion.close(); }

	// codigo extraido de la web para comprobar si existe el archivo
	bool ExisteFiechero() {
		std::string fichero = nombreArchivo + ".csv";
		DWORD atributos = GetFileAttributesA(fichero.c_str());
		return (atributos != INVALID_FILE_ATTRIBUTES && !(atributos & FILE_ATTRIBUTE_DIRECTORY));
	}

public:
	// Constructor para introducir el nombre del archivo que quiera, así vale para otros proyectos
	// y generamos una key la que queramos
	LibrosDocument(std::string _nombreArchivo)
	{
		nombreArchivo = _nombreArchivo;
		key = "LibroSecretKey";
	}

	// Destructor
	~LibrosDocument() = default;

	// Para escribir datos en el archivo
	void Escribir(Libro libro)
	{
		std::ofstream conexion(nombreArchivo + ".csv", ios_base::app); // abrir en modo append se añaden los datos al final
		if (conexion.is_open())
		{
			// Solo he podido entrar si se a abierto la conexion correctamente
			conexion << libro.GetTitulo() << ",";
			conexion << libro.GetAutor() << ",";
			conexion << std::to_string(libro.GetPrecio()) << "\n";

			//MessageBox::Show("Datos guardados con exito.\n");
		}
		else
			MessageBox::Show("No se a podido abir el archivo para escritura.\n");

		// Cierro la conexion siempre después
		Close();
	}
	// Para leer libros del archivo
	std::vector<Libro> Leer()
	{
		// vector provisional para almacenar los libros
		std::vector<Libro> libros;

		// compruebo si existe el fichero, si no existe salgo de leer con un vector vacio
		if (!ExisteFiechero())
			return libros;

		// Enfoco al archivo deseado
		std::ifstream conexion(nombreArchivo + ".csv");

		if (!conexion.is_open())
		{
			// Si no se puede abrir la conseion devuelvo el vector vacio
			MessageBox::Show("No se pudo abrir el archivo.", "Error");
			return libros;
		}

		// Declaro un string linea donde iré metiendo cada linea del archivo
		std::string linea;

		// Ejecuto el while mientras haya datos
		while (getline(conexion, linea))
		{
			// se utiliza para poner en memoria la linea
			std::istringstream ss(linea);
			std::string titulo, autor, precioStr;

			// Extraigo la linea en curso
			if (getline(ss, titulo, ',') && getline(ss, autor, ',') && getline(ss, precioStr))
			{
				try
				{
					// Convierto precio en double para crar el objeto libro
					double precio = std::stod(precioStr);
					libros.emplace_back(titulo, autor, precio);
				}
				catch (const std::invalid_argument& )
				{
					MessageBox::Show("Error al convertir precio a double.", "Error");
				}
				catch (const std::out_of_range& )
				{
					MessageBox::Show("Precio fuera del rango válido.", "Error");
				}
			}
			else
			{
				MessageBox::Show("Formato de línea no válido.", "Error");
			}
		}

		// Cierro y envio libros
		Close();
		return libros;
	}

	// Metodo para comprobar si el libro existe, te devuelve true o false
	bool Existe(Libro libro)
	{
		// si no existe el archivo evidentemente devuelve false
		if (!ExisteFiechero()) return false;
		// Ya que he hecho un metodo leer lo uso
		std::vector<Libro> libros = Leer();

		// Los recorro y comparo la propiedad titulo para saber si existe, devolviendo true en tal caso
		for (Libro& lib : libros)
		{
			if (lib.GetTitulo() == libro.GetTitulo()) return true;
		}
		// Si lelgo aquí no existe
		return false;
	}

	// Escribo un vecto de libros en el archivo
	void EscribirLibros(const std::vector<Libro>& libros)
	{
		std::ofstream conexion(nombreArchivo + ".csv", ios::trunc);  // Abre el archivo en modo de truncamiento para borrar su contenido y escribir el archivo por completo

		if (conexion.is_open())
		{
			for (const Libro& libro : libros)
			{
				// Escribir el correo electrónico y la contraseña en el archivo
				conexion << libro.GetTitulo() << ",";
				conexion << libro.GetAutor() << ",";
				conexion << std::to_string(libro.GetPrecio()) << "\n";
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
