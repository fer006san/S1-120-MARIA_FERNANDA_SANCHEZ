/*En una estación de tren, los pasajeros hacen fila para comprar boletos.
Cada pasajero tiene un nombre y el destino al que quiere viajar.
El cajero atiende a los pasajeros en el orden en que llegaron.
Diseña un programa que gestione la cola de pasajeros y los atienda en el orden correcto.*/
#include <iostream>
#include "queue.h"
using namespace std;
class Boleto{
    private:
    string destino;
    string nombre;

    public:
    Boleto(){
        destino = "desconocido";
        nombre = "desconocido";
    }
    Boleto (string _nombre, string _destino){
        destino = _destino;
        nombre = _nombre;
    }
    void setDestino(string _destino){
        destino = _destino;
    }
    string getDestino()const{
        return destino;
    }
    void setNombre(int _nombre){
        nombre = _nombre;
    }
    string getNombre() const{
        return nombre;
    }
    friend ostream& operator<<(ostream& os, const Boleto& b) {
        os << "[Destino: " << b.destino << ", Nombre: " << b.nombre << "]";
        return os;
    }
};
class Tren{
    private:
    Queue<Boleto> boletos;

    public:
    void llegada(const Boleto &b) {
        boletos.push(b);
        cout << "llegada de pasajero " << b <<endl ;
    }

    void atencion() {
        Boleto b;
        if (boletos.pop(b)) {
            cout << "salida de pasajero: " << b << endl;
        } else {
            cout << "No hay pasajeros por atender" << endl;
        }
    }
    void mostrar() {
        boletos.print();
    }
};
int main(){
    Tren programa;

    programa.llegada(Boleto("Steven", "Venecia"));
    programa.llegada(Boleto("Alex", "Paris"));
    programa.llegada(Boleto("Jack", "Sicilia"));
    programa.mostrar();

    programa.atencion();
    programa.atencion();
    programa.mostrar();
}
