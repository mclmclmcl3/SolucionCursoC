#include <iostream>
#include <string>

using namespace std;

int main3()
{
	try
	{
		string num = "a33a";
		int n = 0;

		n = stoi(num);
		cout << "correcto " << n;
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}

	try {
		int age = 15;
		if (age >= 18) {
			cout << "Access granted - you are old enough.";
		}
		else {
			throw 505;
		}
	}
	catch (int myNum) {
		cout << "Access denied - You must be at least 18 years old.\n";
		cout << "Error number: " << myNum;
	}


	cout << endl;
	system("pause");
	return 0;
}