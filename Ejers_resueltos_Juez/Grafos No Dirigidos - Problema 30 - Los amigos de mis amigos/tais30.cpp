// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Grafo.h"
#include <algorithm>
//==========================>   EJERCICIO 30 <==========================

/*COSTE:
 
 v ==> en el bucle for de la constructora se recorre en el peor de los casos todos los
    vertices V del grado
 +
 
 V + E  ==> en el bucle for del dfs en el peor de los casos, nos recorremos todos los vertices V
        y aristas E del grafo.
 
 
O(V + E) siendo V el numero de vertices y E el numero de aristas
 
 

 
 */

// función que resuelve el problema
class Amigo {
    
private:
    std::vector<bool> marcados;
    int max_cantidad_amigos;
    
public:
    
    Amigo(Grafo const& grafo): marcados(grafo.V(), false), max_cantidad_amigos(0) {
        for(auto verticeO = 0; verticeO < grafo.V(); ++verticeO){
            if(!marcados[verticeO]){
                int cont_amigos = 0;
                dfs(grafo, verticeO, cont_amigos);
                
                if(cont_amigos > max_cantidad_amigos){
                    max_cantidad_amigos = cont_amigos;
                }
            }
        }
        
    }
    
    
    int get_max_cont_amigos(){
        return max_cantidad_amigos;
    }
    
    
private:
    void dfs(Grafo const& grafo, int verticeO, int& cont_amigos){
        marcados[verticeO] = true;
        ++cont_amigos;
        for(auto v_ady : grafo.ady(verticeO)){
            if(!marcados[v_ady]){
                dfs(grafo, v_ady, cont_amigos);
            }
        }
    }
    
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int vertices, aristas;
    std::cin >> vertices >> aristas;
    
    
    Grafo grafo(vertices);
    int verticeOrigen, verticeDestino;
    
    for(int i = 0; i < aristas; ++i ){
        std::cin >> verticeOrigen >> verticeDestino;
        grafo.ponArista(verticeOrigen - 1, verticeDestino - 1);
        
    }
    
    Amigo amigo_de_amigo(grafo);
    
    std::cout << amigo_de_amigo.get_max_cont_amigos() << std::endl;
    // escribir sol
    
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais30.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
