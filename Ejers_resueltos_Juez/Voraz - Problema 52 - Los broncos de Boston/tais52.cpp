// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
//==========================>   EJERCICIO 52 <==========================//

/*COSTE:
 
 O(n) siendo n el numero de elementos del vector
 
 
 ESTRATEGIA VORAZ :
 
    Se ha ordenado de mayor a menor los puntos de los rivales y de menor a mayor los
    puntos de los boston.
 
 */

// función que resuelve el problema
int resolver(std::vector<int>const& v_rivales, std::vector<int>const& v_boston) {
    int resultado = 0;
    
    for(int i = 0; i < v_rivales.size(); ++i){
        if(v_boston[i] > v_rivales[i]){
            resultado += v_boston[i] - v_rivales[i];
        }
    }
    
    return resultado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numPartidos;
    std::cin >> numPartidos;
    
    if (numPartidos == 0)
        return false;
    
    
    std::vector<int> v_rivales(numPartidos);
    int punto_rival;
    
    std::vector<int> v_boston(numPartidos);
    int punto_boston;
    
    for(int i = 0; i < numPartidos; ++i){
        std::cin >> punto_rival;
        v_rivales[i] = punto_rival;
        
    }
    
    
    for(int i = 0; i < numPartidos; ++i){
        std::cin >> punto_boston;
        v_boston[i] = punto_boston;
    }
    
    
    sort(v_rivales.begin(), v_rivales.end(), std::greater<int>());
    sort(v_boston.begin(), v_boston.end());
    
    int sol = resolver(v_rivales, v_boston);
    
    // escribir sol
    std::cout << sol << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais52.txt");
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
