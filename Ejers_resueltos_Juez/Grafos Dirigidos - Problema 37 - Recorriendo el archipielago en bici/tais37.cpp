// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "GrafoValorado.h"
#include "PriorityQueue.h"
//==========================>   EJERCICIO 37 <==========================//

/*COSTE:
 
 - Realizar un top tiene coste constante
 
 - Realizar un pop tiene coste logE, siendo E el numero de aristas del grafo
 
 - Realizar un push tiene coste logE, siendo E el numero de aristas del grafo
 
 - Todas las llamadas a visit dentro del bucle while tienen un coste ElogE siendo E numero de aristas del grafo
 
 - (ElogE) de hacer el pop E veces + (ElogE) de todas las llamadas a visit
 
 O(ElogE)
 
 
 */
class ArchipielagoPrim{
private:
    std::vector<bool> v_marcados;
    int costeMin;
    PriorityQueue<Arista<int>> cola;
    bool hayPuente;
    
public:
    //Constructora
    
    ArchipielagoPrim(GrafoValorado<int>const& grafo) : v_marcados(grafo.V(), false), costeMin(0), hayPuente(true){
        
        visit(grafo, 0);
        
        while(!cola.empty()){
           Arista<int> arista = cola.top();
           cola.pop();
            int verticeOrigen = arista.uno();
            int verticeDestino = arista.otro(verticeOrigen);
            
            if(!v_marcados[verticeOrigen] || !v_marcados[verticeDestino]){
                costeMin += arista.valor();
            }
            
            
            if(!v_marcados[verticeOrigen])
                visit(grafo, verticeOrigen);
            if(!v_marcados[verticeDestino])
                visit(grafo, verticeDestino);
        }
   
        
    }
   
    
    int get_costeMin(){
        return costeMin;
    }
    
    bool get_hayPuente(){
        for(int i = 0; i < v_marcados.size(); ++i){
            if(!v_marcados[i])
                return false;
        }
          return true;
        
    }

    
private:
    
    void visit(GrafoValorado<int>const& grafo, int vertice){
        v_marcados[vertice] = true;
        
        for(auto arista : grafo.ady(vertice)){
            if(!v_marcados[arista.otro(vertice)])
                cola.push(arista);
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
    
    GrafoValorado<int> grafo(numVertices); //Damos tamaño al grafo
    
    int verticeO, verticeDest, costePuente;
    
    
    //Construimos el grafo con sus aristas y los valores de estas
    for(int i = 0; i < numAristas; ++i){
        std::cin >>  verticeO >> verticeDest >> costePuente;
        grafo.ponArista({verticeO - 1, verticeDest - 1, costePuente});
    }
   
    
    ArchipielagoPrim archipielagoEnBici(grafo);
    
     // escribir sol
    if(archipielagoEnBici.get_hayPuente())
        std::cout << archipielagoEnBici.get_costeMin() << std::endl;
    else
        std::cout << "No hay puentes suficientes" << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais37.txt");
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
