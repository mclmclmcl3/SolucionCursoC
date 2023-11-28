#include <iostream>
#include <vector>

using namespace std;

// Definición de la clase Libro
class Libro {
private:
	// para crear objetos con id consecutivo
	int static miId;

	// Campos
	int id;
	string titulo;
	string autor;
	double precio;

public:
	// Constructor vacio para cuando elijo un libro.
	Libro() {}

	// Inicialar el Constructor (No añado el Id, ya que es auto_increment)
	Libro(string _titulo, string _autor, double _precio)
	{
		miId++;
		id = miId;
		titulo = _titulo;
		autor = _autor;
		precio = _precio;
	}

	// Getter
	int GetId() { return id; }
	string GetTitulo() { return titulo; }
	string GetAutor() { return autor; }
	double GetPrecio() { return precio; }

	// Setter
	void SetTitulo(string _titulo) { titulo = _titulo; }
	void SetAutor(string _autor) { autor = _autor; }
	void SetTitulo(double _precio) { precio = _precio; }
};

// Inicializar la variable estatica para simular el Id de una base de datos
int Libro::miId = 0;

// Definición de la clase Tienda
class Tienda {
private:
	vector<Libro> StockLibros;

public:
	// Sacar el numero de libros
	int NumeroLibros() { return StockLibros.size(); }

	// Retorna el libro por su Id
	Libro GetById(int id) { return StockLibros[id]; }

	// Insertar libros
	void InsertLibro(Libro _libro) { StockLibros.push_back(_libro); }

	// Mostrar toda la libreria
	void MostrarLibreria()
	{
		int longitud = StockLibros.size();
		std::cout << "\nLibros disponibles en la libreria:" << endl << endl;
		double total = 0;
		for (int i = 0; i < StockLibros.size(); i++)
		{
			std::cout << "   " << StockLibros[i].GetId() << StockLibros[i].GetTitulo() << " - " << StockLibros[i].GetAutor() << " - " << StockLibros[i].GetPrecio() << " eur" << endl;
			total += StockLibros[i].GetPrecio();
		}
	}
};

// Definición de la clase Carrito
class Carrito {
private:
	vector<Libro> StockLibros;
	double total;
	double iva;

public:
	// Insertar libros
	void InsertLibro(Libro _libro) { StockLibros.push_back(_libro); }

	// Muestro el estado del carrito
	void ListadoCarrito()
	{
		system("cls");
		int longitud = StockLibros.size();
		std::cout << "\nEste es el contenido de tu carrito:" << endl << endl;
		for (int i = 0; i < StockLibros.size(); i++)
		{
			std::cout << "   " << StockLibros[i].GetTitulo() << " - " << StockLibros[i].GetAutor() << " - " << StockLibros[i].GetPrecio() << " eur" << endl;
			total += StockLibros[i].GetPrecio();
		}
		cout << endl << endl;
	}

	// Creo la factura
	void Factura()
	{
		if (total != 0)
		{
			double iva = total * 0.1;
			double total_con_iva = total + iva;

			cout << "\nImporte total: " << total << " eur" << endl;
			cout << "IVA (10%): " << iva << " eur" << endl;
			cout << "Total con IVA: " << total_con_iva << " eur" << endl << endl << endl;
		}
		else
		{
			cout << "No has cogido ningun libro" << endl;
		}
		system("pause");
	}
};


// Metodo para el idioma
void IdiomaEs()
{
	setlocale(LC_ALL, "es_ES.UTF-8");
}


// Inicio Programa
int main() {

	IdiomaEs();

	// Crear instancias de la clase Libro
	Libro libro1("La Catedral del Mar", "Ildefonso Falcones", 19.80);
	Libro libro2("La sombra del viento", "Carlos Ruiz Zafón", 15.20);
	Libro libro3("Los Pilares de La Tierra", "Ken Follet", 21.20);

	// Llenar la tienda de libros
	Tienda tienda;
	tienda.InsertLibro(libro1);
	tienda.InsertLibro(libro2);
	tienda.InsertLibro(libro3);

	// Inicializo el carrito fuera del while para luego acceder a los metodos mostrarCarrito y Factura.
	Carrito carrito;

	while (true) {

		// Limpio la pantala para iniciar
		system("cls");

		// Mostrar el menú de libros disponibles
		tienda.MostrarLibreria();

		// Opción para elegir un libro
		cout << "\n\tElija un libro por su número (0 para finalizar): ";
		int opcion;

		// Comprobar posible error en cin
		while (!(cin >> opcion)) {
			cout << "Entrada no válida. Por favor, ingrese un número valido." << endl;
			cin.clear();  // Limpiar el estado de error
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada no válida
		}

		// Salir del bucle si se ingresa 0
		if (opcion == 0) {
			break;
		}

		// Compruebo que no se salga de la lista
		if (opcion > tienda.NumeroLibros() || opcion < 0) continue;

		// Busco en la tienda el libro seleccionado por su id.
		Libro libro_elegido = tienda.GetById(opcion - 1);

		// Inserto el libro seleccionado en el carrito
		carrito.InsertLibro(libro_elegido);

		// Hago feedback al usuario
		system("cls");
		cout << " - " << libro_elegido.GetTitulo() << "\tañadido al carrito. " << endl;
		system("pause");

	}

	// Mostrar el carrito y calcular el importe total con IVA
	carrito.ListadoCarrito();

	// Crear factura
	carrito.Factura();

	return 0;
}
