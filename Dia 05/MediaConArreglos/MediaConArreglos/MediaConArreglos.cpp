
#include <iostream>
using namespace std;

int main()
{
    system("cls");
    int notas[5];
    int suma = 0;

    for (int i = 0; i < 5; i++)
    {
        cout << "Introduce una nota: ";  cin >> notas[i];
        cout << endl;
        suma += notas[i];
    }
    
    cout << "La nota media es: " << suma / 5 << endl;
    
    system("pause");
    return 0;
}

