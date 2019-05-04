#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <vector>
using namespace std;

class nodo{
    private:
        int idnodo;
        int gradoNodo;

    public:
        nodo();

        nodo(int id, int g);

        void setID(int id);

        void setGrado(int grado);

        int getIDNodo();

        int getGradoNodo();
};
#endif