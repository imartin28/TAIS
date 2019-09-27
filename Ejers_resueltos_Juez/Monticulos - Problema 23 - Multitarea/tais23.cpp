// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"

//==========================>   EJERCICIO 23 <==========================//

/*COSTE:
 
 - Top tiene coste constante
 
 - Pop y push tiene coste logn
 
 - O(nlogn) siendo n el numero de tareas
 
 */


struct tTareas {
    int iniTarea;
    int finTarea;
    int periodoRepeticion;
};


bool operator<(tTareas const& tarea1, tTareas const& tarea2 ){
    return tarea1.iniTarea < tarea2.iniTarea;
}


bool resolver(PriorityQueue<tTareas>& cola, int tiempoConflicto){
   
    bool seSolapa = false;
    tTareas tareaActual = cola.top();
    cola.pop();
  
    
    while(!cola.empty() && cola.top().iniTarea < tiempoConflicto && !seSolapa){
        
        if(tareaActual.finTarea > cola.top().iniTarea){
            seSolapa = true;
        }else{
            if(tareaActual.periodoRepeticion != 0){
                cola.push({tareaActual.iniTarea + tareaActual.periodoRepeticion,
                    tareaActual.finTarea + tareaActual.periodoRepeticion, tareaActual.periodoRepeticion});
            }
            tareaActual = cola.top();
            cola.pop();
        
        }
    }
    return seSolapa;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numTareasUnicas, numTareasPeriodicas, tiempoConflicto;
    std::cin >> numTareasUnicas >> numTareasPeriodicas >> tiempoConflicto;
    
    if (! std::cin)
        return false;
    
    tTareas tarea;
    PriorityQueue<tTareas> cola;
    
    
    if(numTareasUnicas > 0){
        for(int i = 0; i < numTareasUnicas; ++i){
            std::cin >> tarea.iniTarea >> tarea.finTarea;
            tarea.periodoRepeticion = 0;
            cola.push(tarea);
            
        }
    }
    
    if(numTareasPeriodicas > 0){
        for(int i = 0; i < numTareasPeriodicas; ++i){
            std::cin >> tarea.iniTarea >> tarea.finTarea >> tarea.periodoRepeticion;
            cola.push(tarea);
            
        }
    }
    
    
    
    bool seSolapa =  resolver(cola, tiempoConflicto);
    
    
    // escribir sol
    if(seSolapa){
        std::cout << "SI" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais23.txt");
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
