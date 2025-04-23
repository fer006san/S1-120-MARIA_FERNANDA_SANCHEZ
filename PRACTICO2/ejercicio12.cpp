/*En una oficina, los empleados reciben documentos para revisión, los cuales se apilan en una bandeja en el orden en que llegan.
Cada documento tiene un título y una fecha de recepción.
Los documentos deben ser revisados empezando por el último que llegó.
Diseña un programa que permita gestionar el apilado de los documentos y su revisión en el orden correcto.*/
#include <iostream>
#include "stack.h"
using namespace std;

class Documento {
private:
    string titulo;
    string fecha;

public:
    Documento() {}
    Documento(string _titulo, string _fecha) : titulo(_titulo), fecha(_fecha) {}

    string getTitulo() const {
        return titulo;
    }

    string getFecha() const {
        return fecha;
    }

    friend ostream& operator<<(ostream& os, const Documento& d) {
        os << "[Título: " << d.titulo << ", Fecha de recepción: " << d.fecha << "]";
        return os;
    }
};
class Oficina {
    private:
    Stack<Documento> bandeja;

    public:
    void recibir(const Documento &d) {
        bandeja.push(d);
        cout << "documento recibido: " << d << endl;
    }

    void revisar() {
        Documento d;
        if (bandeja.pop(d)) {
            cout << "revisando documento: " << d << endl;
        } else {
            cout << "no hay documentos para revisar" << endl;
        }
    }

    void mostrar() {
        bandeja.print();
    }
};
int main() {
    Oficina oficina;
    oficina.recibir(Documento("informe de ventas", "2025-04-01"));
    oficina.recibir(Documento("solicitud de vacaciones", "2025-04-02"));
    oficina.recibir(Documento("reporte mensual", "2025-04-03"));
    oficina.mostrar();

    oficina.revisar();
    oficina.revisar();
    oficina.mostrar();
}
