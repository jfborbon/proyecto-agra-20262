/*
Integrantes: 
- Juan Felipe Borbon Melo
- Juan Andrés Correa Arenas


Análisis de complejidad:

- Funciones de rotación de MagicCube: O(1)
Esto se debe a que las rotaciones del cubo solo se encargan de intercambiar los 
valores de sus caras. Puesto que la cantidad de caras es constante, por lo tanto, 
las operaciones que se realizan para hacer estos intercambios también lo son.

- posibleNewStateAux: O(1)
La complejidad de esta función es constante, ya que solo realiza operaciones que 
se ejecutan en tiempo constante, como encender, apagar o revisar un bit. La suma 
de varias operaciones constantes resulta en un orden constante.

- posibleNewState: O(1)
Las operaciones que realiza internamente esta función son condicionales de tiempo 
constante con operaciones aritméticas básicas. También usa las operaciones de 
rotación del cubo y hace un llamado a posibleNewStateAux, que, como ya se vio, 
son de tiempo constante. Esto nos da como resultado que la función es constante, 
ya que todas las operaciones que realiza también lo son.

- searchGold: O(n * log(n))
Esta función hace una implementación del algoritmo de Dijkstra orientado a un grafo 
de estados para resolver el problema, haciendo uso de las funciones ya descritas. 
Por ende, siendo n el número de estados posibles del sistema (determinado por la 
posición de Cartman, la configuración del cubo y la distribución del oro en el 
tablero), en el peor de los casos todos los n estados son procesados. En consecuencia, 
estos en algún punto tuvieron que ser introducidos dentro de la cola de prioridad, 
lo cual tiene un costo de O(log(n)). Para cada estado se realizan 4 llamados a 
posibleNewState para evaluar sus transiciones, operación que es constante. Por lo 
tanto, al final tenemos que se procesan n nodos y por cada nodo se pueden dar 4 
inserciones dentro de la cola de prioridad, dando de esta forma una complejidad 
de O(n * log(n)).


Referencias:
- Jakogut, “Hashing function for four unsigned integers (C++),” Stack Overflow, Nov. 30, 2009. 
https://stackoverflow.com/questions/1818134/hashing-function-for-four-unsigned-integers-c

- GeeksforGeeks, “Bitmask in C++,” GeeksforGeeks, Dec. 11, 2023.
https://www.geeksforgeeks.org/cpp/bitmasking-in-cpp/
*/
#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;


// Clase que representa el cubo magico con una variable boleana para cada una de sus caras
// y un contador que lleva la cantidad de oro que ha recogido
class MagicCube {
    public:
        bool front, back, left, right, up, down;
    
        MagicCube() {
            front = false;
            back = false;
            left = false;
            right = false;
            up = false;
            down = false;
        }

        void getGold() {
            if (!down) {
                down = true;
            }
        }

        void dropGold() {
            if (down) {
                down = false;
            }
        }

        void rotateLeft() {
            bool aux = down;
            down = left;
            left = up;
            up = right;
            right = aux;
        }

        void rotateRight() {
            bool aux = down;
            down = right;
            right = up;
            up = left;
            left = aux;
        }

        void rotateUp() {
            bool aux = down;
            down = front;
            front = up;
            up = back;
            back = aux;
        }

        void rotateDown() {
            bool aux = down;
            down = back;
            back = up;
            up = front;
            front = aux;
        }

        int getContGold() {
            return front + back + up + down + left + right;
        }
};

// funcion hash que le asigna un número del 0 al 63 a cada el cubo segun los valores de sus caras
struct MagicCubeHash {
    size_t operator()(const MagicCube& mc) const {
        return 1 * mc.front + 2 * mc.back + 4 * mc.left + 8 * mc.right + 16 * mc.up + 32 * mc.down;
    }
};

// structura que representa los elementos mutables del problema
// Estado: (Cubo, posición del oro, posición de cartman, costo de llegar a este estado)
struct State {
    MagicCube magicCube;
    int cartman;
    long long thersGold;
    int cost;

    // se necesita un operator para que el unordered_set pueda comprovar si 2 estados son iguales o distintos
    bool operator==(const State& state) const {
        return cartman == state.cartman &&
            thersGold == state.thersGold &&
            magicCube.front == state.magicCube.front &&
            magicCube.back == state.magicCube.back &&
            magicCube.left == state.magicCube.left &&
            magicCube.right == state.magicCube.right &&
            magicCube.up == state.magicCube.up &&
            magicCube.down == state.magicCube.down;
    }
};

