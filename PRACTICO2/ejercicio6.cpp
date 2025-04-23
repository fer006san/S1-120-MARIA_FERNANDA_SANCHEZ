/*En un banco, los clientes reciben un número de turno al llegar, y son atendidos en ese mismo orden.
Cada cliente tiene un nombre y el tipo de transacción que desea realizar (depósito, retiro, etc.).
Crea un programa que gestione la fila de clientes y los vaya atendiendo uno por uno.*/
#include <iostream>
#include "queue.h"
using namespace std;
class Cliente {
    private:
    string tipo;
    string nombre;

    public:
    Cliente(){
        tipo = "desconocido";
        nombre = "desconocido";
    }
    Cliente (string _nombre, string _tipo){
        tipo = _tipo;
        nombre = _nombre;
    }
    void setTipo(string _tipo){
        tipo = _tipo;
    }
    string getTipo()const{
        return tipo;
    }
    void setNombre(int _nombre){
        nombre = _nombre;
    }
    string getNombre() const{
        return nombre;
    }
    friend ostream& operator<<(ostream& os, const Cliente& c) {
        os << "[Nombre: " << c.nombre << ", Tipo: " << c.tipo << "]";
        return os;
    }
};
class Turno{
    private:
    Queue<Cliente> clientes;

    public:
    void recepcion(const Cliente &c) {
        clientes.push(c);
        cout << "llegada de cliente " << c <<endl ;
    }

    void salida() {
        Cliente c;
        if (clientes.pop(c)) {
            cout << "salida de cliente: " << c << endl;
        } else {
            cout << "No hay clientes por salir " << endl;
        }
    }
    void mostrar() {
        clientes.print();
    }
};
int main(){
    Turno programa;
    programa.recepcion(Cliente("Alex","deposito"));
    programa.recepcion(Cliente("Steve","retiro"));
    programa.recepcion(Cliente("Mario","abrir cuenta"));
    programa.mostrar();

    cout << "salida de clientes" << endl;
    programa.salida();
    programa.salida();

    cout << "estado actual"  << endl;
    programa.mostrar();

    return 0;
}
