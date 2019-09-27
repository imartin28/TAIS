// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Matriz.h"
//==========================>   EJERCICIO 27 (Sergio) <==========================//

/*
 
 esPosibleFormarCuerda(i, j) = Si es posible formaar una cuerda de longitud j con los cordeles del 1 al i.
 
 CASOS BASE:
 
    esPosibleFormarCuerda(0, j) = FALSE
    esPosibleFormarCuerda(i, 0) = TRUE
 
 
 ECUACION RECURSIVA:
 
    esPosibleFormarCuerda(i, j) = esPosibleFormarCuerda(i - 1, j)   si v_longitud_cordel[i] > j
 
                                  esPosibleFormarCuerda(i - 1, j - v_longitud_cordel[i]) ||
                                  esPosibleFormarCuerda(i - 1, j)      si v_longitud_cordel[i] <= j
 
 COSTE:
 
 - En tiempo: O(n*m) siendo n el numero de filas y m el numero de columnas de la matriz.
 
 - En espacio adicional: O(n*m) siendo n el numero de filas y m el numero de columnas de la matriz
 
 */

// función que resuelve el problema
bool esPosibleFormarCuerda(std::vector<int>const& v_longitud_cordel, int longCometa) {
    
    int n = v_longitud_cordel.size() - 1;
    
    Matriz<bool> matriz_posibleFormarCuerda(n + 1, longCometa + 1, false);
    
    /* CASOS BASE */
    

    for(int i = 0; i < n + 1; ++i){
        matriz_posibleFormarCuerda[i][0] = true;
    }

    /*  LLAMADA RECURSIVA   */
  
    for(int i = 1; i < n + 1; ++i){
        for(int j = 1; j <= longCometa; ++j){
            
            if(v_longitud_cordel[i] > j){
               matriz_posibleFormarCuerda[i][j] = matriz_posibleFormarCuerda[i - 1][j];
            }else{
                matriz_posibleFormarCuerda[i][j] = matriz_posibleFormarCuerda[i - 1][j - v_longitud_cordel[i]] || matriz_posibleFormarCuerda[i - 1][j];
            }
            
            
        }
    }
  
    
    return matriz_posibleFormarCuerda[n][longCometa];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numCordeles, longCometa;
    std::cin >> numCordeles >> longCometa;
    
    if (! std::cin)
        return false;
    
    std::vector<int> v_longitud_cordel(numCordeles + 1);
    std::vector<int> v_coste(numCordeles + 1);
    int longitud_cordel, coste;
    
    for(int i = 1; i <= v_longitud_cordel.size(); ++i){
        std::cin >> longitud_cordel >> coste;
        v_longitud_cordel[i] = longitud_cordel;
        v_coste[i] = coste;
    }
    

    bool esPosible = esPosibleFormarCuerda(v_longitud_cordel, longCometa);
    
    // escribir sol
    if(esPosible)
        std::cout << "SI" << std::endl;
    else
         std::cout << "NO" << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais27_sergio.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    
    while (resuelveCaso())
        ;
    
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
