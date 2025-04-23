/*En una clase de matemáticas, los alumnos van entregando sus exámenes uno por uno.
El profesor debe calcular el promedio de las notas.
Las notas se entregan una tras otra.
Diseña un programa que reciba las notas de los estudiantes y luego calcule el promedio de todas las notas una vez que se hayan registrado todas.*/
#include <iostream>
#include "queue.h"
using namespace std;

class Profesor {
    private:
    Queue<float> notas;

    public:
    void recibirNota(float nota) {
        notas.push(nota);
        cout << "nota recibida: " << nota << endl;
    }

    void calcularPromedio() {
        float suma = 0;
        int cantidad = 0;
        float nota;
        Queue<float> auxiliar;
        while (notas.pop(nota)) {
            suma += nota;
            cantidad++;
            auxiliar.push(nota);
        }
        while (auxiliar.pop(nota)) {
            notas.push(nota);
        }
        float promedio = suma / cantidad;
        cout << "promedio de notas: " << promedio << endl;
    }
    void mostrarNotas() {
        notas.print();
    }
};
int main() {
    Profesor p;
    p.recibirNota(8.5);
    p.recibirNota(7.0);
    p.recibirNota(9.3);
    p.recibirNota(6.5);
    p.mostrarNotas();

    p.calcularPromedio();
}
