// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Matriz.h"
#define INF 1000000000

//==========================>   EJERCICIO 29 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
int resolver(std::vector<int>const& v_valores, int valorAconseguir, std::vector<int>& v_solucion_sectores_utilizado) {
    
    int n = v_valores.size() - 1;
    
    Matriz<int> matriz(n + 1, valorAconseguir + 1, INF);
    
    matriz[0][0] = 0;
    for(int i = 1; i <= n; ++i){
        matriz[i][0] = 0;
    }
    
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= valorAconseguir; ++j){
            if(v_valores[i] > j){
                matriz[i][j] = matriz[i - 1][j];
            }else{
                matriz[i][j] = std::min(matriz[i -1][j], matriz[i][j - v_valores[i]] + 1);
            }
        }
    }
    
    int j_puntuacionRestante = valorAconseguir;
    int i_sectores_utilizados = n;
    
    
    while(j_puntuacionRestante > 0 && i_sectores_utilizados > 0){
        if(j_puntuacionRestante >= v_valores[i_sectores_utilizados] && ((matriz[i_sectores_utilizados][j_puntuacionRestante] - matriz[i_sectores_utilizados][j_puntuacionRestante - v_valores[i_sectores_utilizados]]) == 1 )){
            
            j_puntuacionRestante -= v_valores[i_sectores_utilizados];
            v_solucion_sectores_utilizado.push_back(v_valores[i_sectores_utilizados]);
           
        }else{
            i_sectores_utilizados -= 1;
        }
    }
    
 
    
    
    return matriz[n][valorAconseguir];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int valorAconseguir, numSectoresDiana;
    std::cin >> valorAconseguir >> numSectoresDiana;
    
    if (! std::cin)
        return false;
    
    std::vector<int> v_valores(numSectoresDiana + 1);
    int valorPuntuacionSector;
    
    for(int i = 1; i <= numSectoresDiana; ++i){
        std::cin >> valorPuntuacionSector;
        v_valores[i] = valorPuntuacionSector;
    }
    
    std::vector<int> v_solucion_sectores_utilizados;
    
    int minNumDardos = resolver(v_valores, valorAconseguir, v_solucion_sectores_utilizados);
    
    // escribir sol
    if(minNumDardos >= INF){
        std::cout << "Imposible" << std::endl;
    }else{
        std::cout << minNumDardos << ": ";
        
        for(int i = 0; i < v_solucion_sectores_utilizados.size(); ++i){
            std::cout << v_solucion_sectores_utilizados[i] << ' ';
        }
        std::cout << std::endl;
    }
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais29_sergio.txt");
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
