// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

//==========================>   EJERCICIO 57 <==========================//

/*COSTE:
 
 
 */

struct tTrabajos {
    int iniTrabajo;
    int finTrabajo;
};

bool operator<(tTrabajos const& trabajo1, tTrabajos const& trabajo2){
    return trabajo1.iniTrabajo < trabajo2.iniTrabajo;
}


// función que resuelve el problema
int resolver( std::vector<tTrabajos>const& v_trabajo, int iniPlaneta, int finPlaneta) {
    int cont_trabajos = 0;
    int max_final_trabajo = 0;
    int cubiertoHasta = iniPlaneta;
  
    
    int i = 0;
   
    if(v_trabajo.size() == 0 || v_trabajo[0].iniTrabajo > iniPlaneta){
        return cont_trabajos = 0;
    }
    
    
    while (i < v_trabajo.size() && cubiertoHasta < finPlaneta) {
        if (v_trabajo[i].iniTrabajo > cubiertoHasta) {
            return cont_trabajos = 0;
        } else { //Buscar el trabajo que acabe el ultimo de los que empiezan antes o en cubiertoHasta
            while (i < v_trabajo.size() && v_trabajo[i].iniTrabajo <= cubiertoHasta) {
                if (v_trabajo[i].finTrabajo > v_trabajo[max_final_trabajo].finTrabajo  && v_trabajo[i].finTrabajo > cubiertoHasta) {
                    max_final_trabajo = i;
                }
                ++i;
            }
            cubiertoHasta = v_trabajo[max_final_trabajo].finTrabajo;
            ++cont_trabajos;
        }
    }
    
    if (cubiertoHasta < finPlaneta) {
        return cont_trabajos = 0;
        
    }
    
    return cont_trabajos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int inicioPlaneta, finPlaneta, numTrabajos;
    std::cin >> inicioPlaneta >> finPlaneta >> numTrabajos;
    
    if (inicioPlaneta == 0 && finPlaneta == 0 && numTrabajos == 0)
        return false;
    
    
    std::vector<tTrabajos> v_trabajos(numTrabajos);
    tTrabajos trabajo;
    
    for(int i = 0; i < numTrabajos; ++i){
        std::cin >> trabajo.iniTrabajo >> trabajo.finTrabajo;
        v_trabajos[i] = trabajo;
    }
    
    
    sort(v_trabajos.begin(), v_trabajos.end());
    
    int numTrabajosTotal = resolver(v_trabajos, inicioPlaneta, finPlaneta);
    
    // escribir sol
    if(numTrabajosTotal == 0)
        std::cout << "Imposible" << std::endl;
    else
        std::cout << numTrabajosTotal << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais57.txt");
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
