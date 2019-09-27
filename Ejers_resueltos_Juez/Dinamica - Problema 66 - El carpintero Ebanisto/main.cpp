// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Matriz.h"


#define INF 1000000000
//==========================>   EJERCICIO 66 <==========================//

/*COSTE:
 
 - En espacio adicional coste n*n siendo n el numero de marcas a cortar
 - En tiempo es n*n*n siendo  n el numero de marcas a cortar
 
 */

// función que resuelve el problema
int resolver(std::vector<int>const& v_marcas_cortar) {
    
    int n = v_marcas_cortar.size() - 1;
    // inicialización
    Matriz<int> matriz_solucion(n+1,n+1,0);
    //P = Matriz<int>(n+1,n+1,0);
    
    // recorrido por diagonales
    for (int d = 2; d <= n; ++d) // recorre diagonales
        for (int i = 0; i <= n - d; ++i) { // recorre elementos de diagonal
            int j = i + d;
            // calcular mínimo
            matriz_solucion[i][j] = INF;
            for (int k = i + 1; k <= j-1; ++k) {
                int minimoTemporal = matriz_solucion[i][k] + matriz_solucion[k][j] + 2*(v_marcas_cortar[j] - v_marcas_cortar[i]);
                if (minimoTemporal < matriz_solucion[i][j]) { // es mejor pasar por k
                    matriz_solucion[i][j] = minimoTemporal;
                 
                }
            }
        }
    return matriz_solucion[0][n];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int longitudTablon, numCortes;
    std::cin >> longitudTablon >> numCortes;
    
    if (longitudTablon == 0 &&  numCortes == 0)
        return false;
    
    std::vector<int> v_marcas_cortar(numCortes + 1);
    int marca;
    
    for(int i = 1; i <= numCortes; ++i){
        std::cin >> marca;
        v_marcas_cortar[i] = marca;
    }
    
    v_marcas_cortar.push_back(longitudTablon);
    
    int sol = resolver(v_marcas_cortar);
    
    // escribir sol
    std::cout << sol << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais66.txt");
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
