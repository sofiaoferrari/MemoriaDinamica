#include "lista_enlazada.h"
#include <iostream>
using namespace std;

ListaEnlazada::ListaEnlazada() : _primero(nullptr), _actual(nullptr), _longitud(0) {}

int ListaEnlazada::longitud() {
    return this->_longitud;
}

void ListaEnlazada::agregarAtras(const int elemento) {
    if (this->_primero == nullptr){
        this->_primero = new nodo {elemento, nullptr, nullptr};
        this->_primero->anterior = this->_primero;
        this->_primero->siguiente = this->_primero;
        _actual = this->_primero; 
    }else {
        nodo* actual = this->_primero;
        while (actual->siguiente != this->_primero) {
            actual = actual->siguiente;
        }
        actual->siguiente = new nodo {elemento, actual, this->_primero};
        this->_primero->anterior = actual->siguiente;
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
    for(int i=0; i < _longitud; i++) {
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
    borrarIesimo(_longitud-1);
}

void ListaEnlazada::borrarIesimo(const int posicion) {
    // Pre: 0 <= pos < *this.longitud()
    nodo* iesimo = this->_primero;
    if (posicion == 0 && _longitud == 1) {
        this->_primero = nullptr;    
    } else if (posicion == 0) {
        this->_primero = iesimo->siguiente;
        (iesimo->anterior)->siguiente = iesimo->siguiente; 
        (iesimo->siguiente)->anterior = iesimo->anterior;
    }  else {
        for(int i=0; i < posicion; i++) 
            iesimo = iesimo->siguiente;
        (iesimo->anterior)->siguiente = iesimo->siguiente; 
        (iesimo->siguiente)->anterior = iesimo->anterior;
    }
    if (iesimo == _actual)
        _actual = iesimo->siguiente;
    delete iesimo;
    _longitud--;
}

int ListaEnlazada::actual() {
    return _actual->elemento;
}

void ListaEnlazada::avanzar() {
    _actual = _actual->siguiente;
}

void ListaEnlazada::retroceder() {
    _actual = _actual->anterior;
}