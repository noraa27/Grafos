#include "Arista.h"

    arista::arista(){
            this->idarista = 0;
        }

    arista::arista(int id,nodo n1, nodo n2){
            this->idarista = id;
            this->a.setID(n1.getIDNodo());
            this->a.setGrado(n1.getGradoNodo());
            this->b.setID(n2.getIDNodo());
            this->b.setGrado(n2.getGradoNodo());
        }
    
    int arista::getIDArista(){
        return this->idarista;
    }

    int arista::getIDNodo1(){
        return a.getIDNodo();
    }
    
    int arista::getIDNodo2(){
        return b.getIDNodo();
    }

    nodo arista::getNodo1(){
        return a;
    }

    nodo arista::getNodo2(){
        return b;
    }

    bool arista::contenido(nodo n){
        if(n.getIDNodo() == a.getIDNodo() || n.getIDNodo() == b.getIDNodo())
            return true;
        else
            return false;
    }

    void arista::eliminarArista(){
        a.setGrado(a.getGradoNodo()-1);
        b.setGrado(b.getGradoNodo()-1);
        idarista = -1;
    }
