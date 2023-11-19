#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "IDocument.h"

using namespace std;

class HtmlDocument : IDocument
{
public:
	virtual void Open(string nombre)
	{
		m_out.open(nombre + ".html");
		m_out << "<!DOCTYPE html>" << endl;
		m_out << "<html >" << endl;
		m_out << "<head>" << endl;
		m_out << "<title>Pagina Prueba</title>" << endl;
		m_out << "</head>" << endl;
		m_out << "<body>" << endl;
	}
	virtual void Close()
	{
		m_out << "</body>" << endl;
		m_out << "</html>" << endl;
		m_out.close();
	}
	virtual void Write(vector<string> text)
	{
		m_out << "<h1>";
		for (auto& txt : text)
		{
			m_out << txt << " ";
		}
		m_out << "</h1>";
	}
};