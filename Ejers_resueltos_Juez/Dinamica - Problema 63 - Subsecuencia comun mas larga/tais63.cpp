// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Matriz.h"
#include <algorithm>

//==========================>   EJERCICIO 63 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
int resolver(std::string const& palabra1, std::string const& palabra2) {
    
    int n1 = palabra1.size() - 1;
    int n2 = palabra2.size() - 1;
    
    Matriz<int> matriz_solucion(n1 + 1, n2 + 1, 0);
    
    for(int i = 1; i <= n1; ++i){
        for(int j = 1; j <= n2; ++j){
            if(palabra1[i] == palabra2[j]){
                matriz_solucion[i][j] = (matriz_solucion[i - 1][j - 1]) + 1;
                
            }else{
                matriz_solucion[i][j] = std::max(matriz_solucion[i - 1][j], matriz_solucion[i][j - 1]);
            }
        }
    }
 
    return matriz_solucion[n1][n2];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string palabra1, palabra2;
    std::cin >> palabra1 >> palabra2;
    
    
    if (! std::cin)
        return false;
    
    palabra1.insert(0, " ");
    palabra2.insert(0, " ");
    
    int subsecuenciaMasLarga = resolver(palabra1, palabra2);
    
    // escribir sol
    std::cout << subsecuenciaMasLarga << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais63.txt");
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
