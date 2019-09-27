// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"
#include <algorithm>
//==========================>   EJERCICIO 55 <==========================//

/*COSTE:
 O(n) siendo n el numero de elementos del vector
 
 */

/*  ESTRATEGIA VORAZ:
    Se ordena de menor a mayor fin de pelicula, y se va guardando el final de cada pelicula vista para compararla
    con el inicio de la siguiente.
 */

struct tPeliculas{
    int iniPeli;
    int finPeli;
};

/*  Se ordena de menor a mayor fin de pelicula  */
bool operator<(tPeliculas const& peli1, tPeliculas const& peli2){
    return peli1.finPeli < peli2.finPeli;
}


// función que resuelve el problema
void resolver(std::vector<tPeliculas>& v_peliculas, int& cont_peliculas, int numPeliculas) {
   
    int ultimaPeliVista = v_peliculas[0].finPeli;
    
    for(int i = 1; i < numPeliculas; ++i){
        /*  Si la ultima pelicula vista + 10 minutos es menor o igual que el inicio de la siguiente peli,
            entonces podemos verla y actualizamos la ultima pelicula vista */
        if(ultimaPeliVista + 10 <= v_peliculas[i].iniPeli ){
            ++cont_peliculas;
            ultimaPeliVista = v_peliculas[i].finPeli;
        }
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numPeliculas;
    std::cin >> numPeliculas;
    
    if (numPeliculas == 0)
        return false;
    
    int horas, minutos, duracion;
    char dosPuntos;
    
    std::vector<tPeliculas> v_peliculas(numPeliculas);
    
    tPeliculas pelicula;
    
    for(int i = 0; i < numPeliculas; ++i){
        std::cin >> horas >> dosPuntos >> minutos;
        pelicula.iniPeli = (horas * 60) + minutos;
        
        std::cin >> duracion;
        pelicula.finPeli = pelicula.iniPeli + duracion;
       
        v_peliculas[i] = pelicula;
    }
    
    int cont_peliculas = 1;
    
    sort(v_peliculas.begin(), v_peliculas.end());
    resolver(v_peliculas, cont_peliculas, numPeliculas);
    
    // escribir sol
    std::cout << cont_peliculas << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais55.txt");
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
