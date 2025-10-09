# 📚 Libft - La Biblioteca Fundacional de 42

Este repositorio contiene mi implementación personal de la **Libft**, la primera gran librería de funciones en C que se construye durante el currículo de la escuela 42. El objetivo de este proyecto es recrear desde cero un conjunto de funciones estándar de la librería de C, así como añadir algunas funciones útiles adicionales, con el fin de solidificar la comprensión del lenguaje C y la manipulación de memoria.

## 🌟 ¿Qué es Libft?

En el ecosistema de 42, `libft` es mucho más que un simple proyecto; es el **pilar fundamental** de tu viaje en C. Imagina que es tu caja de herramientas personal, donde cada herramienta (función) la has forjado tú mismo.

Este proyecto te enseña:
*   **Manipulación de memoria:** Trabajar directamente con `malloc`, `free`, `memcpy`, `memset`, etc., sin los `wrappers` de la librería estándar, te da un control y entendimiento profundo.
*   **Pensamiento modular:** Organizar tu código en funciones pequeñas y reutilizables, que luego se compilan en una librería estática (`.a`).
*   **Estándares de codificación:** Adherirse a las estrictas reglas del `norminette` de 42, lo que fomenta un código limpio, legible y consistente.
*   **Resolución de problemas:** Desde implementar un `ft_strlen` hasta un `ft_split`, cada función es un pequeño reto algorítmico que te prepara para desafíos mayores.

## 🚀 Funciones Implementadas

Mi `libft` incluye una amplia gama de funciones, tal como se definen en el `Makefile` [2], y se dividen en varias categorías:

### Funciones de la Libc (Parte 1)
Estas son recreaciones de funciones estándar de la librería C [2]:
*   `ft_atoi`
*   `ft_bzero`
*   `ft_calloc`
*   `ft_isalnum`
*   `ft_isalpha`
*   `ft_isascii`
*   `ft_isdigit`
*   `ft_isprint`
*   `ft_memchr`
*   `ft_memcmp`
*   `ft_memcpy`
*   `ft_memmove`
*   `ft_memset`
*   `ft_strchr`
*   `ft_strdup`
*   `ft_strlcat`
*   `ft_strlcpy`
*   `ft_strlen`
*   `ft_strncmp`
*   `ft_strnstr`
*   `ft_strrchr`
*   `ft_tolower`
*   `ft_toupper`

### Funciones Adicionales (Parte 2)
Estas son funciones no estándar de la Libc, escritas para el proyecto 42 [2]:
*   `ft_substr`
*   `ft_strjoin`
*   `ft_strtrim`
*   `ft_split`
*   `ft_itoa`
*   `ft_strmapi`
*   `ft_striteri`
*   `ft_putchar_fd`
*   `ft_putstr_fd`
*   `ft_putendl_fd`
*   `ft_putnbr_fd`

### Funciones de la Lista Enlazada (`t_list`) (Bonus)
Estas funciones operan sobre la estructura `t_list` [1] y forman la parte "bonus" del proyecto [2]:
*   `ft_lstnew`
*   `ft_lstadd_front`
*   `ft_lstsize`
*   `ft_lstlast`
*   `ft_lstadd_back`
*   `ft_lstdelone`
*   `ft_lstclear`
*   `ft_lstiter`
*   `ft_lstmap`

## 🛠️ Instalación y Uso

Para usar `libft` en tus proyectos, simplemente sigue estos pasos:

1.  **Clonar el repositorio:**
    ```bash
    git clone https://github.com/tu_usuario/libft.git
    cd libft
    ```

2.  **Compilar la librería estándar (`libft.a`):**
    Usa el `Makefile` para compilar la librería estática `libft.a` con las funciones de la Parte 1 y 2 [2].
    ```bash
    make
    ```
    Esto creará el archivo `libft.a` en el directorio raíz del proyecto.

3.  **Compilar la librería con las funciones bonus:**
    Para incluir las funciones de lista enlazada (bonus) en `libft.a` [2]:
    ```bash
    make bonus
    ```

4.  **Limpiar archivos objeto:**
    Elimina todos los archivos `.o` generados durante la compilación [2].
    ```bash
    make clean
    ```

5.  **Limpiar la librería y los archivos objeto:**
    Elimina `libft.a` y todos los archivos `.o` [2].
    ```bash
    make fclean
    ```

6.  **Rehacer (limpiar y compilar todo):**
    Ejecuta `fclean` y luego `all` para recompilar la librería desde cero [2].
    ```bash
    make re
    ```

### Cómo usar `libft.a` en tus proyectos

Para integrar `libft` en tus propios programas C, deberás:

1.  Incluir el archivo de cabecera (`libft.h`) en tus archivos fuente.
2.  Compilar tus archivos `.c` con `gcc`.
3.  Vincular la librería `libft.a` a tu compilación.

**Ejemplo:**
Si tienes un archivo `main.c` que usa funciones de `libft`:

```c
// main.c
#include "libft.h" // Asegúrate de que libft.h esté en tu path de inclusión

int main()
{
    char *s = ft_strdup("Hola 42!");
    if (s) { // Siempre comprueba el retorno de malloc/strdup
        ft_putendl_fd(s, 1);
        free(s); // No olvides liberar la memoria si usas ft_strdup, ft_split, etc.
    }
    return (0);
}
```

Para compilar `main.c` con `libft.a`:

```bash
gcc main.c -L. -lft -I. -o my_program
# -L. : Busca librerías en el directorio actual
# -lft : Busca la librería 'libft.a' (el 'lib' y '.a' se asumen)
# -I. : Busca archivos de cabecera en el directorio actual (donde está libft.h)
# -o my_program : El nombre del ejecutable
```

Luego, puedes ejecutar tu programa:
```bash
./my_program
```

## 🧑‍💻 Autor

Si tienes alguna pregunta o sugerencia, no dudes en contactarme:

*   **Nombre:** Juan Jesús Marquez
*   **GitHub:** https://github.com/elWare
*   **42 Profile:** https://profile-v3.intra.42.fr/users/jumarque
