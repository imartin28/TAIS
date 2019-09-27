// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: TAIS02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>


#define PARED '#'
#define ENTRADA 'E'
#define SALIDA 'P'
#define CASILLA_VIGILADA '&'

//==========================>   EJERCICIO 3B <==========================//

/*COSTE:
 
 
 */

typedef struct {
    int fila;
    int columna;
} Pixel;


const std::pair<int,int> direcciones[4] = {{0,1}, {-1,0}, {0, -1}, {1,0}};
// función que resuelve el problema
class RondaNocturna {
private:
    std::vector<std::vector<bool>> marked;
    std::vector<std::vector<size_t>> distTo;
    int filaEntrada;
    int columnaEntrada;
    int filaSalida;
    int columnaSalida;
    bool entradaVigilada;
    bool salidaVigilada;
    
public:
    
    RondaNocturna(std::vector<std::vector<char>> & imagen) : marked(imagen.size(), std::vector<bool>(imagen[0].size(), false)),
    distTo(imagen.size(), std::vector<size_t>(imagen[0].size(), 0)), entradaVigilada(false), salidaVigilada(false) {
        
        colocarCasillasVigiladasPorSensores(imagen);
        //mostrar(imagen);
        if (!entradaVigilada && !salidaVigilada) {
            recorridoEnAnchura(imagen, filaEntrada, columnaEntrada);
        }
    }
    
    // ¿Hay camino de la entrada a la salida?
    bool hasPathToExit() const {
        return marked[filaSalida][columnaSalida];
    }
    
    // Devuelve el numero minimo de casillas desde la entrada a la salida
    size_t distanceToExit() const {
        return distTo[filaSalida][columnaSalida];
    }
    
private:
    void colocarCasillasVigiladasPorSensores(std::vector<std::vector<char>> & imagen) {
        int alcanceSensor;
        
        for (int fila = 0; fila < imagen.size(); ++fila) {
            for (int columna = 0; columna < imagen[0].size(); ++columna) {
                if (esUnSensor(imagen[fila][columna])) {
                    alcanceSensor = imagen[fila][columna] - '0';
                    imagen[fila][columna] = CASILLA_VIGILADA;
                    colocarCasillasVigiladasPorSensor(fila, columna, imagen, alcanceSensor);
                } else if (imagen[fila][columna] == ENTRADA) {
                    this->filaEntrada = fila;
                    this->columnaEntrada =  columna;
                } else if (imagen[fila][columna] == SALIDA) {
                    this->filaSalida = fila;
                    this->columnaSalida = columna;
                }
            }
        }
    }
    
    void colocarCasillasVigiladasPorSensor(int fila, int columna, std::vector<std::vector<char>> & imagen, int alcanceSensor) {
        int limiteInferiorFila = fila - alcanceSensor, limiteSuperiorFila = fila + alcanceSensor;
        int limiteInferiorColumna = columna - alcanceSensor, limiteSuperiorColumna = columna + alcanceSensor;
        
        for (auto const& direccion : direcciones) {
            int f = fila + direccion.first;
            int c = columna + direccion.second;
            
            while (esValida(f, c, imagen)  && noEsPared(imagen[f][c]) && c >= limiteInferiorColumna && c <= limiteSuperiorColumna && f >= limiteInferiorFila && f <= limiteSuperiorFila) {
                if (imagen[f][c] == ENTRADA) {
                    entradaVigilada = true;
                } else if (imagen[f][c] == SALIDA) {
                    salidaVigilada = true;
                } else if (!esUnSensor(imagen[f][c])) {
                    imagen[f][c] = CASILLA_VIGILADA;
                }
                c += direccion.second;
                f += direccion.first;
            }
            
        }
    }
    
    void recorridoEnAnchura(std::vector<std::vector<char>> const& imagen, int filaOrigen, int columnaOrigen) {
        
        std::queue<Pixel> cola;
        
        marked[filaOrigen][columnaOrigen] = true;
        cola.push({filaOrigen, columnaOrigen});
        
        while(!cola.empty() && !hasPathToExit()){
          auto casillaActual = cola.front();
            cola.pop();
            
            for(auto direccion : direcciones){
                int fila_ady = direccion.first + casillaActual.fila;
                int columna_ady = direccion.second + casillaActual.columna;
                
                if(esValida(fila_ady, columna_ady, imagen) && !marked[fila_ady][columna_ady] && noEstaVigiladaPorSensores(imagen[fila_ady][columna_ady]) && noEsPared(imagen[fila_ady][columna_ady])){
                    
                    marked[fila_ady][columna_ady] = true;
                    distTo[fila_ady][columna_ady] = distTo[casillaActual.fila][casillaActual.columna] + 1;
                    cola.push({fila_ady, columna_ady});
                }
            }
            
        }
        
        
    }
    
    bool esUnSensor(char const& pixel) const {
        return isdigit(pixel);
    }
    
    bool esValida(int fila, int columna, std::vector<std::vector<char>> const& imagen) const {
        return fila >= 0 && fila < imagen.size() &&
        columna >= 0 && columna < imagen[0].size();
    }
    
    bool noEsPared(char const& pixel) const {
        return pixel != PARED;
    }
    
    bool noEstaVigiladaPorSensores(char const& pixel) const {
        return pixel != CASILLA_VIGILADA;
    }
    
    
public:
    //Para depurar, con este método se comprueba si la lectura de la entrada
    //es correcta y si se han añadido las paredes correctamente
    template<class T>
    static void mostrar(std::vector<std::vector<T>> const& imagen) {
        for (auto const& fila : imagen) {
            for (auto pixel : fila) {
                std::cout << pixel << " ";
            }
            std::cout << "\n";
        }
    }
};



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int anchoJardin, altoJardin;
    int columna = 0;
    std::string valoresFila;
    
    std::cin >> anchoJardin >> altoJardin;
    
    //Leer mapa
    std::vector<std::vector<char>> imagen(altoJardin, std::vector<char>(anchoJardin));
    std::cin.ignore();
    for (int fila = 0; fila < altoJardin; ++fila) {
        getline(std::cin, valoresFila);
        
        for(char c : valoresFila) {
            imagen[fila][columna++] = c;
        }
        columna = 0;
    }
    
    
    //RondaNocturna::mostrar(imagen);
    
    RondaNocturna rondaNocturna(imagen);
    
    if (rondaNocturna.hasPathToExit()) {
        std::cout << rondaNocturna.distanceToExit() << "\n";
    } else {
        std::cout << "NO\n";
    }
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/TAIS EXAMEN/txt/tais3b.txt");
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
