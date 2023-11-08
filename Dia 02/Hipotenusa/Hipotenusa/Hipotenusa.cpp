
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double catetoA, catetoB;

    // Solicitar al usuario que ingrese los valores de los catetos
    cout << "Ingresa el valor del cateto A: ";
    cin >> catetoA;

    cout << "Ingresa el valor del cateto B: ";
    cin >> catetoB;

    // Calcular la hipotenusa utilizando el teorema de Pitágoras
    double hipotenusa = sqrt(pow(catetoA, 2) + pow(catetoB,2));

    // Mostrar el resultado
    cout << "La hipotenusa de " << catetoA << " y " << catetoB << " es: " << hipotenusa << " con sqrt y pow" << endl;
    cout << "La hipotenusa de " << catetoA << " y " << catetoB << " es: " << hypot(catetoA, catetoB) << " con la funcion hypot() " << endl;

    system("pause");
    return 0;
}

