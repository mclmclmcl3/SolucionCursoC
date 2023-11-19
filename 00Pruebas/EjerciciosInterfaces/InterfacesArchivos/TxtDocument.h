#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "IDocument.h"

using namespace std;

class TxtDocument : IDocument
{
public:
	virtual void Open(string nombre)
	{
		m_out.open(nombre + ".txt");
	}
	virtual void Close()
	{
		m_out.close();
	}
	virtual void Write(vector<string> text)
	{
		for (auto& txt : text)
		{
			m_out << txt << " ";
		}
	}
};