// hash de tipo polinomial que usa números primos (31 en este caso aunque podria ser cualquiera)
// para combinar los 3 enteros que representan un estado
struct stateHash {
    size_t operator()(const State& s) const {
        MagicCubeHash cubeHasher;
        size_t h = cubeHasher(s.magicCube);
        h = h * 31 + (size_t)(s.cartman);
        h = h * 31 + (size_t)(s.thersGold);
        return h;
    }
};


// structura para comparar 2 estados distintos por medio de su costo
struct greaterState {
    bool operator()(const State& s1, const State& s2) {
        return s1.cost > s2.cost;
    }
};


void posibleNewStateAux(int A, int B, State& state) {
    if (state.thersGold & (1LL << state.cartman)) { // hay oro en la posición de cartman
        if (state.magicCube.down) { // la cara inferior del cubo tiene oro
            state.cost += A;
        }
        else { // la cara inferior del cubo no tiene oro
            state.cost += B;
            state.magicCube.getGold();
            // como se gana oro se recoje el oro de la posición de cartman apagando el bit en esa posición
            state.thersGold &= ~(1LL << state.cartman); // apagar bit
        }
    }
    else { // no hay oro en la posición de cartman
        state.cost += A;
        if (state.magicCube.down) { // la cara inferior del cubo tiene oro
            state.magicCube.dropGold();
            // como pierde oro se tira oro en la posición de cartman prendiendo el bit de esa posición
            state.thersGold |= (1LL << state.cartman); // prender bit
        }
    }
}

State posibleNewState (int orientation, int rows, int colums, int A, int B, State state) {
    // 0: arriba
    // 1: abajo
    // 2: izquierda
    // 3: derecha

    if (orientation == 0 && (state.cartman - colums >= 0)) {
        state.magicCube.rotateUp();
        state.cartman -= colums;
    }
    else if (orientation == 1 && (state.cartman + colums < rows * colums)) {
        state.magicCube.rotateDown();
        state.cartman += colums;
    }
    else if (orientation == 2 && (state.cartman % colums != 0)) {
        state.magicCube.rotateLeft();
        state.cartman--;
    }
    else if (orientation == 3 && ((state.cartman + 1) % colums != 0)) {
        state.magicCube.rotateRight();
        state.cartman++;
    }

    else state.cost = -1;

    if (state.cost != -1) posibleNewStateAux(A, B, state);

    return state;
}


// se impelenta un Dijkstra para la resolución del problema
int searchGold(int rows, int colums, int A, int B, State& initialState) {
    int ans, i;
    ans = -1;
    priority_queue<State, vector<State>, greaterState> pqueue;
    unordered_set<State, stateHash> visited;
    bool found = false;
    State actualState, newState;
    pqueue.push(initialState);

    while (!pqueue.empty() && !found) {
        actualState = pqueue.top();
        pqueue.pop();

        if (!visited.count(actualState)) {
            visited.insert(actualState);

            if (actualState.magicCube.getContGold() == 6) {
                found = true;
                ans = actualState.cost;
            }
            else {
                for (i = 0; i < 4; i++) {
                    newState = posibleNewState(i, rows, colums, A, B, actualState);
                    if (newState.cost != -1 && !visited.count(newState)) {
                        pqueue.push(newState);
                    }
                }
            }
        }
    }

    return ans;
}


int main() {

    // definición de variables
    int T, R, C, A, B, i, cartman, result;
    long long gold;
    char cell;
    State initialState;

    // lectura de datos
    scanf("%d", &T);
    while (T--) {
        
        scanf("%d %d %d %d", &R, &C, &A, &B);

        gold = 0;
        cartman = 0;
        for (i = 0; i < R * C; i++) {
            scanf(" %c", &cell);
            if (cell == 'G') gold |= (1LL << i);
            else if (cell == 'S') cartman = i;
        }

        initialState = {MagicCube(), cartman, gold, 0};

        result = searchGold(R, C, A, B, initialState);

        if (result == -1) printf("Oh my God, they killed Kenny!\n");
        else printf("Screw you guys, I got all the gold for %d cost!\n", result);
    }

    return 0;
}