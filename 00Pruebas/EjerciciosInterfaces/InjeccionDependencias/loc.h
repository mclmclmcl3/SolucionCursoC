#pragma once

#include <string>
#include <memory>
#include "FactoryIoC.h"


using namespace std;

// Interfaz base
class IService {
public:
	virtual string Procesando() = 0;
	virtual ~IService() = default;
};


class DocumentD : public IService {
public:
	string Procesando() override { return "D"; }
};


class EnharedDocumentD : public DocumentD {
public:
	string Procesando() override { return "Hola"; }
};


class DocumentC : public IService {
private:
	shared_ptr<DocumentD> compD;
public:

	DocumentC() : compD(make_shared<DocumentD>()) {}
	string Procesando() override
	{
		return compD->Procesando() + "-C";
	}
};

class DocumentB : public IService {
private:
	shared_ptr<DocumentC> compC;
public:

	DocumentB() : compC(make_shared< DocumentC>()) {}
	string Procesando() override
	{
		return compC->Procesando() + "-B";
	}
};

class DocumentA : public IService {
private:
	shared_ptr<DocumentB> compB;
public:

	DocumentA() : compB(make_shared< DocumentB>()) {}
	string Procesando() override
	{
		return compB->Procesando() + "-A";
	}
};