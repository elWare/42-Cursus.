¡Claro! Aquí tienes un `README.md` completo y profesional para tu proyecto NetPractice en GitHub, diseñado para un estudiante de 42.

---

# 🌐 NetPractice - Configuración de Redes en 42 Málaga

## ✨ Introducción

Este proyecto, `NetPractice`, es una pieza fundamental del currículo de 42 que busca cimentar una comprensión práctica y profunda de los conceptos básicos de redes IP. A través de la configuración de diversas topologías de red en un entorno simulado, el objetivo principal es establecer y verificar la conectividad entre diferentes nodos (hosts y routers) siguiendo unos requisitos específicos.

El desafío reside en asignar correctamente direcciones IP, máscaras de subred y configurar tablas de enrutamiento estático para garantizar que los paquetes de datos puedan viajar de un punto a otro de la red, superando los obstáculos y las restricciones de cada topología.

## 🎯 Objetivos del Proyecto

*   **Configuración de Direcciones IP:** Asignar direcciones IP y máscaras de subred adecuadas a las interfaces de hosts y routers.
*   **Segmentación de Redes (Subnetting):** Comprender y aplicar el concepto de máscara de subred (notación CIDR y decimal) para dividir una red principal en subredes más pequeñas y eficientes, evitando solapamientos.
*   **Enrutamiento Estático:** Configurar tablas de enrutamiento en los routers para dirigir el tráfico entre diferentes subredes y hacia la red externa (Internet).
*   **Configuración de Gateways:** Establecer las puertas de enlace (gateways) correctas para que los hosts y routers puedan comunicarse con redes remotas.
*   **Diagnóstico de Redes (Troubleshooting):** Identificar y resolver problemas de conectividad utilizando las herramientas proporcionadas por el simulador (similar a `ping` y `traceroute`).
*   **Manejo de Restricciones:** Adaptar la configuración a inmutabilidades y requisitos específicos de direcciones IP o máscaras de subred impuestas por el ejercicio.

## ⚙️ Conceptos Clave Aplicados

Durante el desarrollo de NetPractice, se aplicaron y consolidaron los siguientes conceptos:

*   **Direccionamiento IP (IPv4):** Identificación única de dispositivos.
    *   Parte de Red y Parte de Host.
    *   Direcciones IP Públicas vs. Privadas (Rangos Clase A, B, C).
*   **Máscaras de Subred:** Definición del tamaño y límite de una subred.
    *   Notación CIDR (`/X`) y su conversión a formato decimal (`255.255.255.0`).
*   **Direcciones Especiales:**
    *   **Network ID:** La primera dirección de una subred, representa la subred en sí.
    *   **Broadcast ID:** La última dirección de una subred, utilizada para enviar tráfico a todos los hosts de esa subred.
    *   **Rango de Hosts Utilizables:** Direcciones IP asignables a dispositivos reales.
*   **Routers:** Dispositivos de Capa 3 encargados de reenviar paquetes entre diferentes redes.
*   **Gateways (Puertas de Enlace):** La IP del router a la que un dispositivo envía el tráfico destinado a redes externas.
*   **Tablas de Enrutamiento:** Conjunto de reglas que un router utiliza para decidir el próximo salto de un paquete.
*   **Rutas Estáticas:** Entradas configuradas manualmente en la tabla de enrutamiento.
*   **Ruta por Defecto (`0.0.0.0/0` o `default`):** Ruta utilizada para cualquier destino no especificado en la tabla de enrutamiento.
*   **Resolución ARP:** (Implícita en la Capa 2 de la comunicación local).
*   **Switches (Capa 2):** Dispositivos que interconectan hosts dentro de la misma subred.

## 📂 Estructura del Proyecto

Este repositorio contendrá los archivos de configuración (`.json` o similar) de las diversas topologías de NetPractice que se han resuelto. Cada archivo corresponderá a una ronda o a una topología específica, reflejando el estado final de la configuración que permite alcanzar todos los objetivos de conectividad.

```
.
├── README.md
├── round_1_config.json       # Ejemplo de configuración para la Ronda 1
├── round_2_config.json       # Ejemplo de configuración para la Ronda 2
└── ...
```

## 🚀 Cómo usar y validar

1.  **Acceder a NetPractice:** Inicia sesión en la plataforma NetPractice de 42.
2.  **Cargar Topología:** Selecciona la topología correspondiente al archivo de configuración que deseas probar.
3.  **Importar Configuración:** Copia el contenido del archivo `.json` de este repositorio y pégalo en la sección de configuración de la topología en NetPractice.
4.  **Ejecutar Evaluación:** Haz clic en el botón "Evaluar" o "Validation Mode" para ejecutar las pruebas de conectividad.
5.  **Verificar Resultados:** El simulador mostrará un log detallado de cada intento de comunicación (forward y reverse way), indicando si el paquete llegó a su destino y si hubo errores o "loops detectados".

**Nota sobre "loop detected":** En ocasiones, el simulador de NetPractice puede reportar "loop detected" incluso cuando la conectividad se establece correctamente. Esto suele deberse a la forma en que el simulador interpreta el tráfico de control (como ARP) o la visibilidad de un router sobre su propio tráfico en un segmento de switch compartido. Siempre que el mensaje final sea `destination reached`, la configuración es funcional.

## 🐛 Desafíos y Lecciones Aprendidas

*   **Precisión al Milímetro:** La configuración de redes requiere una precisión absoluta. Un solo bit incorrecto en una máscara o una IP mal escrita puede romper toda la conectividad.
*   **Pensamiento Binario:** Entender la conversión entre CIDR, decimal y binario para el cálculo de subredes, Network ID y Broadcast ID es esencial.
*   **Enrutamiento Metódico:** Configurar rutas de forma sistemática, asegurándose de que cada router sabe cómo llegar a todas las redes que no están directamente conectadas a él, ya sea mediante rutas estáticas específicas o rutas por defecto.
*   **Debugging de Redes:** Desarrollar una metodología de depuración, analizando los logs de NetPractice paso a paso para identificar dónde se detiene o se desvía un paquete.
*   **Manejo de Restricciones:** Adaptarse a los requisitos específicos y las inmutabilidades de IPs o máscaras de subred, obligando a un diseño de red más cuidadoso y a veces a reorganizar subredes enteras.
*   **La Importancia de la Máscara:** Comprender que la máscara de subred es tan importante como la propia dirección IP para definir el ámbito de una red.

## ✍️ Autor

Nombre: Juan Jesús Márquez
Perfil GitHub: https://github.com/elWare
42 Login: https://profile-v3.intra.42.fr/users/jumarque
