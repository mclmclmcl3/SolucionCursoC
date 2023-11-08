#include <iostream>

using namespace std;

int main2()
{
	int a = 10;
	int b = 10;

	cout << "++a => " << ++a << endl; // ++a => 11
	cout << "b++ => " << b++ << endl; // b++ => 10

	cout << "pero realmente b a cambiado a => " << b << endl; //pero realmente b a cambiado a => 11

	system("pause");
	return 0;
}