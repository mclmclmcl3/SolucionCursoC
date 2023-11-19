#pragma once

#include <string>
#include <vector>
#include <fstream>
using namespace std;

class IDocument
{
public:
	virtual void Open(string filename) = 0;
	virtual void Close() = 0;
	virtual void Write(vector<string> text) = 0;

protected:
	ofstream m_out;
};
