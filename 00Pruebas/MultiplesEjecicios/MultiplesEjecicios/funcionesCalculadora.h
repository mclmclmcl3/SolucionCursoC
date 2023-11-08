#pragma once

//****************************************//
// FUNCIONES							  //
//****************************************//
// Version 1.0          				  //
// Ultima modificacion documentada        //
// 29/10/2023                             //
// Creaccion							  //
//****************************************//

#include <iostream>
#include <sstream>
#include <conio.h>

using namespace std;

namespace calculadora
{
	// Funcion sumar
	double Sumar(double n1, double n2);

	// Funcion Restar
	double Restar(double n1, double n2);

	// Funcion Multiplicar
	double Multiplicar(double n1, double n2);

	// Funcion Dividir
	double Dividir(double n1, double n2);

	// Funcion Imprimir en pantalla el resultado
	void Imprimir(double resultado, string operacion);

	// Funcion Solicitar un numero por pantalla
	double PedirNumero();

	// Funcion Sacar el menu de la calculadora
	int Menu();

	// Funciones de advertencia al usuario
	void Advertencia(string mensaje);

	// Convertir double a string
	string doubleToString(double numero);
}
