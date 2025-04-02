//Crea la clase Inventario, que gestione un vector de objetos de la clase Producto con los atributos:
//id (numerico) - nombre - precio - cantidad en stock
//El sistema debe permitir: - Agregar y eliminar productos - - Buscar productos por nombre. - Ordenar el inventario por precio.
#include <iostream>
#include "Vector.h"
#include <string>

using namespace std;

class Producto {
  private:
    int id;
    string nombre;
    float precio;
    int stock;

    public :
    Producto(){
        id= 0;
        nombre = "desconocido";
        precio = 0;
        stock = 0;
    }
    Producto(int _id, string _nombre, float _precio, int _stock){
        id= _id;
        nombre = _nombre;
        precio =  _precio;
        stock =_stock;
    }
    void setId(int _id){
        id = _id;
    }
    int getId(){
        return id;
    }
    void setNombre(string _nombre){
        nombre = _nombre;
    }
    string getNombre(){
        return nombre;
    }
    void setPrecio(float _precio){
        precio = _precio;
    }
    float getPrecio(){
        return precio;
    }
    void setStock(int _stock){
        stock = _stock;
    }
    int getStock(){
        return stock;
    }

    void print(){
        cout << "ID: " << id << ", Nombre: " << nombre << ", Precio: " << precio << ", Stock: " << stock << endl;
    }

};
class Inventario {
    private :
    Vector<Producto> productos;

    public :
    void agregar(Producto p){
        productos.pushBack(p);
    }
    void eliminar(int id){
        for(int i =0; i < productos.getSize(); i++){
            Producto p =productos.at(i);
            if (p.getId() == id ){
                productos.removeAt(i);
                cout<< "producto eliminado";
                return;
            }
        }
        cout << "producto no encontrado";
    }
    Producto buscar(int id ){
        for(int i =0; i < productos.getSize(); i++){
            Producto p =productos.at(i);
            if(p.getId() == id){
                return productos.at(i);
            }
        }
        throw runtime_error("no encontrado");
    }

    void ordenarPorPrecio(){
        Vector<Producto> xd;
        for(int i=0; i < productos.getSize(); i++){
            xd.pushBack(productos.at(i));
        }
        for (int i =0; i < xd.getSize()- 1; i++){
            for (int j = 0; j <xd.getSize()- i - 1; j++){
                if(xd.at(j).getPrecio() > xd.at(j+ 1).getPrecio()){
                    Producto temp = xd.at(j);
                    xd.set(j, xd.at(j+1));
                    xd.set(j + 1, temp);
                }
            }
        }
        for(int i = 0; i < xd.getSize(); i++){
            productos.set(i, xd.at(i));
        }
    }
    void print(){
        for (int i=0; i < productos.getSize(); i++){
            productos.at(i).print();
        }
    }

};
int main(){

    Producto P1(1, "shampoo", 25, 50);
    Producto P2(2, "detergente", 35, 55);
    Producto P3(3, "lavandina", 25, 30);

    Inventario inventario;
    inventario.agregar(P1);
    inventario.agregar(P2);
    inventario.agregar(P3);

    cout << "inventario actual" << endl;
    inventario.print();
    cout << endl;
    cout <<"eliminar por id " << endl;
    inventario.eliminar(1);
    inventario.print();

    cout << endl;
    cout << "inventario ordenado por precio";
    inventario.ordenarPorPrecio();
    inventario.print();

    return 0;
}
