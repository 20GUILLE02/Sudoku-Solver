# Sudoku-Solver en C
Este proyecto es un resolvedor de Sudoku implementado en lenguaje C, capaz de completar automáticamente un tablero de 9×9 a partir de un estado inicial parcialmente lleno.

El programa utiliza estructuras dinámicas y una estrategia eficiente basada en el cálculo de valores posibles para cada celda vacía, reduciendo el espacio de búsqueda y resolviendo el tablero de forma sistemática.

Características

Resolución automática de tableros de Sudoku 9×9.

Validación de reglas del Sudoku:

Sin repetidos en filas.

Sin repetidos en columnas.

Sin repetidos en subgrillas de 3×3.

Uso de estructuras dinámicas (listas doblemente enlazadas).

Cálculo previo de números válidos para cada celda vacía.

Implementación eficiente en C con control manual de memoria.

Visualización del tablero en consola.

Estrategia de resolución

El algoritmo sigue los siguientes pasos:

Identificación de celdas vacías
Se recorren todas las posiciones del tablero para detectar aquellas que contienen un 0 (celda vacía).

Cálculo de valores válidos
Para cada celda vacía, se determinan los números posibles que cumplen las reglas del Sudoku.

Estructura de datos auxiliar
Se utiliza una lista doblemente enlazada que almacena:

Posición de la celda vacía.

Cantidad de valores posibles.

Lista de valores válidos.

Resolución iterativa (backtracking optimizado)
El algoritmo prueba los valores posibles en cada celda y retrocede cuando encuentra una combinación inválida, hasta encontrar una solución completa.

Compilación

Usando gcc:

gcc sudoku.c -o sudoku
Ejecución
./sudoku

El programa mostrará el tablero en consola antes y/o después de resolverlo.

Estructura del código

Principales componentes:

imprimir_tablero
Muestra el tablero en formato visual.

validarPos
Verifica si un número es válido en una posición determinada.

cant_vacios
Cuenta la cantidad de celdas vacías.

Lista doblemente enlazada (listVacios)
Almacena información sobre las celdas vacías y sus valores posibles.

Conceptos utilizados

Lenguaje C

Manejo de memoria dinámica (malloc)

Estructuras (struct)

Listas doblemente enlazadas

Algoritmo de backtracking

Resolución de problemas con restricciones

Objetivo del proyecto

Este proyecto fue desarrollado con fines educativos para practicar:

Estructuras de datos dinámicas

Algoritmos de búsqueda

Optimización de resolución de problemas combinatorios

Programación en bajo nivel con C
