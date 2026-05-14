<!--
Informe: https://docs.google.com/document/d/1mYe2-0JJSJ0eMT33SBN20u6liXLCd2189NNc4a60BQc/edit?usp=sharing 
Bitácora: https://docs.google.com/document/d/1r21B8GVLwrdU9LiXVuJgD0mrLyDipj8_0oZAxo1N3Ds/edit?usp=sharing
-->

# Informe: Proyecto final de Árboles y Grafos 2026-1

1<sup>er</sup> Juan Felipe Borbón Melo 

*Dept. De Ingeniería Biomédica & Sistemas y Computación*

*Pontificia Universidad Javeriana de Cali*

Cali, Colombia [jfborbon05@javerianacali.edu.co](mailto:jfborbon05@javerianacali.edu.co)




2<sup>do</sup> Juan Andrés Correa Arenas

*Dept. De Ingeniería de Sistemas y Computación*

*Pontificia Universidad Javeriana de Cali*

Cali, Colombia

[jacorrea22@javerianacali.edu.co](mailto:jacorrea22@javerianacali.edu.co)

**<span style="text-decoration:underline;">Contenido: \
</span>**



1. Descripción general del problema.
2. Especificación del problema.
3. Definición de 3 casos de prueba inventados y el resultado esperado para cada caso.
4. Explicación general de algunas ideas sobre la solución al problema.
5. Registros de bitácora

**1. Descripción general del problema**

El problema Cartman and the Golden Cube se desarrolla en una grilla rectangular en la que se encuentran exactamente seis piezas de oro, una posición inicial para Cartman y varias casillas vacías. Cartman dispone de un cubo mágico que puede desplazarse una casilla a la vez en las cuatro direcciones posibles: norte, sur, este y oeste. Cada vez que el cubo se mueve, cambia su orientación y, al quedar apoyado sobre una nueva casilla, interactúa con ella de una manera particular: si la casilla contiene una pieza de oro, esta pasa a la cara inferior del cubo; pero si dicha cara ya tenía oro, entonces el oro que estaba en el cubo se deja sobre la casilla.

Gracias a esta mecánica, el cubo puede almacenar piezas de oro temporalmente mientras Cartman recorre la grilla. Sin embargo, el objetivo no es solo recoger oro, sino hacerlo con el menor costo total posible. Cada movimiento tiene un costo asociado: si después del movimiento el cubo no recoge una nueva pieza de oro, el costo es A; en cambio, si el movimiento permite recoger una pieza de oro nueva, el costo es B.

El objetivo consiste en determinar si Cartman puede recolectar simultáneamente las seis piezas de oro y, en caso afirmativo, calcular el costo mínimo necesario para lograrlo. Si no es posible reunir todo el oro, debe indicarse que la tarea no puede completarse.

**2. Especificación del problema**

**Entrada:**



* Cuatro números R, C, A, B ∈ N, donde:
    * R y C representan el número de filas y columnas de la grilla, respectivamente, con 1≤R, C ≤ 8.
    * A representa el costo de un movimiento que no permite obtener una nueva pieza de oro, con 1 ≤ A ≤1000.
    * B representa el costo de un movimiento en el que sí se obtiene una nueva pieza de oro, con 1 ≤ B ≤ 1000.
* Luego siguen R líneas, cada una con C caracteres, que describen la grilla del problema.
    * . indica una casilla vacía.
    * G indica una casilla que contiene una pieza de oro.
    * S indica la posición inicial del cubo.

Se garantiza que la grilla contiene exactamente una celda marcada con S y exactamente seis celdas marcadas con G.

**Salida:**

A partir de los datos de entrada del problema, se debe determinar el resultado correspondiente para la única instancia dada. En particular:



* Si es posible recolectar todas las piezas de oro, la salida debe representar el costo mínimo total requerido para lograrlo, con base en los valores (R, C, A, B) y en la configuración de la grilla.
* Si no es posible recolectar todas las piezas de oro, la salida debe indicar que la recolección completa no puede realizarse.

**3. Definición de 3 casos de prueba inventados y el resultado esperado para cada caso**

**4. Explicación general de algunas ideas sobre la solución al problema**

**5. Registros de bitácora**

**29/04/2026**



