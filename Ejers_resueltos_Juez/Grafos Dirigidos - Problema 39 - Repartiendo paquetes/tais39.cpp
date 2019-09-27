// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"
#define INF 1000000000

//==========================>   EJERCICIO 39 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
class Dijkstra {
private:
    std::vector<AristaDirigida<int>> edgeTo;
    std::vector<int> distTo;
    IndexPQ<> cola;
    int esfuerzo_min_ida;
    bool esPosible;
    
    
public:
    
    Dijkstra(GrafoDirigidoValorado<int>const& grafo, int verticeO, std::vector<int> const& v_casas_destino) : edgeTo(grafo.V()), distTo(grafo.V(), INF), cola(grafo.V()), esfuerzo_min_ida(0), esPosible(true) {
        
        distTo[verticeO] = 0;
        cola.push(verticeO, 0);
       
        
        while(!cola.empty()){
            auto vertice = cola.top().elem;
            cola.pop();
                
            
            for(auto verticeAdy : grafo.ady(vertice)){
                relax(verticeAdy, verticeO);
            }
        }
        
       
    }
    
  
    int get_distTo(std::vector<int>const& v_casas_destino){
        int esfuerzoTotal = 0;
        
      for(int i = 0; i < v_casas_destino.size(); ++i){
        if(distTo[v_casas_destino[i]] != INF){
            esfuerzoTotal += distTo[v_casas_destino[i]];
        
        }else{
            esPosible = false;
        }
      }
         return esfuerzoTotal;
    
    }
   
    
    
    bool get_esPosible(){
        return esPosible;
    }
    
private:
    void relax(AristaDirigida<int> vertice, int verticeorigen){
        int verticeOrigen = vertice.from();
        int verticeDestino = vertice.to();
        
        if(distTo[verticeDestino] > distTo[verticeOrigen] + vertice.valor()){
            
            distTo[verticeDestino] = distTo[verticeOrigen] + vertice.valor();
            edgeTo[verticeDestino] = vertice;
            
            cola.update(verticeDestino, distTo[verticeDestino]);
            
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
    
    GrafoDirigidoValorado<int> grafo(numVertices);
    int verticeO, verticeDest, valor;
    
    for(int i = 0; i < numAristas; ++i){
        std::cin >> verticeO >> verticeDest >> valor;
        grafo.ponArista({verticeO - 1, verticeDest - 1, valor});
    }
    
    
    int verticeOrigenOficina, numPaquetes;
    std::cin >> verticeOrigenOficina >> numPaquetes;
    std::vector<int> v_casas_destino(numPaquetes);
    int casa;
    
    
    for(int i = 0; i < numPaquetes; ++i){
        std::cin >> casa;
        v_casas_destino[i] = casa - 1;
    }
    
    
     /*  GRAFO SIN INVERTIR  */
    
    Dijkstra repartidorPaquetes(grafo, verticeOrigenOficina - 1, v_casas_destino);
  
    int esfuerzoMinIda = repartidorPaquetes.get_distTo(v_casas_destino);
    
    
    
    /*  GRAFO INVERTIDO  */
   
    GrafoDirigidoValorado<int> grafoInverso = grafo.inverso();

    Dijkstra repartidorPaquetesInv(grafoInverso, verticeOrigenOficina - 1, v_casas_destino);
    
    int esfuerzoMinVuelta = repartidorPaquetesInv.get_distTo(v_casas_destino);
    

    
  
  
   
    // escribir sol
   if(repartidorPaquetes.get_esPosible() && repartidorPaquetesInv.get_esPosible())
       std::cout << esfuerzoMinIda + esfuerzoMinVuelta << std::endl;
    
    else{
        std::cout << "Imposible" << std::endl;
    }
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais39.txt");
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
