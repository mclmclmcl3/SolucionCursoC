
#include <iostream>
#include <locale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    cout << "Hola ñoñó" << endl;

    system("pause");
    return 0;
}

