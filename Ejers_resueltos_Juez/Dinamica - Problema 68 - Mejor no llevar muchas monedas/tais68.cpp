// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Matriz.h"
#include <algorithm>
#define INF 1000000000

//==========================>   EJERCICIO 68 <==========================//

/*COSTE:
 
 
 */

struct Moneda {
    int valorMoneda;
    int cantidadMoneda;
};


// función que resuelve el problema
int resolver(std::vector<Moneda>const& v_monedas, int precioCoche) {
    
    int n = v_monedas.size() - 1;
    
    Matriz<int> matriz(n + 1, precioCoche + 1, INF);
    
    for(int i = 0; i <= n; ++i){
        matriz[i][0] = 0;
    }
    
    
    
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= precioCoche; ++j){
            int maxValor_k = std::min(j / v_monedas[i].valorMoneda, v_monedas[i].cantidadMoneda);
            
            for(int k = 0; k <= maxValor_k; ++k){
                int minimo = matriz[i - 1][j - k * v_monedas[i].valorMoneda] + k;
                if(minimo < matriz[i][j]){
                    matriz[i][j] = minimo;
                }
            }
        }
    }
    
    return matriz[n][precioCoche];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numTiposMonedas;
    std::cin >> numTiposMonedas;
    
    if (! std::cin)
        return false;
    
    Moneda moneda;
    std::vector<Moneda> v_monedas(numTiposMonedas + 1);
    
    
    
 
    
    for(int i = 1; i <= numTiposMonedas; ++i){
        std::cin >> moneda.valorMoneda;
        v_monedas[i].valorMoneda = moneda.valorMoneda;
    }
    
    
    for(int i = 1; i <= numTiposMonedas; ++i){
        std::cin >> moneda.cantidadMoneda;
        v_monedas[i].cantidadMoneda = moneda.cantidadMoneda;
    }
    
    int precioCoche;
    std::cin >> precioCoche;
    
    
    int minNumMonedas = resolver(v_monedas, precioCoche);
    
    // escribir sol
    if(minNumMonedas >= INF) {
        std::cout << "NO" << std::endl;
    }else{
        std::cout << "SI " << minNumMonedas << std::endl;
    }
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais68.txt");
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
