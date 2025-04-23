/*En un supermercado, los productos perecederos, como la leche, se almacenan en cajas.
Cada caja tiene una fecha de vencimiento y cantidad de unidades.
Las cajas se colocan en una estantería especial donde se deben sacar los productos más antiguos antes de utilizar
los más nuevos para evitar que se venzan. Diseña un programa que gestione este inventario de productos perecederos.*/
#include <iostream>
#include "stack.h"
#include "linkedlist.h"
using namespace std;

class Leche{
    private:
    int fecha;
    int cantidad;

    public:
    Leche(){
        fecha =0;
        cantidad =0;
    }
    Leche (int _fecha, int _cantidad){
        fecha = _fecha;
        cantidad = _cantidad;
    }

    void setFecha(int _fecha){
        fecha = _fecha;
    }
    int getFecha(){
        return fecha;
    }

    void setCantidad(int _cantidad){
        cantidad = _cantidad;
    }
    int getCantidad(){
        return cantidad;
    }

    friend ostream& operator<<(ostream& os, const Leche& l) {
        os << "[fecha: " << l.fecha << ", cantidad: " <<l.cantidad << "]";
        return os;
    }
    bool operator<(const Leche& other) const {
        return fecha < other.fecha;
    }
};

class Cajas{
    private:
    LinkedList<Leche> cajas;
    Stack<Leche> estanteria;

    public:
    void llegada(const Leche &l){
        cajas.pushBack(l);
        cout<< "caja recibida  " << l << endl;
    }

    void acomodar() {
        for (int i = 0; i < cajas.getSize() - 1; ++i) {
            for (int j = 0; j < cajas.getSize() - i - 1; ++j) {
                Leche a = cajas.at(j);
                Leche b = cajas.at(j + 1);
                if (a.getFecha() > b.getFecha()) {
                    cajas.set(j, b);
                    cajas.set(j + 1, a);
                }
            }
        }
        Leche le;
        while (!estanteria.isEmpty()) {
            estanteria.pop(le);
        }

        for (int i = 0; i < cajas.getSize(); ++i) {
            estanteria.push(cajas.at(i));
        }

        cout << "estanteria acomodada:" << endl;
        estanteria.print();
    }

    void sacarCaja() {
        Leche l;
        if (estanteria.pop(l)) {
            cout << "se saco la caja " << l << endl;
        } else {
            cout << "estanteria vacia" << endl;
        }
    }

//Llega todos los paquetes a una <linkedllist, ordeno esa linkled y luego la pusheo a una pila,
//asi siempre saca el ultimo y ya esta ordenado
};
int main(){
    Cajas sistema;

    sistema.llegada(Leche(20250422, 10));
    sistema.llegada(Leche(20250420, 15));
    sistema.llegada(Leche(20250425, 5));

    sistema.acomodar();

    sistema.sacarCaja();
    sistema.sacarCaja();
    sistema.sacarCaja();
    sistema.sacarCaja();

    return 0;

}
