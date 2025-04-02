// Crea la clase Producto, con los siguientes atributos: - id (numerico) -nombre -precio -cantidad en stock
//Luego, implementa la clase Almacen, que guarda objetos de la clase Producto en una matriz, donde:
// Cada fila representa una categoría de productos.
// Cada columna representa una ubicación en stock.
//Debe permitir: Agregar un producto en una posición específica de la matriz. Calcular el total de productos en una categoría (suma de las cantidades en una fila).
#include "Matriz.h"
#include <iostream>
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
template <int ROWS, int COLS>
class Almacen {
    private :
    Producto productos[ROWS][COLS];

    public :
      void agregar(int fila, int columna, Producto p){
          if(fila >= 0 && fila < ROWS && columna >= 0 && columna < COLS){
            productos[fila][columna] = p;
          }else{
            cout << "fuera del rango";
          }
      }
      int total(int fila){
        if (fila < 0 || fila >=ROWS){
            cout << "fuera del rango";
        }
        int total=0;
        for(int j =0; j < COLS; j++){
            total+= productos[fila][j].getStock();
        }
        return total;
      }
      void print(){
        for (int i=0; i < ROWS; i++){
            for (int j=0; j<COLS;j++){
                productos[i][j].print();
            }
        }
      }


};
int main(){
    const int FILAS = 2, COLUMNAS = 3;
    Almacen<FILAS, COLUMNAS> almacen;

    almacen.agregar(0, 0, Producto(1, "Shampoo", 25, 50));
    almacen.agregar(0, 1, Producto(2, "Detergente", 35, 55));
    almacen.agregar(1, 0, Producto(3, "Lavandina", 25, 30));

    cout << "inventario actual" << endl;
    almacen.print();
    cout << endl;

    cout <<" total de productos el la categoria 0: " << almacen.total(0) << endl;

    return 0;
}

