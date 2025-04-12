Sistema de Gestión de Tickets de Soporte Técnico

Este sistema operativo permite a los usuarios administrar los tickets de un soporte técnico. Los ususarios serán capaces de egistrar tickets, modificar su prioridad, visualizar la lista de tickets pendientes y procesar tickets según su urgencia.

Cómo compilar y Ejecutar
El sistema ha sido desarrollado en lenguaje C, puedes utilizar Visual Studio Code para ejecutar el código fácilmente (https://code.visualstudio.com). 
Necesitarás intalar una extensión de C/C++ como C/C++ Extension Pack de Microsoft.

Requisitos Previos:
Tener instalado Visual Studio Code junto su extensión de C/C++.
Tener instalado un compilador de gcc. Se recomienda descargar MinGW (en Windows: https://sourceforge.net/projects/mingw/).

Pasos Para Compilar:
Comienza descargando y descomprimiendo el archivo (.zip)
Abre la carpeta dentro de Visual Studio Code.
Luego necesitarás compilar el codigo:
  Abre el archivo principal (en este caso main.c)
  Selecciona "terminal" arriba a la izquierda y luego "Nueva Terminal".
  Debes ingresar el siguiente comando y luego ejecutarlo: gcc *.c -o main.c
