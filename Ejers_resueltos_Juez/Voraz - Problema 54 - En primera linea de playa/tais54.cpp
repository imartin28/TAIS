// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


//==========================>   EJERCICIO 54 <==========================//

/*COSTE:
 
 
 */

struct tEdificios {
    int iniEdificio;
    int finEdificio;
};


bool operator<(tEdificios const& edificio1, tEdificios const& edicificio2){
    return edificio1.finEdificio < edicificio2.finEdificio;
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numEdificios;
    std::cin >> numEdificios;
    
    if (numEdificios == 0)
        return false;
    
    tEdificios edificio;
    std::vector<tEdificios> v_edificios(numEdificios);
    
    for(int i = 0; i < numEdificios; ++i){
        std::cin >> edificio.iniEdificio >> edificio.finEdificio;
        v_edificios[i] = edificio;
    }
    
    sort(v_edificios.begin(), v_edificios.end());
    
    int cont_edificios = 1;
    int finalEdificioActual = v_edificios[0].finEdificio;
    
    for(int i = 1; i < v_edificios.size(); ++i){
        if(finalEdificioActual <= v_edificios[i].iniEdificio){
            ++cont_edificios;
            finalEdificioActual = v_edificios[i].finEdificio;
        }
    }
    
    // escribir sol
    std::cout << cont_edificios << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais54.txt");
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
