# <center> **Arboles y Grafos 2026-1 Proyecto Final** </center>

#### **Integrantes:** Juan Felipe Borbon Melo y Juan Andrés Correa Arenas
---
## Desripción general del problema

- El problema `Cartman and the Golden Cube` se desarrolla en una grilla rectangular en la que se encuentran exactamente seis piezas de oro, una posición inicial para **Cartman** y varias casillas vacías. **Catrman** dispone de un **cubo mágico** que puede desplazarse una casilla a la vez en las cuatro direcciones posibles: norte, sur, este y oeste. Cada vez que el cubo se mueve, cambia su orientación y, al quedar apoyado sobre una nueva casilla, interactúa con ella de una manera particular: si la casilla contiene una pieza de oro, esta pasa a la cara inferior del cubo; pero si dicha cara ya tenía oro, entonces el oro que estaba en el cubo se deja sobre la casilla. Debido a esta mecánica, el cubo puede almacenar piezas de oro temporalmente mientras **Cartman** recorre la grilla. Sin embargo, el objetivo no es solo recoger oro, sino hacerlo con el menor costo total posible. Cada movimiento tiene un costo asociado: si después del movimiento el cubo no recoge una nueva pieza de oro, el costo es `A`; en cambio, si el movimiento permite recoger una pieza de oro nueva, el costo es `B`. El objetivo consiste en determinar, para cada caso de prueba, si **Cartman** puede recolectar simultáneamente las seis piezas de oro y, en caso afirmativo, calcular el costo mínimo necesario para lograrlo. Si no es posible reunir todo el oro, debe indicarse que la tarea no puede completarse.
---
## Especificación del problema:

## Entrada

* Para cada caso de prueba $T_i$:

  * Cuatro números $R, C, A, B \in \mathbb{N}$, donde:

    * $R$ y $C$ representan el número de filas y columnas de la grilla, respectivamente, con $1 \leq R, C \leq 8$.
    * $A$ representa el costo de un movimiento que no permite obtener una nueva pieza de oro, con $1 \leq A \leq 1000$.
    * $B$ representa el costo de un movimiento en el que sí se obtiene una nueva pieza de oro, con $1 \leq B \leq 1000$.
  * Luego siguen $R$ líneas, cada una con $C$ caracteres, que describen la grilla del caso de prueba.

    * `.` indica una casilla vacía.
    * `G` indica una casilla que contiene una pieza de oro.
    * `S` indica la posición inicial del cubo.

Se garantiza que en cada caso de prueba existe exactamente una celda marcada con `S` y exactamente seis celdas marcadas con `G`.

## Salida

Para cada caso de prueba $T_i$, se debe imprimir exactamente una línea con el resultado correspondiente:

* Si Cartman puede recolectar todas las piezas de oro, se debe imprimir:

$$
\texttt{Screw you guys, I got all the gold for X cost!}
$$

donde $X \in \mathbb{N}$ es el costo mínimo total requerido para recolectarlas todas.

* Si no es posible recolectar todas las piezas de oro, se debe imprimir:

$$
\texttt{Oh my God, they killed Kenny!}
$$
