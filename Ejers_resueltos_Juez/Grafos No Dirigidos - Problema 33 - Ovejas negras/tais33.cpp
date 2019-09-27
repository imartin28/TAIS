// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Matriz.h"
//==========================>   EJERCICIO 33 <==========================//

/*COSTE:
 
 - La constructora de ovejasBlancas tiene coste n*m siendo n el numero de filas y m el numero de columnas
 - En el dfs el coste es 4n*m siendo n el numero de filas y m el numero de columnas.
 
 - 4n*m + n*m pertenece a O(n*m) siendo n el numero de filas y m el numero de columnas.
 
 
 */

const std::pair<int, int> direcciones[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

// función que resuelve el problema
class OvejasBlancas {
    
private:
    Matriz<bool> matriz_marked;
    int cont_componentes_conexas_blancas;
    
public:
    OvejasBlancas(Matriz<char>const& matriz) : matriz_marked(matriz.numfils(), matriz.numcols(), false), cont_componentes_conexas_blancas(0) {
        
        for(auto i = 0; i < matriz.numfils(); ++i){
            for(auto j = 0; j < matriz.numcols(); ++j){
                if(matriz[i][j]== '.' && !matriz_marked[i][j]){
                    dfs(matriz, i, j);
                    ++cont_componentes_conexas_blancas;
                }
            }
        }
        
    }
  
    /*  Se le restara uno por que siempre va a haberhay una componente conexa blanca que no es una oveja */
    int get_cont_componentes_conexas_blancas(){
        return cont_componentes_conexas_blancas - 1;
    }
    

private:
    
    void dfs(Matriz<char>const& matriz, int fila, int columna){
        matriz_marked[fila][columna] = true;
        
        for(auto direccion : direcciones){
            int fila_casillaAdy = fila + direccion.first;
            int col_casillaAdy = columna + direccion.second;
            
            
            if(esCasillaEnRango(fila_casillaAdy, col_casillaAdy) && !matriz_marked[fila_casillaAdy][col_casillaAdy] && matriz[fila_casillaAdy][col_casillaAdy] == '.'){
                dfs(matriz, fila_casillaAdy, col_casillaAdy);
            }
        }
    }
    
    
    
    bool esCasillaEnRango(int fila_casillaAdy,  int col_casillaAdy ){
        if(fila_casillaAdy >= 0 && fila_casillaAdy < matriz_marked.numfils() && col_casillaAdy >= 0 &&  col_casillaAdy < matriz_marked.numcols() )
            return true;
        else
            return false;
        
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int numFilas, numColumnas;
    std::cin >> numColumnas >> numFilas;
    
    
    if (! std::cin)
        return false;
    
    Matriz<char> matriz(numFilas, numColumnas);
    char caracter;
    
    
    for(int i = 0; i < numFilas; ++i){
        for(int j = 0; j < numColumnas; ++j){
            std::cin >> caracter;
            matriz[i][j] = caracter;
        }
    }
    
    
    OvejasBlancas ovejas(matriz);
    
    std::cout << ovejas.get_cont_componentes_conexas_blancas() << std::endl;
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais33.txt");
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
