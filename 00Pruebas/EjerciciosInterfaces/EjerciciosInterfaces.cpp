
#include <iostream>
#include "InterfacesArchivos/Txtdocument.h"
#include "InterfacesArchivos/Csvdocument.h"
#include "InterfacesArchivos/Htmldocument.h"

#include "InjeccionDependencias/loc.h"
#include "InjeccionDependencias/FactoryIoC.h"
#include "InjeccionDependencias/ServiceIoC.h"

using namespace std;

void InyeccionDependencia();
void Herencia();

int main()
{
	// Herencia();
	InyeccionDependencia();
	return 0;
}

void Herencia()
{
	TxtDocument myTest;
	myTest.Open("Test");
	myTest.Write({ "Hello","word","how","are","you" });
	myTest.Close();

	CsvDocument mySpreadsheet;
	mySpreadsheet.Open("Test");
	mySpreadsheet.Write({ "NAME", "BREED" });
	mySpreadsheet.Write({ "Ein", "Cofgi" });
	mySpreadsheet.Write({ "Luna", "Cat" });
	mySpreadsheet.Close();

	HtmlDocument myWebPage;
	myWebPage.Open("test");
	myWebPage.Write({ "Hello","word","how","are","you" });
	myWebPage.Close();
}

void InyeccionDependencia()
{
	// Crear la fábrica de dependencias
	DependencyFactory dependencyFactory;

	// Registrar servicios en la fábrica
	dependencyFactory.RegisterService<EnharedDocumentD>("EnharedDocumentD");
	dependencyFactory.RegisterService<DocumentA>("DocumentA");
	dependencyFactory.RegisterService<DocumentB>("DocumentB");
	//dependencyFactory.RegisterService<DocumentC>("DocumentC");

	//// Registrar servicios con dependencias
	//dependencyFactory.RegisterServiceWithDependencies<DocumentC>("DocumentAWithDependencies", dependencyFactory.Resolve("EnhancedService"));
	//shared_ptr<IService> serviceD = dependencyFactory.Resolve("DocumentAWithDependencies");

	// Resolver e utilizar servicios
	shared_ptr<IService> service1 = dependencyFactory.Resolve("DocumentA");
	cout << service1->Procesando() << endl;


	//std::shared_ptr<IService> service2 = dependencyFactory.Resolve("DocumentB");
	//service2->Procesando();

}