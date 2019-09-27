
// NOMBRE Y APELLIDOS

// comentario sobre la solución, incluyendo recurrencia
// y coste en tiempo y espacio adicional

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

bool resuelveCaso() {
   
   // leemos la entrada
   int N, M;
   cin >> N >> M;
   if (!cin)
      return false;
   
   // leemos el mapa
   vector<string> mapa(N);
   for (string & x : mapa) {
      cin >> x;
   }
   
   // resolvemos
   

   return true;
   
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   // Resolvemos
   while (resuelveCaso());
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
