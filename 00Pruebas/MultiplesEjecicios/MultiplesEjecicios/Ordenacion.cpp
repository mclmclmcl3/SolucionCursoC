

#include "funcionesOrdenacion.h"
#include "MainOrdenacion.h"

using namespace listasOrdenadas;
using namespace std;

namespace listasOrdenadas
{
	void MainOrdenacion()
	{
		//MainCalculadora();
		int lista[] = { 21,58,69,563,25,15,7,5,2,365,89 };
		int longitud = sizeof(lista) / sizeof(lista[0]);

		int* listaOrdenada = Burbuja(lista, longitud);

		for (int i = 0; i < longitud; i++)
		{
			cout << listaOrdenada[i] << " ";
		}

		delete[] listaOrdenada; // No olvides liberar la memoria después de usar el arreglo dinámico.

	}

}
