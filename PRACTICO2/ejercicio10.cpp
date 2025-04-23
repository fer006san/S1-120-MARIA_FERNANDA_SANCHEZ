/*En una empresa de soporte técnico, las consultas de los clientes se procesan en el orden en que se reciben.
Cada consulta tiene un nombre del cliente y una descripción del problema.
Diseña un programa que gestione la fila de consultas y permita saber cuál es la siguiente consulta a atender.*/
#include <iostream>
#include "queue.h"
using namespace std;
class Consulta{
    private:
    string problema;
    string nombre;

    public:
    Consulta(){
        problema = "desconocido";
        nombre = "desconocido";
    }
    Consulta(string _nombre, string _problema){
        problema = _problema;
        nombre = _nombre;
    }
    void setProblema(string _problema){
        problema = _problema;
    }
    string getProblema()const{
        return problema;
    }
    void setNombre(int _nombre){
        nombre = _nombre;
    }
    string getNombre() const{
        return nombre;
    }
    friend ostream& operator<<(ostream& os, const Consulta& c) {
        os << "[problema: " << c.problema << ", nombre: " << c.nombre << "]";
        return os;
    }
};
class Tecnico{
    private:
    Queue<Consulta> clientes;

    public:
    void llegada(const Consulta &c) {
        clientes.push(c);
        cout << "llegada de cliente " << c <<endl ;
    }

    void atencion() {
        Consulta c;
        if (clientes.pop(c)) {
            cout << "se atiende a cliente " << c << endl;
        } else {
            cout << "No hay clientes por atender" << endl;
        }
    }
    void mostrar() {
        clientes.print();
    }
};
int main(){
    Tecnico programa;

    programa.llegada(Consulta("Steven", "se quemo su computadora"));
    programa.llegada(Consulta("Alex", "se olvido su contraseña"));
    programa.llegada(Consulta("Jack", "no prende su computadora"));

    programa.mostrar();

    programa.atencion();
    programa.atencion();
    programa.mostrar();
}
