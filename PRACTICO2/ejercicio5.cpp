/* En un restaurante, los platos sucios se apilan para ser lavados.
Los platos se colocan en una pila uno encima del otro. Los lavaplatos siempre lavan el plato que
está en la cima. Cada plato tiene un identificador y un tipo (hondo, llano, etc.).
Diseña un programa que gestione el apilado y lavado de los platos. */
#include <iostream>
#include "stack.h"
using namespace std;

class Plato {
    private:
    string tipo;
    int id;

    public:
    Plato(){
        tipo = "desconocido";
        id = 0;
    }
    Plato (int _id, string _tipo){
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
    friend ostream& operator<<(ostream& os, const Plato& p) {
        os << "[ID: " << p.id << ", Tipo: " << p.tipo << "]";
        return os;
    }
};

class Lavado{
    private:
    Stack<Plato> platos;

    public:
    void recepcion(const Plato &p) {
        platos.push(p);
        cout << "plato recibido " << p <<endl ;
    }

    void lavado() {
        Plato p;
        if (platos.pop(p)) {
            cout << "Lavando plato: " << p << endl;
        } else {
            cout << "No hay platos por lavar" << endl;
        }
    }
    void mostrar() {
        platos.print();
    }
};

int main (){
    Lavado sistema;
    sistema.recepcion(Plato(1, "hondo"));
    sistema.recepcion(Plato(2, "llano"));
    sistema.recepcion(Plato(3, "hondo"));
    sistema.mostrar();

    cout<< "lavado: " << endl;
    sistema.lavado();
    sistema.lavado();

    cout << "estado final :" <<endl;
    sistema.mostrar();
    return 0;
}
