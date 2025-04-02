//Simetría en un Vector: Implementa una función que verifique si un vector de enteros es simétrico.
//Ejemplo: [1, 2, 3, 2, 1] es simétrico, pero [1, 2, 3, 4] no lo es.
//2. Suma de Pares en Vectores: Implementa una función que calcule la suma de los números pares en un vector de enteros.
#include "Vector.h"
#include <iostream>
using namespace std;

bool es_simetrico(const Vector<int> &v) {
    int j = v.getSize() - 1;
    for (int i = 0; i < v.getSize() / 2; i++) {
        if (v.at(i) != v.at(j)) {
            return false;
        }
    }
    return true;
}

int pares(const Vector<int> &v) {
    int suma = 0;
    for (int i = 0; i < v.getSize(); i++) {
        if (v.at(i) % 2 == 0) {
            suma += v.at(i);
        }
    }
    return suma;
}

int main() {
    Vector<int> v1;

    v1.pushBack(1);
    v1.pushBack(2);
    v1.pushBack(3);
    v1.pushBack(2);
    v1.pushBack(1);

    cout << "Vector: ";
    v1.print();

    cout << "¿Es simétrico? " << es_simetrico(v1) << endl;
    cout << "Suma de pares: " << pares(v1) << endl;

    return 0;
}
