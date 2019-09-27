// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "GrafoValorado.h"
#include "IndexPQ.h"
#define INF 1000000000

//==========================>   EJERCICIO 3D <==========================//

/*COSTE:
 
 - Hacer top tiene coste constante
 - Hacer pop tiene coste logn siendo n el numero de vertices
 - Hacer push tiene coste logn siendo n el numero de vertices
 - Hacer update tiene coste logn siendo n el numero de vertices
 - Coste ElogV siendo E  el numero de aristas y V el numero de vertices
 
 
 */

// función que resuelve el problema
class Dijkstra {
    
private:
    std::vector<int> distTo;
    IndexPQ<int> cola;
    std::vector<int> v_cont_caminos_vertices;

public:
    
    Dijkstra(GrafoValorado<int>const& grafo, int verticeOrigen) : distTo(grafo.V(), INF), cola(grafo.V()) , v_cont_caminos_vertices(grafo.V(), 0){
        
        distTo[verticeOrigen] = 0;
        cola.push(verticeOrigen, 0);
        v_cont_caminos_vertices[verticeOrigen] = 1;
        
        while(!cola.empty()){
            auto verticeActual = cola.top().elem;
            cola.pop();
            
            for(auto arista : grafo.ady(verticeActual)){
                relax(arista.otro(verticeActual), verticeActual, arista.valor());
            }
            
            
        }
        
    }
    
    
    int get_cont_caminos(){
        return  v_cont_caminos_vertices[v_cont_caminos_vertices.size() - 1];
    }
 
    
private:
    
    void relax(int verticeDestino, int verticeOrigen, int valor){
       
        
        if(distTo[verticeDestino] > distTo[verticeOrigen] + valor){
            distTo[verticeDestino] = distTo[verticeOrigen] + valor;
            cola.update(verticeDestino, distTo[verticeDestino]);
            v_cont_caminos_vertices[verticeDestino] = v_cont_caminos_vertices[verticeOrigen];
            
        }else if(distTo[verticeDestino] == distTo[verticeOrigen] + valor){
            
            v_cont_caminos_vertices[verticeDestino] += v_cont_caminos_vertices[verticeOrigen];
        }
        
    }
    
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numVertices, numAristas;
    
    std::cin >> numVertices >> numAristas;
    
    if (! std::cin)
        return false;
    
    GrafoValorado<int> grafo(numVertices);
    int verticeOrigen, verticeDestino, valor;
    
    
    for(int i = 0; i < numAristas; ++i){
        std::cin >> verticeOrigen >> verticeDestino >> valor;
        grafo.ponArista({verticeOrigen - 1, verticeDestino - 1, valor});
    }
    
    
    
    Dijkstra caminoCole(grafo, 0);
    
    // escribir sol
    std::cout << caminoCole.get_cont_caminos() << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais3d.txt");
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
