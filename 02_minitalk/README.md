¡Absolutamente! Aquí tienes el `README.md` para tu proyecto Minitalk, actualizado con un menú de navegación y una sección final con tus enlaces personales.

Recuerda reemplazar `<TU_GITHUB_USERNAME>`, `<TU_42_PROFILE_URL>` y `<TU_NOMBRE_COMPLETO>` con tu información real.

---

# Minitalk

### Comunicación entre Procesos a través de Señales (42 Project)

---

## 📝 **Tabla de Contenidos**

*   [🚀 Introducción](#-introducción)
*   [🎯 Conceptos Centrales y Objetivos](#-conceptos-centrales-y-objetivos)
*   [⚙️ Parte Obligatoria: El Core de Minitalk](#️-parte-obligatoria-el-core-de-minitalk)
    *   [1. El Servidor (`server.c`)](#1-el-servidor-serverc)
    *   [2. El Cliente (`client.c`)](#2-el-cliente-clientc)
*   [🌟 Parte Bonus: Comunicación Fiable y Universal](#-parte-bonus-comunicación-fiable-y-universal)
    *   [1. Comunicación Bidireccional (Acknowledged Delivery)](#1-comunicación-bidireccional-acknowledged-delivery)
    *   [2. Soporte Unicode (UTF-8)](#2-soporte-unicode-utf-8)
*   [🔧 Uso](#-uso)
    *   [1. Compilación](#1-compilación)
    *   [2. Iniciar el Servidor](#2-iniciar-el-servidor)
    *   [3. Ejecutar el Cliente (Parte Obligatoria)](#3-ejecutar-el-cliente-parte-obligatoria)
    *   [4. Ejecutar el Cliente (Parte Bonus con ACK y UTF-8)](#4-ejecutar-el-cliente-parte-bonus-con-ack-y-utf-8)
*   [🧠 Lo que Aprendes con Minitalk](#-lo-que-aprendes-con-minitalk)
*   [🤝 Contacto](#-contacto)

---

## 🚀 **Introducción**

**Minitalk** es un proyecto fundamental de la Escuela 42 que explora la comunicación interprocesos (IPC) utilizando uno de los mecanismos más primitivos y potentes del sistema operativo: **las señales (signals)**.

El objetivo es construir un sistema cliente-servidor donde el cliente puede enviar una cadena de texto (string) al servidor, y el servidor es capaz de recibir y reconstruir ese mensaje. La particularidad y el reto de Minitalk es que **toda la comunicación se realiza exclusivamente a través de las señales `SIGUSR1` y `SIGUSR2`**, sin usar pipes, sockets, o archivos.

---

## 🎯 **Conceptos Centrales y Objetivos**

Minitalk te sumerge en el mundo de la programación de sistemas de bajo nivel, obligándote a dominar:

*   **IPC por Señales:** Comprender cómo se envían y reciben señales entre procesos.
*   **Manipulación de Bits (Bitwise):** Codificar caracteres en secuencias de bits y reconstruirlos.
*   **Gestión de Procesos:** Utilizar PIDs (Process IDs) para dirigir la comunicación.
*   **Programación Asíncrona:** Manejar eventos que ocurren en momentos impredecibles (las señales).
*   **Fiabilidad y Sincronización (Bonus):** Introducir mecanismos para asegurar la entrega y manejar caracteres multi-byte.

---

## ⚙️ **Parte Obligatoria: El Core de Minitalk**

La parte obligatoria establece la base: enviar un mensaje unidireccionalmente del cliente al servidor.

### 1. **El Servidor (`server.c`)**

El servidor es un proceso que se ejecuta continuamente, esperando recibir bits (en forma de señales) del cliente.

*   **Funcionalidad:**
    *   Imprime su propio **PID (Process ID)** al inicio. Este PID es vital, ya que el cliente lo necesita para saber a quién enviar las señales.
    *   Configura un **manejador de señales** para `SIGUSR1` y `SIGUSR2` utilizando `sigaction()`.
        *   `SIGUSR1` se interpreta como un bit `0`.
        *   `SIGUSR2` se interpreta como un bit `1`.
    *   Mantiene **variables estáticas** dentro del manejador de señales para reconstruir los caracteres:
        *   Un `char` temporal para el carácter actual.
        *   Un contador de bits recibidos (de `0` a `7`).
    *   Cada vez que recibe 8 bits, los combina para formar un carácter, lo imprime y resetea el contador para el siguiente carácter.
    *   Permanece en un bucle infinito, generalmente usando `pause()` para ceder el control de la CPU mientras espera señales.

*   **Llamadas al Sistema/Funciones Clave:**
    *   `getpid()`: Para obtener el PID del servidor.
    *   `sigaction()`: Para configurar un manejador de señales robusto.
    *   `pause()`: Para suspender el proceso hasta que llegue una señal.
    *   `write()`: Para imprimir el mensaje recibido.

### 2. **El Cliente (`client.c`)**

El cliente toma el mensaje del usuario y lo descompone en bits para enviarlo al servidor.

*   **Funcionalidad:**
    *   Recibe dos argumentos: el **PID del servidor** y la **cadena de texto** a enviar.
    *   Itera a través de cada carácter de la cadena de texto.
    *   Para cada carácter, itera a través de sus **8 bits** (del más significativo al menos significativo, o viceversa, la consistencia es clave).
    *   Envía `SIGUSR1` para un bit `0` y `SIGUSR2` para un bit `1` al PID del servidor usando `kill()`.
    *   Introduce un pequeño **retraso (`usleep()`)** entre el envío de cada bit para evitar que el sistema operativo se "ahogue" con demasiadas señales en muy poco tiempo, lo que podría llevar a la pérdida de señales.

*   **Llamadas al Sistema/Funciones Clave:**
    *   `atoi()`: Para convertir el PID del servidor (string) a entero.
    *   `kill()`: Para enviar señales a un proceso específico.
    *   `usleep()`: Para introducir el retraso necesario.

---

## 🌟 **Parte Bonus: Comunicación Fiable y Universal**

El bonus transforma Minitalk en un sistema de comunicación más robusto y compatible con estándares modernos.

### 1. **Comunicación Bidireccional (Acknowledged Delivery)**

El mayor cambio es la introducción de un mecanismo de "acuse de recibo" (acknowledgment o ACK).

*   **Rol del Servidor:**
    *   El manejador de señales del servidor debe usar la bandera `SA_SIGINFO` en `sigaction()`: `sa.sa_flags = SA_SIGINFO;`.
    *   Esto permite que el manejador reciba una estructura `siginfo_t* info` como argumento. **Crucialmente, `info->si_pid` contiene el PID del cliente que envió la señal.**
    *   El servidor almacena el `client_pid` y, después de recibir un carácter completo (o el mensaje entero, dependiendo de la implementación), envía una señal (`SIGUSR1` o `SIGUSR2`) de vuelta al cliente para confirmar la recepción: `kill(client_pid, SIGUSR1);`

*   **Rol del Cliente:**
    *   El cliente también debe configurar su propio manejador de señales para recibir los ACKs del servidor.
    *   Después de enviar los bits de un carácter (o de un mensaje), el cliente espera un ACK del servidor antes de proceder a enviar el siguiente carácter/mensaje. Si no recibe el ACK en un tiempo razonable, podría reintentar o reportar un error.
    *   Esto mejora drásticamente la fiabilidad de la comunicación.

### 2. **Soporte Unicode (UTF-8)**

El proyecto se extiende para soportar caracteres que no encajan en 8 bits (ASCII), como los caracteres UTF-8.

*   **Rol del Cliente:**
    *   Debe ser capaz de leer la cadena de entrada como UTF-8.
    *   Debe descomponer correctamente los caracteres UTF-8 en su secuencia de bytes (1, 2, 3 o 4 bytes) y luego cada uno de esos bytes en sus bits.
    *   La lógica de envío de bits se aplica a cada byte de la secuencia UTF-8.

*   **Rol del Servidor:**
    *   El servidor ya no puede asumir que 8 bits = 1 carácter.
    *   Necesita una lógica de reconstrucción más sofisticada:
        *   Recibe el primer byte de una secuencia.
        *   Examina los bits de este primer byte para determinar **cuántos bytes adicionales** debe esperar para completar el carácter Unicode (ej., `0xxxxxxx` es 1 byte, `110xxxxx` es 2 bytes, `1110xxxx` es 3 bytes, etc.).
        *   Acumula los bits de los bytes subsiguientes.
        *   Una vez que se han recibido todos los bytes que componen el carácter Unicode, lo imprime y resetea su estado para el siguiente carácter.
    *   Puede necesitar un `unsigned int` para almacenar el carácter completo, ya que `char` podría no ser suficiente para todos los bytes de un carácter Unicode.

---

## 🔧 **Uso**

### 1. **Compilación**

Utiliza el `Makefile` proporcionado:

```bash
make
```

Esto generará dos ejecutables: `server` y `client`.

### 2. **Iniciar el Servidor**

Ejecuta el servidor en una terminal:

```bash
./server
```

El servidor imprimirá su PID, que necesitarás para el cliente.
Ejemplo de salida del servidor:
```
Server PID: 12345
```

### 3. **Ejecutar el Cliente (Parte Obligatoria)**

En otra terminal, ejecuta el cliente, pasando el PID del servidor y el mensaje:

```bash
./client <SERVER_PID> "¡Hola, Minitalk!"
```

**Ejemplo:**
```bash
./client 12345 "¡Hola desde el cliente!"
```

El servidor debería mostrar:
```
¡Hola desde el cliente!
```

### 4. **Ejecutar el Cliente (Parte Bonus con ACK y UTF-8)**

Si has implementado el bonus, el cliente esperará confirmación y podrá enviar caracteres UTF-8:

```bash
./client <SERVER_PID> "Mensaje con 🚀 emojis y caracteres como ñéúíó"
```

El cliente puede mostrar mensajes de confirmación o un progreso, y el servidor mostrará el mensaje completo.

---

## 🧠 **Lo que Aprendes con Minitalk**

Este proyecto es una inmersión profunda en:

*   **Manejo de Señales:** Desde la teoría básica hasta la implementación avanzada con `sigaction` y `siginfo_t`.
*   **Comunicación Interprocesos (IPC):** Una de las formas más básicas y fundamentales de IPC.
*   **Manipulación a Nivel de Bits:** Codificar y decodificar información bit a bit.
*   **Gestión de Estados:** Mantener el estado de la comunicación a través de variables estáticas y lógicas de secuencia.
*   **Fiabilidad y Control de Flujo:** Implementar ACKs y `usleep` para una comunicación más robusta.
*   **Codificaciones de Caracteres:** Entender cómo funciona UTF-8 a nivel de bytes.

---

## 🤝 **Contacto**

Si tienes alguna pregunta o sugerencia, no dudes en contactarme:

*   **Nombre:** Juan Jesús Marquez
*   **GitHub:** https://github.com/elWare
*   **42 Profile:** https://profile-v3.intra.42.fr/users/jumarque

---