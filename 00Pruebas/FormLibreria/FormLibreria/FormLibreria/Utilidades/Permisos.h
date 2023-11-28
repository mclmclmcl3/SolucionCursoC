#pragma once

#include <iostream>
#include <map>


/// <summary>
/// Este enumerable esta hecho para tener controlados los permisos
/// y no escribir cada vez una cosa por error, mayusculas minusculas, etc.
/// </summary>


enum Permisos { User, Admin, Error };

// Creo los posibles permisos para acceder a ellos.
extern Permisos permisoUsuario;
extern Permisos permisoAdmin;

static std::string enumToString(Permisos permiso)
{
	static std::map<Permisos, std::string> permisoToStringMap =
	{
		{Permisos::User, "User"},
		{Permisos::Admin, "Admin"},
		{Permisos::Error, "Error"}
	};

	auto it = permisoToStringMap.find(permiso);
	return (it != permisoToStringMap.end()) ? it->second : "Error"; // Valor predeterminado en caso de que no se encuentre
}

static Permisos stringToEnum(const std::string& permisoString) {
	static std::map<std::string, Permisos> stringToPermisosMap = {
		{"User", Permisos::User},
		{"Admin", Permisos::Admin},
		{"Error", Permisos::Error}
	};

	auto it = stringToPermisosMap.find(permisoString);
	return (it != stringToPermisosMap.end()) ? it->second : Permisos::Error; // Valor predeterminado en caso de que no se encuentre
}