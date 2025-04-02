//Registro de Calificaciones: Crea la clase GestionCalificaciones, que administre
//una matriz de calificaciones, donde:  Las filas representan estudiantes.
//Las columnas representan distintas materias o evaluaciones.
//Debe permitir: Calcular el promedio de cada estudiante. Obtener el promedio general del curso.
#include "Vector.h"
#include <iostream>
using namespace std;

class Estudiante {
    private:
    int registro;
    string nombre;
    Vector<int> calificaciones;

    public:
    Estudiante(){
        registro = 0;
        nombre = "desconocido";
    }

    Estudiante(int _registro, string _nombre, int _p1, int _p2, int _pp) {
        registro = _registro;
        nombre = _nombre;
        calificaciones.pushBack(_p1);
        calificaciones.pushBack(_p2);
        calificaciones.pushBack(_pp);
    }

    void setRegistro(int _registro){
        registro = _registro;
    }

    int getRegistro() {
        return registro;
    }

    void setNombre(string _nombre){
        nombre = _nombre;
    }

    string getNombre() {
        return nombre;
    }

    Vector<int> getCalificaciones(){
        return calificaciones;
    }

    void mostrar(){
        cout << "Registro: " << registro << ", Nombre: " << nombre << ", Calificaciones: ";
        for (int i = 0; i < calificaciones.getSize(); i++) {
            cout << calificaciones.at(i) << " ";
        }
        cout << endl;
    }
};

class GestionAcademica {
    private:
    Vector<Estudiante> estudiantes;

    public:
    void agregar(Estudiante e){
        estudiantes.pushBack(e);
    }

    float promedioEstudiante(Estudiante e){
        Vector<int> calificaciones = e.getCalificaciones();
        if (calificaciones.getSize() == 0) return 0;

        float suma = 0;
        for (int i = 0; i < calificaciones.getSize(); i++) {
            suma += calificaciones.at(i);
        }
        return suma / calificaciones.getSize();
    }

    float promedioGrupo(){
        if (estudiantes.getSize() == 0) return 0;

        float sumaTotal = 0;
        for (int i = 0; i < estudiantes.getSize(); i++) {
            sumaTotal += promedioEstudiante(estudiantes.at(i));
        }
        return sumaTotal / estudiantes.getSize();
    }

    void promedioEs(){
        for (int i = 0; i < estudiantes.getSize(); i++) {
            estudiantes.at(i).mostrar();
            cout << "Promedio del estudiante: " << promedioEstudiante(estudiantes.at(i)) << endl;
        }
    }
};

int main() {
    Estudiante E1(238, "Maria", 85, 90, 90);
    Estudiante E2(385, "Flavia", 90, 92, 90);
    Estudiante E3(752, "Mateo", 100, 85, 95);

    GestionAcademica semestre;
    semestre.agregar(E1);
    semestre.agregar(E2);
    semestre.agregar(E3);

    cout << "Lista de estudiantes:" << endl;
    semestre.promedioEs();

    cout << "Promedio general del grupo: " << semestre.promedioGrupo() << endl;

    return 0;
}
