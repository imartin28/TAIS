// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 50 <==========================//

/*COSTE:
 
 O(n) siendo n el numero de elementos del vector
 
 */

// función que resuelve el problema
int resolver(std::vector<int>const& v_posiciones_agujeros, int longitudParches) {
    
    int longitudCubreParche = v_posiciones_agujeros[0] + longitudParches;
    int cont_parches = 1;
    
    for(int i = 1; i <=  v_posiciones_agujeros.size() - 1; ++i){
        if(v_posiciones_agujeros[i] > longitudCubreParche){
            ++cont_parches;
            longitudCubreParche = v_posiciones_agujeros[i] + longitudParches;
        }
       
       
       
    }
    return cont_parches;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numAgujeros, longitudParches;
    std::cin >> numAgujeros >> longitudParches;
    
    if (! std::cin)
        return false;
    
    std::vector<int> v_posiciones_agujeros(numAgujeros);
    int posicion;
    
    for(int i = 0; i < numAgujeros; ++i){
        std::cin >> posicion;
        v_posiciones_agujeros[i] = posicion;
    }
    
    
    int sol = resolver(v_posiciones_agujeros, longitudParches);
    
    // escribir sol
    
    std::cout << sol << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais50.txt");
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
