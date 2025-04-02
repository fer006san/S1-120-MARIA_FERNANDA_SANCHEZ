//Simetría en una Matriz: Crea la clase MathMatrix que derive de Matrix<int, ROWS,
//COLS> y agrega un método que determine si una matriz cuadrada es simétrica:
//Añade a MathMatrix métodos que encuentren el valor máximo, el valor mínimo y el promedio de una matriz.

#include "Matriz.h"
#include <iostream>
using namespace std;

template <int ROWS, int COLS>
class MathMatrix : public Matrix <int, ROWS, COLS>{
    public:
    bool esSimetrica(){
        for (int i = 0; i < ROWS / 2; i++){
            for (int j = 0; j < COLS / 2; j++){
                if (this->m[i][j] != this->m[j][i]){
                    return false;
                }
            }
        }
        return true;
    }
    int MaxValor(){
        int max = this->m[0][0];
        for (int i = 0; i < ROWS; i++){
            for (int j = 0; j < COLS; j++){
                if (this->m[i][j] > max ){
                    max = this->m[i][j];
                }
            }
        }
        return max;
    }
    int MinValor(){
        int min = this->m[0][0];
        for (int i = 0; i < ROWS; i++){
            for (int j = 0; j < COLS; j++){
                if (this->m[i][j] < min ){
                    min = this->m[i][j];
                }
            }
        }
        return min;
    }
    float promedio(){
        int suma = 0;
        int promedio = 0;
        for(int i = 0; i < ROWS; i++){
            for(int j= 0; j < COLS; j++){
                suma += this->m[i][j];
          }
        }
        promedio = suma / (ROWS * COLS);
        return promedio;
    }
};
int main (){
    MathMatrix <3,3> m;
    int value = 1;
    for (int i = 0; i < m.numRows(); i++)
    {
        for (int j = 0; j < m.numCols(); j++)
        {
            m.set(i, j, value++);
        }
    }

    m.print();

    cout << " es simetrica ?" << m.esSimetrica() << endl;
    cout << "el valor maximo es : " << m.MaxValor() << endl;
    cout << "el valor minimo es : " << m.MinValor() << endl;
    cout << "el promedio es : " << m.promedio() << endl;
}
