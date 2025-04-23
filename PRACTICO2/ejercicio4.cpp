/*Una impresora recibe trabajos de impresión de diferentes computadoras conectadas en red.
Los trabajos tienen un número de páginas y el nombre del archivo.
Los trabajos de impresión deben procesarse en el orden en que llegaron.
Diseña un programa que gestione la cola de trabajos de impresión y permita saber cuál es el siguiente trabajo a imprimir.*/
#include <iostream>
#include "queue.h"
using namespace std;
class Trabajo{
    private :
    int paginas;
    string nombre;

    public:
    Trabajo() {
        paginas = 0;
        nombre = "desconocido";
    }

    Trabajo(int _paginas, string _nombre) {
        paginas = _paginas;
        nombre = _nombre;
    }

    int getPaginas() const {
        return paginas;
    }

    string getNombre() const {
        return nombre;
    }

    friend ostream& operator<<(ostream& os, const Trabajo& t) {
        os << "[Archivo: " << t.nombre << ", Páginas: " << t.paginas << "]";
        return os;
    }
};
class Impresora{
    private:
    Queue<Trabajo> trabajos;

    public:
    void agregar(const Trabajo& t) {
        trabajos.push(t);
        cout << "trabajo agregado: " << t << endl;
    }

    void imprimir() {
        Trabajo t;
        if (trabajos.pop(t)) {
            cout << "imprimiendo: " << t << endl;
        } else {
            cout << "no hay trabajos pendientes de impresion" << endl;
        }
    }
    void mostrarSiguiente() {
        Trabajo t;
        if (trabajos.peek(t)) {
            cout << "siguiente trabajo en cola: " << t << endl;
        } else {
            cout << "la cola de impresion esta vacia" << endl;
        }
    }
    void mostrarCola() {
        trabajos.print();
    }
};
int main() {
    Impresora impresora;
    impresora.agregar(Trabajo(10, "informe.pdf"));
    impresora.agregar(Trabajo(5, "factura.pdf"));
    impresora.agregar(Trabajo(2, "histograma.png"));

    cout << "estado actual de la cola" << endl;
    impresora.mostrarCola();

    cout << "proximo trabajo" << endl;
    impresora.mostrarSiguiente();

    cout << "imprimiendo trabajos" << endl;
    impresora.imprimir();
    impresora.imprimir();

    cout << "estado de la cola " << endl;
    impresora.mostrarCola();

    return 0;
}
