/*En una tienda de ropa, los empleados reciben paquetes con ropa que deben ser almacenados temporalmente.
Los paquetes tienen un identificador único y el tipode prenda que contienen (camisas, pantalones, etc.).
Los paquetes se colocan en el almacén en el orden en que llegan, pero deben ser sacados del almacén en el mismo orden para evitar confusiones.
Crea un programa que gestione la recepción y salida de los paquetes */
#include <iostream>
#include "queue.h"
using namespace std;
class Paquete {
    private:
    string tipo;
    int id;

    public:
    Paquete(){
        tipo = "desconocido";
        id = 0;
    }
    Paquete (int _id, string _tipo){
        tipo = _tipo;
        id = _id;
    }
    void setTipo(string _tipo){
        tipo = _tipo;
    }
    string getTipo()const{
        return tipo;
    }
    void setId(int _id){
        id = _id;
    }
    int getId() const{
        return id;
    }
    friend ostream& operator<<(ostream& os, const Paquete& p) {
        os << "[ID: " << p.id << ", Tipo: " << p.tipo << "]";
        return os;
    }
};
class Almacen{
    private:
    Queue<Paquete> paquetes;

    public:
    void recepcion(const Paquete &p) {
        paquetes.push(p);
        cout << "paquete recibido " << p <<endl ;
    }

    void salida() {
        Paquete p;
        if (paquetes.pop(p)) {
            cout << "salida de paquete: " << p << endl;
        } else {
            cout << "No hay paquetes por salir " << endl;
        }
    }
    void mostrar() {
        paquetes.print();
    }
};
int main(){
    Almacen programa;
    programa.recepcion(Paquete(1,"camisas"));
    programa.recepcion(Paquete(2,"jeans"));
    programa.recepcion(Paquete(3,"blusas"));
    programa.mostrar();

    cout << "salida de paquetes" << endl;
    programa.salida();
    programa.salida();

    cout << "estado actual"  << endl;
    programa.mostrar();

    return 0;
}
