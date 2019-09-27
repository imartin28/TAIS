// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"
//==========================>   EJERCICIO 26 <==========================//

/*COSTE:
 
 - Hacer top tiene coste constant4e
 
 - Hacer pop y push tiene coste log(m) siendo m el numero de cajas
 
 - O(nlog(m)) siendo m el numero de cajas y n el numero de clientes
 
 
 */


/*  El tiempoOcupada se inicializa a 0 por que ambas cajas estan libres */
struct tDatosCaja{
    int idCaja;
    int tiempoOcupada = 0;
    
};

/*  Ordeno si el tiempo que estan ocupadas las cajas son iguales, ordeno por id y si son distintos, entonces
 ordeno por tiempo  */
bool operator<(tDatosCaja const& datosCaja1, tDatosCaja const& datosCaja2){
    if(datosCaja1.tiempoOcupada == datosCaja2.tiempoOcupada)
      return datosCaja1.idCaja < datosCaja2.idCaja;
    else
        return datosCaja1.tiempoOcupada < datosCaja2.tiempoOcupada;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int numCajas, numClientes;
    std::cin >> numCajas >> numClientes;
    
    if (numCajas == 0 && numClientes == 0)
        return false;
    
    tDatosCaja datosCaja;
    PriorityQueue<tDatosCaja> cola;
    
    for(int i = 1; i <= numCajas; ++i){

        datosCaja.idCaja = i;
        cola.push(datosCaja);
    }
    
    int tiempoCliente;
   
    
    for(int i = 0; i < numClientes; ++i){
        std::cin >> tiempoCliente;
        
        /*  Ahora asigno caja a ese cliente */
        tDatosCaja cajaActual = cola.top();
        cola.pop();
        
        /*  Aumento el tiempo en que la caja va a estar ocupada */
        cajaActual.tiempoOcupada += tiempoCliente;
     
        cola.push(cajaActual);
        
    }
   
    std::cout << cola.top().idCaja << std::endl;
    // escribir sol
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais26.txt");
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
