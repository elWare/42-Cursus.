# 🖨️ ft_printf - Reimplementación de `printf()` de 42 (no bonus)

Este repositorio contiene mi implementación del proyecto **ft_printf** de la escuela 42. Este es un ejercicio crucial para comprender una de las funciones más versátiles y fundamentales de C: `printf()`. El objetivo principal es recrear una versión simplificada de esta función, manejando argumentos variádicos y formateando la salida a la consola.

## 🌟 ¿Qué es ft_printf?

`ft_printf` es un proyecto que te introduce a las **funciones variádicas** en C y te desafía a construir una función de formateo de salida desde cero [17]. Es una excelente oportunidad para mejorar tus habilidades de programación al:

*   Comprender cómo funcionan los argumentos variables (`va_list`, `va_arg`, `va_start`, `va_end`).
*   Gestionar diferentes tipos de datos (caracteres, cadenas, enteros, hexadecimales) y convertirlos a sus representaciones de cadena.
*   Estructurar el código de manera modular y extensible para manejar diversas especificaciones de formato.
*   Integrar tu propia `libft` para funciones auxiliares [17].

Una vez completado, `ft_printf()` se convierte en una herramienta muy útil que puedes añadir a tu `libft` y usar en futuros proyectos en C [17].

## 🎯 Objetivos del Proyecto

El objetivo principal de `ft_printf` es programar una librería que contenga la función `ft_printf()`, la cual debe imitar al `printf()` original de la `libc` [17].

El prototipo de `ft_printf()` es: `int ft_printf(char const *, ...);` [17].

## 🚀 Funcionalidades y Requisitos Clave (Parte Obligatoria)

Mi implementación de `ft_printf` se adhiere a las siguientes especificaciones obligatorias:

*   **Conversiones Soportadas:** La función debe manejar las siguientes especificaciones de formato [17]:
    *   `%c`: Imprime un solo carácter.
    *   `%s`: Imprime una cadena de caracteres (maneja `NULL` como `(null)`).
    *   `%p`: Imprime la dirección de memoria de un puntero en formato hexadecimal.
    *   `%d`: Imprime un número entero decimal con signo.
    *   `%i`: Imprime un número entero decimal con signo (idéntico a `%d`).
    *   `%u`: Imprime un número entero decimal sin signo.
    *   `%x`: Imprime un número en formato hexadecimal (minúsculas).
    *   `%X`: Imprime un número en formato hexadecimal (mayúsculas).
    *   `%%`: Imprime un signo de porcentaje literal.
*   **Sin gestión de buffer:** No se debe implementar la gestión del buffer del `printf()` original [17]. La salida se escribe directamente utilizando `write()`.
*   **Comparación con `printf()`:** La función debe comportarse exactamente igual que el `printf()` original para las conversiones implementadas [17].
*   **Librería estática:** La librería `libftprintf.a` se crea usando `ar` [17].
*   **Archivo `libftprintf.a`:** Debe ubicarse en la raíz del repositorio [17].

### Funciones Auxiliares Implementadas

Para lograr lo anterior, se han desarrollado las siguientes funciones auxiliares (además de `ft_printf` como función principal):

*   `static int	ft_print(unsigned char c, va_list args)`: Una función interna que dirige la llamada a la función de impresión adecuada según el tipo de formato [13, 14].
*   `int	ft_printc(unsigned char c, va_list args)`: Imprime un carácter [14].
*   `int	ft_prints(va_list args)`: Imprime una cadena de caracteres [14, 16].
*   `int	ft_printptr(va_list args)`: Imprime una dirección de puntero [14].
*   `int	ft_printdiu(unsigned char c, va_list args)`: Imprime enteros decimales con y sin signo (`d`, `i`, `u`) [12, 14].
*   `int	ft_printhex(unsigned char c, va_list args)`: Imprime números hexadecimales (`x`, `X`) [14, 15].
*   `char	*ft_uitoa(unsigned int n)`: Convierte un `unsigned int` a una cadena [14]. (Similar a `ft_itoa` pero para unsigned).

### Funciones Autorizadas [17]

*   `malloc`
*   `free`
*   `write`
*   `va_start`
*   `va_arg`
*   `va_copy`
*   `va_end`

### Uso de Libft [17]

Este proyecto permite el uso de `libft` [17]. Mi `ft_printf` integra y utiliza funciones de mi `libft` personal, ubicada en el subdirectorio `./libft/`.

