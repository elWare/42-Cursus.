# 🌀 Push Swap - El Desafío de Clasificación con Dos Stacks

¡Bienvenido/a a mi implementación del proyecto **Push Swap** de la escuela 42! Este es uno de los desafíos algorítmicos más intensos del Cursus, donde el objetivo es clasificar una lista de enteros en un stack (pila) utilizando un conjunto muy limitado de operaciones y optimizando el número de movimientos.

## 🌟 ¿Qué es Push Swap?

Push Swap es un rompecabezas de clasificación que te obliga a pensar de forma algorítmica y a optimizar la complejidad [18]. Te proporciona dos stacks, `a` y `b`, inicialmente con todos los números desordenados en el stack `a` y el stack `b` vacío. Tu tarea es ordenar los números en el stack `a` (del más pequeño al más grande, en la parte superior) utilizando solo un conjunto específico de operaciones.

Este proyecto es fundamental para desarrollar habilidades en:

*   **Algoritmos de Clasificación:** Diseñar y optimizar un algoritmo para ordenar datos bajo restricciones.
*   **Estructuras de Datos:** Manejar eficazmente stacks (pilas) y comprender sus operaciones.
*   **Optimización:** Minimizar el número de operaciones realizadas, lo cual es el criterio principal de evaluación.
*   **Pensamiento Lógico y Resolución de Problemas:** Descomponer un problema complejo en pasos manejables y encontrar soluciones creativas.

## 🎯 Objetivos del Proyecto

El objetivo principal es escribir dos programas [18]:

1.  **`push_swap`** [2]: Este programa recibe una lista de enteros como argumentos y calcula la secuencia **más pequeña** de operaciones [18] para ordenarlos en el stack `a`. Luego, imprime estas operaciones en la salida estándar.
2.  **`checker`** [2]: Este programa recibe la misma lista de enteros como argumentos y luego lee operaciones de la entrada estándar. Ejecuta estas operaciones sobre los stacks y, finalmente, imprime "OK" si el stack `a` está ordenado y el stack `b` está vacío, o "KO" en caso contrario.

## 🚀 Funcionalidades y Operaciones Permitidas

El programa `push_swap` debe generar una serie de instrucciones utilizando solo las siguientes operaciones:

### Operaciones del Stack `a`
*   `sa`: swap a - Intercambia los dos primeros elementos del stack `a`. No hace nada si solo hay uno o ningún elemento.
*   `pa`: push a - Toma el primer elemento del stack `b` y lo pone en la parte superior del stack `a`. No hace nada si `b` está vacío.
*   `ra`: rotate a - Desplaza hacia arriba todos los elementos del stack `a` una posición. El primer elemento se convierte en el último.
*   `rra`: reverse rotate a - Desplaza hacia abajo todos los elementos del stack `a` una posición. El último elemento se convierte en el primero.

### Operaciones del Stack `b`
*   `sb`: swap b - Intercambia los dos primeros elementos del stack `b`. No hace nada si solo hay uno o ningún elemento.
*   `pb`: push b - Toma el primer elemento del stack `a` y lo pone en la parte superior del stack `b`. No hace nada si `a` está vacío.
*   `rb`: rotate b - Desplaza hacia arriba todos los elementos del stack `b` una posición. El primer elemento se convierte en el último.
*   `rrb`: reverse rotate b - Desplaza hacia abajo todos los elementos del stack `b` una posición. El último elemento se convierte en el primero.

### Operaciones Conjuntas
*   `ss`: `sa` y `sb` al mismo tiempo.
*   `rr`: `ra` y `rb` al mismo tiempo.
*   `rrr`: `rra` y `rrb` al mismo tiempo.

### Requisitos Adicionales
*   Manejo de errores: El programa debe gestionar entradas inválidas (no números, duplicados, fuera de rango de enteros, etc.) e imprimir "Error".
*   Optimización: El número total de operaciones debe ser lo más bajo posible para el conjunto de números dado [18].

## 🛠️ Instalación y Uso

Para compilar y usar Push Swap, sigue estos pasos:

1.  **Clonar el repositorio:**
    ```bash
    git clone https://github.com/tu_usuario/push_swap.git
    cd push_swap
    ```

2.  **Compilar los programas:**
    Usa el `Makefile` [2] para compilar `push_swap` y `checker`.
    ```bash
    make
    ```
    Esto creará los ejecutables `push_swap` y `checker` en el directorio raíz.

3.  **Limpiar archivos:**
    ```bash
    make clean   # Elimina archivos .o [2]
    make fclean  # Elimina .o y los ejecutables [2]
    make re      # fclean y luego all [2]
    ```

### Cómo usar `push_swap`

Ejecuta `push_swap` con una lista de enteros separados por espacios como argumentos.
Por ejemplo:
```bash
./push_swap 2 1 3 6 5 4
```
Esto imprimirá la secuencia de operaciones para ordenar los números.

### Cómo usar `checker`

El `checker` se usa para verificar las operaciones generadas por `push_swap`. Puedes "pipear" la salida de `push_swap` directamente al `checker`:

```bash
./push_swap 2 1 3 6 5 4 | ./checker 2 1 3 6 5 4
```
Si el orden es correcto, imprimirá `OK`. De lo contrario, imprimirá `KO`.

El programa `checker` utiliza `get_next_line` para leer las instrucciones que se le proporcionan [2]. También puedes pasarle operaciones manualmente al `checker` (una por línea):
```bash
./checker 2 1 3
sa
pa
# ... y luego presionar Ctrl+D para enviar EOF
```

## 📚 Estructura del Repositorio

*   `Makefile`: Para compilar `push_swap` y `checker` [2].
*   `src/`: Directorio que contiene los archivos fuente para `push_swap` y sus funciones auxiliares (ej: `ft_push.c`, `ft_rotate_down.c`, `ft_swap.c`, `ft_tsort_big.c`, `push_swap.c`) [2].
*   `src_bonus/`: Directorio que contiene los archivos fuente para el `checker` (ej: `checker_bonus.c`, `checker_utils_bonus.c`) [2].
*   `include/`: Directorio para los archivos de cabecera y librerías internas como `get_next_line` [2].
*   `libft/`: Subdirectorio con mi `libft` personal (se utiliza para funciones básicas como `ft_atoi`, `ft_split`, etc.).
*   `README.md`: Este archivo.

## 🧑‍💻 Autor

*   **Nombre:** Juan Jesús Marquez
*   **GitHub:** https://github.com/elWare
*   **42 Profile:** https://profile-v3.intra.42.fr/users/jumarque

## 📝 Licencia

Este proyecto está bajo la licencia [Tu Licencia Preferida, por ejemplo: MIT License] - ver el archivo [LICENSE.md](LICENSE.md) para más detalles (si tienes un archivo de licencia).

## 👏 Agradecimientos

*   A la escuela 42 por el currículo y los desafíos que me empujan a aprender y mejorar.
*   A mis compañeros de estudio y mentores por su apoyo, las discusiones sobre algoritmos y las valiosas revisiones de código.

---