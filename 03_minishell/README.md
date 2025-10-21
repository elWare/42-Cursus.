# 🚀 Minishell 🚀

![Minishell Banner](https://img.shields.io/badge/Project-Minishell-blueviolet)
![Language](https://img.shields.io/badge/Language-C-blue)
![Norme](https://img.shields.io/badge/Norme-42-lightgreen)
![Status](https://img.shields.io/badge/Status-_Finished-green)
![License](https://img.shields.io/badge/License-MIT-lightgray)

---

## 📝 Tabla de Contenidos

1.  [Visión General del Proyecto](#1-visión-general-del-proyecto)
    *   [¿Qué es Minishell?](#¿qué-es-minishell)
    *   [Objetivos del Proyecto (42 Málaga)](#objetivos-del-proyecto-42-málaga)
2.  [Características Implementadas](#2-características-implementadas)
3.  [Conceptos Clave e Implementación](#3-conceptos-clave-e-implementación)
    *   [I. Estructuras de Datos Principales](#i-estructuras-de-datos-principales)
    *   [II. Flujo de Procesamiento y Ejecución](#ii-flujo-de-procesamiento-y-ejecución)
        *   [A. Lectura de Input y Señales](#a-lectura-de-input-y-señales)
        *   [B. Tokenización](#b-tokenización)
        *   [C. Expansión de Variables](#c-expansión-de-variables)
        *   [D. Construcción de Comandos (Parsing)](#d-construcción-de-comandos-parsing)
        *   [E. Manejo de Redirecciones](#e-manejo-de-redirecciones)
        *   [F. Ejecución de Comandos](#f-ejecución-de-comandos)
    *   [III. Gestión de Memoria](#iii-gestión-de-memoria)
    *   [IV. Built-ins y Variables de Entorno](#iv-built-ins-y-variables-de-entorno)
    *   [V. Códigos de Salida y Manejo de Errores](#v-códigos-de-salida-y-manejo-de-errores)
4.  [Bonus (Planificado/En Desarrollo)](#4-bonus-planificadoen-desarrollo)
5.  [Cómo Empezar](#5-cómo-empezar)
    *   [Prerrequisitos](#prerrequisitos)
    *   [Construir el Proyecto](#construir-el-proyecto)
    *   [Ejecutar Minishell](#ejecutar-minishell)
6.  [Uso y Ejemplos](#6-uso-y-ejemplos)
7.  [Testing y Depuración](#7-testing-y-depuración)
    *   [Tester Automático](#tester-automático)
    *   [Depuración con Valgrind](#depuración-con-valgrind)
8.  [Agradecimientos y Contacto](#8-agradecimientos-y-contacto)

---

## **1. Visión General del Proyecto**

### ¿Qué es Minishell?

Minishell es un proyecto fundamental del plan de estudios de la [École 42](https://www.42.fr/es/escuela/escuela-42/) (y sus campus asociados, como 42 Málaga). Consiste en la implementación de un *shell* Unix básico, similar a Bash o Zsh, utilizando exclusivamente el lenguaje C. Este proyecto desafía a los estudiantes a comprender en profundidad cómo funciona un intérprete de comandos, desde el procesamiento de la entrada del usuario hasta la ejecución de programas en el sistema operativo.

### Objetivos del Proyecto (42 Málaga)

Los objetivos principales de Minishell son:
*   **Dominar C:** Profundizar en el manejo avanzado de punteros, gestión de memoria, estructuras de datos y llamadas al sistema (syscalls).
*   **Comprender el Sistema Operativo:** Entender la interacción entre una *shell* y el SO (creación de procesos con `fork()`, ejecución con `execve()`, manejo de pipes, redirecciones, señales).
*   **Desarrollar un Parser:** Diseñar e implementar un analizador léxico y sintáctico robusto para interpretar la línea de comandos.
*   **Adquirir Habilidades de Depuración:** La complejidad del proyecto obliga a desarrollar fuertes habilidades de *debugging*.
*   **Emular Comportamientos Estándar:** Replicar con precisión el comportamiento de shells POSIX y Bash en diversos escenarios de entrada y error.

---

## **2. Características Implementadas**

Minishell actualmente soporta las siguientes funcionalidades:

*   **Ejecución de Comandos Básicos:** Ejecuta programas externos (`ls`, `cat`, `grep`, etc.) y sus argumentos.
*   **Pipes (`|`):** Encadenamiento de la salida de un comando a la entrada de otro.
*   **Redirecciones de Entrada/Salida:**
    *   `<` (redirección de entrada de archivo)
    *   `>` (redirección de salida a archivo, sobrescribir)
    *   `>>` (redirección de salida a archivo, añadir)
    *   `<<` (here-document, `heredoc`)
*   **Built-in Commands (Comandos Internos):**
    *   `echo` con la opción `-n`.
    *   `cd` con rutas relativas/absolutas y `cd -`.
    *   `pwd` (Print Working Directory).
    *   `export` (añadir/modificar variables de entorno y exportarlas a procesos hijos).
    *   `unset` (eliminar variables de entorno).
    *   `env` (mostrar variables de entorno exportadas).
    *   `exit` (terminar la *shell* con un código de salida específico).
*   **Manejo de Variables de Entorno:** Expansión de `$VAR` y la variable especial `$?`.
*   **Gestión de Señales:** Manejo de `Ctrl+C` (`SIGINT`) y `Ctrl+\` (`SIGQUIT`) en diferentes contextos.
*   **Historial de Comandos:** Integración con la librería `readline` para historial y edición de línea.

---

## **3. Conceptos Clave e Implementación**

### I. Estructuras de Datos Principales

Definidas en `minishell.h`, estas estructuras son el esqueleto de la *shell*:

*   `t_shell`: Encapsula el estado global de la *shell*.
    ```c
    typedef struct s_shell
    {
        char    *input;         // Línea de comando leída por readline
        char    **env;          // Copia del entorno de variables del sistema
        int     exit_status;    // Código de salida del último comando ejecutado ($?)
        int     last_exit_st;   // Estado de salida anterior para expansión de $?
        t_token *token;         // Lista enlazada de tokens
        t_cmd   *cmd_lst;       // Lista enlazada de comandos para ejecución
    } t_shell;
    ```
*   `t_token`: Representa una unidad léxica de la línea de comandos.
    ```c
    typedef struct s_token
    {
        char            *tkn;    // Cadena de texto del token (ej. "ls", "|")
        int             type;    // Tipo de token (WORD, PI, LR1, RR1, etc.)
        bool            join;    // Indica si debe unirse al siguiente (ej. cat"file")
        bool            expand;  // Indica si contiene variables a expandir (ej. "$USER")
        struct s_token  *next;
    } t_token;
    ```
*   `t_cmd`: Representa un comando completo con sus argumentos y redirecciones.
    ```c
    typedef struct s_cmd
    {
        char    **args;       // Array de argumentos (ej. {"ls", "-l", NULL})
        char    *infile;      // Archivo para redirección de entrada (<)
        char    *delimiter;   // Delimitador para here-document (<<)
        char    *outfile;     // Archivo para redirección de salida (>, >>)
        bool    append;       // true si es >>, false si es >
        bool    hd;           // true si hay here-document
        bool    is_btn;       // true si el comando es un built-in
        int     exit_status;  // Estado de salida del comando (interno)
        struct s_cmd *next;   // Siguiente comando en una tubería
    } t_cmd;
    ```
*   `g_signal_flag`: Variable global crucial para el manejo de señales, indicando el contexto actual de la *shell* (`0`: prompt, `1`: ejecutando comando, `2`: leyendo here-doc).

### II. Flujo de Procesamiento y Ejecución

La *shell* opera en un ciclo continuo (REPL: Read-Eval-Print Loop) que procesa la entrada del usuario en varias etapas:

#### A. Lectura de Input y Señales
*   **`ft_read_input`**: Lee la línea de comandos usando la librería `readline()`, que proporciona historial y edición de línea.
*   **`ft_setup_signals`**: Configura los manejadores de señales (`signal()`) al inicio de cada ciclo de lectura.
*   **`ft_handle_sigint`**: Es el manejador para `Ctrl+C` (`SIGINT`). Su comportamiento se adapta gracias a `g_signal_flag`:
    *   En el prompt (`g_signal_flag = 0`): limpia la línea de `readline` y actualiza `$?` a `130`.
    *   Ejecutando un comando externo (`g_signal_flag = 1`): permite que el proceso hijo termine y actualiza `$?` a `130`.
    *   Leyendo un `here-doc` (`g_signal_flag = 2`): interrumpe el `here-doc` y **termina la minishell completamente** con `exit(130)`, replicando el comportamiento de Bash.
*   `Ctrl+D` (`EOF`): En línea vacía, la *shell* sale. En línea con texto, `readline` envía el texto sin `\n`, y la *shell* lo procesa como un comando normal.

#### B. Tokenización
*   **`ft_tokenize`**: Divide la línea de entrada (`shell->input`) en unidades léxicas (`t_token`s). Ignora espacios en blanco y reconoce palabras, comillas, pipes y operadores de redirección.

#### C. Expansión de Variables
*   **`ft_find_dollar` / `ft_expand_var`**: Recorre los tokens y expande las variables de entorno (`$VAR`) y la variable especial `$?` (usando `shell->last_exit_st`), sustituyendo sus valores en la cadena del token. Las comillas simples (`'`) suprimen la expansión.
*   **`ft_dequotize`**: Elimina las comillas (`'` y `"`) de los tokens después de la expansión.

#### D. Construcción de Comandos (Parsing)
*   **`ft_get_commands`**: Transforma la lista de `t_token`s (ya expandidos y sin comillas) en una lista estructurada de comandos (`t_cmd`) listos para ejecución.
*   **`ft_process_token`**: Despacha el procesamiento de cada token, agrupando argumentos, redirecciones y creando nuevos `t_cmd`s para cada comando en una tubería. Realiza comprobaciones de sintaxis básicas.
*   **`ft_fill_cmd`**: Rellena el array `args` de un `t_cmd` con los tokens de tipo `WORD`. Utiliza `ft_count_args` para pre-calcular la memoria necesaria y marca si el comando es un *built-in*.

#### E. Manejo de Redirecciones
Gestionado en dos fases clave:
1.  **Fase de Parsing (`ft_process_redir` y `ft_process_xxx`):** Ocurre durante la construcción de comandos. Identifica el tipo de redirección (`<`, `<<`, `>`, `>>`), extrae el nombre del archivo o delimitador, y lo almacena en `t_cmd`. Para `>` y `>>`, el archivo **se abre y se trunca/crea/añade en este momento**, detectando errores de permiso y actualizando `shell->exit_status`.
2.  **Fase de Ejecución (`ft_redirections` y `ft_redir_xxx`):** Ocurre en el proceso hijo, justo antes de `execve()`.
    *   **Prioridad:** Aplica las redirecciones en el orden correcto: `here-doc` (`<<`) > entrada de archivo (`<`) > salida a archivo (`>`/`>>`).
    *   Utiliza `dup2()` para redirigir `STDIN_FILENO` (0) y `STDOUT_FILENO` (1) a los archivos o pipes correspondientes.
    *   `ft_redir_heredoc`: Lee la entrada interactiva del `here-doc`, expande variables (si no está entrecomillado el delimitador), y la canaliza a un pipe temporal que se convierte en `STDIN` del comando.

#### F. Ejecución de Comandos
Orquestada por `ft_exec_commands` [4]:
1.  **Built-ins únicos:** Si el comando es un *built-in* y no está en una tubería, se ejecuta directamente en la *shell* padre (`exec_builtins`) para que sus efectos (`cd`, `export`) persistan.
2.  **Comandos Externos o Built-ins en Pipes:**
    *   `ft_exec_single_cmd` [4]: Crea un `pipe()` si hay tuberías, luego usa `fork()` para crear un proceso hijo.
    *   **`child_process`** [4]: En el proceso hijo, configura las redirecciones y pipes con `dup2()`, cierra descriptores de archivo innecesarios, y luego:
        *   Si es un *built-in* (en un pipe), lo ejecuta internamente (`exec_builtins`) y el hijo `exit()`.
        *   Si es un comando externo, llama a `execute_command` para buscarlo y ejecutarlo.
    *   **`execute_command`** [4]:
        *   Maneja casos especiales: si el comando es `""` (expansión vacía), `exit(0)`. Si `PATH` no está definido, `exit(127)`.
        *   Usa `ft_path` para construir la ruta completa del ejecutable (`/bin/ls`) buscando en `PATH`.
        *   Finalmente, llama a `execve(full_path, cmd->args, shell->env)`. Si `execve` tiene éxito, **no retorna** (el proceso hijo se transforma en el nuevo programa). Si falla, regresa y el código posterior maneja el error.
    *   **`parent_process`** [4]: En la *shell* padre, cierra los extremos de los pipes no utilizados y actualiza el estado de `g_signal_flag`.
    *   **`ft_wait_all_processes`** [4]: Espera a que todos los procesos hijos de una tubería terminen (`waitpid()`) y actualiza `shell->exit_status` con el código del último comando.

### III. Gestión de Memoria

*   **Valgrind-Clean:** El proyecto busca una gestión de memoria impecable, con cero fugas definitivas o indirectas.
*   **`ft_cleanup_shell`**: Libera la memoria utilizada en cada ciclo (input, tokens, comandos).
*   **`ft_clean`**: Realiza la limpieza final al terminar la *shell* (entorno, estructura `t_shell`).
*   Uso consistente de `malloc`, `free`, y `ft_calloc` para inicializar memoria y evitar errores de valores no inicializados.

### IV. Built-ins y Variables de Entorno

*   **`cd`**: Cambia el directorio de trabajo, actualizando `PWD` y `OLDPWD` en el entorno de la *shell*. Maneja `cd -` correctamente.
*   **`export`**: Añade o modifica variables de entorno en `shell->env` y las marca como exportables a procesos hijos.
*   **`SHLVL`**: La *shell* gestiona la variable `SHLVL`, incrementándola al inicio (`ft_shellevel`) para reflejar el nivel de anidamiento de *shells*.
*   **`PWD` y `OLDPWD`**: Se mantienen actualizadas con `getcwd()` después de cada `cd`, siguiendo el formato estándar (sin barra final, excepto para `/`).

### V. Códigos de Salida y Manejo de Errores

*   El `shell->exit_status` (que representa `$?`) siempre se mantiene en el rango **0 a 255** (aplicando `% 256`).
*   **`0`**: Éxito.
*   **`1` a `125`**: Fallos específicos del programa o *built-in*.
*   **`126`**: Comando encontrado, pero no ejecutable (ej. permiso denegado).
*   **`127`**: Comando no encontrado.
*   **`128 + N`**: Terminado por la señal `N` (ej. `130` para `SIGINT`).
*   **`258`**: Error de sintaxis (comportamiento de Bash).
*   **`perror()`**: Utilizado para imprimir mensajes de error del sistema localizados (ej. "Permiso denegado"), construyendo prefijos descriptivos que incluyen el comando o archivo erróneo.

---

## **4. Bonus (Planificado/En Desarrollo)**

*   **Operadores Lógicos (`&&` y `||`):** Ejecución condicional de comandos.
*   **Paréntesis para Prioridades (`()`):** Permite agrupar comandos y ejecutarlos en un subshell, aislando los cambios de entorno.
*   **Wildcards (`*`, `?`, `[]`):** Expansión de patrones de nombres de archivo (globbing) antes de la ejecución del comando.

---

## **5. Cómo Empezar**

### Prerrequisitos

*   Un compilador de C (ej. `gcc`).
*   La librería `readline` (generalmente instalada por defecto o a través del gestor de paquetes de tu sistema).
*   Tu `libft` (una librería personal de funciones básicas para el proyecto 42).

### Construir el Proyecto

Navega al directorio raíz del proyecto y ejecuta `make`:

```bash
git clone git@github.com:elWare/ware_repository.git minishell
cd minishell
make
```

### Ejecutar Minishell

```bash
./minishell
```

---

## **6. Uso y Ejemplos**

```bash
minishell$ ls -l
minishell$ echo "Hola, $USER! El último comando salió con $?."
minishell$ cat < infile.txt > outfile.txt
minishell$ grep "patron" infile.txt | sort | uniq >> results.txt
minishell$ cd /tmp
minishell$ export MY_VAR="Minishell_Rocks"
minishell$ env | grep MY_VAR
minishell$ exit 42
```

---

## **7. Testing y Depuración**

### Tester Automático

Se incluye un *script* `tester` para validar la funcionalidad del *shell* contra el comportamiento de Bash:

```bash
./tester [builtins|pipes|redirects|extras|wildcards|bonus]
```
*   `✅`: Test superado.
*   `❌`: Test fallido.

### Depuración con Valgrind

Para detectar problemas de memoria (fugas, accesos a memoria no inicializada, etc.), utiliza `Valgrind` (compilando con la bandera `-g`):

```bash
make re
valgrind --leak-check=full --show-leak-kinds=all ./minishell
```

---

## **8. Agradecimientos y Contacto**

Este proyecto es parte del currículo de la [École 42](https://www.42.fr/es/escuela/escuela-42/).

## ✍️ Autor
Nombre: Juan Jesús Márquez
Perfil GitHub: https://github.com/elWare
42 Login: https://profile-v3.intra.42.fr/users/jumarque

