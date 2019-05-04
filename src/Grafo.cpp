#include "Grafo.h"

Grafo::Grafo(vector<nodo>nuevosnodos,vector<arista>nuevasaristas){
    this->nodos = nuevosnodos;
    this->aristas = nuevasaristas;    
}

nodo Grafo::getNodo(int pos){
    return nodos[pos];
}


arista Grafo::getArista(int pos){
    return aristas[pos];
}

void Grafo::aniadirNodo(nodo n){
    bool esta = false;
    for(int i=0;i<nodos.size() && !esta;i++){
        if(n.getIDNodo()== nodos[i].getIDNodo() && n.getGradoNodo()==nodos[i].getGradoNodo())
            esta = true;
    }

    if(!esta){
        nodos.push_back(n);
    }
}

void Grafo::aniadirArista(arista a){
    bool esta = false;
    for(int i=0;i<aristas.size() && !esta;i++){
        if(a.getIDArista() == aristas[i].getIDArista())
            esta = true;
    }

    if(!esta){
        aniadirNodo(a.getNodo1());
        aniadirNodo(a.getNodo2());
        aristas.push_back(a);
        a.getNodo1().setGrado(a.getNodo1().getGradoNodo()+1);
        a.getNodo2().setGrado(a.getNodo2().getGradoNodo()+1);
    }
}

void Grafo::eliminarNodo(nodo n){
    bool esta = false;
    int posicion = 0;
    for(int i=0;i<nodos.size() && !esta;i++){
        if(n.getIDNodo()== nodos[i].getIDNodo() && n.getGradoNodo()==nodos[i].getGradoNodo())
            esta = true;
            posicion = i;
    }
    if(esta){
        nodos.erase(nodos.begin()+posicion);
    }
}

void Grafo::eliminarArista(arista a){
    bool esta = false;
    int posicion = 0;
    for(int i=0;i<nodos.size() && !esta;i++){
        if(a.getIDArista() == aristas[i].getIDArista())
            esta = true;
            posicion = i;
    }

    if(esta){
        a.eliminarArista();
        aristas.erase(aristas.begin()+posicion);
    }
}

nodo Grafo::nodoMaxGrado(){
    nodo resultado;
    int gradomayor = 1;
    for(int i=0;i<nodos.size();i++){
        if(nodos[i].getGradoNodo() > gradomayor){
            resultado.setGrado(nodos[i].getGradoNodo());
            resultado.setID(nodos[i].getIDNodo());
            gradomayor = nodos[i].getIDNodo();
        }
    }
    return resultado;
}

void Grafo::eliminarAristasNodo(nodo n){

    for(int i=0;i<aristas.size();i++){
        if(n.getIDNodo() == aristas[i].getIDNodo1() || n.getIDNodo() == aristas[i].getIDNodo2()){
            eliminarArista(aristas[i]);
        }
    }
}