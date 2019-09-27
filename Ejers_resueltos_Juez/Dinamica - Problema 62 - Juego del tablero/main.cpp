// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Matriz.h"
#include <algorithm>
//==========================>   EJERCICIO 62 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
int resolver(Matriz<int>const& matrizTablero, int& columnaEmpieceRecorrido) {
    int n = matrizTablero.numfils() - 1;
    
    Matriz<int> matriz_solucion(n + 2, n + 2, 0);
    
    
    for(int j = 1; j <= n; ++j){
        matriz_solucion[1][j] = matrizTablero[1][j];
    }
    
    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            matriz_solucion[i][j] = matrizTablero[i][j] + std::max( matriz_solucion[i - 1][j - 1], std::max(  matriz_solucion[i - 1][j ],  matriz_solucion[i-1][j+1]));
           
        }
    }
    
    
    /*  Ahora debemos coger el maximo de la ultima fila para saber que columna es */
    int valorMaximo = 0;
    for(int columna = 1; columna <= n; ++columna){
        if(matriz_solucion[n][columna] > valorMaximo){
            valorMaximo = matriz_solucion[n][columna];
            columnaEmpieceRecorrido = columna;
        }
    }
    
  
    return valorMaximo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int dimensionTablero;
    std::cin >> dimensionTablero;
    
    if (! std::cin)
        return false;
    
    Matriz<int> matrizTablero(dimensionTablero + 1, dimensionTablero + 1);
    int valorTablero;
    
    for(int fila = 1; fila <= dimensionTablero; ++fila){
        for(int col = 1; col <= dimensionTablero; ++col){
            std::cin >> valorTablero;
            matrizTablero[fila][col] = valorTablero;
        }
    }
    
   
    int columnaEmpieceRecorrido = 0;
    int maxCantidadJuego = resolver(matrizTablero, columnaEmpieceRecorrido);
    
    // escribir sol
    std::cout << maxCantidadJuego << ' ' << columnaEmpieceRecorrido << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais62.txt");
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
