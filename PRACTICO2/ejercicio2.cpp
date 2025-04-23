/*Donaciones de libros en una biblioteca
En una biblioteca se reciben donaciones de libros que tienen un título, un autor y una editorial.
Los libros llegan a la biblioteca de manera desordenada, y se almacenan en una estantería temporal hasta que se les asigne un lugar definitivo.
Los empleados primero deben registrar el último libro que llegó antes de procesar los demás.
Diseña un programa que permita gestionar la recepción y registro de las donaciones. */
#include <iostream>
#include "stack.h"
using namespace std;
class Libro{
    private :
    string titulo;
    string autor;
    string editorial;

    public:
    Libro(){
        titulo = "desconocido";
        autor = "desconocido";
        editorial = "desconocido";
    }
    Libro(string _titulo, string _autor, string _editorial){
        titulo = _titulo;
        autor = _autor;
        editorial = _editorial;
    }
    void setTitulo(string _titulo){
        titulo = _titulo;
    }
    string getTitulo()const{
        return titulo;
    }

    void setAutor(string _autor){
        autor = _autor;
    }
    string getAutor()const{
        return autor;
    }

    void setEditorial(string _editorial){
        editorial = _editorial;
    }
    string getEditorial()const{
        return editorial;
    }

    friend ostream& operator<<(ostream& os, const Libro& l) {
        os << "[Titulo: " << l.titulo << ", Autor: " << l.autor << ", Editorial: " << l.editorial << "]";
        return os;
    }
};
class Biblioteca{
    private:
    Stack<Libro> libros;

    public:
    void recepcion(const Libro &l){
        libros.push(l);
        cout<<"libro recibido " << l << endl;
    }

    void registro(){
        Libro l;
        if (libros.pop(l)) {
            cout << "Registrando libro: " << l << endl;
        } else {
            cout << "No hay libros por registrar" << endl;
        }
    }
    void mostrar(){
        libros.print();
    }
};
int main() {
    Biblioteca biblioteca;
    biblioteca.recepcion(Libro("Cien años de soledad", "Gabriel García Márquez", "Sudamericana"));
    biblioteca.recepcion(Libro("Don Quijote de la Mancha", "Miguel de Cervantes", "Francisco de Robles"));
    biblioteca.recepcion(Libro("Rayuela", "Julio Cortázar", "Sudamericana"));

    cout << "registro " << endl ;
    biblioteca.registro();
    biblioteca.registro();

    cout << "estado actual de la estanteria : ";
    biblioteca.mostrar();

    return 0;
}
