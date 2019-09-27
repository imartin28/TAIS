// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"
//==========================>   EJERCICIO 20 <==========================//

/*COSTE:
 
 - Realizar un top tiene coste constante
 
 - El coste de hacer pop es logN siendo n el numero de elementos de la cola
 
 - El coste de hacer push es logN sienddo n el numero de elementos de la cola
 
 - (logN) de hacer el pop n veces, siendo n el numero de elementos de la cola + (logN) de hacer el push n veces
 
  O(logN)
 
 */

// función que resuelve el problema
long long int resolver(PriorityQueue<long long int>& cola) {
    long long int esfuerzoMin = 0, resultado = 0;
    long long int primerDigito = 0, segundoDigito = 0;
    
    while(cola.size() > 1){
        primerDigito = cola.top();
        cola.pop();
        
        segundoDigito = cola.top();
        cola.pop();
        
        resultado = primerDigito + segundoDigito;
        esfuerzoMin += resultado;
        cola.push(resultado);
        
    }
    return esfuerzoMin;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long long int numSumandos;
    std::cin >> numSumandos;
    
    if (numSumandos == 0)
        return false;
    
    PriorityQueue<long long int> cola;
    long long int digito;
    
    for(long long int i = 0; i < numSumandos; ++i){
        std::cin >> digito;
        cola.push(digito);
    }
    
    long long int sol = 0;
    
    if(numSumandos > 1)
        sol = resolver(cola);
    
    
    // escribir sol
    std::cout << sol << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais20.txt");
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
