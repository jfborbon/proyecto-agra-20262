# <center> Analisis de casos de prueba proyecto AGRA-2026-1 </center>

- Siendo el cubo una tupla de 6 caras que pueden tener o no tener oro, entonces se puede representar el estado de un cubo como la tupla (frente, atrás, izquierda, derecha, arriba, abajo), tal que los valores de cada uno sean o $0$ o $1$.

### Caso de prueba 1:

#### Entrada:  
    7 3 1 2
    ...
    ..G
    ..G
    .GG
    .G.
    .G.
    .S.

#### Respuesta: 12

* **Proceso:**

    0) El estado inicial es:
        * **Cubo:** (0, 0, 0, 0, 0, 0)
        * **Costo actual:** 0
        * **Posición:** (6, 1)

    1) :
        * **Movimiento:** Arriba
        * **Costo del movimiento:** +2
        * **Costo actual:** 2
        * **Cubo:** (0, 0, 0, 0, 0, 1)
        * **Posición:** (5, 1)
    
    2) :
        * **Movimiento:** Arriba
        * **Costo del movimiento:** +2
        * **Costo actual:** 4
        * **Cubo:** (1, 0, 0, 0, 0, 1)
        * **Posición:** (4, 1)

    3) :
        * **Movimiento:** Arriba
        * Costo del  movimiento: +2
        * **Costo actual:** 6
        * **Cubo:** (1, 0, 0, 0, 1, 1)
        * **Posición:** (3, 1)

    4) :
        * **Movimiento:** Derecha
        * **Costo del movimiento:** +2
        * **Costo actual:** 8
        * **Cubo:** (1, 0, 1, 1, 0, 1)
        * **Posición:** (3, 2)

    5) :
        * **Movimiento:** Arriba
        * **Costo del movimiento:** +2
        * **Costo actual:** 10
        * **Cubo:** (1, 0, 1, 1, 1, 1)
        * **Posición:** (2, 2)

    6) :
        * **Movimiento:** Arriba
        * **Costo del movimiento:** +2
        * **Costo actual:** 12
        * **Cubo:** (1, 1, 1, 1, 1, 1)
        * **Posición:** (1, 2)
    
### Caso de prueba 2:

#### Entrada:
    2 7 1 1
    S.G.G.G
    G.G.G..

#### Respuesta: 10

* **Proceso:**

    0) El estado inicial es:
        * **Cubo:** (0, 0, 0, 0, 0, 0)
        * **Costo actual:** 0
        * **Posición:** (0, 0)

    1) :
        * **Movimiento:** Abajo
        * **Costo del movimiento:** +1
        * **Costo actual:** 1
        * **Cubo:** (0, 0, 0, 0, 0, 1)
        * **Posición:** (1, 0)

    2) :
        * **Movimiento:** Derecha
        * **Costo del movimiento:** +1
        * **Costo actual:** 2
        * **Cubo:** (0, 0, 1, 0, 0, 1)
        * **Posición:** (1, 1)

    3) :
        * **Movimiento:** Arriba
        * **Costo del movimiento:** +1
        * **Costo actual:** 3
        * **Cubo:** (0, 1, 1, 0, 0, 1)
        * **Posición:** (0, 1)

    4) :
        * **Movimiento:** Derecha
        * **Costo del movimiento:** +1
        * **Costo actual:** 4
        * **Cubo:** (0, 1, 1, 0, 1, 1)
        * **Posición:** (0, 2)

    5) :
        * **Movimiento:** Abajo
        * **Costo del movimiento:** +1
        * **Costo actual:** 5
        * **Cubo:** (1, 1, 1, 0, 0, 1)
        * **Posición:** (1, 2)

    6) :
        * **Movimiento:** Derecha
        * **Costo del movimiento:** +1
        * **Costo actual:** 6
        * **Cubo:** (1, 1, 1, 1, 0, 1)
        * **Posición:** (1, 3)

    7) :
        * **Movimiento:** Arriba
        * **Costo del movimiento:** +1
        * **Costo actual:** 7
        * **Cubo:** (1, 1, 1, 1, 0, 1)
        * **Posición:** (0, 3)

    8) :
        * **Movimiento:** Derecha
        * **Costo del movimiento:** +1
        * **Costo actual:** 8
        * **Cubo:** (1, 1, 1, 1, 1, 1)
        * **Posición:** (0, 4)

    9) :
        * **Movimiento:** Abajo
        * **Costo del movimiento:** +1
        * **Costo actual:** 9
        * **Cubo:** (1, 1, 1, 1, 1, 1)
        * **Posición:** (1, 4)

    10) :
        * **Movimiento:** Derecha
        * **Costo del movimiento:** +1
        * **Costo actual:** 10
        * **Cubo:** (1, 1, 1, 1, 1, 1)
        * **Posición:** (1, 5)

