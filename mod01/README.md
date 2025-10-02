# C++ Módulo 01: Introducción a la Programación Orientada a Objetos y Fundamentos ✨

## Descripción General del Módulo

Este repositorio contiene los proyectos y ejercicios realizados como parte del C++ Módulo 01 de la Formación 42 (o École 42) 🚀. El objetivo de este módulo es establecer una base sólida en la programación en C++, introduciendo conceptos fundamentales de la Programación Orientada a Objetos (POO), el manejo de memoria a bajo nivel (punteros y referencias), la gestión de archivos y el uso de estructuras de datos básicas.

Cada ejercicio está diseñado para reforzar un conjunto específico de habilidades y conocimientos, preparando al estudiante para desafíos más complejos en módulos subsiguientes.

## Ejercicios y Conceptos Clave

A continuación, se detalla cada ejercicio del módulo y los conceptos principales abordados:

### `ex00: BraiiiiiiinnnzzzZ` 🧟‍♂️
*   **Descripción**: Primer contacto con las clases en C++, creando una clase `Zombie` que simula el comportamiento básico de estos seres [3].
*   **Conceptos Clave**:
    *   Definición básica de clases, objetos, atributos privados (`std::string name`) y funciones miembro (`announce()`) [3].
    *   Implementación de constructores y destructores [3].
    *   Uso de directivas de preprocesador (`#ifndef`, `#define`, `#endif`) como guardas de inclusión [3].
    *   Entrada y salida estándar con `std::cout` [3].
*   **Archivos Relevantes**: `Zombie.hpp`, `Zombie.cpp`, `main.cpp` [3].

### `ex01: Moar brainz!` 🧟‍♀️ horde
*   **Descripción**: Extensión del ejercicio `ex00` para manejar una "horda" de zombies, centrándose en la gestión dinámica de memoria para crear múltiples objetos [4].
*   **Conceptos Clave**:
    *   Gestión dinámica de memoria (`new` y `delete[]`) para arrays de objetos [4].
    *   Creación de objetos en el *heap*.
    *   Trabajo con punteros a objetos y arrays de objetos.
    *   Funciones externas que interactúan con las clases (ej. `zombieHorde`) [4].
    *   Inicialización de cada zombie con un nombre proporcionado [4].
    *   Liberación de memoria asignada dinámicamente para evitar fugas [4].
*   **Archivos Relevantes**: `Zombie.hpp`, `Zombie.cpp`, `zombieHorde.cpp`, `main.cpp` [4].

### `ex02: HI THIS IS BRAIN` 🧠
*   **Descripción**: Este ejercicio aborda las diferencias y similitudes entre variables, punteros y referencias en C++, y cómo interactúan con la memoria [5].
*   **Conceptos Clave**:
    *   Declaración de una variable `std::string` [5].
    *   Creación de un puntero (`stringPTR`) que apunta a la dirección de la variable usando el operador `&` [5].
    *   Creación de una referencia (`stringREF`) que es un alias de la misma variable [5].
    *   Impresión de direcciones de memoria (`&variable`, `puntero`, `&referencia`) [5].
    *   Acceso a los valores mediante la variable, el puntero (`*puntero`) y la referencia [5].
    *   Confirmación de que los tres apuntan a la misma dirección y valor [5].
*   **Archivos Relevantes**: `main.cpp` [5].

### `ex03: Unnecessary violence` ⚔️
*   **Descripción**: Implementación de clases que modelan armas (`Weapon`) y personajes (`HumanA`, `HumanB`) que pueden usarlas, destacando la **composición de objetos** y la distinción crucial entre **referencias** y **punteros** [6].
*   **Conceptos Clave**:
    *   **Clase `Weapon`**: Atributo privado `type` y métodos `getType()` y `setType()` [6].
    *   **Clase `HumanA`**: Representa un personaje que siempre posee un arma, gestionada mediante una **referencia (`Weapon&`)** en su constructor [6]. Las referencias no pueden ser nulas y no cambian de objeto una vez inicializadas [6].
    *   **Clase `HumanB`**: Representa un personaje que puede o no tener un arma inicialmente, o cambiarla dinámicamente, gestionada mediante un **puntero (`Weapon*`)** [6]. Los punteros pueden ser `nullptr` [6].
    *   Comprensión de las implicaciones de diseño al usar referencias vs. punteros para la composición [6].
*   **Archivos Relevantes**: `Weapon.hpp`, `Weapon.cpp`, `HumanA.hpp`, `HumanA.cpp`, `HumanB.hpp`, `HumanB.cpp`, `main.cpp` [6].

### `ex04: Sed is for losers` 📄
*   **Descripción**: Creación de un programa que replica la funcionalidad básica del comando `sed` de Linux: reemplazar todas las ocurrencias de una cadena (`s1`) por otra (`s2`) dentro de un archivo [7].
*   **Conceptos Clave**:
    *   Manejo de archivos utilizando las clases de flujo de C++: `std::ifstream` (para lectura) y `std::ofstream` (para escritura) [7].
    *   Restricción de no usar funciones de manipulación de archivos de C (como `fopen`, `fclose`) [7].
    *   Procesamiento de texto: búsqueda y reemplazo de subcadenas (`std::string::find`, `std::string::replace`) [7].
    *   Validación de argumentos de línea de comandos (`argc`, `argv`) y manejo de errores (ej. archivo inexistente, cadenas vacías) [7].
    *   Creación de archivos de salida con nombres específicos (ej. `<filename>.replace`) [7].
