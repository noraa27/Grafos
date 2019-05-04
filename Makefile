SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


# **** Compilación de módulos ****

$(BIN)/grafos: $(OBJ)/grafos.o $(LIB)/libgrafos.a
	$(CXX) -o $(BIN)/grafos $(OBJ)/grafos.o -I$(INC) -L$(LIB) -lgrafos

$(LIB)/libgrafos.a : $(OBJ)/Nodo.o $(OBJ)/Arista.o $(OBJ)/Grafo.o
	ar rvs $(LIB)/libgrafos.a $(OBJ)/Nodo.o $(OBJ)/Arista.o $(OBJ)/Grafo.o $(OBJ)/tsp_insercion.o

$(OBJ)/Nodo.o : $(SRC)/Nodo.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Nodo.o $(SRC)/Nodo.cpp -I$(INC)

$(OBJ)/Arista.o : $(SRC)/Arista.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Arista.o $(SRC)/Arista.cpp -I$(INC)

$(OBJ)/Grafo.o : $(SRC)/Grafo.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Grafo.o $(SRC)/Grafo.cpp -I$(INC)

$(OBJ)/tsp_insercion.o : $(SRC)/tsp_insercion.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/tsp_insercion.o $(SRC)/tsp_insercion.cpp -I$(INC)

$(OBJ)/grafos.o : $(SRC)/grafos.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/grafos.o $(SRC)/grafos.cpp -I$(INC)

all: $(BIN)/grafos	
# **** Ejecutar ** **
exec:
	./$(BIN)/grafos 
# **** Limpieza ****
clean :
	-rm $(OBJ)/* $(BIN)/* $(LIB)/*

mrproper : clean
	
