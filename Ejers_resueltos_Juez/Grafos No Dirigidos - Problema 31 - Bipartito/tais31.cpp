// Nombre del alumno: Irene Martin Berlanga y Patricia Ortiz Zamora
// Usuario del Juez: TAIS02 y TAIS38



#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Grafo.h"

//==========================>   EJERCICIO 31 <==========================//

/*COSTE:
 
 v ==> en el peor de los casos se recorre en la constructora todos los vertices V del grafo
 
 +
 
 V + E ==> si es bipartito recorre todos los vertices V y las aritas E del grafo, y en caso de que
    no sea bipartito recorre los vertices V y las aristas E del grafo hasta que dos vertices adyacentes tengan el mismo color
 
 
 
 O(V + E) siendo V los vertices del grafo y E las aristas.
 
 */

// función que resuelve el problema

class Bipartito{
private:
    std::vector<bool> marcado;
    std::vector<bool> v_colores;
    bool esBipartito;
    
    
public:
    
    Bipartito(Grafo const& grafo): marcado(grafo.V(), false), v_colores(grafo.V(), false), esBipartito(true) {
        for(auto verticeO = 0; verticeO < grafo.V(); ++verticeO){
            if(!marcado[verticeO]){
                dfs(grafo, verticeO);
            }
            
       
        }
        
    }
    
    
    bool get_esBipartito(){
        return esBipartito;
    }

private:
    
    void dfs(Grafo const& grafo, int verticeO){
        marcado[verticeO] = true;
        
        for(auto v_ady : grafo.ady(verticeO)){
            if(!marcado[v_ady]){
                v_colores[v_ady] = !v_colores[verticeO]; //marca del color contrario a su vertice origen
                dfs(grafo, v_ady);
            }else{
                if(v_colores[v_ady] == v_colores[verticeO]){
                    esBipartito = false;
                    return;
                }
                
            }
        }
        
        
    }
    
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numVertices;
    std::cin >> numVertices;
    if (! std::cin)
        return false;
    
    int numAristas;
    std::cin >> numAristas;
    
    Grafo grafo(numVertices);
    int verticeO, verticeDest;
    
    for(int i = 0; i < numAristas; ++i){
        std::cin >> verticeO >> verticeDest;
        grafo.ponArista(verticeO , verticeDest);
    }
    
   
    Bipartito bipartito(grafo);
    
    if(bipartito.get_esBipartito()){
        std::cout << "SI" << std::endl;
    }else{
         std::cout << "NO" << std::endl;
    }
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais31.txt");
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
