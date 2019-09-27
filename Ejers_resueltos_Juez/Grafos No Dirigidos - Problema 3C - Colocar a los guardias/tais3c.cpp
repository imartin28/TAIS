// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Grafo.h"


//==========================>   EJERCICIO 3C <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
class Guardias{
private:
    std::vector<bool> v_marked;
    std::vector<bool> v_cruces_marcados;
    bool esPosibleColocarGuardia;
    int cont_guardias_true;
    int cont_guardias_false;
  
    int minimoGuardias;
    
public:
    
    Guardias(Grafo const& grafo, int verticeOrigen) : v_marked(grafo.V(), false), v_cruces_marcados(grafo.V(), false), esPosibleColocarGuardia(true), cont_guardias_true(0), cont_guardias_false(0), minimoGuardias(0) {
        
        for(int verticeActual = 0; verticeActual < grafo.V(); ++verticeActual){
            cont_guardias_true = 0;
            cont_guardias_false = 0;
            
            if(!v_marked[verticeActual]){
                ++cont_guardias_false;
                dfs(grafo, verticeActual);
            }
            
             minimoGuardias += std::min(cont_guardias_true, cont_guardias_false);
        }
        
    }
    
    
    bool get_esPosibleColocarGuardia(){
        return esPosibleColocarGuardia;
    }
    
    
    
    
    int get_minimo_guardias(){
        return minimoGuardias;
    }
    
private:
    
    void dfs(Grafo const& grafo, int verticeOrigen){
        
        v_marked[verticeOrigen] = true;
     
        for(auto verticeAdy : grafo.ady(verticeOrigen)) {
            if(!v_marked[verticeAdy]) {
                v_cruces_marcados[verticeAdy] = !v_cruces_marcados[verticeOrigen];
                
                if(v_cruces_marcados[verticeAdy]){
                    ++cont_guardias_true;
                }else{
                    ++cont_guardias_false;
                }
                
                dfs(grafo, verticeAdy);
                
            }else if(v_marked[verticeAdy] && v_cruces_marcados[verticeAdy] == v_cruces_marcados[verticeOrigen]){
                esPosibleColocarGuardia = false;
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
    
    Grafo grafo(numVertices);
    int verticeOrigen, verticeDest;
    
    for(int i = 0; i < numAristas; ++i){
        std::cin >> verticeOrigen >> verticeDest;
        grafo.ponArista(verticeOrigen - 1, verticeDest - 1);
    }
    
    
    Guardias guardias(grafo, 0);
    
    // escribir sol
    
    if(!guardias.get_esPosibleColocarGuardia()){
        std:: cout << "IMPOSIBLE" << std::endl;
    }else{
        std::cout << guardias.get_minimo_guardias() << std::endl;
    }
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais3c.txt");
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
