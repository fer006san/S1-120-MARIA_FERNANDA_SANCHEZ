//Operaciones entre Matrices: Crea la clase MatrixCalculator, que implemente métodos para realizar operaciones entre matrices del mismo tamaño: -
//Suma - Resta - Multiplicación
#include <iostream>
#include "Matriz.h"
using namespace std;
template <int ROWS, int COLS>
class MatrixCalculator {
    public :
    Matrix<int, ROWS, COLS> suma(const Matrix<int, ROWS, COLS> &m1, const Matrix<int,  ROWS, COLS> &m2){
        Matrix<int, ROWS, COLS> resultado;
        for (int i =0; i < ROWS; i++){
            for (int j=0; j < COLS; j++){
                int suma = m1.at(i,j) + m2.at(i,j);
                resultado.set(i,j,suma);
            }
        }
        return resultado;
    }
    Matrix<int, ROWS, COLS> resta(const Matrix<int, ROWS, COLS> &m1, const Matrix<int,ROWS, COLS> &m2){
        Matrix<int, ROWS,COLS> result;
        for (int i=0; i < ROWS; i++){
            for (int j=0; j < COLS; j++){
                int resta = m1.at(i,j) - m2.at(i,j);
                result.set(i,j,resta);
            }
        }
        return result;
    }
    Matrix<int, ROWS, COLS> mult(const Matrix<int,ROWS,COLS> &m1, const Matrix<int, ROWS,COLS> &m2){
        Matrix<int, ROWS,COLS> r;
        for(int i =0; i <ROWS; i++){
            for (int j=0; j < COLS; j++){
                int multi = m1.at(i,j) * m2.at(i,j);
                r.set(i,j,multi);
            }
        }
        return r;
    }
};
int main(){
    Matrix<int, 3, 3> m1, m2;
    int val= 2;
    for (int i = 0; i < m1.numRows(); i++)
    {
        for (int j = 0; j < m1.numCols(); j++)
        {
            m1.set(i, j, val++);
        }
    }
    cout<< "MATRICES INICIALES " << endl;
    m1.print();
    cout << endl;
    int value= 1;
    for (int i = 0; i < m2.numRows(); i++)
    {
        for (int j = 0; j < m2.numCols(); j++)
        {
            m2.set(i, j, value++);
        }
    }
    m2.print();
    cout << endl;
    MatrixCalculator<3,3> cal;
    Matrix<int, 3, 3> resultado = cal.suma(m1,m2);
    cout << "el resultado de la suma es" << endl;
    resultado.print();
    cout<< endl;
    Matrix<int, 3,3> result = cal.resta(m1,m2);
    cout << "el resultado de la resta es" << endl;
    result.print();
    cout<< endl;
    Matrix<int, 3,3> r = cal.mult(m1,m2);
    cout<< "el resultado de la multiplicacion es" << endl;
    r.print();

    return 0;

}
