#include "Grafo.h"


int main(){

    vector<nodo> nodos;
    nodo n1(1,2);
    nodo n2(2,2);
    nodo n3(3,2);
    nodo n4(4,2);

    vector<arista> aristas;
    arista a12(12,n1,n2);
    arista a14(14,n1,n4);
    arista a23(23,n2,n3);
    arista a34(24,n3,n4);

    Grafo grafo(nodos,aristas);

    grafo.aniadirNodo(n1);
    grafo.aniadirNodo(n2);
    grafo.aniadirNodo(n3);
    grafo.aniadirNodo(n4);

    grafo.aniadirArista(a12);
    grafo.aniadirArista(a14);
    grafo.aniadirArista(a23);
    grafo.aniadirArista(a34);


    cout<<"El primer nodo con id "<<grafo.getNodo(0).getIDNodo()<<" tiene un grado de "<<grafo.getNodo(0).getGradoNodo()<<endl;




}