# ⚙️ Módulo 02 de C++ en 42: Clases, Sobrecarga de Operadores y Geometría ⚙️

Este repositorio contiene las implementaciones de los ejercicios del Módulo 02 de mi formación en la escuela 42 Málaga. Este módulo profundiza en los conceptos de la Programación Orientada a Objetos (POO) en C++, con un enfoque especial en la **Ortodoxa Forma Canónica (OCF)**, la **sobrecarga de operadores** y su aplicación a problemas prácticos de **geometría computacional** y **aritmética de punto fijo**.

Todos los proyectos cumplen con las estrictas directrices de 42, incluyendo el estándar **C++98** y banderas de compilación rigurosas.

---

## 📚 Tabla de Contenidos

1.  [Filosofía de 42 C++ y Estándares](#-filosofía-de-42-c-y-estándares)
2.  [Ejercicios Implementados](#-ejercicios-implementados)
    *   [ex00: My First Class in O.C.F. (Fixed Point Numbers)](#ex00-my-first-class-in-ocf-fixed-point-numbers)
    *   [ex01: Towards a More Useful Fixed-Point Number Class](#ex01-towards-a-more-useful-fixed-point-number-class)
    *   [ex02: A More Advanced Fixed-Point Number Class](#ex02-a-more-advanced-fixed-point-number-class)
    *   [ex03: BSP (Binary Space Partitioning)](#ex03-bsp-binary-space-partitioning)
3.  [Compilación y Ejecución](#️-compilación-y-ejecución-general)
4.  [Autor](#️-autor)

---

## 🎓 Filosofía de 42 C++ y Estándares

En 42, el desarrollo en C++ se adhiere a un conjunto de principios rigurosos para asegurar la calidad, eficiencia y comprensión profunda del lenguaje:

*   **Estándar C++98**: Todos los proyectos se compilan estrictamente bajo el estándar C++98. Esto implica evitar características modernas de C++11, C++14, etc., forzando la comprensión de los fundamentos y las herramientas disponibles en esa versión (ej. `NULL` en lugar de `nullptr` [1]).
*   **Banderas de Compilación Estrictas (`CXXFLAGS`)**:
    *   `-Wall`, `-Werror`, `-Wextra`: Obligatorias para asegurar un código impecable, donde cualquier advertencia se trata como un error.
    *   `-std=c++98`: Fuerza la compatibilidad con C++98.
    *   `-g`: Incluye información de depuración para `gdb`.
*   **Programación Orientada a Objetos (POO)**: Un pilar fundamental, con un enfoque en la **Orthodox Canonical Form (OCF)** (Constructor por defecto, Constructor de Copia, Operador de Asignación, Destructor) [1].
*   **Gestión de Memoria**: Un enfoque riguroso en la gestión manual de la memoria (`new`/`delete` para C++).
*   **Organización del Código**: Estructura clara del proyecto, con archivos de cabecera (`.hpp`) y archivos fuente (`.cpp`).
*   **Makefiles**: Obligatoriedad de `Makefiles` para automatizar la compilación, limpieza (`clean`, `fclean`) y reconstrucción (`re`).

---

## 🎯 Ejercicios Implementados

A continuación, se detallan los ejercicios del Módulo 02, cada uno ubicado en su propio subdirectorio (`ex00/`, `ex01/`, `ex02/`, `ex03/`).

### ex00: My First Class in O.C.F. (Fixed Point Numbers)

Este ejercicio introduce la base de la aritmética de punto fijo y la forma canónica ortodoxa.

*   **Objetivo**: Implementar una clase `Fixed` que represente números en formato de punto fijo en C++, siguiendo la Orthodox Canonical Form (OCF) [1]. Se enfoca en la conversión entre enteros, flotantes y esta representación interna.
*   **Conceptos Clave Aplicados**:
    *   **Clases y Objetos**: Declaración y definición de la clase `Fixed` [1].
    *   **Orthodox Canonical Form (OCF)**: Implementación del Constructor por defecto, Constructor de copia, Operador de asignación (`operator=`) y Destructor [1].
    *   **Manejo de Números de Punto Fijo**: Uso de un entero (`_value`) y una cantidad fija de bits fraccionarios (`_fractBits` o `_fractional_bits`) para representar números decimales [1].
    *   **Desplazamiento de Bits (`<<`, `>>`)**: Conversión entre enteros/flotantes y la representación interna de punto fijo [1].
    *   **Constructores de Conversión**: Desde `int` y `float` hacia `Fixed` [1].
    *   **Getters y Setters**: `getRawBits()` y `setRawBits()` para acceder a la representación interna [1].
    *   **Métodos de Conversión**: `toFloat()` y `toInt()` para obtener el valor en `float` e `int` respectivamente [1].
*   **Ubicación**: `ex00/`
*   **Ejecutable**: `fixed`

### ex01: Towards a More Useful Fixed-Point Number Class

Este ejercicio amplía la clase `Fixed` para mejorar su utilidad y legibilidad.

*   **Objetivo**: Extender la clase `Fixed` del `ex00` para facilitar la visualización de sus valores en la salida estándar [9].
*   **Conceptos Clave Aplicados**:
    *   **Sobrecarga del Operador de Inserción (`operator<<`)**: Implementación de una función global `std::ostream& operator<<(std::ostream& os, const Fixed& fixed_obj)` para permitir imprimir objetos `Fixed` directamente usando `std::cout` [9].
    *   **Reutilización de `toFloat()`**: El operador `operator<<` utiliza el método `toFloat()` de la clase `Fixed` para mostrar el valor en un formato legible [9].
    *   **OCF y Constructores de Conversión**: Se mantienen y refuerzan del `ex00` [9].
*   **Ubicación**: `ex01/`
*   **Ejecutable**: `fixed`

### ex02: A More Advanced Fixed-Point Number Class

Este es el ejercicio más completo de la serie `Fixed`, dotándola de todas las operaciones aritméticas y de comparación.

*   **Objetivo**: Implementar la sobrecarga de un conjunto completo de operadores para la clase `Fixed`, permitiendo que se comporte de manera similar a los tipos numéricos primitivos [1].
*   **Conceptos Clave Aplicados**:
    *   **Sobrecarga de Operadores de Comparación**: `operator>`, `operator<`, `operator>=`, `operator<=`, `operator==`, `operator!=` [1].
    *   **Sobrecarga de Operadores Aritméticos**: `operator+`, `operator-`, `operator*`, `operator/` [1]. (Nota: La implementación sigue la semántica de `operator=` [1]).
    *   **Sobrecarga de Operadores de Incremento/Decremento**:
        *   `Fixed& operator++()` (pre-incremento) [1].
        *   `Fixed operator++(int)` (post-incremento) [1].
        *   `Fixed& operator--()` (pre-decremento) [1].
        *   `Fixed operator--(int)` (post-decremento) [1].
    *   **Funciones Miembro Estáticas**: Implementación de `static Fixed& min(Fixed&, Fixed&)` y `static const Fixed& min(const Fixed&, const Fixed&)` (y sus contrapartes `max`) para encontrar el valor mínimo y máximo entre dos objetos `Fixed` [1].
    *   **OCF y `operator<<`**: Se mantienen y refuerzan de los `ex00` y `ex01` [1].
*   **Ubicación**: `ex02/`
*   **Ejecutable**: `fixed`

### ex03: BSP (Binary Space Partitioning)

Este ejercicio aplica la clase `Fixed` a un problema de geometría computacional.

*   **Objetivo**: Implementar una función `bsp()` que determine si un punto dado se encuentra dentro de un triángulo, utilizando para todas las coordenadas la clase `Fixed` [9].
*   **Conceptos Clave Aplicados**:
    *   **Composición de Clases**: Creación de una clase `Point` que utiliza objetos `Fixed` para sus coordenadas `x` e `y` [9].
    *   **OCF para `Point`**: Implementación de la Orthodox Canonical Form para la clase `Point` [8]. (Nota: El operador de asignación de `Point` puede ser una trampa debido a los miembros `const Fixed` [7]).
    *   **Geometría Computacional**: Aplicación del "Método de las Áreas" (o coordenadas baricéntricas) para verificar la posición de un punto [5].
    *   **Precisión de Punto Fijo**: Utilización de `Fixed` para los cálculos geométricos, lo que subraya la importancia del manejo de la precisión.
    *   **Funciones Auxiliares**: `area()` para calcular el área de un triángulo [5].
    *   **Uso de `const` Referencias**: Pasar objetos `Point` y `Fixed` por referencia constante para eficiencia y seguridad [5].
*   **Ubicación**: `ex03/`
*   **Ejecutable**: `bsp`

---

## 🛠️ Compilación y Ejecución General

Cada ejercicio se encuentra en su propio subdirectorio (`ex00/`, `ex01/`, `ex02/`, `ex03/`) y utiliza un `Makefile` específico para su compilación y gestión.

1.  **Navega al directorio del proyecto**:
    ```bash
    cd <nombre_del_directorio_del_proyecto> # Ejemplo: cd ex00
    ```
2.  **Compilar (construir el ejecutable)**:
    ```bash
    make
    # O para una reconstrucción limpia (recomendado):
    make re
    ```
3.  **Ejecutar el programa**:
    ```bash
    ./<nombre_del_ejecutable> # Ejemplo: ./fixed (para ex00, ex01, ex02) o ./bsp (para ex03)
    ```
4.  **Limpiar archivos objeto (`.o`)**:
    ```bash
    make clean
    ```
5.  **Limpiar todos los archivos generados (`.o` y ejecutable)**:
    ```bash
    make fclean
    ```

---
## ✍️ Autor

*   **Nombre**: Juan Jesús Márquez
*   **Perfil GitHub**: https://github.com/elWare
*   **42 Login**: https://profile-v3.intra.42.fr/users/jumarque

---