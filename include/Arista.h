#ifndef ARISTA_H
#define ARISTA_H
#include "Nodo.h"

class arista{
    private:
        int idarista;
        nodo a,b;
    public:
        arista();

        arista(int id,nodo n1, nodo n2);

        int getIDArista();

        int getIDNodo1();

        int getIDNodo2();

        nodo getNodo1();

        nodo getNodo2();

        bool contenido(nodo n);

        void eliminarArista();

};




#endif