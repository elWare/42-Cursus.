# 💻 Born2BeRoot - Administración de Sistemas en 42

Este repositorio contiene mi implementación del proyecto **Born2BeRoot** de la escuela 42. Este es un ejercicio fundamental de administración de sistemas cuyo objetivo principal es familiarizarse con la instalación, configuración y monitoreo de un servidor Linux (específicamente Debian), asegurando su seguridad y funcionalidad básica.

## 🌟 ¿Qué es Born2BeRoot?

Born2BeRoot es uno de los primeros proyectos en el currículo de 42 que te introduce al mundo de la **administración de sistemas Linux**. Es un "bautismo de fuego" que te obliga a salir de la zona de confort del desarrollo en C y sumergirte en la línea de comandos, la configuración de red, la gestión de usuarios, la seguridad SSH y la creación de scripts de monitoreo.

El objetivo es instalar y configurar una máquina virtual Debian, hardening el sistema y automatizando tareas de monitoreo.

## 🎯 Objetivos del Proyecto

Los objetivos principales de Born2BeRoot incluyen:

*   **Instalación de un servidor:** Instalar una distribución Debian en una máquina virtual.
*   **Configuración básica:** Configurar usuarios, permisos, red y servicios esenciales.
*   **Seguridad del sistema (Hardening):** Implementar medidas de seguridad, como la configuración de SSH con autenticación por clave y la gestión de la política de contraseñas.
*   **Monitoreo del sistema:** Desarrollar un script `monitoring.sh` para supervisar el estado del servidor.

## 🚀 Requisitos Clave y Funcionalidades

El proyecto Born2BeRoot, en su versión 3.4 [3], implica cumplir con una serie de requisitos de configuración y seguridad, y la creación de un script de monitoreo.

### El script `monitoring.sh` [3]

Uno de los componentes centrales del proyecto es un script sencillo llamado `monitoring.sh`, desarrollado en `bash` [3]. Este script está diseñado para:

*   Ser ejecutado cuando el servidor inicia.
*   Mostrar cierta información del sistema en *todos* los terminales cada 10 minutos (utilizando `wall`) [3]. El banner de `wall` es opcional y no deben ser visibles errores [3].

La información que el script `monitoring.sh` debe mostrar incluye [3]:

*   La arquitectura del sistema operativo y su versión de kernel.
*   El número de núcleos físicos.
*   El número de núcleos virtuales.
*   La memoria RAM disponible actualmente en el servidor y su porcentaje de uso.
*   La memoria disponible actualmente en el servidor y su utilización como un porcentaje.
*   El porcentaje actual de uso de los núcleos.
*   La fecha y hora del último reinicio.
*   Si LVM está activo o no.
*   El número de conexiones activas.
*   El número de usuarios del servidor.
*   La dirección IPv4 del servidor y su MAC (Media Access Control).
*   El número de comandos ejecutados con `sudo`.

## 🛠️ Tecnologías y Herramientas Utilizadas

*   **Linux Debian:** Sistema operativo base para la máquina virtual.
*   **Máquina Virtual (VM):** Generalmente VirtualBox o VMWare.
*   **Bash:** Lenguaje de scripting para `monitoring.sh` [3].
*   **Herramientas de línea de comandos:** `sudo`, `ssh`, `ufw`, `systemctl`, `crontab`, etc.

## 📚 Estructura del Repositorio

Aunque este proyecto es principalmente sobre la configuración de una VM, este repositorio contendrá:

*   `./README.md`: Este archivo.
*   `./monitoring.sh`: El script `bash` para monitorear el sistema [3].
*   `./documentation/`: Cualquier documentación adicional, notas o capturas de pantalla del proceso de configuración.
*   (Opcional) `./ansible/` o `./scripts/`: Si se utilizan herramientas de automatización para la configuración.

## 🚀 Instalación y Configuración (Guía General)

Para replicar este proyecto, necesitarás:

1.  **Software de Virtualización:** Instala VirtualBox o VMWare Workstation/Fusion.
2.  **Imagen ISO de Debian:** Descarga la imagen `netinst` o `minimal` de Debian.
3.  **Crear una VM:**
    *   Crea una nueva máquina virtual con al menos 20GB de disco, 2GB de RAM.
    *   Configura la tarjeta de red en modo "Bridge" o "NAT" según los requisitos específicos del ejercicio.
4.  **Instalar Debian:** Sigue el proceso de instalación de Debian, asegurando una instalación mínima sin entorno gráfico.
5.  **Configuración del sistema:**
    *   Configura la partición de disco siguiendo los requisitos (LVM, etc.).
    *   Configura el usuario `admin` con `sudo`.
    *   Configura SSH para permitir la conexión solo con clave pública.
    *   Aplica políticas de contraseñas robustas.
    *   Configura el firewall (`ufw` o `iptables`).
6.  **Desplegar `monitoring.sh`:** Coloca el script `monitoring.sh` en la VM, hazlo ejecutable y configura su ejecución automática al inicio y cada 10 minutos (usando `crontab` o un servicio `systemd`).

## 🧑‍💻 Autor

Si tienes alguna pregunta o sugerencia, no dudes en contactarme:

*   **Nombre:** Juan Jesús Marquez
*   **GitHub:** https://github.com/elWare
*   **42 Profile:** https://profile-v3.intra.42.fr/users/jumarque
