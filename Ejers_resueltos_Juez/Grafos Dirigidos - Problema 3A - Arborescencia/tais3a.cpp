// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "GrafoDirigido.h"

//==========================>   EJERCICIO 3A <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
class Arborescencia{
private:
    
    std::vector<bool> v_marked;
    bool esArborescente;
    int cont_vertices_marcados;
    int verticeRaiz;
    

    
public:
    
    Arborescencia(GrafoDirigido const& grafo) : v_marked(grafo.V(), false), esArborescente(true), cont_vertices_marcados(0), verticeRaiz(0) {
       
        int cont_candidatos_arborescentes = 0;
        
        for(auto verticeOrigen = 0; verticeOrigen < grafo.V() && cont_candidatos_arborescentes <= 1; ++verticeOrigen){
            /* si esCandidatoParaSerRaiz es que el numero de aristas entrantes es 0 */
            if(esCandidatoParaSerRaiz(grafo, verticeOrigen)){
                ++cont_candidatos_arborescentes;
                
                /* El dfs comprueba que llega a todos los vertices */
                dfs(grafo, verticeOrigen);
                
                
                /*  Comprobamos que todos los vertices esten marcados */
                if(cont_vertices_marcados != grafo.V()){
                    esArborescente = false;
                }else{
                    verticeRaiz = verticeOrigen;
                 
                }
            }
        }
        
        if(cont_candidatos_arborescentes == 0){
            esArborescente = false;
        }
    } //Termina constructora
    
    
    bool get_esArborescente(){
        return esArborescente;
    }
    
    int get_verticeRaiz(){
        return verticeRaiz;
    }
    
private:
    
    /*  Comprobamos que el grado de entrada es 0, es decir, que no tiene ninguna arista que le entre.
        Hacemos un for que recorra todos los vertices, para ver cuantas aristas le entran.
     
     */
    
    bool esCandidatoParaSerRaiz(GrafoDirigido const& grafo, int verticeOrigen){
        int cont_aristas_entrantes = 0;
        
        for(auto verticeActual = 0; verticeActual < grafo.V() && cont_aristas_entrantes == 0; ++verticeActual){
            
            for(auto verticeAdy : grafo.ady(verticeActual)){
                if(verticeAdy == verticeOrigen){
                    /* Aumenta el contador de aristas entrantes al vertice origen */
                    ++cont_aristas_entrantes;
                }
            }
        }
        
        if(cont_aristas_entrantes == 0)
            return true;
        else
            return false;
        
    } // Termina esCandidatoParaSerRaiz
    
    
    
    void dfs(GrafoDirigido const& grafo, int verticeOrigen){
        v_marked[verticeOrigen] = true;
        ++cont_vertices_marcados;
        
        for(auto verticeAdy : grafo.ady(verticeOrigen)){
            if(!v_marked[verticeAdy])
                dfs(grafo, verticeAdy);
            else{
                esArborescente = false;
            }
        }
    }  //Termina dfs
    
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int numVertices, numAristas;
    std::cin >> numVertices >> numAristas;
    
    if (! std::cin)
        return false;
    
    
    GrafoDirigido grafo(numVertices);
    int verticeOrigen, verticeDest;
    
    for(int i = 0; i < numAristas; ++i){
        std::cin >> verticeOrigen >> verticeDest;
        grafo.ponArista(verticeOrigen, verticeDest);
    }
    
    
    
    Arborescencia arborescencia(grafo);
    
    // escribir sol
    if(arborescencia.get_esArborescente())
        std::cout << "SI " << arborescencia.get_verticeRaiz() << std::endl;
    else
        std::cout << "NO" << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais3a.txt");
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
