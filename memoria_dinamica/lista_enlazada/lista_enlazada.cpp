#include "lista_enlazada.h"

ListaEnlazada::ListaEnlazada() : _primero(nullptr), _actual(nullptr), _longitud(0) {}

int ListaEnlazada::longitud() {
    return this->_longitud;
}

void ListaEnlazada::agregarAtras(const int elemento) {
    if (this->_primero == nullptr)
        this->_primero = new nodo {elemento, nullptr};
    else {
        nodo* actual = this->_primero;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = new nodo {elemento, nullptr};
    }
    this->_longitud++;
}

int ListaEnlazada::iesimo(const int posicion) {
    // Pre: 0 <= pos < *this.longitud()

    nodo* actual = _primero;
    int i = 0;
    while (i < posicion){
        actual = actual->siguiente;
        i++;
    }
    return actual->elemento;
}

ListaEnlazada::~ListaEnlazada() {
    nodo * actual = this->_primero;
    while (actual != nullptr) {
        nodo* sig = actual->siguiente;
        delete actual;
        actual = sig;
    }
    this->_primero = nullptr;
}

int ListaEnlazada::suma() {
    int res = 0;
    for(int posicion = 0; posicion < this->longitud(); posicion++){
        res = res + this->iesimo(posicion);
    }
    return res;
}

void ListaEnlazada::borrarUltimo() {
    // Pre: 0 < *this.longitud()
}

void ListaEnlazada::borrarIesimo(const int posicion) {
    // Pre: 0 <= pos < *this.longitud()
}

int ListaEnlazada::actual() {
    return -1;
}

void ListaEnlazada::avanzar() {
}

void ListaEnlazada::retroceder() {
}
