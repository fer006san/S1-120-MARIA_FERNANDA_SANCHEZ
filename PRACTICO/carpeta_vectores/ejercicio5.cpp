//Crea la clase VectorCalculator que tenga métodos
//que reciban dos vectores como parámetros y calcule las siguientes operaciones
//elemento a elemento:
//Suma, Resta y Multiplicación
#include <iostream>
#include "Vector.h"
using namespace std;

class VectorCalculator {

    public:
    Vector <int> sumaVectores(const Vector<int> &v1, const Vector<int> &v2){
        Vector<int> resultado;
        int suma=0;
        int siz=v1.getSize();
        for (int i= 0; i< siz; i++){
            int suma = v1.at(i) + v2.at(i);
            resultado.pushBack(suma);
        }

        return resultado;
    }

    Vector <int> restaVectores(const Vector<int> &v1, const Vector<int> &v2){
        Vector<int> result;
        int resta= 0;
        int siz=v1.getSize();
        for(int i = 0; i < siz; i++){
            int resta = v1.at(i)- v2.at(i);
            result.pushBack(resta);
        }
        return result;
    }

    Vector <int> multiplicacionVectores (const Vector<int> &v1, const Vector<int> &v2){
        Vector <int> r;
        int mult= 0;
        int siz = v1.getSize();
        for(int i = 0; i < siz; i++){
            int mult = v1.at(i)* v2.at(i);
            r.pushBack(mult);
        }
        return r;
    }

};
int main (){
    Vector<int> v1, v2;

    v1.pushBack(2);
    v1.pushBack(3);
    v1.pushBack(4);

    v2.pushBack(1);
    v2.pushBack(2);
    v2.pushBack(3);

    VectorCalculator calculador;
    Vector <int> resultado = calculador.sumaVectores(v1, v2);
    Vector <int> result = calculador.restaVectores(v1, v2);
    Vector <int> r = calculador.multiplicacionVectores(v1, v2);

    cout << "el vector resultante de la suma  es : " << endl;
    resultado.print();

    cout << "el vector resultante de la resta es : " << endl;
    result.print();

    cout << "el vector resultante de la multiplicacion es : " << endl;
    r.print();

    return 0;
}
