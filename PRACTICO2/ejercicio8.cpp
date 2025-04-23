/*En un editor de texto, el usuario realiza varias acciones (escribir, borrar, copiar, pegar).
El programa debe permitir que el usuario pueda "deshacer" las acciones más recientes.
Cada acción tiene un tipo y el contenido de la operación.
Diseña un programa que registre las acciones del usuario y permita deshacer las últimas acciones realizadas.*/
#include <iostream>
#include "stack.h"
using namespace std;

class Accion{
    private:
    string tipo;
    string contenido;

    public:
    Accion() {}
    Accion(string _tipo, string _contenido) : tipo(_tipo), contenido(_contenido) {}

    string getTipo() const {
        return tipo;
    }
    string getContenido() const {
        return contenido;
    }
    friend ostream& operator<<(ostream& os, const Accion& a) {
        os << "[Tipo: " << a.tipo << ", Contenido: \"" << a.contenido << "\"]";
        return os;
    }
};
class Editor{
    private:
    Stack<Accion> acciones;

    public:
    void registro(const Accion &a){
        acciones.push(a);
        cout << "acciones realizadas :" << a << endl;
    }

    void deshacer(){
        Accion a;
        if (acciones.pop(a)) {
            cout << "se deshizo de :  " << a << endl;
        } else {
            cout << "No hay mas acciones " << endl;
        }
    }

    void mostrar(){
        acciones.print();
    }
};
int main(){
    Editor programa;

    programa.registro(Accion("escribir", "hello kitty"));
    programa.registro(Accion("escribir", "hola demonio"));
    programa.registro(Accion("copiar", "hello kitty"));
    programa.mostrar();

    programa.deshacer();
    programa.deshacer();

    programa.mostrar();

}
