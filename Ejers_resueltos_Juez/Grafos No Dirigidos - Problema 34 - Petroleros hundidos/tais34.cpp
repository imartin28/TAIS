// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Matriz.h"
#include "ConjuntosDisjuntos.h"

//==========================>   EJERCICIO 34 <==========================//

/*COSTE:
 
 
 */

const std::pair<int, int> direcciones[8] = {{0, -1}, {1, 1}, {1, 0}, {1, -1} , {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}};

class Petroleros{
    
private:
    int mancha_mas_grande;
    ConjuntosDisjuntos conjuntosDisjuntos;
    
public:
    
    Petroleros(Matriz<char>const& matriz) : mancha_mas_grande(0), conjuntosDisjuntos(matriz.numfils()*matriz.numcols()) {
        
        for(int fila = 0; fila < matriz.numfils(); ++fila){
            for(int columna = 0; columna < matriz.numcols(); ++columna){
                if(matriz[fila][columna] == '#'){
                    for(auto direccion : direcciones){
                        int fila_ady = direccion.first + fila;
                        int columna_ady = direccion.second + columna;
                        
                        if(enRango(matriz, fila_ady, columna_ady) && matriz[fila_ady][columna_ady] == '#'){
                            int id_posicion_mancha_actual = columna + fila * matriz.numcols();
                            int id_posicion_mancha_ady = columna_ady + fila_ady * matriz.numcols();
                            
                            conjuntosDisjuntos.unir(id_posicion_mancha_actual, id_posicion_mancha_ady);
                            if(conjuntosDisjuntos.tam(id_posicion_mancha_actual) > mancha_mas_grande){
                                mancha_mas_grande = conjuntosDisjuntos.tam(id_posicion_mancha_actual);
                            }
                        }
                        
                    }
                }
            }
        }
    }
    
    
    void nueva_mancha_mas_grande(Matriz<char>const& matriz, int fila_nueva_mancha, int columna_nueva_mancha ){
        
        for(auto direccion : direcciones){
            int fila_ady = direccion.first + fila_nueva_mancha;
            int columna_ady = direccion.second + columna_nueva_mancha;
            
            if(enRango(matriz, fila_ady, columna_ady) && matriz[fila_ady][columna_ady] == '#'){
                int id_posicion_mancha_grande = columna_ady + fila_ady * matriz.numcols();
                int id_posicion_mancha_actual = columna_nueva_mancha + fila_nueva_mancha * matriz.numcols();
                conjuntosDisjuntos.unir(id_posicion_mancha_grande, id_posicion_mancha_actual);
                
                if(conjuntosDisjuntos.tam(id_posicion_mancha_grande) > mancha_mas_grande){
                    mancha_mas_grande = conjuntosDisjuntos.tam(id_posicion_mancha_grande);
                }
            }
        }
    }
    
    
    int get_mancha_mas_grande(){
        return mancha_mas_grande;
    }
    
private:
    
    bool enRango(Matriz<char>const& matriz, int fila_ady, int columna_ady){
        return fila_ady < matriz.numfils() && fila_ady >= 0 && columna_ady < matriz.numcols() && columna_ady >= 0;
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int numFilas, numColumnas;
    std::cin >> numFilas >> numColumnas;
    if (! std::cin)
        return false;
    
    
    Matriz<char> matriz(numFilas, numColumnas);
    char caracter;
    
    std::string contenidoPorFila;
    int j = 0;
    std::cin.ignore();
    for(int i = 0; i < numFilas; ++i){
        
        getline(std::cin, contenidoPorFila);
        for(char c : contenidoPorFila){
            matriz[i][j++] = c;
        }
        j = 0;
        
    }
    
   
    
    Petroleros petrolero(matriz);
    std::cout << petrolero.get_mancha_mas_grande() << ' ';
    
    int numImagenesAdicionales;
    std::cin >> numImagenesAdicionales;
    int fila_nueva_mancha, columna_nueva_mancha;
    
    for(int i = 0; i < numImagenesAdicionales; ++i){
        std::cin >> fila_nueva_mancha >> columna_nueva_mancha;
        matriz[fila_nueva_mancha - 1][columna_nueva_mancha - 1] = '#';
        
        petrolero.nueva_mancha_mas_grande(matriz, fila_nueva_mancha - 1, columna_nueva_mancha - 1);
        std::cout << petrolero.get_mancha_mas_grande() << ' ';
    }
    
    std::cout << std::endl;
    
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais34.txt");
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
