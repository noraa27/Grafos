#include "Grafo.h"
#include "tsp_insercion.h"
#include "tsp_cercania.h"

/*int main(int argc, char* argv[]){

	vector<nodo> ciudades;
	vector<nodo> solucionC;
	vector<int> solucion;
	vector<vector<double> > D;
	double total = 0;

	llenaGrafo(ciudades, argv[1]);
	distancia(ciudades, D);
	trianguloInicio(ciudades, solucionC);

	//Añado a la solucion las tres primeras ciudades escogidas
	for(unsigned i = 0; i < solucionC.size(); i++){
		solucion.push_back(solucionC[i].getIDNodo());
	}

	solucionC.clear();


	//El conjunto de if-else if es para mostrar la información por consola de diferentes formas
	//si no tiene parámetros muestra el resultado simple, comenzando a calcularlo desde la primera ciudad
	if(argc == 2){
		//Calculo la mejor solucion
		vecinoInsercion(D, solucion);
		//Añado la primera ciudad al final, a la que hay volver
		solucion.push_back(solucion[0]);
		//Calculo la distancia de mi solucion
		total = calcularDistancia(D, solucion);
		//Muestro por pantalla la solucion
		for(unsigned i = 0; i < solucion.size(); i++)
			cout << solucion[i] << endl;

		cout << endl << total << endl;
	}
	//Si tiene un parámetro, que debe ser numerico y puede ser cualquiera muestra el resultado COMPLETO con la ubicación de cada una de las ciudades para
	//redireccionarlo a un archivo .tsp y que se pueda imprimir en gnuplot la grafica que representa el camino seleccionado
	else if(argc == 3){
		vecinoInsercion(D, solucion);
		vecinoBuscarDatosCiudades(solucion, ciudades, solucionC);
		for(unsigned i = 0; i < solucionC.size(); i++)
			cout << solucionC[i].getIDNodo() << "\t" << solucionC[i].getX() << "\t" << solucionC[i].getY() << endl;
	}

	//Devuelve el tiempo de ejecución, no el orden
	else if(argc == 4){
		high_resolution_clock::time_point tantes, tdespues;
  		duration<double> transcurrido;
  		tantes = high_resolution_clock::now();
		vecinoInsercion(D, solucion);	
		tdespues = high_resolution_clock::now();
		transcurrido = duration_cast<duration<double>>(tdespues-tantes);
		cout << transcurrido.count() << endl;	
	}

	return 0;
}*/


// FRAN //
int main(int argc, char* argv[]){

	vector<nodo> nodos, solucion;
	high_resolution_clock::time_point tantes, tdespues;
	duration<double> transcurrido;

	nodos = llenaGrafo_cercania(argv[1]);

	tantes = high_resolution_clock::now();
	calcularRuta(nodos, solucion);
	tdespues = high_resolution_clock::now();

	transcurrido = duration_cast<duration<double>>(tdespues-tantes);

	for(int i = 0; i < (int) solucion.size(); i++)
		cout << solucion[i].getIDNodo() << " " << solucion[i].getX() << " " << solucion[i].getY() << endl;

	cout << endl << calcularDistanciaNodos(solucion) << endl;

	cout << endl << "Transcurrido: " << transcurrido.count() << endl;

	return 0;
}