#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "IDocument.h"

using namespace std;

class CsvDocument : IDocument
{
public:
	virtual void Open(string nombre)
	{
		m_out.open(nombre + ".csv");
	}
	virtual void Close()
	{
		m_out.close();
	}
	virtual void Write(vector<string> text)
	{
		for (auto& txt : text)
		{
			m_out << txt << ",";
		}
		m_out << endl;
	}
};