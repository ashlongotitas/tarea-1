#include "tdas/list.h"
#include "tdas/extra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct
{
  int id;
  char descripcion[100];  
  char prioridad[10]; // Alta, Media, Baja
  time_t horaRegistro;
} datosTicket;

// Menú principal
void mostrarMenuPrincipal() 
{
  limpiarPantalla();
  puts("========================================");
  puts("     Sistema de Gestion de Tickets");
  puts("========================================");

  puts("1) Registrar ticket");
  puts("2) Asignar prioridad a ticket");
  puts("3) Mostrar lista de tickets pendientes");
  puts("4) Procesar siguiente ticket");
  puts("5) Buscar ticket por ID");
  puts("6) Salir");
}

void registrar_ticket(List *listaTickets) 
{
  printf("Registrar nuevo ticket\n");
  datosTicket *nuevoTicket = (datosTicket*) malloc(sizeof(datosTicket));
  if (nuevoTicket == NULL)
  {
    puts("Error al registrar el ticket\n");
    return;
  }

  printf("Ingrese ID del ticket: ");
  scanf("%d", &nuevoTicket->id);

  printf("Ingrese descripcion del problema: ");
  scanf(" %99[^\n]", &nuevoTicket->descripcion);

  strcpy(nuevoTicket->prioridad, "Baja");
  time(&nuevoTicket->horaRegistro);

  list_pushBack(listaTickets, nuevoTicket);
  printf("El ticket se ha registrado correctamente.\n");
}

void asignar_prioridad(List *listaTickets)
{
  if(list_size == 0)
  {
    puts("No hay tickets registrados.\n");
    return;
  }

  int id_ticketBuscado;
  char nuevaPrioridad[20];

  printf("Ingrese el ID del ticket al que desea asignar prioridad: ");
  scanf("%d", &id_ticketBuscado);

  datosTicket *ticketBuscado = list_first(listaTickets);
  bool encontrado = false;
  while(ticketBuscado != NULL)
  {
    if(ticketBuscado->id == id_ticketBuscado)
    {
      encontrado = true;
      break;
    }
    ticketBuscado = list_next(listaTickets);
  }

  if(!encontrado)
  {
    puts("No se encontro el ticket con el ID ingresado.\n");
    return;
  }

  printf("\nTicket encontrado. Por favor ingrese la nueva prioridad (Alta, Media, Baja): ");
  scanf("%s[19]", nuevaPrioridad);

  if(strcmp(nuevaPrioridad, "Alta") == 0 || strcmp(nuevaPrioridad, "Media") == 0 || strcmp(nuevaPrioridad, "Baja") == 0)
  {
    strcpy(ticketBuscado->prioridad, nuevaPrioridad);
    printf("La prioridad del ticket ha sido actualizada correctamente.\n");
  }
  else
  {
    printf("Prioridad no valida. Por favor use 'Alta', 'Media' o 'Baja'.\n");
  }
}

int prioridad_a_numero(const char *prioridad)
{
  if(strcmp(prioridad, "Alta") == 0) return 3;
  if(strcmp(prioridad, "Media") == 0) return 2;
  if(strcmp(prioridad, "Baja") == 0) return 1;

  return 0;
}

int compararTickets(const void *a, const void *b)
{
  datosTicket *ptrA = *(datosTicket **) a;
  datosTicket *ptrB = *(datosTicket **) b;

  int prioridadA = prioridad_a_numero(ptrA->prioridad);
  int prioridadB = prioridad_a_numero(ptrB->prioridad);

  if(prioridadA != prioridadB)
  {
    if(prioridadA < prioridadB) return 1;
    if(prioridadA > prioridadB) return -1;

  }
  if(prioridadA == prioridadB)
  {
    if(ptrA->horaRegistro > ptrB->horaRegistro) return 1;
    if(ptrA->horaRegistro < ptrB->horaRegistro) return -1;
  }

  return 0;
}

void mostrar_lista_tickets(List *listaTickets) 
{
  if(list_size(listaTickets) == 0)
  {
    printf("\nNo hay tickets pendientes.\n");
    return;
  }
  printf("\nLista de tickets pendientes: \n");
  int total_tickets = list_size(listaTickets);

  datosTicket *copia_ticket[total_tickets];
  datosTicket *ticket_actual = list_first(listaTickets);

  for(int i = 0; i < total_tickets; i++)
  {
    copia_ticket[i] = ticket_actual;
    ticket_actual = list_next(listaTickets);
  }
  
  qsort(copia_ticket, total_tickets, sizeof(datosTicket*), compararTickets);
  for(int i = 0; i < total_tickets; i++)
  {
    printf("ID Ticket: %d\n", copia_ticket[i]->id);
  }
  
}

int main() {
  char opcion;
  List *listaTickets = list_create(); // puedes usar una lista para gestionar los pacientes

  do {
    mostrarMenuPrincipal();
    printf("\nIngrese su opcion: ");
    scanf(" %c", &opcion); // Nota el espacio antes de %c para consumir el
                           // newline anterior

    switch (opcion) {
    case '1':
      registrar_ticket(listaTickets);
      break;
    case '2':
      // Lógica para asignar prioridad
      asignar_prioridad(listaTickets);
      break;
    case '3':
      mostrar_lista_tickets(listaTickets);
      break;
    case '4':
      // Lógica para atender al siguiente paciente
      break;
    case '5':
      // Lógica para mostrar pacientes por prioridad
      break;
    case '6':
      puts("Saliendo del sistema de gestión de tickets...");
      break;
    default:
      puts("Opción no válida. Por favor, intente de nuevo.");
    }
    presioneTeclaParaContinuar();

  } while (opcion != '6');

  // Liberar recursos, si es necesario
  list_clean(listaTickets);

  return 0;
}

