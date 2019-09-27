// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"
#define INF 1000000000
//==========================>   EJERCICIO 38 <==========================//

/*COSTE:
 
 ElogV siendo E el numero de aristas y V el numero de vertices.
 
 */

// función que resuelve el problema
class Dijkstra{
    
private:
    std::vector<AristaDirigida<int>> edgeTo;
    std::vector<int> distTo;
    IndexPQ<int> pq;
    
public:
    Dijkstra(GrafoDirigidoValorado<int>& grafo, int verticeO, std::vector<int>const& v_tiempo_carga_pagina):  edgeTo(grafo.V()), distTo(grafo.V(), INF), pq(grafo.V()) {
        
        
        distTo[verticeO] = v_tiempo_carga_pagina[verticeO];
        pq.push(verticeO, 0);
        
        while(!pq.empty()){
            int vertice = pq.top().elem;
            pq.pop();
            
            for(auto arista : grafo.ady(vertice)){
                relax(arista, v_tiempo_carga_pagina);
            }
        }
    }
    
    
    int get_distTo(){
        return distTo[distTo.size() - 1];
    }
    
    
private:
    void relax(AristaDirigida<int> arista, std::vector<int>const& v_tiempo_carga_pagina){
        int verticeOrigen = arista.from();
        int verticeDestino = arista.to();
        
        
        if(distTo[verticeDestino] > distTo[verticeOrigen] + arista.valor() + v_tiempo_carga_pagina[verticeDestino]){
            distTo[verticeDestino] = distTo[verticeOrigen] + arista.valor() + v_tiempo_carga_pagina[verticeDestino];
            edgeTo[verticeDestino] = arista;
            
            pq.update(verticeDestino, distTo[verticeDestino]);
        }
    }
    
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numPaginas;
    std::cin >> numPaginas;
    
    if (numPaginas == 0)
        return false;
    
    std::vector<int> v_tiempo_carga_pagina(numPaginas);
    int tiempo;
    
    for(int i = 0; i < numPaginas; ++i){
        std::cin >> tiempo;
        v_tiempo_carga_pagina[i] = tiempo;
    }
    
    GrafoDirigidoValorado<int> grafo(numPaginas);
    int verticeO, verticeDest, tiempoCarga, numEnlaces;
    std::cin >> numEnlaces;
    
    for(int i = 0; i < numEnlaces; ++i){
        std::cin >> verticeO >> verticeDest >> tiempoCarga;
        grafo.ponArista({verticeO - 1, verticeDest - 1, tiempoCarga});
    }
    
    Dijkstra dijkstraNavegando(grafo, 0, v_tiempo_carga_pagina);
    
    // escribir sol
    if(dijkstraNavegando.get_distTo() == INF)
        std::cout << "IMPOSIBLE" << std::endl;
    else
        std::cout << dijkstraNavegando.get_distTo() << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais38.txt");
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
