# 🚀 Mi Viaje en C++: Proyectos Cpp en 42 🚀
![Cpp Banner](https://img.shields.io/badge/Project-Cpp-blueviolet)
![Language](https://img.shields.io/badge/Language-C-blue)
![Norme](https://img.shields.io/badge/Norme-42-lightgreen)
![Status](https://img.shields.io/badge/Status-In_progress-orange)
![License](https://img.shields.io/badge/License-MIT-lightgray)

Este repositorio documenta y contiene una colección de proyectos y ejercicios realizados como parte de mi formación en la prestigiosa escuela 42. La serie de ejercicios se enfoca en la introducción y consolidación de los principios fundamentales de la Programación Orientada a Objetos (POO) en C++, con un énfasis estricto en el estándar **C++98** y las buenas prácticas de codificación impuestas por la escuela.

Cada proyecto está diseñado para desafiar y profundizar la comprensión de conceptos específicos de C++, desde la manipulación básica de argumentos de línea de comandos hasta el diseño de clases complejas con miembros estáticos y gestión de colecciones.

---

## 📚 Tabla de Contenidos

1.  [Filosofía de 42 C++](#filosofía-de-42-c)
2.  [Proyectos Implementados](#proyectos-implementados)
    *   [Módulo 00, ex00: megaphone](#módulo-00-ex00-megaphone)
    *   [Módulo 00, ex01: My Awesome PhoneBook](#módulo-0001-ex01-my-awesome-phonebook)
    *   [Módulo 00, ex02: Account Class](#módulo-0001-ex02-account-class)
3.  [Compilación y Ejecución](#compilación-y-ejecución)
4.  [Herramientas de Testing](#herramientas-de-testing)
5.  [Autor](#autor)

---

## 🎓 Filosofía de 42 C++

En 42, el desarrollo en C++ se rige por una serie de principios estrictos que buscan fomentar la disciplina, la eficiencia y una comprensión profunda del lenguaje, especialmente en sus fundamentos:

*   **Estándar C++98**: Todos los proyectos se compilan obligatoriamente bajo el estándar **C++98**. Esto implica abstenerse de utilizar características introducidas en versiones posteriores (C++11, C++14, etc.), lo que nos fuerza a dominar las bases del lenguaje y sus herramientas tradicionales (ej. `std::stringstream` en lugar de `std::stoi`).
*   **Banderas de Compilación Estrictas (`CXXFLAGS`)**:
    *   `-Wall`: Habilita la mayoría de las advertencias razonables del compilador.
    *   `-Werror`: **Convierte todas las advertencias en errores**. Si hay un solo *warning*, el programa no compila. Esto exige un código impecable y sin ambigüedades.
    *   `-Wextra`: Habilita un conjunto adicional de advertencias para una mayor rigurosidad.
    *   `-std=c++98`: Fuerza la compatibilidad con el estándar C++98.
    *   `-g`: Incluye información de depuración para usar con herramientas como `gdb`, esencial para la depuración de errores.
*   **Programación Orientada a Objetos (POO)**: Un pilar fundamental. Se exige una implementación rigurosa de la encapsulación (miembros `private`/`public`), constructores, destructores, herencia y polimorfismo.
*   **Organización del Código**: Se sigue la convención de dividir la declaración de clases y funciones en archivos de cabecera (`.hpp`) y sus implementaciones en archivos fuente (`.cpp`).
*   **Makefiles**: La obligatoriedad de utilizar `Makefiles` para automatizar todo el proceso de compilación, limpieza (`clean`, `fclean`) y reconstrucción (`re`) del proyecto. Esto es vital para la evaluación automática por la moulinette.

---

## 🎯 Proyectos Implementados

A continuación, se detallan los proyectos de C++ que he desarrollado, cada uno ubicado en su propio subdirectorio (`ex00/`, `ex01/`, `ex02/`).

### Módulo 00, ex00: megaphone

Este es uno de los primeros ejercicios de C++ y sirve como una introducción a la manipulación de argumentos de línea de comandos y el procesamiento básico de cadenas de caracteres.

*   **Objetivo**: El programa `megaphone` debe tomar argumentos de la línea de comandos, convertirlos a mayúsculas y mostrarlos en la salida estándar. Si no se proporcionan argumentos, debe imprimir un mensaje predefinido.
*   **Conceptos Clave Aplicados**:
    *   Función `main(int argc, char **argv)`: Acceso y comprensión de los argumentos pasados al programa.
    *   `std::cout`: Uso de la salida estándar para imprimir mensajes.
    *   `<cctype>`: Aplicación de la función `std::toupper()` para la conversión de caracteres a mayúsculas.
    *   `static_cast<char>`: Realización de conversiones explícitas de tipo para asegurar la compatibilidad con `std::toupper()`.
    *   Manejo de cadenas de caracteres al estilo C (`char*`) y punteros.
*   **Ubicación**: `ex00/`
*   **Cómo Compilar**: `make -C ex00`
*   **Cómo Ejecutar**:
    ```bash
    ./ex00/megaphone                            # Sin argumentos
    ./ex00/megaphone "hello world"              # Un argumento
    ./ex00/megaphone "this" "is" "a" "test"     # Múltiples argumentos
    ```
*   **Ejemplo de Salida**:
    ```
    $> ./ex00/megaphone
    * LOUD AND UNBEARABLE FEEDBACK NOISE *
    $> ./ex00/megaphone "hello world"
    HELLO WORLD 
    $> ./ex00/megaphone "this" "is" "a" "test"
    THIS IS A TEST 
    ```

### Módulo 00/01, ex01: My Awesome PhoneBook

Este proyecto consiste en construir una aplicación interactiva de agenda telefónica, haciendo un uso intensivo de clases, colecciones y validación de entrada/salida.

*   **Objetivo**: Desarrollar una aplicación de consola que funcione como una agenda telefónica simple. Debe permitir añadir, buscar y visualizar contactos, con un límite de 8 contactos y una lógica de reemplazo para el contacto más antiguo cuando la agenda está llena.
*   **Conceptos Clave Aplicados**:
    *   **Diseño de Clases Avanzado**: Implementación de dos clases interrelacionadas: `PhoneBook` (la agenda) y `Contact` (un contacto individual).
    *   **Composición de Clases**: `PhoneBook` contiene un arreglo estático de objetos `Contact`, mostrando cómo las clases pueden interactuar entre sí.
    *   **Arrays Estáticos**: Gestión de colecciones de objetos en memoria estática, sin el uso de asignación dinámica (`new`/`delete`) ni contenedores de la STL como `std::vector` (debido a las restricciones del proyecto).
    *   **Lógica de Búfer Circular**: Implementación de un mecanismo para mantener un máximo de 8 contactos, sobrescribiendo el contacto "más antiguo" cuando se añade uno nuevo.
    *   **Entrada del Usuario Robusta y Validada**:
        *   `std::getline()`: Lectura de líneas completas de texto para los comandos y los datos del contacto.
        *   Validación de campos no vacíos para los detalles del contacto.
        *   Validación de entradas numéricas para seleccionar índices (utilizando `std::stringstream` para cumplir con C++98).
        *   Normalización de comandos (`ADD`, `SEARCH`, `EXIT`) para hacerlos insensibles a mayúsculas y espacios.
    *   **Salida Formateada**: Uso de `<iomanip>` (`std::setw()`, `std::right`) para presentar la lista de contactos en un formato de tabla ordenado y alineado, con truncamiento de cadenas largas.
*   **Ubicación**: `ex01/`
*   **Cómo Compilar**: `make -C ex01`
*   **Cómo Ejecutar**: `./ex01/phonebook`
*   **Ejemplo de Interacción**:
    ```
    $> ./ex01/phonebook
    Bienvenido a My Awesome PhoneBook!
    Introduce un comando (ADD, SEARCH, EXIT): ADD
    Primer Nombre: John
    Apellido: Doe
    Apodo: Johnny
    Número de teléfono: 123-456-7890
    Secreto más oscuro: Le teme a los payasos
    Contacto añadido correctamente.

    Introduce un comando (ADD, SEARCH, EXIT): SEARCH
         Índice|PrimerNombre|  Apellido|    Apodo
    ----------|------------|----------|----------
             0|        John|       Doe|    Johnny

    Introduce el índice del contacto a ver (o cualquier letra para cancelar): 0
    --- Detalles Completos del Contacto ---
    Primer Nombre:    John
    Apellido:         Doe
    Apodo:            Johnny
    Número Teléfono:  123-456-7890
    Secreto Oscuro:   Le teme a los payasos
    -------------------------------------

    Introduce un comando (ADD, SEARCH, EXIT): EXIT
    Saliendo de la agenda. ¡Adiós!
    $>
    ```

### Módulo 00/02, ex02: Account Class

Este proyecto es una inmersión profunda en el uso de miembros estáticos para gestionar el estado global y registrar operaciones detalladas en un sistema de objetos.

*   **Objetivo**: Implementar una clase `Account` que simule una cuenta bancaria. Además de las operaciones individuales (depósito, retiro, consulta de saldo), la clase debe mantener un registro global y detallado del estado de *todas* las cuentas (número total de cuentas, monto total, depósitos/retiros totales) y loguear todas las operaciones con marcas de tiempo.
*   **Conceptos Clave Aplicados**:
    *   **Miembros Estáticos (`static`)**: Implementación de variables estáticas (`_nbAccounts`, `_totalAmount`, `_totalNbDeposits`, `_totalNbWithdrawals`) y métodos estáticos (`getNbAccounts()`, `displayAccountsInfos()`, `_displayTimestamp()`) que pertenecen a la clase y no a objetos individuales. Son esenciales para mantener un estado global y estadísticas agregadas.
    *   **Gestión de Estado Global**: Cómo los métodos de instancia (`makeDeposit()`, `makeWithdrawal()`) actualizan los miembros estáticos globales, y cómo los métodos estáticos consultan y muestran esta información global.
    *   **Generación de Timestamps**: Uso de la librería `<ctime>` y manipuladores de flujo de `<iomanip>` para generar y formatear marcas de tiempo precisas en los logs de operaciones.
    *   **Constructores y Destructores con Logueo**: Registro explícito de la creación y cierre de cada cuenta mediante mensajes de log con timestamp.
    *   **Validación de Operaciones**: Implementación de lógica para manejar retiros que pueden ser rechazados si el saldo es insuficiente, y su correcto reflejo en los logs y contadores.
    *   **`const` Métodos**: Uso consistente de `const` en métodos como `checkAmount()` y `displayStatus()` para indicar que no modifican el estado del objeto.
    *   **Constructor Privado**: Demostrar el control de la instanciación de objetos (`Account(void)` privado).
*   **Ubicación**: `ex02/`
*   **Cómo Compilar**: `make -C ex02`
*   **Cómo Ejecutar**: `./ex02/accounts`
*   **Ejemplo de Salida (Extracto, los timestamps variarán)**:
    ```
    $> ./ex02/accounts
    [YYYYMMDD_HHMMSS] accounts:0;total:0;deposits:0;withdrawals:0
    [YYYYMMDD_HHMMSS] index:0;amount:42;created
    [YYYYMMDD_HHMMSS] index:1;amount:54;created
    [YYYYMMMM_HHMMSS] index:2;amount:957;created
    ... (y así sucesivamente por 8 cuentas) ...
    [YYYYMMDD_HHMMSS] accounts:8;total:20049;deposits:0;withdrawals:0
    [YYYYMMDD_HHMMSS] index:0;amount:42;deposits:0;withdrawals:0
    ... (estados individuales de 8 cuentas) ...
    [YYYYMMDD_HHMMSS] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
    ... (depósitos para 8 cuentas) ...
    [YYYYMMDD_HHMMSS] accounts:8;total:21524;deposits:8;withdrawals:0
    ... (estados individuales después de depósitos) ...
    [YYYYMMDD_HHMMSS] index:0;p_amount:47;withdrawal:refused
    [YYYYMMDD_HHMMSS] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
    ... (retiros para 8 cuentas, incluyendo rechazos) ...
    [YYYYMMDD_HHMMSS] accounts:8;total:12442;deposits:8;withdrawals:6
    ... (estados individuales después de retiros) ...
    [YYYYMMDD_HHMMSS] index:0;amount:47;closed
    ... (8 cuentas cerradas) ...
    ```

---

## 🛠️ Compilación y Ejecución

Cada proyecto está encapsulado en su propio directorio y utiliza un `Makefile` específico para su construcción. Sigue estos pasos para interactuar con cualquiera de los proyectos:

1.  **Navega al directorio del proyecto**:
    ```bash
    cd <nombre_del_directorio_del_proyecto> # Ejemplo: cd ex00
    ```
2.  **Compilar (construir el ejecutable)**:
    *   Este comando utiliza el `Makefile` para compilar los archivos fuente (`.cpp`) y enlazarlos en un ejecutable.
    ```bash
    make
    ```
    *   Para asegurar una compilación completamente limpia y reconstruir todo (muy útil después de muchos cambios o si encuentras errores extraños):
    ```bash
    make re
    ```
3.  **Ejecutar el programa**:
    *   Una vez compilado, el ejecutable estará en el directorio actual.
    ```bash
    ./<nombre_del_ejecutable> # Ejemplo: ./megaphone o ./phonebook o ./accounts
    ```
4.  **Limpiar archivos objeto (`.o`)**:
    *   Elimina los archivos intermedios generados por el compilador.
    ```bash
    make clean
    ```
5.  **Limpiar todos los archivos generados (`.o` y ejecutable)**:
    *   Deja el directorio del proyecto en un estado "prístino", como si nunca se hubiera compilado.
    ```bash
    make fclean
    ```

---

## 🧪 Herramientas de Testing

Para cada proyecto, se han desarrollado scripts de shell (`.sh`) auxiliares para automatizar las pruebas y verificar que la implementación cumple con los requisitos y produce la salida esperada. Estos scripts emulan el tipo de pruebas automatizadas que se encuentran en el entorno de la moulinette de 42.

*   **Ubicación de los Testers**: Los scripts de testing se encuentran en el directorio raíz de este repositorio a excepción del test_ex00.sh (ej. `test_ex00.sh`, `test_ex01.sh`, `test_ex02.sh`).
*   **Cómo Usar un Tester**:
    1.  Asegúrate de que el script tenga permisos de ejecución:
        ```bash
        chmod +x <nombre_del_script_tester>.sh # Ejemplo: chmod +x test_ex00.sh
        ```
    2.  Ejecuta el script desde el directorio raíz del repositorio (no desde el directorio del proyecto):
        ```bash
        ./<nombre_del_script_tester>.sh # Ejemplo: ./test_ex00.sh
        ```
*   **Funcionamiento General**:
    *   Cada script primero realiza un `make re` en el directorio del proyecto correspondiente para asegurar una compilación limpia de la última versión del código.
    *   Luego, ejecuta el programa con diferentes argumentos de línea de comandos o simulando la entrada interactiva del usuario (mediante `echo` y pipes `|`).
    *   Captura la salida estándar (`std::cout`) del programa.
    *   Procesa la salida capturada (ej. eliminando timestamps variables en el caso de `ex02`).
    *   Compara la salida procesada con una salida esperada (un log de referencia) utilizando `diff`.
    *   Reporta el éxito o el fallo de cada prueba, mostrando las diferencias exactas si las hay, lo que es crucial para la depuración.

---

## ✍️ Autor

*   **Nombre**: Juan Jesús Márquez
*   **Perfil GitHub**: https://github.com/elWare
*   **42 Login**: https://profile-v3.intra.42.fr/users/jumarque