## 🛠️ Instalación y Uso

Para usar `ft_printf` en tus proyectos, simplemente sigue estos pasos:

1.  **Clonar el repositorio:**
    ```bash
    git clone https://github.com/tu_usuario/ft_printf.git
    cd ft_printf
    ```

2.  **Compilar la librería:**
    Usa el `Makefile` para compilar la librería estática `libftprintf.a` [2, 17]. Esto también compilará tu `libft` si no está compilada [2].
    ```bash
    make
    ```
    Esto creará el archivo `libftprintf.a` en el directorio raíz del proyecto.

3.  **Limpiar archivos objeto:**
    Elimina todos los archivos `.o` generados durante la compilación, tanto de `ft_printf` como de `libft` [2].
    ```bash
    make clean
    ```

4.  **Limpiar la librería y los archivos objeto:**
    Elimina `libftprintf.a`, `libft.a` y todos los archivos `.o` [2].
    ```bash
    make fclean
    ```

5.  **Rehacer (limpiar y compilar todo):**
    Ejecuta `fclean` y luego `all` para recompilar la librería desde cero [2].
    ```bash
    make re
    ```

### Cómo usar `libftprintf.a` en tus proyectos

Para integrar `libftprintf` en tus propios programas C, deberás:

1.  Incluir el archivo de cabecera (`ft_printf.h`) en tus archivos fuente.
2.  Compilar tus archivos `.c` con `gcc`.
3.  Vincular la librería `libftprintf.a` a tu compilación.

**Ejemplo:**
Si tienes un archivo `main.c` que usa `ft_printf()`:

```c
// main.c
#include "ft_printf.h" // Asegúrate de que ft_printf.h esté en tu path de inclusión
#include <stdio.h>    // Para comparar con printf original (opcional)

int main()
{
    char    c = 'A';
    char    *s = "Hola, 42!";
    int     d = -123;
    unsigned int u = 42;
    void    *p = &d;
    int     x = 255;

    ft_printf("Char: %c\n", c);
    printf("Char: %c\n", c); // Comparación

    ft_printf("String: %s\n", s);
    printf("String: %s\n", s);

    ft_printf("Decimal: %d\n", d);
    printf("Decimal: %d\n", d);

    ft_printf("Unsigned: %u\n", u);
    printf("Unsigned: %u\n", u);

    ft_printf("Hex (lower): %x\n", x);
    printf("Hex (lower): %x\n", x);

    ft_printf("Hex (upper): %X\n", x);
    printf("Hex (upper): %X\n", x);

    ft_printf("Pointer: %p\n", p);
    printf("Pointer: %p\n", p);

    ft_printf("Percent: %%\n");
    printf("Percent: %%\n");

    return (0);
}
```

Para compilar `main.c` con `libftprintf.a`:

```bash
gcc main.c -L. -lftprintf -I. -o my_printf_test
# -L. : Busca librerías en el directorio actual
# -lftprintf : Busca la librería 'libftprintf.a'
# -I. : Busca archivos de cabecera en el directorio actual (donde está ft_printf.h)
# -o my_printf_test : El nombre del ejecutable
```

Luego, puedes ejecutar tu programa:
```bash
./my_printf_test
```

## 📚 Estructura del Repositorio

*   `Makefile`: Archivo para automatizar la compilación de `libftprintf.a` [2, 17].
*   `ft_printf.h`: Archivo de cabecera con los prototipos de las funciones `ft_printf` y sus auxiliares [14].
*   `ft_printf.c`: Implementación de la función principal `ft_printf` [13].
*   `ft_printc.c`: Implementación de la conversión `%c`.
*   `ft_printdiu.c`: Implementación de las conversiones `%d`, `%i`, `%u` [12].
*   `ft_printhex.c`: Implementación de las conversiones `%x`, `%X` [15].
*   `ft_printptr.c`: Implementación de la conversión `%p`.
*   `ft_prints.c`: Implementación de la conversión `%s` [16].
*   `ft_uitoa.c`: Función auxiliar para convertir `unsigned int` a cadena.
*   `libft/`: Subdirectorio que contiene el código fuente y `Makefile` de mi `Libft` [2].

## 🧑‍💻 Autor

Si tienes alguna pregunta o sugerencia, no dudes en contactarme:

*   **Nombre:** Juan Jesús Marquez
*   **GitHub:** https://github.com/elWare
*   **42 Profile:** https://profile-v3.intra.42.fr/users/jumarque
