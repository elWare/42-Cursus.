# 🌟 Modulo 03 - Proyecto Cpp Modulo 03:

## Descripción

Este proyecto se centra en la implementación y uso de clases heredadas y polimorfismo en C++98. Se trata principalmente del segundo ejercicio (EX03) donde cada clase representa una entidad con funciones específicas que simulan escenarios de juego.

El código está estructurado para incluir varias clases como `ClapTrap`, `ScavTrap`, `FragTrap` y `DiamondTrap`. Cada una tiene sus propias características y métodos, y todas heredan de la clase base `ClapTrap`.

## Estructura del Proyecto

- **main.cpp**: Archivo principal que crea instancias de las clases y prueba sus funcionalidades.
- **ClapTrap.hpp/.cpp**: Definición de la clase base `ClapTrap`.
- **ScavTrap.hpp/.cpp**: Definición de la clase `ScavTrap` que hereda de `ClapTrap`.
- **FragTrap.hpp/.cpp**: Definición de la clase `FragTrap` que también hereda de `ClapTrap`.
- **DiamondTrap.hpp/.cpp**: Definición de la clase `DiamondTrap`, que combina características de `ScavTrap` y `FragTrap`.

## Requisitos

Asegúrate de tener un compilador C++98 (como g++) instalado.

## Instalación

Para configurar este proyecto en tu máquina, sigue estos pasos:

2. Compila y ejecuta el programa:
   - Navega a la carpeta del proyecto.
   - Ejecuta `make` para compilar el código.

3. Para limpiar los archivos de compilación, usa:
   ```bash
   make clean
   ```
   
4. Si quieres eliminar tanto los objetos como el binario generado y luego limpiar:
   ```bash
   make fclean
   ```

5. Para volver a configurar y ejecutar la aplicación (compila, limpia y vuelve a compilar):
   ```bash
   make re
   ```

## Ejecución

Ejecuta el binario generado para ver los resultados del programa:
```bash
./diamond
```

### Estructura de Archivos:

- `Makefile`: Contiene las reglas necesarias para la compilación y limpieza.
- `main.cpp`, `ClapTrap.hpp/.cpp`, `ScavTrap.hpp/.cpp`, `FragTrap.hpp/.cpp`, `DiamondTrap.hpp/.cpp`: Cada archivo contiene la implementación de una clase o el código principal.

## Ejemplos

Aquí hay un ejemplo básico de cómo se utilizarían las clases en `main.cpp`:

```cpp
#include "DiamondTrap.hpp"

int main(){

	DiamondTrap Diamond("Damien"); // Crear una instancia de DiamondTrap

	// ... (pruebas adicionales)
}
```

## ✍️ Autor

*   **Nombre**: Juan Jesús Márquez
*   **Perfil GitHub**: https://github.com/elWare
*   **42 Login**: https://profile-v3.intra.42.fr/users/jumarque

