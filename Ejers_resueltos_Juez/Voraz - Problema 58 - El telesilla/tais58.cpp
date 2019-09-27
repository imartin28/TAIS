// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

//==========================>   EJERCICIO 58 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
int resolver(std::vector<int>const& v_personas, int pesoMaxSilla) {
    
    int cont_viajes = 0;
    
    int i = 0;
    int j = v_personas.size() - 1;
    
    while(i <= j){
         if(i != j && v_personas[i] + v_personas[j] <= pesoMaxSilla){
            --j;
         }
        ++i;
        ++cont_viajes;
    }
    
    return cont_viajes;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int pesoMaxSilla, numPersonas;
    std::cin >> pesoMaxSilla >> numPersonas;
    
    if (! std::cin)
        return false;
    
    std::vector<int> v_personas(numPersonas);
    int pesoPersona;
    
    for(int i = 0; i < numPersonas; ++i){
        std::cin >> pesoPersona;
        v_personas[i] = pesoPersona;
    }
    
    sort(v_personas.begin(), v_personas.end(), std::greater<int>());
    
    
    int numViajes = resolver(v_personas, pesoMaxSilla);
    
    // escribir sol
    std::cout << numViajes << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais58.txt");
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
