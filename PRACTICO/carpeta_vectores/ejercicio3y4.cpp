//3. Crea la clase MathVector, que derive de Vector<int>, e implemente métodos para:
//Calcular el promedio de los valores del vector.- Determinar la mediana del conjunto de datos.- Identificar la moda (el número que más veces aparece).
//4. Máximo y Mínimo: Añade a la clase MathVector los siguientes métodos: -Encontrar el valor máximo del vector. -Encontrar el valor mínimo del vector.
#include "Vector.h"
#include <iostream>
#include <algorithm>

using namespace std;

class MathVector : public Vector<int>{
    public :
    float promedio(){
        int suma = 0;
        int promedio = 0;
        for (int i = 0; i < size; i++){
            suma += items[i];
        }
        promedio = suma / size;

        return promedio;
    }
    double mediana() {
        int temp[size];
        for (int i = 0; i < size; i++) {
            temp[i] = items[i];
        }
        sort(temp, temp + size);

        if (size % 2 != 0) {
            return temp[size / 2];
        } else {
            return (temp[size / 2 - 1] + temp[size / 2]) / 2.0;
        }
    }

    int moda() {
        int moda = items[0];
        int maxFrecuencia = 0;

        for (int i = 0; i < size; i++) {
            int frecuencia = 0;
            bool yaContado = false;

            for (int j = 0; j < i; j++) {
                if (items[i] == items[j]) {
                    yaContado = true;
                    break;
                }
            }

            if (yaContado) {
                continue;
            }
            for (int k = 0; k < size; k++) {
                if (items[i] == items[k]) {
                    frecuencia++;
                }
            }
            if (frecuencia > maxFrecuencia) {
                maxFrecuencia = frecuencia;
                moda = items[i];
            }
        }

        return moda;
    }

    int MaxValor(){
        int max = items[0];
        for (int i= 0; i < size; i++){
            if ( items[i] > max ){
                max = items[i];
            }

        }
        return max;
    }

    int MinValor(){
        int min = items[0];
        for(int i= 0;i < size; i++ ){
            if (items[i] < min){
                min = items[i];
            }
        }
        return min;
    }
};

int main (){
    MathVector v;

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);
    v.pushBack(3);
    v.pushBack(5);
    v.pushBack(2);

    cout << "vector";
    v.print();

    cout << "promedio :" << v.promedio() << endl;
    cout << "mediana :" << v.mediana() << endl;
    cout << "moda :" << v.moda() << endl;
    cout << "valor maximo : " << v.MaxValor() << endl;
    cout << "valor minimo :" << v.MinValor() << endl;

    return 0;
}
