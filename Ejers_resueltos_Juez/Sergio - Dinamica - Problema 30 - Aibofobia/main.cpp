// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Matriz.h"

//==========================>   EJERCICIO 30 (Sergio) <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
int resolver(std::string const& palabra) {
    
    int n = palabra.size() -1;
    
    Matriz<int> matriz(n + 1, n + 1, 0);
    
   
    
    
    for (int d = 1; d <= n; ++d){ // recorre diagonales
        for (int i = 0; i <= n - d; ++i) { // recorre elementos de diagonal
            int j = i + d;
            // calcular míni
            if(palabra[i] == palabra[j]){
                matriz[i][j] = matriz[i + 1][j - 1];
            }else{
                matriz[i][j] = std::min(matriz[i][j - 1], matriz[i+1][j]) + 1;
            }
            
        }
        
    }
    
    return matriz[0][n];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string palabra;
    std::cin >> palabra;
    
    if (! std::cin)
        return false;
    
    
    
    int minNumLetras = resolver(palabra);
    
    // escribir sol
    std::cout << minNumLetras << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais30_sergio.txt");
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
