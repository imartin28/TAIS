// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"
#define INF 1000000000

//==========================>   EJERCICIO 3E     <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
class Dijkstra {
private:
    std::vector<int> distTo;
    IndexPQ<int> cola;

    
public:
    Dijkstra(GrafoDirigidoValorado<int> const& grafo, int verticeOrigen) : distTo(grafo.V(), INF), cola(grafo.V()){
        
        distTo[verticeOrigen] = 0;
        cola.push(verticeOrigen, 0);
        
        while(!cola.empty()){
            int vertice = cola.top().elem;
            cola.pop();
            
            for(auto arista_ady : grafo.ady(vertice)){
                relax(arista_ady);
            }
        }
        
    }
    
    
    
    int get_distTo(int tiempoCronometro, int verticeOrigen){
        int cont_ratones = 0;
        
        for(int i = 0; i < distTo.size(); ++i){
            if(distTo[i] <= tiempoCronometro && i != verticeOrigen){
                ++cont_ratones;
            }
        }
        return cont_ratones;
    }
private:
    
    void relax(AristaDirigida<int>const& arista_ady){
        
        int verticeO = arista_ady.from();
        int verticeDest =  arista_ady.to();
        
        if(distTo[verticeDest] > distTo[verticeO] + arista_ady.valor()){
            distTo[verticeDest] = distTo[verticeO] + arista_ady.valor();
            
            cola.update(verticeDest, distTo[verticeDest]);
        }
        
    }
    
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int numVertices, casillaSalida, tiempoCronometro, numAristas;
    std::cin >> numVertices >> casillaSalida >> tiempoCronometro >> numAristas;
    
    if (! std::cin)
        return false;
    
    GrafoDirigidoValorado<int> grafo(numVertices);
    int verticeOrigen, verticeDestino, tiempo;
    
    for(int i = 0; i < numAristas; ++i){
        std::cin >> verticeOrigen >> verticeDestino >> tiempo;
        grafo.ponArista({verticeOrigen - 1, verticeDestino - 1, tiempo});
    }
    
    
    Dijkstra ratones(grafo.inverso(), casillaSalida - 1);
    
    std::cout << ratones.get_distTo(tiempoCronometro, casillaSalida - 1) << std::endl;
   
    
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais3e.txt");
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
