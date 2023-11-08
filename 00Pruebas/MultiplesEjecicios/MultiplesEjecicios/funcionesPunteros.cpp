

#include "funcionesPunteros.h"

namespace punteros
{
	int longitudCadena(char* cadena)
	{
		char* pcadena = cadena;
		const char* incio = pcadena;

		while (*pcadena != '\0')
		{
			pcadena++;
		}
		return pcadena - incio;
	}

	int BuscaCaracter(const char* cadena, char caracter) {
		for (int i = 0; cadena[i] != '\0'; i++) {
			if (cadena[i] == caracter) {
				return i; // Se encontr� el car�cter, devolvemos la posici�n
			}
		}
		return -1; // No se encontr� el car�cter en la cadena
	}
}