// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

//==========================>   EJERCICIO 53 <==========================//

/*COSTE:
 
 Estrategia voraz: Se ha ordenado de mayor a menor el vector de voltajes, y se coge los voltajes de los
    extremos, si suman menos que el voltaje minimo necesario, nos quedamos con el voltaje mas alto de los dos
    y movemos el otro indice.
 
 */

// función que resuelve el problema
int resolver(std::vector<int>const& v_voltajes, int voltaje_min) {
    
    int i = 0;
    int j = v_voltajes.size() - 1;
    int cont_coches = 0;
    
    while(i < j){
        
        if(v_voltajes[i] + v_voltajes[j] >= voltaje_min){
            ++cont_coches;
            ++i;
            --j;
        }else{
            --j;
        }
        
        
    }
    
    return cont_coches;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int numPilas, voltaje_min;
    std::cin >> numPilas >> voltaje_min;
    
    std::vector<int> v_voltajes(numPilas);
    int voltaje;
    
    for(int i = 0; i < numPilas; ++i){
        std::cin >> voltaje;
        v_voltajes[i] = voltaje;
    }
    
    sort(v_voltajes.begin(), v_voltajes.end(), std::greater<int>());
    int sol = resolver(v_voltajes, voltaje_min);
    // escribir sol
    std::cout << sol << std::endl;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais53.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
