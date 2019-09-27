// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"
#include <algorithm>
//==========================>   EJERCICIO 56 <==========================//

/*COSTE:
 
 
 */

struct tCharlas {
    int iniCharla;
    int finCharla;

};

/*  Ordenamos el vector por inicio de menor a mayor */
bool operator<(tCharlas const& charla1, tCharlas const& charla2){
        return charla1.iniCharla < charla2.iniCharla;
    
    
}

// función que resuelve el problema
void resolver(std::vector<tCharlas>& v_charlas, PriorityQueue<int>& colaAmigos ) {
    
  /*    En la primera charla siemore va a poder ir una persona  */
    colaAmigos.push(v_charlas[0].finCharla);
    
    
    for(auto i = 1; i < v_charlas.size(); ++i){
        
        /*  Cogemos el final de la charla que antes termina */
        int ultimaCharla = colaAmigos.top();
       
        if(ultimaCharla > v_charlas[i].iniCharla){
            colaAmigos.push(v_charlas[i].finCharla);
            
        }else{
            colaAmigos.pop();
            colaAmigos.push(v_charlas[i].finCharla);
        }
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numActividades;
    std::cin >> numActividades;
    
    if (numActividades == 0)
        return false;
    
    tCharlas charlas;
    PriorityQueue<int> colaAmigos;
    std::vector<tCharlas> v_charlas(numActividades);
    
    for(int i = 0; i < numActividades;++i ){
        std::cin >> charlas.iniCharla >> charlas.finCharla;
        v_charlas[i] = charlas;
    }
    
    sort(v_charlas.begin(), v_charlas.end());
    resolver(v_charlas, colaAmigos);
    
    // escribir sol
    std::cout << colaAmigos.size() - 1<< std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais56.txt");
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
