// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

//==========================>   EJERCICIO 5A <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
int resolver(std::vector<int>const& v_tallas_nuevosJugadores, std::vector<int>const& v_tallas_tenemos ) {
    
    
    int ini_tallas_nuevos_jugadores = 0;
    int camisetas_asignadas = 0;
    int camisetas_a_comprar = 0;
    
    
    
    int ini_talla_camisetas_tenemos = 0;
    
    
    
    while(ini_tallas_nuevos_jugadores != v_tallas_nuevosJugadores.size() && ini_talla_camisetas_tenemos != v_tallas_tenemos.size()){
        
        
        if( ( v_tallas_tenemos[ini_talla_camisetas_tenemos] - v_tallas_nuevosJugadores[ini_tallas_nuevos_jugadores]) == 1 || ( v_tallas_tenemos[ini_talla_camisetas_tenemos] - v_tallas_nuevosJugadores[ini_tallas_nuevos_jugadores]) == 0){
            
            ++ini_tallas_nuevos_jugadores;
            ++ini_talla_camisetas_tenemos;
            ++camisetas_asignadas;
            
        }else if(v_tallas_nuevosJugadores[ini_tallas_nuevos_jugadores] < v_tallas_tenemos[ini_talla_camisetas_tenemos]){
            
            ++ini_talla_camisetas_tenemos;
            
        }else {
            
            ++ini_tallas_nuevos_jugadores;
        }
        
    }
    
    
    if(camisetas_asignadas == 0){
        camisetas_a_comprar = v_tallas_nuevosJugadores.size();
    }else{
        camisetas_a_comprar = v_tallas_nuevosJugadores.size() - camisetas_asignadas;
    }
    
    return camisetas_a_comprar;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numJugadores, numEquipaciones;
    std::cin >> numJugadores >> numEquipaciones;
    
    if (! std::cin)
        return false;
    
    std::vector<int> v_tallas_nuevosJugadores(numJugadores);
    std::vector<int> v_tallas_tenemos(numEquipaciones);
    int tallaNecesitaJugador, tallaQueTenemos;
    
    for(int i = 0; i < numJugadores; ++i){
        std::cin >> tallaNecesitaJugador;
        v_tallas_nuevosJugadores[i] = tallaNecesitaJugador;
    }
    
    for(int i = 0; i < numEquipaciones; ++i){
        std::cin >> tallaQueTenemos;
        v_tallas_tenemos[i] = tallaQueTenemos;
    }
    
    
    sort(v_tallas_tenemos.begin(), v_tallas_tenemos.end(), std::greater<int>());
    sort(v_tallas_nuevosJugadores.begin(), v_tallas_nuevosJugadores.end(), std::greater<int>());
    
    
    int numMinCamisetas = resolver(v_tallas_nuevosJugadores, v_tallas_tenemos);
    
    // escribir sol
    std::cout << numMinCamisetas << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais5a.txt");
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
