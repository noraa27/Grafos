#include "Nodo.h"


nodo::nodo(){
    this->idnodo = 0;
    this->gradoNodo = 0; 
}

nodo::nodo(int id, int g){
    this->idnodo = id;
    this->gradoNodo = g;
 }


void nodo::setID(int id){
    this->idnodo = id;
}

void nodo::setGrado(int grado){
    this->gradoNodo = grado;
}

int nodo::getIDNodo(){
    return idnodo;
}

int nodo::getGradoNodo(){
    return gradoNodo;
}