// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

//==========================>   EJERCICIO 5B <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
int resolver(std::vector<int>const& v_libros) {
    
    int i = 0;
    int cont_libros = 0;
    int descuento = 0;
    
    while(i < v_libros.size() && cont_libros < 3){
       
        if(cont_libros != 3){
             ++cont_libros;
             ++i;
        }
        
        if(cont_libros == 3){
            descuento += v_libros[i - 1];
            cont_libros = 0;
            
        }
       
    }
    return descuento;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numLibros;
    std::cin >> numLibros;
    
    
    if (! std::cin)
        return false;
    std::vector<int> v_libros(numLibros);
    int libro;
    
    for(int i = 0; i < numLibros; ++i){
        std::cin >> libro;
        v_libros[i] = libro;
    }
    
    sort(v_libros.begin(), v_libros.end(), std::greater<int>());
    
    if(v_libros.size() < 3){
        std::cout << "0" << std::endl;
    }else{
        int descuentoMax = resolver(v_libros);
        std::cout << descuentoMax << std::endl;
    }
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais5b.txt");
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
