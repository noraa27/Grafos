#ifndef GRAFO_H
#define GRAFO_H
#include "Arista.h"

class Grafo{
    private:
        vector<nodo> nodos;
        vector<arista> aristas;
    public:
        Grafo();

        Grafo(vector<nodo>nuevosnodos,vector<arista>nuevasaristas);

        nodo getNodo(int pos);

        arista getArista(int pos);

        void aniadirNodo(nodo n);

        void aniadirArista(arista a);

        void eliminarNodo(nodo n);

        void eliminarArista(arista a);

        nodo nodoMaxGrado();

        void eliminarAristasNodo(nodo n);

};


#endif