//Crea la clase GestionCalificaciones, que administre una matriz de calificaciones, donde:
// Las filas representan estudiantes. - Las columnas representan distintas materias o evaluaciones.
// Debe permitir: - Calcular el promedio de cada estudiante. - Obtener el promedio general del curso.
#include "Matriz.h"
#include <string>
#include "Vector.h"
#include <iostream>
using namespace std;
template <int ROWS, int COLS>
class GestionCalificaciones {
    private:
    Matrix<int, ROWS, COLS> calificaciones;
    Vector<string> nombres;

    public:

    GestionCalificaciones() : nombres(ROWS) {
        for(int i= 0; i < ROWS; i++){
            nombres.pushBack("");
        }
    }

    void agregarNombre(int estudiante,const string &nombre){
        if (estudiante >= 0 && estudiante < ROWS) {
            nombres.set(estudiante, nombre);
        } else {
            cout << "fuera de rango" << endl;
        }
    }

    void Calificaciones(int estudiante, int materia, int nota){
        if (estudiante >= 0 && estudiante < ROWS && materia >= 0 && materia < COLS) {
            calificaciones.set(estudiante, materia, nota);
        } else {
            cout << "fuera de rango" << endl;
        }
    }

    float promedioGrupo(){
        float sumaTotal = 0;
        for (int i = 0; i < ROWS; i++) {
            sumaTotal += promedioEs(i);
        }
        return sumaTotal / ROWS;
    }

    float promedioEs(int estudiante){
        if (estudiante < 0 || estudiante >= ROWS) return 0;
        float suma = 0;
        for (int i = 0; i < COLS; i++) {
            suma += calificaciones.at(estudiante, i);
        }
        return suma / COLS;
    }

    void mostrar(){
        cout << "MATRIZ DE CALIFICACIONES" << endl;
        for (int i=0; i < ROWS; i++){
            cout << nombres.at(i) << ":" << endl;
            for (int j=0; j< COLS; j++){
                cout << calificaciones.at(i,j) << "  " ;
            }
        }
        cout << endl;
    }
};

int main() {

    const int estudiantes = 3;
    const int materias = 3;
    GestionCalificaciones<estudiantes, materias> semestre;

    semestre.agregarNombre(0, "Maria");
    semestre.agregarNombre(1, "Flavia");
    semestre.agregarNombre(2, "Mateo");

    semestre.Calificaciones(0,0,85);
    semestre.Calificaciones(0,1,90);
    semestre.Calificaciones(0,2,90);

    semestre.Calificaciones(1,0,90);
    semestre.Calificaciones(1,1,92);
    semestre.Calificaciones(1,2,90);

    semestre.Calificaciones(2,0,100);
    semestre.Calificaciones(2,1,85);
    semestre.Calificaciones(2,2,95);

    semestre.mostrar();

    cout << "Promedio de Maria: " << semestre.promedioEs(0) << endl;
    cout << "Promedio de Flavia: " << semestre.promedioEs(1) << endl;
    cout << "Promedio de Mateo: " << semestre.promedioEs(2) << endl;

    cout << "Promedio general del curso: " << semestre.promedioGrupo() << endl;

    return 0;
}
