// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Matriz.h"

//==========================>   EJERCICIO 64 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
 int resolver(std::string const& palabra, std::vector<bool>& v_palabra_final) {
     
     int n = palabra.size() - 1;
     
     Matriz<int> matriz(n + 1, n + 1, 0);
     
     for(int i = 0; i <= n; ++i){
         matriz[i][i] = 1;
     }
     
     for (int d = 1; d <= n; ++d){ // recorre diagonales
         for (int i = 0; i <= n - d; ++i) { // recorre elementos de diagonal
             int j = i + d;
             // calcular míni
             
             if(palabra[i] == palabra[j]){
                 matriz[i][j] = (matriz[i + 1][j - 1]) + 2;
             }else{
                 matriz[i][j] = std::max(matriz[i][j - 1], matriz[i + 1][j]);
             }
             
         }
     }
     
     int i = 0;
     int j = n;
    
     
     
     while(i < n && j > 0 && i <= j){
         if(palabra[i] == palabra[j]){
             v_palabra_final[i] = true;
             v_palabra_final[j] = true;
             ++i;
             --j;
         }else{
             if(matriz[i][j] == matriz[i + 1][j]){
                 ++i;
             }else if(matriz[i][j] == matriz[i][j - 1]){
                 --j;
             }
             
             
         }
     }
     
     return matriz[0][n];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    std::string palabra;
    std::cin >> palabra;
    
    if (! std::cin)
        return false;
    
     std::vector<bool> v_palabra_final(palabra.size(), false);
    
    int patindromo = resolver(palabra, v_palabra_final);
    
    // escribir sol

    
    
    for(int i = 0; i < v_palabra_final.size(); ++i){
        if(v_palabra_final[i]){
            std::cout << palabra[i] ;
        }
    }
    std::cout << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais64.txt");
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
