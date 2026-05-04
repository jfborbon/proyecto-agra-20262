/*
Integrantes: 
- Juan Felipe Borbon Melo
- Juan Andrés Correa Arenas

Referencias:
- Jakogut, “Hashing function for four unsigned integers (C++),” Stack Overflow, Nov. 30, 2009. 
https://stackoverflow.com/questions/1818134/hashing-function-for-four-unsigned-integers-c

- GeeksforGeeks, “Bitmask in C++,” GeeksforGeeks, Dec. 11, 2023. https://www.geeksforgeeks.org/cpp/bitmasking-in-cpp/
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
        int contGold;
    
        MagicCube() {
            front = false;
            back = false;
            left = false;
            right = false;
            up = false;
            down = false;
            contGold = 0;
        }

        void getGold() {
            if (!down) {
                down = true;
                contGold++;
            }
        }

        void dropGold() {
            if (down) {
                down = false;
                contGold--;
            }
        }

        void rotateLeft() {
            bool aux = front;
            front = left;
            left = back;
            back = right;
            right = aux;
        }

        void rotateRight() {
            bool aux = front;
            front = right;
            right = back;
            back = left;
            left = aux;
        }

        void rotateUp() {
            bool aux = front;
            front = up;
            up = back;
            back = down;
            down = aux;
        }

        void rotateDown() {
            bool aux = front;
            front = down;
            down = back;
            back = up;
            up = aux;
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

            if (actualState.magicCube.contGold == 6) {
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