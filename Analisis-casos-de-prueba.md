# <center> Analisis de casos de prueba proyecto AGRA-2026-1 </center>

* Siendo el cubo una tupla de 6 caras que pueden tener o no tener oro, entonces se puede representar el estado de un cubo como la tupla (frente, atrás, izquierda, derecha, arriba, abajo), tal que los valores de cada uno sean 0 ó 1.

**Input**

```
3
7 3 1 2
...
..G
..G
.GG
.G.
.G.
.S.
2 7 1 1
S.G.G.G
G.G.G..
4 4 2 1
SG..
.GG.
.G..
.GG.

```

**Output**

```
Screw you guys, I got all the gold for 12 cost!
Screw you guys, I got all the gold for 13 cost!
Screw you guys, I got all the gold for 9 cost!

```

Caso de prueba 1:

* **Proceso:**
    1. El estado inicial es:
        * **Cubo:** (0, 0, 0, 0, 0, 0)
        * **Costo actual:** 0
        * **Posición:** (7, 2)
    2. 
        * Movimiento: Arriba
        * Costo del movimiento: +2
        * **Costo actual:** 2
        * **Cubo:** (0, 0, 0, 0, 0, 1)
        * **Posición:** (6, 2)
    3. 
        * Movimiento: Arriba
        * Costo del movimiento: +2
        * **Costo actual:** 4
        * **Cubo:** (0, 1, 0, 0, 0, 1)
        * **Posición:** (5, 2)
    4. 
        * Movimiento: Arriba
        * Costo del movimiento: +2
        * **Costo actual:** 6
        * **Cubo:** (0, 1, 0, 0, 1, 1)
        * **Posición:** (4, 2)
    5. 
        * Movimiento: Derecha
        * Costo del movimiento: +2
        * **Costo actual:** 8
        * **Cubo:** (0, 1, 1, 1, 0, 1)
        * **Posición:** (4, 3)
    6. 
        * Movimiento: Arriba
        * Costo del movimiento: +2
        * **Costo actual:** 10
        * **Cubo:** (0, 1, 1, 1, 1, 1)
        * **Posición:** (3, 3)
    7. 
        * Movimiento: Arriba
        * Costo del movimiento: +2
        * **Costo actual:** 12
        * **Cubo:** (1, 1, 1, 1, 1, 1)
        * **Posición:** (2, 3)
* Resultado: 12

Caso de prueba 2:



* **Proceso:**
    1. El estado inicial es:
        * **Cubo:** (0, 0, 0, 0, 0, 0)
        * **Costo actual:** 0
        * **Posición:** (0, 0)
    2. 
        * Movimiento: Abajo
        * Costo del movimiento: +1
        * **Costo actual:** 1
        * **Cubo:** (0, 0, 0, 0, 0, 1)
        * **Posición:** (1, 0)
    3. 
        * Movimiento: Derecha
        * Costo del movimiento: +1
        * **Costo actual:** 2
        * **Cubo:** (0, 0, 1, 0, 0, 0)
        * **Posición:** (1, 1)
    4. 
        * Movimiento: Derecha
        * Costo del movimiento: +1
        * **Costo actual:** 3
        * **Cubo:** (0, 0, 0, 0, 1, 1)
        * **Posición:** (1, 2)
    5. 
        * Movimiento: Arriba
        * Costo del movimiento: +1
        * **Costo actual:** 4
        * **Cubo:** (1, 1, 0, 0, 0, 1)
        * **Posición:** (0, 2)
    6. 
        * Movimiento: Derecha
        * Costo del movimiento: +1
        * **Costo actual:** 5
        * **Cubo:** (1, 1, 1, 0, 0, 0)
        * **Posición:** (0, 3)
    7. 
        * Movimiento: Abajo
        * Costo del movimiento: +1
        * **Costo actual:** 6
        * **Cubo:** (0, 0, 1, 0, 1, 0)
        * **Posición:** (1, 3)
    8. 
        * Movimiento: Arriba
        * Costo del movimiento: +1
        * **Costo actual:** 7
        * **Cubo:** (1, 0, 1, 0, 0, 0)
        * **Posición:** (0, 3)
    9. 
        * Movimiento: Abajo
        * Costo del movimiento: +1
        * **Costo actual:** 8
        * **Cubo:** (0, 0, 1, 0, 1, 1)
        * **Posición:** (1, 3)
    10. 
        * Movimiento: Derecha
        * Costo del movimiento: +1
        * **Costo actual:** 9
        * **Cubo:** (0, 0, 1, 1, 1, 1)
        * **Posición:** (1, 4)
    11. 
        * Movimiento: Arriba
        * Costo del movimiento: +1
        * **Costo actual:** 10
        * **Cubo:** (1, 1, 1, 1, 0, 1)
        * **Posición:** (0, 4)
    12. 
        * Movimiento: Derecha
        * Costo del movimiento: +1
        * **Costo actual:** 11
        * **Cubo:** (1, 1, 1, 0, 1, 0)
        * **Posición:** (0, 5)
    13. 
        * Movimiento: Derecha
        * Costo del movimiento: +1
        * **Costo actual:** 12
        * **Cubo:** (1, 1, 0, 1, 1, 1)
        * **Posición:** (0, 6)
    14. 
        * Movimiento: Izquierda
        * Costo del movimiento: +1
        * **Costo actual:** 13
        * **Cubo:** (1, 1, 1, 1, 1, 1)
        * **Posición:** (0, 5)
* Resultado: 13

Caso de prueba 3:



* **Proceso:**
    1. El estado inicial es:
        * **Cubo:** (0, 0, 0, 0, 0, 0)
        * **Costo actual:** 0
        * **Posición:** (0, 0)
    2. 
        * Movimiento: Derecha
        * Costo del movimiento: +1
        * **Costo actual:** 1
        * **Cubo:** (0, 0, 0, 0, 0, 1)
        * **Posición:** (0, 1)
    3. 
        * Movimiento: Abajo
        * Costo del movimiento: +1
        * **Costo actual:** 2
        * **Cubo:** (1, 0, 0, 0, 0, 1)
        * **Posición:** (1, 1)
    4. 
        * Movimiento: Abajo
        * Costo del movimiento: +1
        * **Costo actual:** 3
        * **Cubo:** (1, 0, 0, 0, 1, 1)
        * **Posición:** (2, 1)
    5. 
        * Movimiento: Abajo
        * Costo del movimiento: +1
        * **Costo actual:** 4
        * **Cubo:** (1, 1, 0, 0, 1, 1)
        * **Posición:** (3, 1)
    6. 
        * Movimiento: Derecha
        * Costo del movimiento: +1
        * **Costo actual:** 5
        * **Cubo:** (1, 1, 1, 1, 0, 1)
        * **Posición:** (3, 2)
    7. 
        * Movimiento: Arriba
        * Costo del movimiento: +2
        * **Costo actual:** 7
        * **Cubo:** (0, 1, 1, 1, 1, 0)
        * **Posición:** (2, 2)
    8. 
        * Movimiento: Arriba
        * Costo del movimiento: +1
        * **Costo actual:** 8
        * **Cubo:** (1, 0, 1, 1, 1, 1)
        * **Posición:** (1, 2)
    9. 
        * Movimiento: Abajo
        * Costo del movimiento: +1
        * **Costo actual:** 9
        * **Cubo:** (1, 1, 1, 1, 1, 1)
        * **Posición:** (2, 2)
* Resultado: 9