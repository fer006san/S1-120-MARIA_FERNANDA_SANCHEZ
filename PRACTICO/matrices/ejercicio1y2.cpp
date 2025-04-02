//Implementa una función que reciba
//una matriz de enteros y retorne la suma de todos los números impares contenidos
//en ella.
//2. Cálculo de la Suma de Cada Fila: Escribe una función que reciba una matriz de enteros y devuelva un vector con la suma de cada fila
#include "Matriz.h"
#include "Vector.h"
#include <iostream>
using namespace std;

template <int ROWS, int COLS>
int sumaImpares(const Matrix<int, ROWS, COLS> &m) {
    int suma = 0;
    for (int i=0; i< ROWS; i++){
        for (int j=0; j<COLS; j++){
            if (m.at(i,j) % 2 != 0){
                suma += m.at(i,j);

                }
         }
    }
    return suma;
}
template <int ROWS, int COLS>
Vector<int> sumaFilas(const Matrix<int, ROWS, COLS > &m){
    Vector<int> suma;
    for(int i=0; i<ROWS; i++){
        int s= 0;
        for(int j=0; j<COLS; j++){
            s += m.at(i,j);
        }
        suma.pushBack(s);
    }
    return suma;
}

int main()
{
    Matrix<int, 3, 3> m;
    int value = 1;
    for (int i = 0; i < m.numRows(); i++)
    {
        for (int j = 0; j < m.numCols(); j++)
        {
            m.set(i, j, value++);
        }
    }

    m.print();

    cout << "la suma de los impares es " << sumaImpares<3, 3>(m) << endl;
    cout<< endl;

    Vector<int> resultado = sumaFilas<3,3>(m);

    cout << "la suma de las filas es : " <<endl;
    for (int i = 0; i < resultado.getSize(); i++){
        cout << resultado.at(i) << " ";
    }
    cout << endl;

    return 0;
}
