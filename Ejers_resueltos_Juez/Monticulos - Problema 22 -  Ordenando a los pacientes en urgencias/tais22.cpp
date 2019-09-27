// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"
//==========================>   EJERCICIO 22 <==========================//

/*COSTE:
 
 - Hacer top tiene coste constante
 
 - Hacer pop tiene coste log(m) siendo m el numero de pacientes
 
 - Hacer push tiene coste log(m) siendo m el numero de pacientes
 
 - nlog(m) siendo n el numero de eventos y m el numero de pacientes.
 
 */

struct tDatosPacientes {
    int id;
    std::string nombre;
    int gravedad;
};


bool operator<(tDatosPacientes const& paciente1, tDatosPacientes const& paciente2){
    if(paciente1.gravedad == paciente2.gravedad){
        return paciente1.id < paciente2.id;
    }else{
        return paciente1.gravedad > paciente2.gravedad;
    }
}





// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int numEventos;
    std::cin >> numEventos;
    
    if (numEventos == 0)
        return false;
    
    PriorityQueue<tDatosPacientes> cola;
    tDatosPacientes datosPaciente;
    char tipoEvento;

    for(auto i = 0; i < numEventos; ++i){
        std::cin >> tipoEvento;
        if(tipoEvento == 'I'){
            std::cin >> datosPaciente.nombre >> datosPaciente.gravedad;
            datosPaciente.id = i;
            cola.push(datosPaciente);
        }else{
            /*  Sacamos de la cola al enfermo con mayor gravedad */
            
            tDatosPacientes enfermoConMayorGravedad = cola.top();
            cola.pop();
            
            std::cout << enfermoConMayorGravedad.nombre << std::endl;;
            
        }
    }
    
    std::cout << "----" << std::endl;
    
    // escribir sol
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais22.txt");
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
