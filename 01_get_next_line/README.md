# 📝 Get Next Line (GNL) - Lector de Líneas de 42

Este repositorio contiene mi implementación del proyecto **Get Next Line (GNL)** de la escuela 42. El objetivo es simple: desarrollar una función robusta que permita leer una línea de texto de un descriptor de archivo, una a la vez, gestionando la memoria de forma eficiente y persistente entre llamadas.

## 🌟 ¿Qué es Get Next Line?

GNL es un proyecto clave que desafía tu comprensión de:
*   **Manejo de ficheros:** Interactuar directamente con el sistema de archivos utilizando llamadas al sistema como `read()`.
*   **Memoria dinámica:** Asignar y liberar memoria (`malloc`, `free`) de manera cuidadosa para evitar fugas de memoria y errores de segmento.
*   **Variables estáticas:** Utilizar variables estáticas para mantener el estado entre las llamadas a la función, lo cual es fundamental para el funcionamiento de `get_next_line` [5, 7, 9].
*   **Buffer de lectura:** Trabajar con un `BUFFER_SIZE` configurable para leer datos en bloques [6, 8].
*   **Recursividad o Iteración sofisticada:** Implementar una lógica para leer fragmentos de datos, almacenar el exceso y devolver la línea correcta.

Es un ejercicio de lógica y gestión de recursos que te prepara para proyectos más complejos.

## 🎯 Objetivos del Proyecto

El objetivo principal es programar una función `get_next_line` que devuelva una línea leída de un descriptor de archivo [4]. La línea devuelta debe terminar con `\n`, excepto si se ha llegado al final del archivo y este no termina con `\n` [4].

## 🚀 Funcionalidades y Requisitos Clave

Mi implementación de `get_next_line` se adhiere a las siguientes especificaciones:

*   **Lectura línea por línea:** La función `get_next_line(int fd)` lee desde un descriptor de archivo (`fd`) y devuelve una cadena de caracteres que representa la siguiente línea, incluyendo el carácter `\n` si está presente [4, 5, 7, 9].
*   **Manejo de final de archivo (EOF):** Si se llega al final del archivo y no hay `\n` al final, devuelve la última porción de texto. Si no hay más que leer, devuelve `NULL`.
*   **Persistencia del estado:** Utiliza una variable estática (`static char *buffer;` o `static char *buffer[__FD_SETSIZE];` para el bonus) para almacenar los caracteres que se leyeron pero no pertenecen a la línea actual, permitiendo retomar la lectura en la siguiente llamada [5, 7, 9].
*   **Tamaño del buffer:** La lectura se realiza en bloques definidos por `BUFFER_SIZE`, el cual está configurado a `42` en esta implementación [6, 8].
*   **Manejo de errores:** Devuelve `NULL` en caso de error (por ejemplo, `read()` falla o `malloc()` falla).
*   **Fugas de memoria:** Es crucial que la función no genere fugas de memoria.

### Funciones Implementadas

El proyecto se estructura en la función principal `get_next_line` y varias funciones de ayuda:

*   `char *get_next_line(int fd)`: La función principal que lee y devuelve la siguiente línea del descriptor de archivo `fd` [6].
*   `char *ft_create(int fd, char *buffer)`: Lee del `fd` y construye el buffer persistente hasta encontrar un `\n` o EOF [5, 6, 7, 9].
*   `char *ft_getline(char *buffer)`: Extrae la línea actual (hasta el primer `\n` o EOF) del buffer [5, 6, 7, 9].
*   `char *ft_cleanline(char *buffer)`: Limpia el buffer, eliminando la línea ya extraída y dejando el resto de los caracteres para la siguiente llamada [6, 7, 9].
*   `size_t ft_strln(const char *s)`: Calcula la longitud de una cadena [5, 6, 7, 9].
*   `char *ft_strchr(const char *str, int c)`: Localiza la primera ocurrencia de un carácter en una cadena [6, 10, 11].
*   `char *ft_strjoin(char *s1, char *s2)`: Concatena dos cadenas, liberando la primera (o creándola si es NULL) [6, 10, 11].

### Parte Bonus

La implementación bonus (`get_next_line_bonus.c`) permite leer de **múltiples descriptores de archivo simultáneamente** [4]. Esto se logra utilizando un array de buffers estáticos, donde cada elemento del array corresponde a un descriptor de archivo diferente [7]. La parte bonus solo se evaluará si la parte obligatoria es perfecta [4].

## 🛠️ Instalación y Uso

Para usar `get_next_line` en tus proyectos, sigue estos pasos:

1.  **Clonar el repositorio:**
    ```bash
    git clone https://github.com/tu_usuario/get_next_line.git
    cd get_next_line
    ```

2.  **Compilar (Mandatorio):**
    Para la versión no bonus, compila `get_next_line.c` junto con `get_next_line_utils.c` y tu `main.c`:
    ```bash
    gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl_program
    ```
    *   `-D BUFFER_SIZE=42`: Define el tamaño del buffer de lectura [6, 8]. Puedes cambiar `42` por cualquier otro valor positivo.

3.  **Compilar (Bonus):**
    Para la versión bonus, que soporta múltiples descriptores de archivo, compila `get_next_line_bonus.c` junto con `get_next_line_utils_bonus.c` y tu `main.c`:
    ```bash
    gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus_program
    ```

### Ejemplo de Uso

Aquí tienes un ejemplo básico de cómo usar `get_next_line` para leer un archivo:

```c
// main.c
#include "get_next_line.h" // O "get_next_line_bonus.h" para la versión bonus
#include <fcntl.h> // Para la función open()
#include <stdio.h> // Para printf()

int main(void)
{
    int     fd;
    char    *line;

    // Abre un archivo de texto para lectura
    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return (1);
    }

    // Lee y imprime cada línea hasta el final del archivo
    printf("Contenido del archivo:\n");
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // printf ya añade un \n si line lo contiene.
        free(line); // ¡Muy importante liberar la memoria!
    }

    close(fd); // Cierra el descriptor de archivo
    return (0);
}
```
**`example.txt`:**
```
Hola mundo
Esta es la segunda linea.
Y la tercera
```

**Salida esperada:**
```
Contenido del archivo:
Hola mundo
Esta es la segunda linea.
Y la tercera
```

## 📚 Estructura del Repositorio

*   `get_next_line.h`: Archivo de cabecera principal con los prototipos de las funciones [6].
*   `get_next_line.c`: Implementación de la función `get_next_line` y funciones auxiliares para la parte obligatoria [5, 9].
*   `get_next_line_utils.c`: Funciones de utilidad como `ft_strjoin` y `ft_strchr` para la parte obligatoria [10].
*   `get_next_line_bonus.h`: Archivo de cabecera para la parte bonus [8].
*   `get_next_line_bonus.c`: Implementación de `get_next_line` para la parte bonus, manejando múltiples descriptores de archivo [7].
*   `get_next_line_utils_bonus.c`: Funciones de utilidad para la parte bonus [11].
*   `Makefile`: (Opcional, pero recomendado) Un archivo Makefile para automatizar la compilación.

## 🧑‍💻 Autor

Si tienes alguna pregunta o sugerencia, no dudes en contactarme:

*   **Nombre:** Juan Jesús Marquez
*   **GitHub:** https://github.com/elWare
*   **42 Profile:** https://profile-v3.intra.42.fr/users/jumarque