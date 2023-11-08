
#include "funcionesOrdenacion.h"

namespace listasOrdenadas
{
	// Es muy lento y no se recomienda
	int* Burbuja(int lista[], int longitud)
	{
		for (int i = 0; i < longitud; i++)
		{
			for (int j = 0; j < longitud - 1; j++)
			{
				if (lista[j] > lista[j + 1])
				{
					int temp = lista[j];
					lista[j] = lista[j + 1];
					lista[j + 1] = temp;
				}
			}
		}
		int* listaOrdenada = new int[longitud]; // Crear un nuevo arreglo para almacenar la lista ordenada.
		for (int i = 0; i < longitud; i++)
		{
			listaOrdenada[i] = lista[i];
		}

		return listaOrdenada;
	};
}