* Lectura inicial del enunciado de la tarea, específicamente las instrucciones, entregables y requisitos.
* Creación de bitácora, repositorio de GitHub para trabajar el proyecto simultáneamente, archivos cube.py y cube.cpp para proponer la solución en Python o C++.
* Repositorio: [https://github.com/jfborbon/proyecto-agra-20262](https://github.com/jfborbon/proyecto-agra-20262) 

**2/05/2026 - 3/05/2026**



* Análisis e interpretación individual del enunciado del problema.
    * Nos dimos cuenta (por aparte, pero coincidimos) que tenía cierta similitud o semejanzas con un problema que habíamos trabajado en la arena el semestre pasado en *Estructuras de Datos*, llamado “die”, sobre un juego con un dado, y posteriormente Juan Andrés pensó en el problema *The New Villa* que trabajamos en clase.
    * Vimos la oportunidad de poder trabajar sobre algo parecido para el movimiento del cubo.

**4/05/2026**



* Juan Andrés: Intento la primera resolución del problema con planteamientos iniciales como la incorporación de una clase que modele el dado e intercambie los valores de sus caras para simular las rotaciones o también el uso de máscaras binarias para interpretar qué partes del mapa tienen o no tienen una pieza de oro. También se usó un Dijkstra para la resolución inicial del problema. En esta primera implementación se representa el tablero/mapa como un bitmask con base a la implementación del problema “[The New Villa](https://onlinejudge.org/external/3/321.pdf) ” vista en clase. Cabe aclarar que para este momento no se han realizado pruebas exhaustivas de la solución planteada.

**5/05/2026**



* Primera redacción de la especificación del problema, entrada y salida
    * Surge la duda de si en la entrada y la salida se ponen los datos que el enunciado en sí dice que recibe o los que nuestra implementación recibe (?).
        * Le preguntamos al profesor.
    * Faltaría completar más la entrada y casi que toda la salida.
    * Como se ve hasta ahora: \
*Descripción general del problema*

        *El problema Cartman and the Golden Cube es situado dentro de una grilla cuadriculada en la cual hay 6 piezas de oro y el sujeto Cartman el cual tiene una herramienta reconocida como un cubo magico. Este cubo tiene la particularidad de que cuando su cara inferior entre en contacto con una pieza de oro esta es recojida por el cubo, pero si al momento en que Cartman se mueva la cara del cubo que pasa a rotar y posicionarse en la parte inferior tiene una piesa de oro que se haya adherido anteriormente, entonces esta se caera del cubo. Adicionalmente para Cartman el hecho de moverse hasta cierta posicíon tiene un costo de A, pero en el caso de que este consiga obtener un trozo de oro mas el costo de este movimiento para Cartman sera de B. Por esto mismo, lo que quiere nuestro sujeto Carman es precisamente coseguir todos los trozso de oro con el menor costo posible.*


    *Especificación del problema:*


    *Entrada:*

* *Dos números R,C∈N que representan el número de filas y de columnas respectivamente tales que 1≤R,C≤8.*
* *Dos números A,B∈N tales que 1≤A,B≤100. Siendo A el costo de un movimiento que no te permite obtener oro y B el costo de un movimiento que si te lo permite.*
* 

    *Salida:*

* *…*

**6/05/2026**



* El profe nos responde que es lo mismo lo de la entrada que dice el problema y el de nuestra solución.
* A tener en cuenta desde ahora: es necesario que nos devolvamos o demos un paso atrás para no apresurarnos a proponer soluciones sin primero haber definido la especificación del problema; tanto entrada como salida.

**9/05/2026**



* Corrección de lo que teníamos de especificación del problema y primer borrador de especificación, entrada y salida completo.

**11/05/2026**



* Aquí en respuesta a una evaluación preliminar con el profesor, nos dimos cuenta de aspectos a tener en cuenta a la hora de construir la especificación:
    * Hay que olvidarnos de los casos de prueba.
        * Hacer la especificación para el problema general como si se fuera a resolver una sola vez.
    * Las condiciones que están ahí, garantizan que el problema tenga sentido.
        * Si se quitaran, se incumpliría esto.
    * “La salida es independiente de la forma en la que se deban presentar los resultados”
    * “En la salida deberían mencionarse todos los datos en la especificación de la entrada”

**13/05/2026**



* Corrección de la especificación, entrada y salida del problema.
    * Consulta con el profe para validar si lo que se tuvo en cuenta en la corrección es válido (a la espera de la respuesta).
* Propuesta de implementación por parte de Juan Felipe en Python:
    * La solución está pensada…
    * A partir de esta propuesta, vamos a revisar qué aspectos conservamos de las que hemos propuesto, puede que surja una nueva o sigamos a partir de una, pero eso lo veremos mañana.
