// Interfaces.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

class IAnimal // Clase abstact (interface)
{
public:
	virtual void Speak() = 0; // funcion puramente virtual
};

class Cat : public IAnimal
{
public:
	virtual void Speak()
	{
		cout << "MEOW" << endl;
	}
	virtual void ClawFurniture()
	{
		cout << "Your furniture is detroyect" << endl;
	}

};

class Dog : public IAnimal
{
public:
	virtual void Speak()
	{
		cout << "Wuaw" << endl;
	}

};


int main2()
{
	Cat gato;
	gato.Speak();

	Dog perro;
	perro.Speak();

	return 0;
}

