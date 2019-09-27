// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

//==========================>   EJERCICIO 51 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
int resolver(std::vector<int>const& v_alturas, std::vector<int>const& v_longitud_esquis) {
   
    int min_diferencia = 0;

    for(int i = 0; i < v_longitud_esquis.size(); ++i){
        
        min_diferencia += abs(v_alturas[i] - v_longitud_esquis[i]);

    }
    
    return min_diferencia;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numEsquiadores;
    std::cin >> numEsquiadores;
    
    if (numEsquiadores == 0)
        return false;
    
    std::vector<int> v_alturas(numEsquiadores);
    int altura;
    
    std::vector<int> v_longitud_esquis(numEsquiadores);
    int esqui;
    
    for(int i = 0; i < numEsquiadores; ++i){
        std::cin >> altura;
        v_alturas[i] = altura;
    }
    
    for(int i = 0; i < numEsquiadores; ++i){
        std::cin >> esqui;
        v_longitud_esquis[i] = esqui;
    }
    
    sort(v_alturas.begin(), v_alturas.end());
    sort(v_longitud_esquis.begin(), v_longitud_esquis.end());
    
    int sol = resolver(v_alturas, v_longitud_esquis);
    
    // escribir sol
    std::cout << sol << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais51.txt");
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
