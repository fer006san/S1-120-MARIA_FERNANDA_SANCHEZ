/*Atención de pacientes en una clínica
En una clínica, los pacientes llegan a la sala de espera y son atendidos en el orden en que llegaron.
Cada paciente tiene un nombre, edad y motivo de consulta.
Los pacientes son llamados por el médico uno a uno.
Crea un programa que gestione la llegada y atención de los pacientes de manera ordenada. */
#include <iostream>
#include "queue.h"
using namespace std;
class Paciente {
    private:
    string nombre;
    int edad;
    string motivo;

    public:
    Paciente(){
        nombre = "desconocido";
        edad = 0;
        motivo = "desconocido";
    }
    Paciente(int _edad, string _nombre, string _motivo){
        nombre = _nombre;
        edad = _edad;
        motivo = _motivo;
    }
    void setNombre(string _nombre){
        nombre = _nombre;
    }
    string getNombre()const{
        return nombre;
    }
    void setEdad(int _edad){
        edad = _edad;
    }
    int getEdad() const{
        return edad;
    }
    void setMotivo(string _motivo){
        motivo = _motivo;
    }
    string getMotivo()const{
        return motivo;
    }
    friend ostream& operator<<(ostream& os, const Paciente& p) {
        os << "[edad: " << p.edad << ", Nombre: " << p.nombre << ", motivo : " << p.motivo << "]";
        return os;
    }
};
class Clinica{
    private:
    Queue<Paciente> pacientes;

    public:
    void llegada(const Paciente &p) {
        pacientes.push(p);
        cout << "un paciente llego " << p <<endl ;
    }

    void atencion() {
        Paciente p;
        if (pacientes.pop(p)) {
            cout << "se atiende al primer paciente: " << p << endl;
        } else {
            cout << "No hay pacientes por atender  " << endl;
        }
    }
    void mostrar() {
        pacientes.print();
    }
};
int main(){
    Clinica sala;
    sala.llegada(Paciente(23,"Flavia","gripe"));
    sala.llegada(Paciente(67,"Omar","dolor de rodilla"));
    sala.llegada(Paciente(32,"Steve","gastritis"));
    sala.mostrar();

    cout << "atencion de pacientes" << endl;
    sala.atencion();
    sala.atencion();

    cout << "sala de espera actual "  << endl;
    sala.mostrar();

    return 0;
}
