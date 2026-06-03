# <center> **Arboles y Grafos 2026-1 Proyecto Final** </center>

#### **Integrantes:** Juan Felipe Borbon Melo y Juan Andrés Correa Arenas
---

## **1. Descripción general del problema**

El problema Cartman and the Golden Cube se desarrolla en una grilla rectangular en la que se encuentran exactamente seis piezas de oro, una posición inicial para Cartman y varias casillas vacías. Cartman dispone de un cubo mágico que puede desplazarse una casilla a la vez en las cuatro direcciones posibles: norte, sur, este y oeste. Cada vez que el cubo se mueve, cambia su orientación y, al quedar apoyado sobre una nueva casilla, interactúa con ella de una manera particular: si la casilla contiene una pieza de oro, esta pasa a la cara inferior del cubo; pero si dicha cara ya tenía oro, entonces el oro que estaba en el cubo se deja sobre la casilla.

Gracias a esta mecánica, el cubo puede almacenar piezas de oro temporalmente mientras Cartman recorre la grilla. Sin embargo, el objetivo no es solo recoger oro, sino hacerlo con el menor costo total posible. Cada movimiento tiene un costo asociado: si después del movimiento el cubo no recoge una nueva pieza de oro, el costo es A; en cambio, si el movimiento permite recoger una pieza de oro nueva, el costo es B.

El objetivo consiste en determinar si Cartman puede recolectar simultáneamente las seis piezas de oro y, en caso afirmativo, calcular el costo mínimo necesario para lograrlo. Si no es posible reunir todo el oro, debe indicarse que la tarea no puede completarse.

## **2. Especificación del problema**

**Entrada:**



* Cuatro números R, C, A, B ∈ N, donde:
    * R y C representan, respectivamente, el número de filas y columnas de una grilla rectangular.
    * A representa el costo de un movimiento que no permite obtener una nueva pieza de oro.
    * B representa el costo de un movimiento en el que sí se obtiene una nueva pieza de oro.
* Una grilla rectangular de R filas y C columnas en la que cada celda contiene uno de los siguientes símbolos:
    * . para indicar una casilla vacía.
    * G para indicar una casilla que contiene una pieza de oro.
    * S para indicar la posición inicial del cubo.

Se garantiza que la grilla contiene exactamente una celda marcada con S y exactamente seis celdas marcadas con G.

**Salida:**

La solución del problema debe determinar el menor costo total necesario para que Cartman recolecte simultáneamente las seis piezas de oro mediante los movimientos permitidos del cubo.



* Si es posible recolectar todas las piezas de oro, el resultado debe ser el costo mínimo total de esa recolección.
* Si no es posible recolectarlas todas, el resultado debe indicar que la recolección completa no puede realizarse.