// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "GrafoValorado.h"
//==========================>   EJERCICIO 36 <==========================
/*COSTE:
 
 O(V + E) ya que en el peor de los casos hay que recorrer todos los vertices V y todas las aristas E
 
 */

class Camion{
private:
    std::vector<bool> v_marcados;
    bool siCabeCamion;
    
public:
    Camion(GrafoValorado<int>const& grafo, int origen, int destino, int anchuraCamion) : v_marcados(grafo.V(), false), siCabeCamion(false){
        
        if(!v_marcados[origen]){
            dfs(grafo, origen, anchuraCamion);
        }
        
        siCabeCamion = v_marcados[destino];
    }
    
 
    bool get_siCabeCamion(){
        return siCabeCamion;
    }
    
private:
    
    void dfs(GrafoValorado<int>const& grafo, int verticeOrigen, int anchuraCamion){
        v_marcados[verticeOrigen] = true;
        
        for(auto arista : grafo.ady(verticeOrigen)){   //Te devuelve las aristas
            if(!v_marcados[arista.otro(verticeOrigen)] && arista.valor() >= anchuraCamion){
                dfs(grafo, arista.otro(verticeOrigen) , anchuraCamion);
            }
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
    int verticeO, verticeDest, anchuraMax;
    
    for(int i = 0; i < numAristas; ++i){
        std::cin >> verticeO >> verticeDest >> anchuraMax;
        grafo.ponArista({verticeO - 1, verticeDest - 1, anchuraMax});
    }
    
    
    int numCasosDePrueba, origen, destino, anchuraCamion;
    std::cin >> numCasosDePrueba;
    
    
    for(int i = 0; i < numCasosDePrueba; ++i){
        std::cin >> origen >> destino >> anchuraCamion;
        
        Camion camionesReparto(grafo, origen - 1, destino - 1, anchuraCamion);
        if(camionesReparto.get_siCabeCamion()){
            std::cout << "SI" << std::endl;
        }else{
            std::cout << "NO" << std::endl;
        }
    }
    
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais36.txt");
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
