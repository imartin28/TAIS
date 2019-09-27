// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Matriz.h"
#include <algorithm>

//==========================>   EJERCICIO 67 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
int resolver(std::vector<int>const& v_cubos) {
    
    int n = v_cubos.size() - 1;
    
    Matriz<int> matriz_solucion(n + 1, n + 1, 0);
    
    for(int i = 0; i <= n; ++i){
        matriz_solucion[i][i] = v_cubos[i];
    }
    
    int izq, der;
   
    // recorrido por diagonales
    for (int d = 1; d <= n; ++d){ // recorre diagonales
        for (int i = 0; i <= n - d; ++i) { // recorre elementos de diagonal
            int j = i + d;
            // calcular míni
     
            /* Calcular izquierda*/
            
            if(v_cubos[i + 1] > v_cubos[j]){
                izq = matriz_solucion[i + 2][j];
            }else{
                izq = matriz_solucion[i + 1][j - 1];
            }
            
            
            /*  Calcular derecha    */
            
            if(v_cubos[j - 1] > v_cubos[i]){
                der = matriz_solucion[i][j - 2];
            }else{
                der = matriz_solucion[i + 1][j - 1];
            }
            
            
            
            matriz_solucion[i][j] = std::max(izq + v_cubos[i], der + v_cubos[j]);
            
            
        }
        
    }
    
    return matriz_solucion[0][n];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numCubos;
    std::cin >> numCubos;
    
    if (numCubos == 0)
        return false;
    
    std::vector<int> v_cubos(numCubos);
    int cantidadComidaCubo;
    
    for(int i = 0; i < numCubos; ++i){
        std::cin >> cantidadComidaCubo;
        v_cubos[i] = cantidadComidaCubo;
    }
    
    int maxCantidadComida = resolver(v_cubos);
    
    // escribir sol
    std::cout << maxCantidadComida << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais67.txt");
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
