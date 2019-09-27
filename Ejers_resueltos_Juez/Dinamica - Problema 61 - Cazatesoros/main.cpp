// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Matriz.h"
//==========================>   EJERCICIO 61 <==========================//


/*
 
 
 
 */

/*COSTE:
 
 Coste en espacio adicional : (n*m) siendo n el numero de cofres y m la cantidad de aire disponible.
 
 Coste en tiempo:   (n*m) siendo n el numero de cofres y m la cantidad de aire disponible + (n*m) siendo n
    el numero de cofres y m la cantidad de aire disponible.
 
 (n*m) + (n*m) pertenece a O(n*m)
 
 
 */

struct tCofres{
    int profundidad;
    int cantidadOro;
    
};


// función que resuelve el problema
int resolver(std::vector<tCofres>const& v_cofres, int tiempoMaxAgua, int& cont_cofres_recogidos, std::vector<bool>& v_cofres_recogidos) {
    
    int n = v_cofres.size() - 1;
  
    
    Matriz<int> matriz_cantidad_oro(n + 1, tiempoMaxAgua + 1, 0);
    
   
    for(int i = 1; i <= n ; ++i){
        for(int j = 1; j <= tiempoMaxAgua; ++j){
            
            
            if((3*v_cofres[i].profundidad) > j){
                matriz_cantidad_oro[i][j] = matriz_cantidad_oro[i - 1][j];
                
            }else{
                matriz_cantidad_oro[i][j] = std::max(matriz_cantidad_oro[i - 1][j], matriz_cantidad_oro[i - 1][j - (3*v_cofres[i].profundidad)] + v_cofres[i].cantidadOro);
            }
        }
    }
    
    
    
    int j = tiempoMaxAgua;
    for(int indice_cofre = n; indice_cofre > 0; --indice_cofre){
        /*  si lo cojo */
        if(matriz_cantidad_oro[indice_cofre][j] != matriz_cantidad_oro[indice_cofre-1][j]){
        
            v_cofres_recogidos[indice_cofre] = true;
            ++cont_cofres_recogidos;
            j -= 3*v_cofres[indice_cofre].profundidad;
        }
   
    }
    
    return matriz_cantidad_oro[n][tiempoMaxAgua];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int tiempoMaxEnAgua;
    std::cin >> tiempoMaxEnAgua;
    
    if (! std::cin)
        return false;
    
    int numCofres;
    std::cin >> numCofres;
    tCofres cofre;
    
    
    std::vector<tCofres> v_cofres(numCofres + 1);
    
    for(int i = 1; i <= numCofres; ++i){
        std::cin >> cofre.profundidad >> cofre.cantidadOro;
        v_cofres[i] = cofre;
    }
    
    int cont_cofres_recogidos = 0;
    std::vector<bool> v_cofres_recogidos(v_cofres.size() + 1, false);

    
    int maxCantidadOro = resolver(v_cofres, tiempoMaxEnAgua, cont_cofres_recogidos, v_cofres_recogidos);
    
    
    std::cout << maxCantidadOro << std::endl;
    std::cout << cont_cofres_recogidos << std::endl;
    // escribir sol
    for(int i = 0; i < v_cofres_recogidos.size(); ++i){
        if(v_cofres_recogidos[i])
            std::cout << v_cofres[i].profundidad << ' ' << v_cofres[i].cantidadOro << std::endl;
    }
    
    std::cout << "----" << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais61.txt");
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
