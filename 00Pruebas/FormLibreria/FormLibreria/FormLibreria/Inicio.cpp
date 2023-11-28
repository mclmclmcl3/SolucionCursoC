#pragma once

#include "Views/FormLibreria.h"
#include "Models/Libreria.h"

using namespace System::Windows::Forms;



int main()
{
	Application::Run(gcnew FormLibreria::FormLibreria);
	//Application::Run(gcnew FormLibreria::FormLogin);
	//Application::Run(gcnew FormLibreria::PruebasRapidas);
	return 0;
};
