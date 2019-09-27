// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"
//==========================>   EJERCICIO 21 <==========================//

/*COSTE:
 
 - El coste de hacer top es constante
 
 - El coste de hacer pop es logn siendo n el numero de elementos de la cola
 
 - El coste de hacer push es logn siendo n el numero de elementos de la cola
 
 
 O(mlog(n)) siendo m el numero de envios y siendo n el numero de elementos de la cola.
 
 */


struct tDatos {
    
    int id;
    int periodicidad;
    int siguiente_turno;
};


bool operator<(tDatos const& datos1, tDatos const& datos2){
    if(datos1.siguiente_turno == datos2.siguiente_turno){
        return datos1.id < datos2.id;
    }else{
       return datos1.siguiente_turno < datos2.siguiente_turno;
    }
}

// función que resuelve el problema
void resolver(PriorityQueue<tDatos>& cola, int numEnvios) {
    
    
    for(int i = 0; i < numEnvios; ++i){
        tDatos elementCola = cola.top();
        cola.pop();
        
        std::cout << elementCola.id << std::endl;
        
        elementCola.siguiente_turno += elementCola.periodicidad;
        cola.push(elementCola);
    }
    
    std::cout << "----" << std::endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numUsuarios;
    std::cin >> numUsuarios;
    
    
    if (numUsuarios == 0)
        return false;
    
    tDatos datos;
    
    PriorityQueue<tDatos> cola;
    
    for(int i = 0; i < numUsuarios; ++i ){
        std::cin >> datos.id >> datos.periodicidad;
        datos.siguiente_turno = datos.periodicidad;
        
        cola.push(datos);
    }
    
    int numEnvios = 0;
    std::cin >> numEnvios;
    
    resolver(cola, numEnvios);
    
    // escribir sol
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais21.txt");
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
