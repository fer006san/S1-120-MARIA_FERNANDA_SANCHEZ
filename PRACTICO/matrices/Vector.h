#ifndef VECTOR_H //Verifica si no se ha definido VECTOR_H antes.
#define VECTOR_H //Lo define para que no se vuelva a incluir.

#include <iostream>
#include <stdexcept> //Permite lanzar excepciones (throw out_of_range) cuando se accede a un índice inválido.

using namespace std;

template <typename T> class Vector { //T es un tipo genérico que será reemplazado con un tipo específico cuando se cree un objeto Vector<int>, Vector<double>, etc.
  protected:
    T *items; //Un puntero a un arreglo dinámico que almacena los elementos del vector.
    int size; //numero actual de los elementos almacenados.
    int capacity; //tamaño máximo que puede almacenar.

  public:
    // CONSTRUCTOR DE LA CLASE
    Vector(int _capacity = 10) : size(0), capacity(_capacity)
    {
        items = new T[capacity]; // Crea un arreglo dinámico para almacenar los elementos.
    }

    // CONSTRUCTOR DE COPIA
    Vector(const Vector<T>& other) : size(other.size), capacity(other.capacity)
    {
        items = new T[capacity]; // Asigna nueva memoria
        for (int i = 0; i < size; i++) {
            items[i] = other.items[i]; // Copia los elementos
        }
    }

    // OPERADOR DE ASIGNACIÓN
    Vector<T>& operator=(const Vector<T>& other)
    {
        if (this == &other) {
            return *this; // Evitar auto-asignación
        }

        delete[] items; // Libera la memoria previa

        size = other.size;
        capacity = other.capacity;
        items = new T[capacity]; // Asigna nueva memoria

        for (int i = 0; i < size; i++) {
            items[i] = other.items[i]; // Copia los elementos
        }

        return *this;
    }

    // DESTRUCTOR
    ~Vector()
    {
        delete[] items; // Libera la memoria reservada por new, evitando fugas de memoria
    }

    // Agrega un elemento al final del vector
    void pushBack(const T& value)
    {
        if (size == capacity) {
            resize(capacity * 2); // Si el vector está lleno, aumenta su capacidad
        }
        items[size++] = value; // Asigna el valor al final y aumenta el tamaño
    }

    // Retorna el elemento en la posición index
    T at(int index) const
    {
        if (index < 0 || index >= size) {
            throw out_of_range("Índice fuera de rango");
        }
        return items[index];
    }

    // Modifica el elemento en index con value
    void set(int index, T value)
    {
        if (index < 0 || index >= size) {
            throw out_of_range("Índice fuera de rango");
        }
        items[index] = value;
    }

    // Devuelven el número de elementos (size) y la capacidad (capacity) del vector
    int getSize() const
    {
        return size;
    }

    int getCapacity() const
    {
        return capacity;
    }

    // Cambia el tamaño del vector
    void resize(int newCapacity)
    {
        if (newCapacity <= capacity)
            return;

        T* newItems = new T[newCapacity]; // Crea un nuevo arreglo dinámico
        for (int i = 0; i < size; i++) {
            newItems[i] = items[i]; // Copia los elementos
        }
        delete[] items; // Libera la memoria previa
        items = newItems; // Asigna la nueva memoria
        capacity = newCapacity; // Actualiza la capacidad
    }

    // Imprime los elementos del vector
    void print()
    {
        for (int i = 0; i < size; i++) {
            cout << items[i] << " | ";
        }
        cout << endl;
    }

    void removeAt(int index) { 
        if (index < 0 || index >= size) {
            throw out_of_range("Índice fuera de rango");
        }
        for (int i = index; i < size - 1; ++i) {
            items[i] = items[i + 1];
        }
        size--;
    }
};

#endif // VECTOR_H