*   **Archivos Relevantes**: `main.cpp` [7].

### `ex05: Harl 2.0` 🗣️
*   **Descripción**: Implementación de la clase `Harl`, que simula un sistema de "quejas" con diferentes niveles de severidad (`DEBUG`, `INFO`, `WARNING`, `ERROR`), utilizando **punteros a funciones miembro** para despachar los comandos de forma modular, **evitando el uso de `if/else if/else` anidados** [8].
*   **Conceptos Clave**:
    *   **Punteros a Funciones Miembro**: Un concepto avanzado en C++ que permite invocar dinámicamente métodos de una instancia de clase [8].
    *   Patrón de **Despachador de Comandos**: Mapeo de cadenas de texto a funciones miembro específicas mediante un array de estructuras o punteros para ejecutar la función correcta [8].
    *   Encapsulación y modularidad de la lógica para cada nivel de queja [8].
*   **Archivos Relevantes**: `Harl.hpp`, `Harl.cpp`, `main.cpp` [8].

### `ex06: Harl filter` ⚙️
*   **Descripción**: Una extensión del `ex05`, donde la clase `Harl` se mejora para **filtrar las quejas** según un nivel de severidad mínimo especificado como argumento en la línea de comandos [9].
*   **Conceptos Clave**:
    *   Aplicación de lógica de control de flujo (como un `switch` o un array de punteros a funciones con índices) para filtrar los mensajes y mostrar solo los que tienen una severidad igual o superior a la indicada [9].
    *   Manejo y validación de argumentos de línea de comandos para el nivel de filtro [9].
    *   Reuso y extensión de la clase `Harl` existente [9].
    *   Gestión de mensajes de error y uso (`USAGE`) para entradas de usuario inválidas [9].
*   **Archivos Relevantes**: `Harl.hpp`, `Harl.cpp`, `main.cpp` [9].

## Estructura del Repositorio 📁

Cada ejercicio se organiza en su propio directorio (e.g., `ex00/`, `ex01/`), conteniendo los archivos de cabecera (`.hpp`), las implementaciones (`.cpp`) y un archivo `main.cpp` para pruebas, junto con un `Makefile` específico para compilar dicho ejercicio.

```
.
├── ex00/
│   ├── Zombie.hpp
│   ├── Zombie.cpp
│   ├── main.cpp
│   └── Makefile
├── ex01/
│   ├── Zombie.hpp
│   ├── Zombie.cpp
│   ├── zombieHorde.cpp
│   ├── main.cpp
│   └── Makefile
├── ex02/
│   ├── main.cpp
│   └── Makefile
├── ex03/
│   ├── Weapon.hpp
│   ├── Weapon.cpp
│   ├── HumanA.hpp
│   ├── HumanA.cpp
│   ├── HumanB.hpp
│   ├── HumanB.cpp
│   ├── main.cpp
│   └── Makefile
├── ex04/
│   ├── main.cpp
│   └── Makefile
├── ex05/
│   ├── Harl.hpp
│   ├── Harl.cpp
│   ├── main.cpp
│   └── Makefile
├── ex06/
│   ├── Harl.hpp
│   ├── Harl.cpp
│   ├── main.cpp
│   └── Makefile
└── README.md
```

## Cómo Compilar y Ejecutar ▶️

Para compilar y ejecutar los ejercicios, navega al directorio específico del ejercicio que deseas probar. Cada directorio debería contener un `Makefile` preconfigurado [1].

1.  **Compilar (en el directorio del ejercicio)**:
    ```bash
    make
    ```
    Los `Makefile`s están configurados para usar `g++` con las banderas de compilación obligatorias en 42: `-Wall -Werror -Wextra -std=c++98 -g` [1].

2.  **Ejecutar (en el directorio del ejercicio)**:
    ```bash
    ./<nombre_del_ejecutable> [argumentos si aplican]
    ```
    *   Para `ex00`, `ex01`, `ex02`, `ex03`, `ex05`: `./<nombre_del_ejecutable>` (ej. `./harl` para `ex05`).
    *   Para `ex04`: `./<nombre_del_ejecutable> <filename> <s1> <s2>` (ej. `./sed_for_losers texto.txt Hola Adios`).
    *   Para `ex06`: `./<nombre_del_ejecutable> <severity_level>` (ej. `./harlFilter WARNING`).

3.  **Limpiar archivos generados**:
    ```bash
    make clean
    make fclean
    ```

## Notas Adicionales / Estándares de 42 📝

*   **Compilador**: Se utiliza `g++` para compilar todos los proyectos de C++ [1].
*   **Banderas de compilación**: La compilación debe realizarse estrictamente con las banderas `-Wall -Werror -Wextra -std=c++98 -g`. La bandera `-Werror` es fundamental, ya que cualquier advertencia (`warning`) se tratará como un error, impidiendo la compilación [1].
*   **Estándar C++98**: Todos los ejercicios se desarrollan siguiendo el estándar C++98, evitando el uso de características o sintaxis introducidas en versiones posteriores de C++ [6].

## Autor / Contacto 🧑‍💻

*   **Nombre**: Juan Jesús Márquez
*   **Perfil GitHub**: https://github.com/elWare
*   **42 Login**: https://profile-v3.intra.42.fr/users/jumarque