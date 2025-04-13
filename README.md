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

![image](https://github.com/user-attachments/assets/104b004a-12aa-476a-93d4-466b57edaa20)


  Una vez en terminal seleccione al lado del "+" y luego Git Bash.

![image](https://github.com/user-attachments/assets/f9d1c158-3622-4b3f-8d49-9d9c013b8ccc)


  Debes ingresar el siguiente comando en la terminal: gcc sistema_tickets.c -o sistema_tickets.exe
  
  Una vez compilado, podrás ejecutarlo con: ./sistema_tickets 

Funcionalidades (funcionando correctamente):
- Registrar Ticket con su ID y la descripción del problema.
- Asignarle prioridad a algún ticket registrado, asegúrese de que esta sea escrita como: Alta, Media o Baja.
- Mostrar lista de tickets pendientes (ordenados por prioridad y hora).
- Procesar el siguiente ticket (siguiendo el orden de prioridad).

Problemas Conocidos:
El sistema no verifica si el ID registrado ya está dentro de la lista, esto puede causar que hayan IDs duplicados.

Funcionalidades a Mejorar:
Permitir al usuario editar la descripción de un ticket dedspúes de ser registrado.
Una busqueda avanzada, permitir al usario filtrar tickets por prioridad u hora.

Ejemplo de Uso:
Sistema de Gestion de Tickets

1) Registrar ticket
2) Asignar prioridad a ticket
3) Mostrar lista de tickets pendientes
4) Procesar siguiente ticket
5) Buscar ticket por ID
6) Salir

Opción 1: Registrar un Ticket.
- Llega un nuevo cliente al soporte técnico.

Registrar nuevo ticket 

Ingrese ID del ticket: 1234 

Ingrese descripcion del problema: Sistema lento, lo necesito mañana para mi trabajo

El ticket se ha registrado correctamente.


El programa automáticamente registra el ticket con prioridad "Baja", la prioridad puede ser cambiada más adelante y si el usuario le asigna una nueva prioridad al ticket, la hora se actualizará a la hora donde la prioridad fue actualizada.

Opción 2: Asignar Prioridad
- El cliente necesita urgentemente su computadora arreglada para poder usarla en su trabajo.

Ingrese el ID del ticket al que desea asignar prioridad: 1234

Ticket encontrado. Por favor ingrese la nueva prioridad (Alta, Media, Baja): Alta

La prioridad del ticket ha sido actualizada correctamente.

El programa actualiza la prioridad del ticket 1234 a "Alta", de esta forma se asegura que el cliente será uno de los próximos en ser atendido.

Opción 3: Mostrar lista
- El usuario podrá ver la lista de clientes que esperan ser atendindos, estos estarán ordenados por prioridad y por hora.

Lista de tickets pendientes

ID del Ticket: 1234 Descripcion: Sistema lento, lo necesito mañana para mi trabajo, Prioridad: Alta

La lista mostrará primero al cliente con mayor prioridad y con la hora más antigua (en este caso solo a nuestro cliente con ID 1234)

Opción 4: Atender al siguiente cliente
- Se atiende al siguiente cliente basandose en su prioridad.
Se mostrarán los datos del cliente que fue atendido y se eliminarán sus datos de la lista de pendientes.

Opción 5: Buscar ticket por ID
- El usuario podrá buscar cualquier ticket por su ID y ver sus detalles.

Ingrese el ID del Ticket a buscar: 1234

Ticket encontrado

ID: 1234

Descripcion: Sistema lento, lo necesito mañana para mi trabajo

Prioridad: Alta

Hora de registro: 22:35

El programa nos mostrará todos los detalles del ID que busquemos, no lo eliminará de la lista, por lo que el usuario podrá revisar los detalles sin que el cliente sea atendido aún. 
