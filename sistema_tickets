#include "list.h"
#include "list.c"
#include "extra.h"
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

int prioridad_a_numero(const char *prioridad)
{
  if (strcmp(prioridad, "Alta") == 0) return 3;
  if (strcmp(prioridad, "Media") == 0) return 2;
  if (strcmp(prioridad, "Baja") == 0) return 1;
  return 0;
}

void insertar_por_prioridad(List *listaTickets, datosTicket *nuevoTicket)
{
  if (list_size(listaTickets) == 0)
  {
    list_pushBack(listaTickets, nuevoTicket);
    return;
  }

  List *listaTemporal = list_create();
  bool agregado = false;

  datosTicket *ticket_actual = list_first(listaTickets);
  int prioridad_nueva = prioridad_a_numero(nuevoTicket->prioridad);

  while (ticket_actual != NULL)
  {
    int prioridad_actual = prioridad_a_numero(ticket_actual->prioridad);
    if (!agregado && prioridad_nueva > prioridad_actual)
    {
      list_pushBack(listaTemporal, nuevoTicket);
      agregado = true;
    }
    else if (!agregado && prioridad_nueva == prioridad_actual)
    {
      if(nuevoTicket->horaRegistro < ticket_actual->horaRegistro)
      {
        list_pushBack(listaTemporal, nuevoTicket);
        agregado = true;
      }
    }
    list_pushBack(listaTemporal, ticket_actual);
    ticket_actual = list_next(listaTickets);
  }

  if(!agregado)
  {
    list_pushBack(listaTemporal, nuevoTicket);
  }

  list_clean(listaTickets);
  ticket_actual = list_first(listaTemporal);
  while (ticket_actual != NULL)
  {
    list_pushBack(listaTickets, ticket_actual);
    ticket_actual = list_next(listaTemporal);
  }
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

  insertar_por_prioridad(listaTickets, nuevoTicket);
  printf("El ticket se ha registrado correctamente.\n");
}

void asignar_prioridad(List *listaTickets)
{
  if(list_size(listaTickets) == 0)
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
    printf("No se encontro el ticket con el ID ingresado.\n");
    return;
  }

  printf("\nTicket encontrado. Por favor ingrese la nueva prioridad (Alta, Media, Baja): ");
  scanf("%s[19]", nuevaPrioridad);

  if(strcmp(nuevaPrioridad, "Alta") == 0 || strcmp(nuevaPrioridad, "Media") == 0 || strcmp(nuevaPrioridad, "Baja") == 0)
  {
    strcpy(ticketBuscado->prioridad, nuevaPrioridad);
    time(&ticketBuscado->horaRegistro);
    printf("La prioridad del ticket ha sido actualizada correctamente.\n");
  }
  else
  {
    printf("Prioridad no valida. Por favor use 'Alta', 'Media' o 'Baja'.\n");
  }
}

void mostrar_lista_tickets(List *listaTickets) 
{
  if(list_size(listaTickets) == 0)
  {
    printf("\nNo hay tickets pendientes.\n");
    return;
  }
  printf("\nLista de tickets pendientes\n");
  datosTicket *ticket_actual = list_first(listaTickets);
  while(ticket_actual != NULL)
  {
    printf("ID del Ticket: %d, Descripcion: %s, Prioridad: %s\n", ticket_actual->id, ticket_actual->descripcion, ticket_actual->prioridad);
    ticket_actual = list_next(listaTickets);
  }
}

void procesar_siguiente_ticket(List *listaTickets)
{
  if(list_size(listaTickets) == 0)
  {
    printf("No hay tickets pendientes.\n");
    return;
  }
  datosTicket *ticketProcesado = list_first(listaTickets);
  char hora[10];
  strftime(hora, sizeof(hora), "%H:%M", localtime(&ticketProcesado->horaRegistro));

  printf("Datos del ticket procesado\n");
  printf("ID del Ticket: %d\n", ticketProcesado->id);
  printf("Descripcion: %s.\n", ticketProcesado->descripcion);
  printf("Prioridad: %s.\n", ticketProcesado->prioridad);
  printf("Hora de Registro: %s.\n", hora);

  list_popFront(listaTickets);
}

void buscar_ticket(List *listaTickets)
{
  if(list_size(listaTickets) == 0)
  {
    printf("No hay tickets registrados :) \n");
    return;
  }

  int ticketBuscado;
  printf("Ingrese el ID del Ticket a buscar: ");
  scanf("%d", &ticketBuscado);

  datosTicket *ticket_actual = list_first(listaTickets);
  bool encontrado = false;

  while (ticket_actual != NULL)
  {
    if (ticket_actual->id == ticketBuscado)
    {
      encontrado = true;
      break;
    }
    ticket_actual = list_next(listaTickets);
  }

  if (!encontrado)
  {
    printf("El ticket no se encuentra en la lista :( \n");
    return;
  }

  char hora[10];
  strftime(hora, sizeof(hora), "%H:%M", localtime(&ticket_actual->horaRegistro));
  printf("Ticket encontrado\n");
  printf("ID: %d\n", ticket_actual->id);
  printf("Descripcion: %s\n", ticket_actual->descripcion);
  printf("Prioridad: %s\n", ticket_actual->prioridad);
  printf("Hora de registro: %s\n", hora);

}

int main() {
  char opcion;
  List *listaTickets = list_create(); 

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
      asignar_prioridad(listaTickets);
      break;
    case '3':
      mostrar_lista_tickets(listaTickets);
      break;
    case '4':
      procesar_siguiente_ticket(listaTickets);
      break;
    case '5':
      buscar_ticket(listaTickets);
      break;
    case '6':
      puts("Saliendo del sistema de gestion de tickets...");
      break;
    default:
      puts("Opcion no valida. Por favor, intente de nuevo.");
    }
    presioneTeclaParaContinuar();

  } while (opcion != '6');

  list_clean(listaTickets);

  return 0;
}