### Caso de prueba 3:

#### Entrada:
    1 7 1 2
    GGGGGGS

#### Respuesta:
    No existe una solución

* **Explicación:**

Al haber solo una dimensión en este caso el cubo magico de **Cartman** se le imposibilita moerse tanto hacia arriba como hacia abajo, por lo que la cara frontal y tacera del cubo no son accecibles y por ende **Cartman** no puede conseguir que estas toquen el suelo para tomar una pieza de oro con estas y no es capaz de conseguir todas las 6 piezas.

### Caso de prueba 4:

#### Entrada:
    4 4 2 1
    SG..
    .GG.
    .G..
    .GG.

#### Respuesta: 14

* **Proceso:**

    0) El estado inicial es:
        * **Cubo:** (0, 0, 0, 0, 0, 0)
        * **Costo actual:** 0
        * **Posición:** (0, 0)

    1) :
        * **Movimiento:** Derecha
        * **Costo del movimiento:** +1
        * **Costo actual:** 1
        * **Cubo:** (0, 0, 0, 0, 0, 1)
        * **Posición:** (0, 1)

    2) :
        * **Movimiento:** Abajo
        * **Costo del movimiento:** +1
        * **Costo actual:** 2
        * **Cubo:** (1, 0, 0, 0, 0, 1)
        * **Posición:** (1, 1)

    3) :
        * **Movimiento:** Abajo
        * **Costo del movimiento:** +1
        * **Costo actual:** 3
        * **Cubo:** (1, 0, 0, 0, 1, 1)
        * **Posición:** (2, 1)

    4) :
        * **Movimiento:** Abajo
        * **Costo del movimiento:** +1
        * **Costo actual:** 4
        * **Cubo:** (1, 1, 0, 0, 1, 1)
        * **Posición:** (3, 1)

    5) :
        * **Movimiento:** Arriba
        * **Costo del movimiento:** +2
        * **Costo actual:** 6
        * **Cubo:** (1, 1, 0, 0, 1, 0)
        * **Posición:** (2, 1)

    6) :
        * **Movimiento:** Derecha
        * **Costo del movimiento:** +2
        * **Costo actual:** 8
        * **Cubo:** (0, 0, 1, 1, 1, 0)
        * **Posición:** (2, 2)

    7) :
        * **Movimiento:** Izquierda
        * **Costo del movimiento:** +1
        * **Costo actual:** 9
        * **Cubo:** (1, 1, 0, 0, 1, 1)
        * **Posición:** (2, 1)

    8) :
        * **Movimiento:** Derecha
        * **Costo del movimiento:** +2
        * **Costo actual:** 11
        * **Cubo:** (0, 0, 1, 1, 1, 0)
        * **Posición:** (2, 2)

    9) :
        * **Movimiento:** Abajo
        * **Costo del movimiento:** +1
        * **Costo actual:** 12
        * **Cubo:** (0, 1, 1, 1, 0, 1)
        * **Posición:** (3, 2)

    10) :
        * **Movimiento:** Arriba
        * **Costo del movimiento:** +1
        * **Costo actual:** 13
        * **Cubo:** (0, 1, 1, 1, 1, 1)
        * **Posición:** (2, 2)

    11) :
        * **Movimiento:** Arriba
        * **Costo del movimiento:** +1
        * **Costo actual:** 14
        * **Cubo:** (1, 1, 1, 1, 1, 1)
        * **Posición:** (1, 2)