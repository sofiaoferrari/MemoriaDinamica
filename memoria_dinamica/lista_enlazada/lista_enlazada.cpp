#include "lista_enlazada.h"
#include <iostream>
using namespace std;

ListaEnlazada::ListaEnlazada() : _primero(nullptr), _actual(nullptr), _longitud(0) {}

int ListaEnlazada::longitud() {
    return this->_longitud;
}

void ListaEnlazada::agregarAtras(const int elemento) {
    if (this->_primero == nullptr){
        this->_primero = new nodo {elemento, nullptr};
        _actual = this->_primero; //?? preguntar
    }else {
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
    nodo* anterior = this->_primero;
    if (anterior->siguiente == nullptr){
        delete anterior;
        this->_primero = nullptr;
        _actual = nullptr;
    } else {
        nodo* actual = anterior->siguiente;
        while (actual->siguiente != nullptr){
            anterior = actual;
            actual = actual->siguiente;
        }
        if (actual == _actual)
            _actual = actual->siguiente;
        delete actual;
        anterior->siguiente = nullptr;
    }
    _longitud--;
}

void ListaEnlazada::borrarIesimo(const int posicion) {
    // Pre: 0 <= pos < *this.longitud()
    nodo* anterior = this->_primero;
    if (posicion == _longitud-1) borrarUltimo();
    else if (posicion == 0){
        this->_primero = anterior->siguiente;
        _actual = this->_primero; //
        delete anterior;
        _longitud--;
    } else {
        for(int i=0; i < posicion-1; i++) 
            anterior = anterior->siguiente;
        nodo* actual = anterior->siguiente;
        anterior->siguiente = actual->siguiente;
        if (actual == _actual)
            _actual = actual->siguiente;
        delete actual;
        _longitud--;
    }
}

int ListaEnlazada::actual() {
    //
    return _actual->elemento;
}

void ListaEnlazada::avanzar() {
    if (_actual->siguiente == nullptr)
        _actual = this->_primero;
    else _actual = _actual->siguiente;
}

void ListaEnlazada::retroceder() {
    nodo* anterior = this->_primero;
    if (_actual == anterior && _longitud > 1) {
        while(anterior->siguiente != nullptr){
            anterior = anterior->siguiente;
        }
        _actual = anterior;
    } else if (_actual != anterior) {
        while(anterior->siguiente != _actual)
            anterior = anterior->siguiente;
    }
        _actual = anterior;
}