
#include <iostream>

using namespace std;

void manipulacion(string* nombre, string apellido);

int main()
{
	system("cls");

	int x = 5, y = 10, aux = 0;
	int* px = &x; // pongo en px la direccion de x
	int* py = &y; // pongo en py la direccion de y

	cout << "px " << px << endl;
	cout << "py " << py << endl;

	cout << "*px " << *px << endl; // devuelve el contenido de px
	cout << "*py " << *py << endl; // devuelve el contenido de py

	const char* a[] = { "Pedro","Fran","Ana","Katty","Claudia" }; // no se puden modificar las direcciones pero si el contenido
	cout << *(a + 1) << "\n";			// devuelvo Fran
	cout << *(*(a + 1) + 1) << "\n";	// devuvelve r de Fran


	string nombre = "Mariano", apellido = "Crespo";
	cout << nombre << " ," << apellido << endl;
	manipulacion(&nombre, apellido);
	cout << nombre << " ," << apellido << endl;


	system("pause");
	return 0;
}


void manipulacion(string* nombre, string apellido)
{
	*nombre = "pedro";
	apellido = "Ruiz";
}

/*
*
*    ptr				=> contenido
*	*ptr				=> valor
*	&x					=> direccion
*	*ptr = &x			=> el valor de ptr es = a la direccion de x
*	**ptrdoble = &ptr	=> el valor de ptrdoble = a la direccion de prt
*	int a[]={3,5,6,8,3,6,7,9}
*	int *ptr = &a[0]	=> el puntero tiene la direccion del primer elemento o sea 3
*	int *ptr = &a[3]	=> el puntero tiene la direccion del primer elemento o sea 8
*	*ptr = 55;
*	a[5]				=> se cambia 6 por 55
*
*	for(int i=0; i<8;i++)
*		cout << *(ptr+i) << "\n"; => se imprimer los elementos del array
*
* */
